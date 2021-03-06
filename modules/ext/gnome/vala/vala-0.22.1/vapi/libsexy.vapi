/* libsexy.vapi generated by vapigen, do not modify. */

namespace Sexy {
	[CCode (cheader_filename = "libsexy/sexy.h")]
	public class IconEntry : Gtk.Entry, Atk.Implementor, Gtk.Buildable, Gtk.Editable, Gtk.CellEditable {
		[CCode (has_construct_function = false, type = "GtkWidget*")]
		public IconEntry ();
		public void add_clear_button ();
		public unowned Gtk.Image get_icon (Sexy.IconEntryPosition position);
		public bool get_icon_highlight (Sexy.IconEntryPosition position);
		public void set_icon (Sexy.IconEntryPosition position, Gtk.Image? icon);
		public void set_icon_highlight (Sexy.IconEntryPosition position, bool highlight);
		public virtual signal void icon_pressed (int icon_pos, int button);
		public virtual signal void icon_released (int icon_pos, int button);
	}
	[CCode (cheader_filename = "libsexy/sexy.h")]
	public class SpellEntry : Gtk.Entry, Atk.Implementor, Gtk.Buildable, Gtk.Editable, Gtk.CellEditable {
		[CCode (has_construct_function = false, type = "GtkWidget*")]
		public SpellEntry ();
		public void activate_default_languages ();
		public bool activate_language (string lang) throws GLib.Error;
		public void deactivate_language (string lang);
		public unowned GLib.SList get_active_languages ();
		public unowned string get_language_name (string lang);
		public unowned GLib.SList get_languages ();
		public bool is_checked ();
		public bool language_is_active (string lang);
		public bool set_active_languages (GLib.SList langs) throws GLib.Error;
		public void set_checked (bool checked);
		public virtual signal bool word_check (string word);
	}
	[CCode (cheader_filename = "libsexy/sexy.h")]
	public class Tooltip : Gtk.Window, Atk.Implementor, Gtk.Buildable {
		[CCode (has_construct_function = false, type = "GtkWidget*")]
		public Tooltip ();
		public void position_to_rect (Gdk.Rectangle rect, Gdk.Screen screen);
		public void position_to_widget (Gtk.Widget widget);
		[CCode (has_construct_function = false, type = "GtkWidget*")]
		public Tooltip.with_label (string text);
	}
	[CCode (cheader_filename = "libsexy/sexy.h")]
	public class TreeView : Gtk.TreeView, Atk.Implementor, Gtk.Buildable {
		[CCode (has_construct_function = false, type = "GtkWidget*")]
		public TreeView ();
		public void set_tooltip_label_column (uint column);
		public virtual signal unowned Gtk.Widget get_tooltip (Gtk.TreePath path, Gtk.TreeViewColumn column);
	}
	[CCode (cheader_filename = "libsexy/sexy.h")]
	public class UrlLabel : Gtk.Label, Atk.Implementor, Gtk.Buildable {
		[CCode (has_construct_function = false, type = "GtkWidget*")]
		public UrlLabel ();
		public void set_markup (string markup);
		public virtual signal void url_activated (string url);
	}
	[CCode (cheader_filename = "libsexy/sexy.h", cprefix = "SEXY_ICON_ENTRY_")]
	public enum IconEntryPosition {
		PRIMARY,
		SECONDARY
	}
	[CCode (cheader_filename = "libsexy/sexy.h", cprefix = "SEXY_SPELL_ERROR_")]
	public enum SpellError {
		BACKEND
	}
	[CCode (cheader_filename = "libsexy/sexy.h")]
	public static GLib.Quark spell_error_quark ();
}
