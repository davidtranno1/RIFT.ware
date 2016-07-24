
/*
 * 
 * (c) Copyright RIFT.io, 2013-2016, All Rights Reserved
 *
 */


/**
 * @file rwvx.h
 * @author Justin Bronder (justin.bronder@riftio.com)
 * @date 09/29/2014
 * @brief Top level API include for rwcal submodule
 */

#ifndef __RWCAL_API_H__
#define __RWCAL_API_H__

#include <stdbool.h>

#include <libpeas/peas.h>

#include <rwcal.h>
#include <rwlib.h>
#include <rw-manifest.pb-c.h>
#include <rw_vx_plugin.h>

#include "rwlog.h"

__BEGIN_DECLS

struct rwcal_module_s {
  rw_vx_framework_t * framework;
  rw_vx_modinst_common_t *mip;

  PeasExtension * zk;
  RwCalZookeeper * zk_cls;
  RwCalZookeeperIface * zk_iface;

  PeasExtension * cloud;
  RwCalCloud * cloud_cls;
  RwCalCloudIface * cloud_iface;

  rwlog_ctx_t *rwlog_instance;
};
typedef struct rwcal_module_s * rwcal_module_ptr_t;

/* Type generated by vala, see rwcal.vala RwCal::ZkServerPortDetail */
typedef RwCalZkServerPortDetail * rwcal_zk_server_port_detail_ptr_t;

/* Type generated by vala, see rwcal.vala RwCal::KazooClientStateEnum */
typedef RwCalKazooClientStateEnum rwcal_kazoo_client_state_t;

/* Type generated by vala, see rwcal.vala RwCal::Closure */
typedef RwCalClosure * rwcal_closure_ptr_t;

// Redefine yang autonames
typedef RWPB_E(RwManifest_RwcalCloudType) rwcal_cloud_type;

/*
 * Allocate a rwcal module.  Once allocated, the clients within
 * the module still need to be initialized.  For rwzk, see
 * rwcal_rwzk_{kazoo,zake}_init().  For rwcloud, see
 * rwcal_cloud_init().  It is a fatal error to attempt to use any
 * client before it has been initialized.  However, it is
 * perfectly fine to not initialize a client that will remain
 * unused.  Note that every function contains the client that it
 * will use as part of the name, just after the rwcal_ prefix.
 *
 * @return - rwcal module handle or NULL on failure.
 */
rwcal_module_ptr_t rwcal_module_alloc();

/*
 * Deallocate a rwcal module.
 *
 * @param - pointer to the rwcal module to be deallocated.
 */
void rwcal_module_free(rwcal_module_ptr_t * rwcal);

/*
 * Create a rwcal closure.  The closure can be passed as an argument to python
 * functions which expect a callback.  Then, when python triggers its callback,
 * the closure will execute the function that was passed in.  If the function
 * returns anything but RW_STATUS_SUCCESS, the corresponding exception will
 * be raised in python (RWError*), where it can be handled normally by python.
 *
 * Callbacks must match the declaration:
 *  rw_status_t callback(rwcal_module_ptr_t rwcal, void * user_data);
 * The first parameter will be set to the rwcal instance that created this
 * closure.  The second is user specified.
 *
 * @param rwcal     - module handle.
 * @param callback  - callback to execute when python's callback is triggered.
 * @param user_data - passed as the second argument to the callback.
 * @return          - rwcal closure instance or NULL on error.
 */
rwcal_closure_ptr_t rwcal_closure_alloc(
    rwcal_module_ptr_t rwcal,
    rw_status_t (*callback)(rwcal_module_ptr_t, void *, int),
    void * user_data);

/*
 * Deallocate a rwcal closure.  Note that any user data that was passed in will
 * not be touched.  It is up to the caller to handle that.  On return, closure
 * will be set to NULL.
 *
 * @param closure - pointer to closure to deallocate.
 */
void rwcal_closure_free(rwcal_closure_ptr_t * closure);

/*
 * Create a rwcal zookeeper server port detail.  This can be passed as an 
 * argument to kazoo client init functions
 *
 * @param zk_server_addr - zookeeper server ip address as a string
 * @param zk_client_port - client port associated with the server
 * @param zk_server_id   - id associated with the server
 * @param zk_server_start - indicate if server needs to be started
 * @param zk_client_connect - indicate if client need to connect to this server
 * @return               - rwcal_zk_server_port_detail instance or NULL on error.
 */
