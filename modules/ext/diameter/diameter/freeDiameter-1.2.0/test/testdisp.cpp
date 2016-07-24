/*********************************************************************************************************
* Software License Agreement (BSD License)                                                               *
* Author: Sebastien Decugis <sdecugis@freediameter.net>							 *
*													 *
* Copyright (c) 2013, WIDE Project and NICT								 *
* All rights reserved.											 *
* 													 *
* Redistribution and use of this software in source and binary forms, with or without modification, are  *
* permitted provided that the following conditions are met:						 *
* 													 *
* * Redistributions of source code must retain the above 						 *
*   copyright notice, this list of conditions and the 							 *
*   following disclaimer.										 *
*    													 *
* * Redistributions in binary form must reproduce the above 						 *
*   copyright notice, this list of conditions and the 							 *
*   following disclaimer in the documentation and/or other						 *
*   materials provided with the distribution.								 *
* 													 *
* * Neither the name of the WIDE Project or NICT nor the 						 *
*   names of its contributors may be used to endorse or 						 *
*   promote products derived from this software without 						 *
*   specific prior written permission of WIDE Project and 						 *
*   NICT.												 *
* 													 *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED *
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A *
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR *
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 	 *
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 	 *
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR *
* TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF   *
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.								 *
*********************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
#include "../tests/tests.h"
#ifdef __cplusplus
}
#endif

#include "rwut.h"
using ::testing::AtLeast;

#define Define_cb( __int, __extra )												\
int cb_##__int( struct msg ** msg, struct avp * avp, struct session * session, void * opaque, enum disp_action * action )	\
{																\
	EXPECT_EQ( 1, msg ? 1 : 0 );												\
	EXPECT_EQ( 1, action ? 1 : 0 );												\
	EXPECT_EQ( sess, session );													\
	if (opaque) {														\
		EXPECT_EQ( 1, opaque == g_opaque ? 1 : 0 );										\
	}															\
	*action = DISP_ACT_CONT;												\
	cbcalled[__int] += 1;													\
	do {															\
		__extra ;													\
	} while (0);														\
	return 0;														\
}

#define NB_CB	10
static char cbcalled[NB_CB];
static struct session * sess;
static void * g_opaque = (void *)"test";

/* cb_0 */  Define_cb( 0, );
/* cb_1 */  Define_cb( 1, );
/* cb_2 */  Define_cb( 2, );
/* cb_3 */  Define_cb( 3, );
/* cb_4 */  Define_cb( 4, );
/* cb_5 */  Define_cb( 5, );
/* cb_6 */  Define_cb( 6, return 12345 );
/* cb_7 */  Define_cb( 7, { EXPECT_EQ( 1, avp ? 1 : 0 ); } );
/* cb_8 */  Define_cb( 8, { EXPECT_EQ( 0, fd_msg_free( *msg ) ); *msg = NULL; } );
/* cb_9 */  Define_cb( 9, *action = DISP_ACT_SEND );
/* max: cb_<NB_CB - 1> */

/* Create a new message containing what we want */
struct msg * new_msg(int appid, struct dict_object * cmd, struct dict_object * avp1, struct dict_object * avp2, int val)
{
	struct msg *vnew;
	struct avp *avp;
	union avp_value value;
	struct msg_hdr * msg_hdr = NULL;
	
	EXPECT_EQ( 0, fd_msg_new ( cmd, 0, &vnew ) );
	EXPECT_EQ( 0, fd_msg_hdr ( vnew, &msg_hdr ) );
	msg_hdr->msg_appl = appid;
	
	if (avp1) {
		EXPECT_EQ( 0, fd_msg_avp_new ( avp1, 0, &avp ) );
		value.u32 = 0;
		EXPECT_EQ( 0, fd_msg_avp_setvalue ( avp, &value ) );
		EXPECT_EQ( 0, fd_msg_avp_add ( vnew, MSG_BRW_LAST_CHILD, avp ) );
	}
	
	if (avp2) {
		EXPECT_EQ( 0, fd_msg_avp_new ( avp2, 0, &avp ) );
		value.u32 = val;
		EXPECT_EQ( 0, fd_msg_avp_setvalue ( avp, &value ) );
		EXPECT_EQ( 0, fd_msg_avp_add ( vnew, MSG_BRW_LAST_CHILD, avp ) );
	}
	
	return vnew;	
}

