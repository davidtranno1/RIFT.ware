/* gstreamer-pbutils-1.0.vapi generated by vapigen, do not modify. */

[CCode (cprefix = "Gst", gir_namespace = "GstPbutils", gir_version = "1.0", lower_case_cprefix = "gst_")]
namespace Gst {
	namespace PbUtils {
		namespace Codec {
			namespace AAC {
				[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_aac_caps_set_level_and_profile")]
				public static bool caps_set_level_and_profile (Gst.Caps caps, uint8 audio_config, uint len);
				[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_aac_get_index_from_sample_rate")]
				public static int get_index_from_sample_rate (uint rate);
				[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_aac_get_level")]
				public static unowned string get_level (uint8 audio_config, uint len);
				[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_aac_get_profile")]
				public static unowned string get_profile (uint8 audio_config, uint len);
				[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_aac_get_sample_rate_from_index")]
				public static uint get_sample_rate_from_index (uint sr_idx);
			}
			namespace H264 {
				[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_h264_caps_set_level_and_profile")]
				public static bool caps_set_level_and_profile (Gst.Caps caps, uint8 sps, uint len);
				[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_h264_get_level")]
				public static unowned string get_level (uint8 sps, uint len);
				[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_h264_get_level_idc")]
				public static uint8 get_level_idc (string level);
				[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_h264_get_profile")]
				public static unowned string get_profile (uint8 sps, uint len);
			}
			namespace MPEG4Video {
				[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_mpeg4video_caps_set_level_and_profile")]
				public static bool caps_set_level_and_profile (Gst.Caps caps, uint8 vis_obj_seq, uint len);
				[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_mpeg4video_get_level")]
				public static unowned string get_level (uint8 vis_obj_seq, uint len);
				[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_mpeg4video_get_profile")]
				public static unowned string get_profile (uint8 vis_obj_seq, uint len);
			}
		}
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GstDiscoverer", lower_case_cprefix = "gst_discoverer_", type_id = "gst_discoverer_get_type ()")]
		[GIR (name = "Discoverer")]
		public class Discoverer : GLib.Object {
			[CCode (has_construct_function = false)]
			public Discoverer (Gst.ClockTime timeout) throws GLib.Error;
			public Gst.PbUtils.DiscovererInfo discover_uri (string uri) throws GLib.Error;
			public bool discover_uri_async (string uri);
			public void start ();
			public void stop ();
			[NoAccessorMethod]
			public uint64 timeout { get; set construct; }
			public virtual signal void discovered (Gst.PbUtils.DiscovererInfo info, GLib.Error err);
			public virtual signal void finished ();
			public virtual signal void source_setup (Gst.Element source);
			public virtual signal void starting ();
		}
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GstDiscovererAudioInfo", lower_case_cprefix = "gst_discoverer_audio_info_", type_id = "gst_discoverer_audio_info_get_type ()")]
		[GIR (name = "DiscovererAudioInfo")]
		public class DiscovererAudioInfo : Gst.PbUtils.DiscovererStreamInfo {
			[CCode (has_construct_function = false)]
			protected DiscovererAudioInfo ();
			public uint get_bitrate ();
			public uint get_channels ();
			public uint get_depth ();
			public unowned string get_language ();
			public uint get_max_bitrate ();
			public uint get_sample_rate ();
		}
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GstDiscovererContainerInfo", lower_case_cprefix = "gst_discoverer_container_info_", type_id = "gst_discoverer_container_info_get_type ()")]
		[GIR (name = "DiscovererContainerInfo")]
		public class DiscovererContainerInfo : Gst.PbUtils.DiscovererStreamInfo {
			[CCode (has_construct_function = false)]
			protected DiscovererContainerInfo ();
			public GLib.List<Gst.PbUtils.DiscovererStreamInfo> get_streams ();
		}
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GstDiscovererInfo", lower_case_cprefix = "gst_discoverer_info_", type_id = "gst_discoverer_info_get_type ()")]
		[GIR (name = "DiscovererInfo")]
		public class DiscovererInfo : GLib.Object {
			[CCode (has_construct_function = false)]
			protected DiscovererInfo ();
			public Gst.PbUtils.DiscovererInfo copy ();
			public GLib.List<Gst.PbUtils.DiscovererStreamInfo> get_audio_streams ();
			public GLib.List<Gst.PbUtils.DiscovererStreamInfo> get_container_streams ();
			public Gst.ClockTime get_duration ();
			[Deprecated]
			public unowned Gst.Structure get_misc ();
			[CCode (array_length = false, array_null_terminated = true)]
			public string[] get_missing_elements_installer_details ();
			public Gst.PbUtils.DiscovererResult get_result ();
			public bool get_seekable ();
			public Gst.PbUtils.DiscovererStreamInfo get_stream_info ();
			public GLib.List<Gst.PbUtils.DiscovererStreamInfo> get_stream_list ();
			public GLib.List<Gst.PbUtils.DiscovererStreamInfo> get_streams (GLib.Type streamtype);
			public GLib.List<Gst.PbUtils.DiscovererStreamInfo> get_subtitle_streams ();
			public unowned Gst.TagList get_tags ();
			public unowned Gst.Toc get_toc ();
			public unowned string get_uri ();
			public GLib.List<Gst.PbUtils.DiscovererStreamInfo> get_video_streams ();
		}
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GstDiscovererStreamInfo", lower_case_cprefix = "gst_discoverer_stream_info_", type_id = "gst_discoverer_stream_info_get_type ()")]
		[GIR (name = "DiscovererStreamInfo")]
		public class DiscovererStreamInfo : GLib.Object {
			[CCode (has_construct_function = false)]
			protected DiscovererStreamInfo ();
			public Gst.Caps get_caps ();
			[Deprecated]
			public unowned Gst.Structure get_misc ();
			public Gst.PbUtils.DiscovererStreamInfo get_next ();
			public Gst.PbUtils.DiscovererStreamInfo get_previous ();
			public unowned string get_stream_id ();
			public unowned string get_stream_type_nick ();
			public unowned Gst.TagList get_tags ();
			public unowned Gst.Toc get_toc ();
			public static void list_free (GLib.List<Gst.PbUtils.DiscovererStreamInfo> infos);
		}
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GstDiscovererSubtitleInfo", lower_case_cprefix = "gst_discoverer_subtitle_info_", type_id = "gst_discoverer_subtitle_info_get_type ()")]
		[GIR (name = "DiscovererSubtitleInfo")]
		public class DiscovererSubtitleInfo : Gst.PbUtils.DiscovererStreamInfo {
			[CCode (has_construct_function = false)]
			protected DiscovererSubtitleInfo ();
			public unowned string get_language ();
		}
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GstDiscovererVideoInfo", lower_case_cprefix = "gst_discoverer_video_info_", type_id = "gst_discoverer_video_info_get_type ()")]
		[GIR (name = "DiscovererVideoInfo")]
		public class DiscovererVideoInfo : Gst.PbUtils.DiscovererStreamInfo {
			[CCode (has_construct_function = false)]
			protected DiscovererVideoInfo ();
			public uint get_bitrate ();
			public uint get_depth ();
			public uint get_framerate_denom ();
			public uint get_framerate_num ();
			public uint get_height ();
			public uint get_max_bitrate ();
			public uint get_par_denom ();
			public uint get_par_num ();
			public uint get_width ();
			public bool is_image ();
			public bool is_interlaced ();
		}
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GstEncodingAudioProfile", lower_case_cprefix = "gst_encoding_audio_profile_", type_id = "gst_encoding_audio_profile_get_type ()")]
		[GIR (name = "EncodingAudioProfile")]
		public class EncodingAudioProfile : Gst.PbUtils.EncodingProfile {
			[CCode (has_construct_function = false)]
			public EncodingAudioProfile (Gst.Caps format, string? preset, Gst.Caps? restriction, uint presence);
		}
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GstEncodingContainerProfile", lower_case_cprefix = "gst_encoding_container_profile_", type_id = "gst_encoding_container_profile_get_type ()")]
		[GIR (name = "EncodingContainerProfile")]
		public class EncodingContainerProfile : Gst.PbUtils.EncodingProfile {
			[CCode (has_construct_function = false)]
			public EncodingContainerProfile (string? name, string? description, Gst.Caps format, string? preset);
			public bool add_profile (owned Gst.PbUtils.EncodingProfile profile);
			public bool contains_profile (Gst.PbUtils.EncodingProfile profile);
			public unowned GLib.List<Gst.PbUtils.EncodingProfile> get_profiles ();
		}
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GstEncodingProfile", lower_case_cprefix = "gst_encoding_profile_", type_id = "gst_encoding_profile_get_type ()")]
		[GIR (name = "EncodingProfile")]
		public class EncodingProfile : GLib.Object {
			[CCode (has_construct_function = false)]
			protected EncodingProfile ();
			public static Gst.PbUtils.EncodingProfile find (string targetname, string profilename, string? category);
			public static Gst.PbUtils.EncodingProfile from_discoverer (Gst.PbUtils.DiscovererInfo info);
			public unowned string get_description ();
			public unowned string get_file_extension ();
			public Gst.Caps get_format ();
			public Gst.Caps get_input_caps ();
			public unowned string get_name ();
			public uint get_presence ();
			public unowned string get_preset ();
			public unowned string get_preset_name ();
			public Gst.Caps get_restriction ();
			public unowned string get_type_nick ();
			public bool is_equal (Gst.PbUtils.EncodingProfile b);
			public void set_description (string description);
			public void set_format (Gst.Caps format);
			public void set_name (string name);
			public void set_presence (uint presence);
			public void set_preset (string preset);
			public void set_preset_name (string preset_name);
			public void set_restriction (owned Gst.Caps restriction);
			[NoAccessorMethod]
			public Gst.Caps restriction_caps { owned get; set; }
		}
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GstEncodingTarget", lower_case_cprefix = "gst_encoding_target_", type_id = "gst_encoding_target_get_type ()")]
		[GIR (name = "EncodingTarget")]
		public class EncodingTarget : GLib.Object {
			[CCode (has_construct_function = false)]
			public EncodingTarget (string name, string category, string description, GLib.List<Gst.PbUtils.EncodingProfile> profiles);
			public bool add_profile (owned Gst.PbUtils.EncodingProfile profile);
			public unowned string get_category ();
			public unowned string get_description ();
			public unowned string get_name ();
			public Gst.PbUtils.EncodingProfile get_profile (string name);
			public unowned GLib.List<Gst.PbUtils.EncodingProfile> get_profiles ();
			public static Gst.PbUtils.EncodingTarget load (string name, string? category) throws GLib.Error;
			public static Gst.PbUtils.EncodingTarget load_from_file (string filepath) throws GLib.Error;
			public bool save () throws GLib.Error;
			public bool save_to_file (string filepath) throws GLib.Error;
		}
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GstEncodingVideoProfile", lower_case_cprefix = "gst_encoding_video_profile_", type_id = "gst_encoding_video_profile_get_type ()")]
		[GIR (name = "EncodingVideoProfile")]
		public class EncodingVideoProfile : Gst.PbUtils.EncodingProfile {
			[CCode (has_construct_function = false)]
			public EncodingVideoProfile (Gst.Caps format, string? preset, Gst.Caps? restriction, uint presence);
			public uint get_pass ();
			public bool get_variableframerate ();
			public void set_pass (uint pass);
			public void set_variableframerate (bool variableframerate);
		}
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GstInstallPluginsContext", copy_function = "g_boxed_copy", free_function = "g_boxed_free", lower_case_cprefix = "gst_install_plugins_context_", type_id = "gst_install_plugins_context_get_type ()")]
		[Compact]
		[GIR (name = "InstallPluginsContext")]
		public class InstallPluginsContext {
			[CCode (has_construct_function = false)]
			public InstallPluginsContext ();
			public void free ();
			public void set_xid (uint xid);
		}
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GstDiscovererResult", cprefix = "GST_DISCOVERER_", type_id = "gst_discoverer_result_get_type ()")]
		[GIR (name = "DiscovererResult")]
		public enum DiscovererResult {
			OK,
			URI_INVALID,
			ERROR,
			TIMEOUT,
			BUSY,
			MISSING_PLUGINS
		}
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GstInstallPluginsReturn", cprefix = "GST_INSTALL_PLUGINS_", type_id = "gst_install_plugins_return_get_type ()")]
		[GIR (name = "InstallPluginsReturn")]
		public enum InstallPluginsReturn {
			SUCCESS,
			NOT_FOUND,
			ERROR,
			PARTIAL_SUCCESS,
			USER_ABORT,
			CRASHED,
			INVALID,
			STARTED_OK,
			INTERNAL_FAILURE,
			HELPER_MISSING,
			INSTALL_IN_PROGRESS
		}
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GstInstallPluginsResultFunc", instance_pos = 1.9)]
		public delegate void InstallPluginsResultFunc (Gst.PbUtils.InstallPluginsReturn result);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GST_ENCODING_CATEGORY_CAPTURE")]
		public const string ENCODING_CATEGORY_CAPTURE;
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GST_ENCODING_CATEGORY_DEVICE")]
		public const string ENCODING_CATEGORY_DEVICE;
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GST_ENCODING_CATEGORY_ONLINE_SERVICE")]
		public const string ENCODING_CATEGORY_ONLINE_SERVICE;
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GST_ENCODING_CATEGORY_STORAGE_EDITING")]
		public const string ENCODING_CATEGORY_STORAGE_EDITING;
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GST_PLUGINS_BASE_VERSION_MAJOR")]
		public const int PLUGINS_BASE_VERSION_MAJOR;
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GST_PLUGINS_BASE_VERSION_MICRO")]
		public const int PLUGINS_BASE_VERSION_MICRO;
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GST_PLUGINS_BASE_VERSION_MINOR")]
		public const int PLUGINS_BASE_VERSION_MINOR;
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "GST_PLUGINS_BASE_VERSION_NANO")]
		public const int PLUGINS_BASE_VERSION_NANO;
		[CCode (cheader_filename = "gst/pbutils/pbutils.h")]
		public static bool add_codec_description_to_tag_list (Gst.TagList taglist, string? codec_tag, Gst.Caps caps);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_h265_caps_set_level_tier_and_profile")]
		public static bool codec_utils_h265_caps_set_level_tier_and_profile (Gst.Caps caps, uint8 profile_tier_level, uint len);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_h265_get_level")]
		public static unowned string codec_utils_h265_get_level (uint8 profile_tier_level, uint len);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_h265_get_level_idc")]
		public static uint8 codec_utils_h265_get_level_idc (string level);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_h265_get_profile")]
		public static unowned string codec_utils_h265_get_profile (uint8 profile_tier_level, uint len);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_codec_utils_h265_get_tier")]
		public static unowned string codec_utils_h265_get_tier (uint8 profile_tier_level, uint len);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_encoding_list_all_targets")]
		public static GLib.List<Gst.PbUtils.EncodingTarget> encoding_list_all_targets (string? categoryname);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_encoding_list_available_categories")]
		public static GLib.List<string> encoding_list_available_categories ();
		[CCode (cheader_filename = "gst/pbutils/pbutils.h")]
		public static string get_codec_description (Gst.Caps caps);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h")]
		public static string get_decoder_description (Gst.Caps caps);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h")]
		public static string get_element_description (string factory_name);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h")]
		public static string get_encoder_description (Gst.Caps caps);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h")]
		public static string get_sink_description (string protocol);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h")]
		public static string get_source_description (string protocol);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h")]
		public static void init ();
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_install_plugins_async")]
		public static Gst.PbUtils.InstallPluginsReturn install_plugins_async ([CCode (array_length = false, array_null_terminated = true)] string[] details, Gst.PbUtils.InstallPluginsContext? ctx, [CCode (scope = "async")] owned Gst.PbUtils.InstallPluginsResultFunc func);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_install_plugins_installation_in_progress")]
		public static bool install_plugins_installation_in_progress ();
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_install_plugins_return_get_name")]
		public static unowned string install_plugins_return_get_name (Gst.PbUtils.InstallPluginsReturn ret);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_install_plugins_supported")]
		public static bool install_plugins_supported ();
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_install_plugins_sync")]
		public static Gst.PbUtils.InstallPluginsReturn install_plugins_sync ([CCode (array_length = false, array_null_terminated = true)] string[] details, Gst.PbUtils.InstallPluginsContext? ctx);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_is_missing_plugin_message")]
		public static bool is_missing_plugin_message (Gst.Message msg);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_missing_decoder_installer_detail_new")]
		public static string missing_decoder_installer_detail_new (Gst.Caps decode_caps);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_missing_decoder_message_new")]
		public static Gst.Message missing_decoder_message_new (Gst.Element element, Gst.Caps decode_caps);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_missing_element_installer_detail_new")]
		public static string missing_element_installer_detail_new (string factory_name);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_missing_element_message_new")]
		public static Gst.Message missing_element_message_new (Gst.Element element, string factory_name);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_missing_encoder_installer_detail_new")]
		public static string missing_encoder_installer_detail_new (Gst.Caps encode_caps);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_missing_encoder_message_new")]
		public static Gst.Message missing_encoder_message_new (Gst.Element element, Gst.Caps encode_caps);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_missing_plugin_message_get_description")]
		public static string missing_plugin_message_get_description (Gst.Message msg);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_missing_plugin_message_get_installer_detail")]
		public static string missing_plugin_message_get_installer_detail (Gst.Message msg);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_missing_uri_sink_installer_detail_new")]
		public static string missing_uri_sink_installer_detail_new (string protocol);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_missing_uri_sink_message_new")]
		public static Gst.Message missing_uri_sink_message_new (Gst.Element element, string protocol);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_missing_uri_source_installer_detail_new")]
		public static string missing_uri_source_installer_detail_new (string protocol);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_missing_uri_source_message_new")]
		public static Gst.Message missing_uri_source_message_new (Gst.Element element, string protocol);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_plugins_base_version")]
		public static void plugins_base_version (out uint major, out uint minor, out uint micro, out uint nano);
		[CCode (cheader_filename = "gst/pbutils/pbutils.h", cname = "gst_plugins_base_version_string")]
		public static string plugins_base_version_string ();
	}
}