rwcal_zk_server_port_detail_ptr_t rwcal_zk_server_port_detail_alloc(
    char               *zk_server_addr,
    int                zk_client_port,
    int                zk_server_id,
    bool               zk_server_start,
    bool               zk_client_connect);

/*
 * Deallocate a rwcal zookeeper server port detail.  
 * On return the zk_server_port_detail shall be set to NULL
 *
 * @param zk_server_port_detail - pointer to zk_server_port_detail to deallocate.
 */
void rwcal_zk_server_port_detail_free(rwcal_zk_server_port_detail_ptr_t * zk_server_port_detail);

/*
 * Create the zookeeper server configuration.
 *
 * @param rwcal         - module handle.
 * @param id            - identifier of this server in the zookeeper ensemble.
 * @param client_port   - client port for this server instance
 * @param unique_ports  - generate port number based on UID.
 * @param server_details - NULL terminated list of zookeeper server port detail
 * @return              - rift_status.
 */
rw_status_t rwcal_rwzk_create_server_config(
    rwcal_module_ptr_t rwcal,
    int id,
    int client_port,
    bool unique_ports,
    rwcal_zk_server_port_detail_ptr_t *server_details);

/*
 * Start the zookeeper server.
 *
 * @param rwcal         - module handle.
 * @param id            - identifier of this server in the zookeeper ensemble.
 * @return              - pid of started zoo keeper server
 */
int rwcal_rwzk_server_start(rwcal_module_ptr_t rwcal, int id);

/*
 * Initialize rwcal to use a real zookeeper server.  This is done
 * by using the python Kazoo module.
 *
 * @param rwcal         - module handle.
 * @param server_details - NULL terminated list of zookeeper server port detail
 * @return              - rift_status.
 */
rw_status_t rwcal_rwzk_kazoo_init(rwcal_module_ptr_t rwcal, rwcal_zk_server_port_detail_ptr_t *server_details);

/*
 * Start kazoo client
 * by using the python Kazoo module.
 *
 * @param rwcal         - module handle.
 * @return              - rift_status.
 */
rw_status_t rwcal_rwzk_kazoo_start(rwcal_module_ptr_t rwcal);

/*
 * Stop kazoo client
 * by using the python Kazoo module.
 *
 * @param rwcal         - module handle.
 * @return              - rift_status.
 */
rw_status_t rwcal_rwzk_kazoo_stop(rwcal_module_ptr_t rwcal);

/*
 * Initialize rwcal to use a fake, in-memory, server.  This is suitable
 * for fully collapsed RIFT collectives.
 *
 * @param rwcal - module handle.
 * @return      - rift status.
 */
rw_status_t rwcal_rwzk_zake_init(rwcal_module_ptr_t rwcal);

/*
 * Create a zookeeper node
 *
 * @param rwcal   - module handle.
 * @param path    - path to the node to create.
 * @param closure - callback closure which would result in invoke of async
 *                  flavor of zk operation
 * @return      - RW_STATUS_SUCCESS on creation,
 *                RW_STATUS_EXISTS if the node already exists,
 *                RW_STATUS_FAILURE otherwise.
 */
rw_status_t rwcal_rwzk_create(rwcal_module_ptr_t rwcal, const char * path,
                              const rwcal_closure_ptr_t closure);

/*
 * Check if a zookeeper node exists
 *
 * @param rwcal - module handle.
 * @param path  - path to the node.
 * @return      - true if the node exists, false otherwise.
 */
bool rwcal_rwzk_exists(rwcal_module_ptr_t rwcal, const char * path);

/*
 * Get data stored at the given zookeeper node.
 *
 * @param rwcal   - module_handle.
 * @param path    - path to node.
 * @param data    - on success, contains a pointer to a buffer containing the node data.
 * @param closure - callback closure which would result in invoke of async
 *                  flavor of zk operation
 * @return      - RW_STATUS_SUCCESS,
 *                RW_STATUS_NOTFOUND if the node doesn't exists,
 *                RW_STATUS_FAILURE otherwise.
 */
rw_status_t rwcal_rwzk_get(
    rwcal_module_ptr_t rwcal,
    const char * path,
    char ** data,
    const rwcal_closure_ptr_t closure);

/*
 * Set data stored at the given zookeeper node.
 *
 * @param rwcal   - module_handle.
 * @param path    - path to node.
 * @param data    - pointer to data to set in the node.
 * @param closure - callback closure which would result in invoke of async
 *                  flavor of zk operation
 * @return      - RW_STATUS_SUCCESS,
 *                RW_STATUS_NOTFOUND if the node doesn't exists,
 *                RW_STATUS_FAILURE otherwise.
 */