/* Main test routine */
TEST (RwDiameter, TestDisp)
{
	struct dict_object * app1, * app2;
	struct dict_object * cmd1, * cmd2;
	struct dict_object * avp1, * avp2; /* avp2 is enumerated; they are both unsigned32 types */
	struct dict_object * enu1, * enu2;
	struct msg * msg = NULL, *error;
	enum disp_action action;
	struct disp_hdl * hdl[NB_CB];
	struct disp_when when;
	char * ec, *em;
	
	/* Create a dummy session, we don't use it anyway */
	#define DUMMY_SID "test.disp"
	EXPECT_EQ( 0, fd_sess_new( &sess, DUMMY_SID, CONSTSTRLEN(DUMMY_SID), NULL, 0 ) );
	
	memset(&when, 0xff, sizeof(when)); /* check that we don't use un-initialized parts */
	
	/* Initialize dictionary objects */
	{
		struct dict_object * enutype;
		struct dict_application_data app1_data = { 1, "Application test 1" };
		struct dict_application_data app2_data = { 2, "Application test 2" };
		struct dict_cmd_data cmd1_data = { 1, "Command test 1 (req)", CMD_FLAG_REQUEST,	CMD_FLAG_REQUEST };
		struct dict_cmd_data cmd2_data = { 1, "Command test 2 (ans)", CMD_FLAG_REQUEST,	0 };
		struct dict_type_data type_data = { AVP_TYPE_UNSIGNED32, "Type test", NULL, NULL };
		struct dict_avp_data avp1_data = { 10001, 0, "AVP test 1", 0, 0, AVP_TYPE_UNSIGNED32 };
		struct dict_avp_data avp2_data = { 10002, 0, "AVP test 2", 0, 0, AVP_TYPE_UNSIGNED32 };
		struct dict_enumval_data enu1_data = { "ENU test 1", { .u32 = 1 }};
		struct dict_enumval_data enu2_data = { "ENU test 2", { .u32 = 2 }};
		
		EXPECT_EQ( 0, fd_dict_new ( fd_g_config->cnf_dict, DICT_APPLICATION, &app1_data, NULL, &app1 ) );
		EXPECT_EQ( 0, fd_dict_new ( fd_g_config->cnf_dict, DICT_APPLICATION, &app2_data, NULL, &app2 ) );
		EXPECT_EQ( 0, fd_dict_new ( fd_g_config->cnf_dict, DICT_COMMAND, &cmd1_data, NULL, &cmd1 ) );
		EXPECT_EQ( 0, fd_dict_new ( fd_g_config->cnf_dict, DICT_COMMAND, &cmd2_data, NULL, &cmd2 ) );
		EXPECT_EQ( 0, fd_dict_new ( fd_g_config->cnf_dict, DICT_TYPE, &type_data, NULL, &enutype ) );
		EXPECT_EQ( 0, fd_dict_new ( fd_g_config->cnf_dict, DICT_AVP, &avp1_data, NULL,    &avp1 ) );
		EXPECT_EQ( 0, fd_dict_new ( fd_g_config->cnf_dict, DICT_AVP, &avp2_data, enutype, &avp2 ) );
		EXPECT_EQ( 0, fd_dict_new ( fd_g_config->cnf_dict, DICT_ENUMVAL, &enu1_data, enutype, &enu1 ) );
		EXPECT_EQ( 0, fd_dict_new ( fd_g_config->cnf_dict, DICT_ENUMVAL, &enu2_data, enutype, &enu2 ) );
	}
	
	/* Register first handler, very simple test */
	{
		EXPECT_EQ( 0, fd_disp_register( cb_0, DISP_HOW_ANY, NULL, NULL, &hdl[0] ) );
		EXPECT_EQ( 1, hdl[0] ? 1 : 0 );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[0], NULL ) );
		EXPECT_EQ( NULL, hdl[0] );
		EXPECT_EQ( 0, fd_disp_register( cb_0, DISP_HOW_ANY, NULL, NULL, &hdl[0] ) );
	
		/* Check this handler is called for a message */
		msg = new_msg( 0, cmd1, avp1, NULL, 0 );
		memset(cbcalled, 0, sizeof(cbcalled));
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		
		/* Delete the message */
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[0], NULL ) );
	}
	
	/* Handlers for applications */
	{
		EXPECT_EQ( 0, fd_disp_register( cb_0, DISP_HOW_ANY, &when, NULL, &hdl[0] ) );
		when.app = app1;
		EXPECT_EQ( 0, fd_disp_register( cb_1, DISP_HOW_APPID, &when, NULL, &hdl[1] ) );
		when.app = app2;
		EXPECT_EQ( 0, fd_disp_register( cb_2, DISP_HOW_APPID, &when, NULL, &hdl[2] ) );
		when.avp = avp2;
		EXPECT_EQ( 0, fd_disp_register( cb_3, DISP_HOW_APPID, &when, NULL, &hdl[3] ) );
		when.avp = avp1;
		EXPECT_EQ( 0, fd_disp_register( cb_4, DISP_HOW_APPID, &when, NULL, &hdl[4] ) );
	
		/* Check the callbacks are called as appropriate */
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 0, cmd1, avp1, NULL, 0 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 0, cbcalled[1] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( 0, cbcalled[4] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 1, cmd1, avp1, NULL, 0 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( 0, cbcalled[4] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 2, cmd1, avp1, NULL, 0 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 0, cbcalled[1] );
		EXPECT_EQ( 1, cbcalled[2] );
		EXPECT_EQ( 1, cbcalled[3] );
		EXPECT_EQ( 1, cbcalled[4] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[0], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[1], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[2], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[3], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[4], NULL ) );
	}
	
	/* Handlers for commands */
	{
		when.app = NULL;
		when.command = NULL;
		EXPECT_EQ( 0, fd_disp_register( cb_0, DISP_HOW_ANY, &when, NULL, &hdl[0] ) );
		EXPECT_EQ( EINVAL, fd_disp_register( cb_1, DISP_HOW_CC, &when, NULL, &hdl[1] ) );
		when.command = cmd1;
		EXPECT_EQ( 0, fd_disp_register( cb_1, DISP_HOW_CC, &when, NULL, &hdl[1] ) ); /* cmd1 */
		when.app = app2;
		EXPECT_EQ( 0, fd_disp_register( cb_2, DISP_HOW_CC, &when, NULL, &hdl[2] ) ); /* app2 + cmd1 */
		when.command = cmd2;
		when.app = NULL;
		when.avp = avp1;
		EXPECT_EQ( 0, fd_disp_register( cb_3, DISP_HOW_CC, &when, NULL, &hdl[3] ) ); /* cmd2 (avp1 ignored) */
		
		/* Check the callbacks are called as appropriate */
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 0, cmd1, avp1, NULL, 0 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 2, cmd1, avp1, NULL, 0 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 1, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 2, cmd2, avp1, NULL, 0 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 0, cbcalled[1] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 1, cbcalled[3] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 1, cmd2, NULL, avp2, 0 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 0, cbcalled[1] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 1, cbcalled[3] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[0], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[1], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[2], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[3], NULL ) );
	}
	
	/* Handlers for AVPs */
	{
		when.app = NULL;
		when.command = NULL;
		when.avp = NULL;
	
		EXPECT_EQ( 0, fd_disp_register( cb_0, DISP_HOW_ANY, &when, NULL, &hdl[0] ) ); /* all */
		EXPECT_EQ( EINVAL, fd_disp_register( cb_1, DISP_HOW_AVP, &when, NULL, &hdl[1] ) );
		
		when.avp = avp1;
		EXPECT_EQ( 0, fd_disp_register( cb_1, DISP_HOW_AVP, &when, NULL, &hdl[1] ) ); /* avp1 */
		
		when.command = cmd1;
		EXPECT_EQ( 0, fd_disp_register( cb_2, DISP_HOW_AVP, &when, NULL, &hdl[2] ) ); /* avp1 + cmd1 */
		
		when.command = NULL;
		when.app = app1;
		EXPECT_EQ( 0, fd_disp_register( cb_3, DISP_HOW_AVP, &when, NULL, &hdl[3] ) ); /* avp1 + app1 */
		
		when.command = cmd1;
		EXPECT_EQ( 0, fd_disp_register( cb_4, DISP_HOW_AVP, &when, NULL, &hdl[4] ) ); /* avp1 + cmd1 + app1 */
		
		when.app = NULL;
		when.command = NULL;
		when.avp = avp2;
		when.value = enu1;
		EXPECT_EQ( 0, fd_disp_register( cb_5, DISP_HOW_AVP, &when, NULL, &hdl[5] ) ); /* avp2 */
		
		when.value = enu2;
		EXPECT_EQ( 0, fd_disp_register( cb_7, DISP_HOW_AVP, &when, NULL, &hdl[6] ) ); /* avp2 */
		
		
		
		/* Check the callbacks are called as appropriate */
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 0, cmd1, NULL, NULL, 0 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 0, cbcalled[1] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( 0, cbcalled[4] );
		EXPECT_EQ( 0, cbcalled[5] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 0, cmd1, avp1, NULL, 0 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 1, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( 0, cbcalled[4] );
		EXPECT_EQ( 0, cbcalled[5] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 1, cmd2, avp1, NULL, 0 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 1, cbcalled[3] );
		EXPECT_EQ( 0, cbcalled[4] );
		EXPECT_EQ( 0, cbcalled[5] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 1, cmd1, avp1, NULL, 0 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 1, cbcalled[2] );
		EXPECT_EQ( 1, cbcalled[3] );
		EXPECT_EQ( 1, cbcalled[4] );
		EXPECT_EQ( 0, cbcalled[5] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 1, cmd1, avp1, avp2, 0 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 1, cbcalled[2] );
		EXPECT_EQ( 1, cbcalled[3] );
		EXPECT_EQ( 1, cbcalled[4] );
		EXPECT_EQ( 1, cbcalled[5] );
		EXPECT_EQ( 1, cbcalled[7] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 1, cmd1, NULL, avp2, 1 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 0, cbcalled[1] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( 0, cbcalled[4] );
		EXPECT_EQ( 1, cbcalled[5] );
		EXPECT_EQ( 1, cbcalled[7] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 1, cmd1, NULL, avp2, 2 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 0, cbcalled[1] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( 0, cbcalled[4] );
		EXPECT_EQ( 1, cbcalled[5] );
		EXPECT_EQ( 1, cbcalled[7] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[0], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[1], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[2], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[3], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[4], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[5], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[6], NULL ) );
	}
		
	/* Handlers for enum values */
	{
		when.app = NULL;
		when.command = NULL;
		when.avp = NULL;
		when.value = NULL;
		
		EXPECT_EQ( 0, fd_disp_register( cb_0, DISP_HOW_ANY, &when, NULL, &hdl[0] ) ); /* all */
		EXPECT_EQ( EINVAL, fd_disp_register( cb_1, DISP_HOW_AVP_ENUMVAL, &when, NULL, &hdl[1] ) );
		when.value = enu1;
		EXPECT_EQ( EINVAL, fd_disp_register( cb_1, DISP_HOW_AVP_ENUMVAL, &when, NULL, &hdl[1] ) );
		when.avp = avp1;
		EXPECT_EQ( EINVAL, fd_disp_register( cb_1, DISP_HOW_AVP_ENUMVAL, &when, NULL, &hdl[1] ) );
		when.avp = avp2;
		EXPECT_EQ( 0, fd_disp_register( cb_1, DISP_HOW_AVP_ENUMVAL, &when, NULL, &hdl[1] ) ); /* avp2, enu1 */
		
		when.command = cmd1;
		EXPECT_EQ( 0, fd_disp_register( cb_2, DISP_HOW_AVP_ENUMVAL, &when, NULL, &hdl[2] ) ); /* avp2, enu1 + cmd1 */
		
		when.command = NULL;
		when.app = app1;
		when.value = enu2;
		EXPECT_EQ( 0, fd_disp_register( cb_3, DISP_HOW_AVP_ENUMVAL, &when, NULL, &hdl[3] ) ); /* avp2, enu2 + app1 */
		
		/* Check the callbacks are called as appropriate */
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 0, cmd1, avp1, NULL, 0 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 0, cbcalled[1] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 1, cmd2, avp1, avp2, 0 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 0, cbcalled[1] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 1, cmd2, avp1, avp2, 1 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 1, cmd2, avp1, avp2, 2 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 0, cbcalled[1] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 1, cbcalled[3] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 1, cmd1, avp1, avp2, 1 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 1, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 1, cmd2, avp1, avp2, 1 );
		{
			struct avp *avp;
			union avp_value value;
			EXPECT_EQ( 0, fd_msg_avp_new ( avp2, 0, &avp ) );
			value.u32 = 2;
			EXPECT_EQ( 0, fd_msg_avp_setvalue ( avp, &value ) );
			EXPECT_EQ( 0, fd_msg_avp_add ( msg, MSG_BRW_LAST_CHILD, avp ) );
		}
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 1, cbcalled[3] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[0], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[1], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[2], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[3], NULL ) );
	}
	
	/* Test behavior of handlers */
	{
		EXPECT_EQ( 0, fd_disp_register( cb_0, DISP_HOW_ANY, &when, NULL, &hdl[0] ) );
		EXPECT_EQ( 0, fd_disp_register( cb_1, DISP_HOW_ANY, &when, NULL, &hdl[1] ) );
		EXPECT_EQ( 0, fd_disp_register( cb_6, DISP_HOW_ANY, &when, NULL, &hdl[2] ) );
		EXPECT_EQ( 0, fd_disp_register( cb_2, DISP_HOW_ANY, &when, NULL, &hdl[3] ) );
		EXPECT_EQ( 0, fd_disp_register( cb_3, DISP_HOW_ANY, &when, NULL, &hdl[4] ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 1, cmd1, avp1, avp2, 1 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 1, cbcalled[6] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( 0, msg ? 1 : 0);
		EXPECT_EQ( 1, em ? 1 : 0);
		EXPECT_EQ( 0, fd_msg_free( error ) );
		
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[0], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[1], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[2], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[3], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[4], NULL ) );
		
		EXPECT_EQ( 0, fd_disp_register( cb_0, DISP_HOW_ANY, &when, NULL, &hdl[0] ) );
		EXPECT_EQ( 0, fd_disp_register( cb_1, DISP_HOW_ANY, &when, NULL, &hdl[1] ) );
		EXPECT_EQ( 0, fd_disp_register( cb_8, DISP_HOW_ANY, &when, NULL, &hdl[2] ) );
		EXPECT_EQ( 0, fd_disp_register( cb_2, DISP_HOW_ANY, &when, NULL, &hdl[3] ) );
		EXPECT_EQ( 0, fd_disp_register( cb_3, DISP_HOW_ANY, &when, NULL, &hdl[4] ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 1, cmd1, avp1, avp2, 1 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 1, cbcalled[8] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( NULL, msg );
		EXPECT_EQ( NULL, em );
		
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[0], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[1], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[2], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[3], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[4], NULL ) );
		
		EXPECT_EQ( 0, fd_disp_register( cb_0, DISP_HOW_ANY, &when, NULL, &hdl[0] ) );
		EXPECT_EQ( 0, fd_disp_register( cb_1, DISP_HOW_ANY, &when, NULL, &hdl[1] ) );
		EXPECT_EQ( 0, fd_disp_register( cb_9, DISP_HOW_ANY, &when, NULL, &hdl[2] ) );
		EXPECT_EQ( 0, fd_disp_register( cb_2, DISP_HOW_ANY, &when, NULL, &hdl[3] ) );
		EXPECT_EQ( 0, fd_disp_register( cb_3, DISP_HOW_ANY, &when, NULL, &hdl[4] ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 1, cmd1, avp1, avp2, 1 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 1, cbcalled[9] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( DISP_ACT_SEND, action );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[0], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[1], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[2], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[3], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[4], NULL ) );
	}
		
	/* Test order of handlers */
	{
		when.app = app2;
		when.command = cmd2;
		when.avp = avp2;
		when.value = enu2;
		
		EXPECT_EQ( 0, fd_disp_register( cb_0, DISP_HOW_ANY, &when, NULL, &hdl[0] ) );
		EXPECT_EQ( 0, fd_disp_register( cb_1, DISP_HOW_AVP_ENUMVAL, &when, NULL, &hdl[1] ) );
		EXPECT_EQ( 0, fd_disp_register( cb_2, DISP_HOW_AVP, &when, NULL, &hdl[2] ) );
		EXPECT_EQ( 0, fd_disp_register( cb_3, DISP_HOW_CC, &when, NULL, &hdl[3] ) );
		EXPECT_EQ( 0, fd_disp_register( cb_4, DISP_HOW_APPID, &when, NULL, &hdl[4] ) );
		
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 2, cmd2, avp1, avp2, 2 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 1, cbcalled[2] );
		EXPECT_EQ( 1, cbcalled[3] );
		EXPECT_EQ( 1, cbcalled[4] );
		EXPECT_EQ( 0, cbcalled[9] );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		
		EXPECT_EQ( 0, fd_disp_register( cb_9, DISP_HOW_ANY, &when, NULL, &hdl[5] ) );
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 2, cmd2, avp1, avp2, 2 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 0, cbcalled[1] );
		EXPECT_EQ( 0, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( 0, cbcalled[4] );
		EXPECT_EQ( 1, cbcalled[9] );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[5], NULL ) );
		
		EXPECT_EQ( 0, fd_disp_register( cb_9, DISP_HOW_AVP_ENUMVAL, &when, NULL, &hdl[5] ) );
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 2, cmd2, avp1, avp2, 2 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 1, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( 0, cbcalled[4] );
		EXPECT_EQ( 1, cbcalled[9] );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[5], NULL ) );
		
		EXPECT_EQ( 0, fd_disp_register( cb_9, DISP_HOW_AVP, &when, NULL, &hdl[5] ) );
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 2, cmd2, avp1, avp2, 2 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 1, cbcalled[2] );
		EXPECT_EQ( 0, cbcalled[3] );
		EXPECT_EQ( 0, cbcalled[4] );
		EXPECT_EQ( 1, cbcalled[9] );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[5], NULL ) );
		
		EXPECT_EQ( 0, fd_disp_register( cb_9, DISP_HOW_CC, &when, NULL, &hdl[5] ) );
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 2, cmd2, avp1, avp2, 2 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 1, cbcalled[2] );
		EXPECT_EQ( 1, cbcalled[3] );
		EXPECT_EQ( 0, cbcalled[4] );
		EXPECT_EQ( 1, cbcalled[9] );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[5], NULL ) );
		
		EXPECT_EQ( 0, fd_disp_register( cb_9, DISP_HOW_APPID, &when, NULL, &hdl[5] ) );
		memset(cbcalled, 0, sizeof(cbcalled));
		msg = new_msg( 2, cmd2, avp1, avp2, 2 );
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( 1, cbcalled[1] );
		EXPECT_EQ( 1, cbcalled[2] );
		EXPECT_EQ( 1, cbcalled[3] );
		EXPECT_EQ( 1, cbcalled[4] );
		EXPECT_EQ( 1, cbcalled[9] );
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[5], NULL ) );
		
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[0], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[1], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[2], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[3], NULL ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[4], NULL ) );
	}			
	
	/* Test application support advertisement */
	{
		struct dict_object * vnd;
		struct dict_vendor_data vnd_data = { 1, "Vendor test" };
		struct fd_app * app;
		
		EXPECT_EQ( 0, fd_dict_new ( fd_g_config->cnf_dict, DICT_VENDOR, &vnd_data, NULL, &vnd ) );
		
		EXPECT_EQ( EINVAL, fd_disp_app_support ( vnd, NULL, 1, 0 ) );
		EXPECT_EQ( EINVAL, fd_disp_app_support ( app1, NULL, 0, 0 ) );
		EXPECT_EQ( 0, fd_disp_app_support ( app1, NULL, 1, 0 ) );
		EXPECT_EQ( 0, fd_disp_app_support ( app1, NULL, 0, 1 ) );
		EXPECT_EQ( 0, fd_disp_app_support ( app2, vnd, 1, 0 ) );
		
		app = (struct fd_app *)(fd_g_config->cnf_apps.next);
		EXPECT_EQ( 1, app->appid );
		EXPECT_EQ( 1, app->flags.auth );
		EXPECT_EQ( 1, app->flags.acct );
		app = (struct fd_app *)(fd_g_config->cnf_apps.prev);
		EXPECT_EQ( 2, app->appid );
		EXPECT_EQ( 1, app->flags.auth );
		EXPECT_EQ( 0, app->flags.acct );
		
		#if 0
		fd_log_debug("%s", fd_conf_dump(FD_DUMP_TEST_PARAMS));
		#endif
	}
	
	/* Test opaque pointer management */
	{
		void * ptr;
		EXPECT_EQ( 0, fd_disp_register( cb_0, DISP_HOW_ANY, NULL, g_opaque, &hdl[0] ) );
	
		/* Check this handler is called for a message */
		msg = new_msg( 0, cmd1, avp1, NULL, 0 );
		memset(cbcalled, 0, sizeof(cbcalled));
		EXPECT_EQ( 0, fd_msg_dispatch ( &msg, sess, &action, &ec, &em, &error ) );
		EXPECT_EQ( 1, cbcalled[0] );
		EXPECT_EQ( DISP_ACT_CONT, action );
		
		/* Delete the message */
		EXPECT_EQ( 0, fd_msg_free( msg ) );
		EXPECT_EQ( 0, fd_disp_unregister( &hdl[0], &ptr ) );
		EXPECT_EQ( 1, ptr == g_opaque ? 1 : 0 );
	}
	
} 
	