rw_status_t rwcal_rwzk_set(
    rwcal_module_ptr_t rwcal,
    const char * path,
    const char * data,
    const rwcal_closure_ptr_t closure);

/*
 * Get a list of the children of the specified node.
 *
 * @param rwcal     - module handle.
 * @param path      - path to node.
 * @param children  - On success, NULL-terminated list of children nodes.
 * @param closure   - callback closure which would result in invoke of async
 *                    flavor of zk operation
 * @return          - RW_STATUS_SUCCESS,
 *                    RW_STATUS_NOTFOUND if the node doesn't exist,
 *                    RW_STATUS_FAILURE otherwise.
 */
rw_status_t rwcal_rwzk_get_children(
    rwcal_module_ptr_t rwcfal,
    const char * path,
    char *** children,
    const rwcal_closure_ptr_t closure);

/*
 * Delete a zookeeper node.  Note that similar to 'rmdir' the node must
 * not have any children.
 *
 * @param rwcal   - module handle.
 * @param path    - path to node.
 * @param closure - callback closure which would result in invoke of async
 *                  flavor of zk operation
 * @return      - RW_STATUS_SUCCESS,
 *                RW_STATUS_NOTEMPTY if the node has children,
 *                RW_STATUS_NOTFOUND if the node doesn't exist,
 *                RW_STATUS_FAILURE otherwise.
 */
rw_status_t rwcal_rwzk_delete(rwcal_module_ptr_t rwcal, const char * path,
                              const rwcal_closure_ptr_t closure);

/*
 * Watch a zookeeper node for any data changes as well as creation/deletion
 * of the node itself.
 *
 * @param rwcal   - module handle.
 * @param path    - path to node to monitor.
 * @param closure - callback closure which would result in invoke of async
 *                  flavor of zk operation
 * @return        - rw_status_t
 */
rw_status_t rwcal_rwzk_register_watcher(
    rwcal_module_ptr_t rwcal,
    const char * path,
    const rwcal_closure_ptr_t closure);

/*
 * Stop watching a zookeeper node for any changes.
 *
 * @param rwcal   - module handle.
 * @param path    - path to stop monitoring.
 * @param closure - callback closure to unregister.
 * @return        - rw_status_t
 */
rw_status_t rwcal_rwzk_unregister_watcher(
    rwcal_module_ptr_t rwcal,
    const char * path,
    const rwcal_closure_ptr_t closure);

/*
 * Lock a node for writing.  This call is reentrant.
 *
 * @param rwcal   - module handle.
 * @param path    - path to lock.
 * @param timeout - if not NULL, maximum amount of time to wait on acquisition
 * @return        - RW_STATUS_SUCCESS,
 *                  RW_STATUS_NOTFOUND if the node does not exist,
 *                  RW_STATUS_NOTCONNECTED if lock acquisition fails
 *                  RW_STATUS_TIMEOUT if acquisition timed out
 *                  RW_STATUS_FAILURE otherwise.
 */
rw_status_t rwcal_rwzk_lock(
    rwcal_module_ptr_t rwcal,
    const char * path,
    struct timeval * timeout);

/*
 * Unlock a node for writing.
 *
 * @param rwcal - module handle.
 * @param path  - path to unlock.
 * @return      - RW_STATUS_SUCCESS,
 *                RW_STATUS_NOTFOUND if the node does not exist,
 *                RW_STATUS_NOTCONNECTED if a lock was not previously acquired,
 *                RW_STATUS_FAILURE otherwise.
 */
rw_status_t rwcal_rwzk_unlock(rwcal_module_ptr_t rwcal, const char * path);

/*
 * Test if a node is locked or not.
 *
 * @param rwcal - module handle.
 * @param path  - path to check for locked status.
 * @return      - True if the node is locked, false otherwise.
 */
bool rwcal_rwzk_locked(rwcal_module_ptr_t rwcal, const char * path);


/*
 * Initialize the rwcal cloud controller.
 *
 * key/secret for various cloud types:
 *  EC2: ACCESS_ID/SECRET_KEY
 *
 * @param rwcal       - module handle.
 * @return        - RW_STATUS_SUCCESS,
 *                  RW_STATUS_NOTFOUND if the type is unknown,
 *                  RW_STATUS_FAILURE otherwise.
 */
rw_status_t rwcal_cloud_init(rwcal_module_ptr_t rwcal);

/*
 * Get a list of the names of the available images that can be
 * used to start a new VM.
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param image_names - on success, contains a NULL-terminated
 *                      list of image names.
 * @return            - rw_status_t
 */
rw_status_t rwcal_get_image_list(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    rwpb_gi_Rwcal_VimResources **images);

/*
 * Delete Image.
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param image_id    - id of image to be deleted
 * @return            - rw_status_t
 */
rw_status_t rwcal_delete_image(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char * image_id);

/*
 * Create a flavor.
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param flavor      - rwpb_gi_Rwcal_FlavorInfoItem object describing the
 *                      flavor to be created
 * @param flavor_id   - on success, contains a NULL-terminated string containing the new flavor_id
 * @return            - rw_status_t
 */
rw_status_t rwcal_create_flavor(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    rwpb_gi_Rwcal_FlavorInfoItem *flavor,
    char *flavor_id);


/*
 * Delete flavor.
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param flavor_id   - id of flavor to be deleted
 * @return            - rw_status_t
 */
rw_status_t rwcal_delete_flavor(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char * flavor_id);

/*
 * Get a specific flavor
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param flavor_id   - id of the flavor to return
 * @param flavir      - rwpb_gi_Rwcal_FlavorInfoItem object containing the
 *                      details of the requested flavor
 *
 * @return            - rw_status_t
 */
rw_status_t rwcal_get_flavor(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char * flavor_id,
    rwpb_gi_Rwcal_FlavorInfoItem **flavor);

/*
 * Get a list of the details for all flavors
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param flavors     - on success, contains a list of flavor info objects
 *
 * @return            - rw_status_t
 */
rw_status_t rwcal_get_flavor_list(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    rwpb_gi_Rwcal_VimResources **flavors);

/*
 * Create a virtual machine.
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param vm          - the information that defines what kind of VM will be
 *                      created
 * @param vm_id       - on success, contains a NULL-terminated string
 *                      containing the new vm id
 *
 * @return            - rw_status_t
 */
rw_status_t rwcal_create_vm(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    rwpb_gi_Rwcal_VMInfoItem *vm,
    char **vm_id);

/*
 * Delete VM.
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param vm_id       - id of vm to be deleted
 * @return            - rw_status_t
 */
rw_status_t rwcal_delete_vm(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char * vm_id);

/*
 * Reboot VM.
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param vm_id       - id of vm to be deleted
 * @return            - rw_status_t
 */
rw_status_t rwcal_reboot_vm(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char * vm_id);

/*
 * Start VM.
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param vm_id       - id of a vm to start
 * @return            - rw_status_t
 */
rw_status_t rwcal_start_vm(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char * vm_id);

/*
 * Stop VM.
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param vm_id       - id of a vm to stop
 * @return            - rw_status_t
 */
rw_status_t rwcal_stop_vm(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char * vm_id);

/*
 * Get a list of the names of the available vms
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param vms         - on success, contains a NULL-terminated
 *                      list of vms.
 * @return            - rw_status_t
 */
rw_status_t rwcal_get_vm_list(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    rwpb_gi_Rwcal_VimResources** vms);

/*
 * Create a tenant.
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param tenant_name - name to assign to the tenant.
 * @param tenant_info - on success, contains a NULL-terminated list of tenant_info
 * @return            - rw_status_t
 */
rw_status_t rwcal_create_tenant(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char * tenant_name,
    char *** tenant_info);

/*
 * Delete tenant.
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param tenant_id   - id of tenant to be deleted
 * @return            - rw_status_t
 */
rw_status_t rwcal_delete_tenant(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char * tenant_id);

/*
 * Get a list of the available tenants
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param tenants     - on success, contains a NULL-terminated
 *                      list of tenants.
 * @return            - rw_status_t
 */
rw_status_t rwcal_get_tenant_list(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    rwpb_gi_Rwcal_VimResources **tenants);

/*
 * Create a role.
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param role_name   - name to assign to the role.
 * @param role_info   - on success, contains a NULL-terminated list of role_info
 * @return            - rw_status_t
 */
rw_status_t rwcal_create_role(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char * role_name,
    char *** role_info);

/*
 * Delete role.
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param role_id     - id of role to be deleted
 * @return            - rw_status_t
 */
rw_status_t rwcal_delete_role(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char * role_id);

/*
 * Get a list of the available roles
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param roles       - on success, contains a NULL-terminated
 *                      list of roles.
 * @return            - rw_status_t
 */
rw_status_t rwcal_get_role_list(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    rwpb_gi_Rwcal_VimResources **roles);

/*
 * Add a new host
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param host        - host info
 * @param host_id     - on success, contains a NULL-terminated string
 *                      containing the new host_id
 *
 * @return            - rw_status_t
 */
rw_status_t rwcal_add_host(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    rwpb_gi_Rwcal_HostInfoItem *host,
    char **host_id);

/*
 * Remove a new host
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param host_id     - the id of the host to remove
 *
 * @return            - rw_status_t
 */
rw_status_t rwcal_remove_host(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char *host_id);

/*
 * Get a specific host
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param host_id     - the id of the host to return
 * @param host        - the requested host info
 *
 * @return            - rw_status_t
 */
rw_status_t rwcal_get_host(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char *host_id,
    rwpb_gi_Rwcal_HostInfoItem **host);

/*
 * Get a list of hosts
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param hosts       - on success, contains a NULL-terminated list of hosts.
 *
 * @return            - rw_status_t
 */
rw_status_t rwcal_get_host_list(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    rwpb_gi_Rwcal_VimResources **hosts);

/*
 * Create a new port
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param port        - port info
 * @param port_id     - on success, contains a NULL-terminated string
 *                      containing the new port id
 *
 * @return            - rw_status_t
 */
rw_status_t rwcal_create_port(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    rwpb_gi_Rwcal_PortInfoItem *port,
    char **port_id);

/*
 * Delete a port
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param port_id     - the id of the port to remove
 *
 * @return            - rw_status_t
 */
rw_status_t rwcal_delete_port(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char *port_id);

/*
 * Get a specific port
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param port_id     - the id of the port to return
 * @param port        - the requested port info
 *
 * @return            - rw_status_t
 */
rw_status_t rwcal_get_port(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char *port_id,
    rwpb_gi_Rwcal_PortInfoItem **port);

/*
 * Get a list of ports
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param ports       - on success, contains a NULL-terminated list of ports.
 *
 * @return            - rw_status_t
 */
rw_status_t rwcal_get_port_list(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    rwpb_gi_Rwcal_VimResources **ports);

/*
 * Create a new network
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param network     - network info
 * @param network_id  - on success, contains a NULL-terminated string
 *                      containing the new network id
 *
 * @return            - rw_status_t
 */
rw_status_t rwcal_create_network(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    rwpb_gi_Rwcal_NetworkInfoItem *network,
    char **network_id);

/*
 * Delete a network
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param network_id  - the id of the network to remove
 *
 * @return            - rw_status_t
 */
rw_status_t rwcal_delete_network(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char *network_id);

/*
 * Get a specific network
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param network_id  - the id of the network to return
 * @param network     - the requested network info
 *
 * @return            - rw_status_t
 */
rw_status_t rwcal_get_network(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    const char *network_id,
    rwpb_gi_Rwcal_NetworkInfoItem **network);

/*
 * Get a the management network
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param network     - the management network info
 *
 * @return            - rw_status_t
 */
rw_status_t rwcal_get_management_network(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    rwpb_gi_Rwcal_NetworkInfoItem **network);

/*
 * Get a list of networks
 *
 * @param rwcal       - module handle.
 * @param account     - cloud account information.
 * @param networks    - on success, contains a NULL-terminated list of networks.
 *
 * @return            - rw_status_t
 */
rw_status_t rwcal_get_network_list(
    rwcal_module_ptr_t rwcal,
    rwpb_gi_Rwcal_CloudAccount *account,
    rwpb_gi_Rwcal_VimResources **networks);

/*
 * Get a RwLog Context so that log messages can go to rwlog
 *
 * @param rwcal       - module handle.
 *
 * @return            - rwlog_ctx_t
 */
rwlog_ctx_t *rwcal_get_rwlog_ctx(rwcal_module_ptr_t rwcal);


/*
 * Get different elements from the userdata
 *
 * @param users       - userdata as returned in zk callback functions
 * @param idx         - index to the data to be picked up
 * @return            - pointer to first userdata pointer or NULL
 */
void *rwcal_get_userdata_idx(void *userdata, int idx);

/*
 * Get kazoo client state. this is pending upgrade to later kazoo
 * version as client_state may not be stored at kazoo client otherwise
 *
 * @param rwcal - module handle.
 * @return      - client state 
 */
rwcal_kazoo_client_state_t
rwcal_rwzk_client_state(rwcal_module_ptr_t rwcal);

__END_DECLS

#endif


