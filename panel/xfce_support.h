/*  xfce_support.h
 *  
 *  Copyright (C) 2002 Jasper Huijsmans (huysmans@users.sourceforge.net)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#ifndef __XFCE_SUPPORT_H__
#define __XFCE_SUPPORT_H__

/* files and directories */
char *get_save_dir(void);
char *get_save_file(const char *name);
char **get_read_dirs(void);
char *get_read_file(const char *name);
char **get_plugin_dirs(void);
char **get_theme_dirs(void);
void write_backup_file(const char *path);

/* tooltips */
void add_tooltip(GtkWidget * widget, char *tip);

/* button with text and stock icon */
GtkWidget *mixed_button_new(const char *stock, const char *message);

/* x atoms and properties */
void set_window_type_dock(GtkWidget *win, gboolean set);
void set_window_layer(GtkWidget *win, int layer);
gboolean check_net_wm_support(void);
void set_window_skip(GtkWidget *win);

/* dnd */
void dnd_set_drag_dest(GtkWidget * widget);

typedef void (*DropCallback) (GtkWidget * widget, GList * drop_data,
                              gpointer data);

#define DROP_CALLBACK(f) (DropCallback)f

void dnd_set_callback(GtkWidget * widget, DropCallback function, gpointer data);

void gnome_uri_list_free_strings(GList * list);
GList *gnome_uri_list_extract_uris(const gchar * uri_list);
GList *gnome_uri_list_extract_filenames(const gchar * uri_list);

/* dialogs */
gboolean confirm(const char *text, const char *stock, const char *action);
void report_error(const char *text);
void show_info(const char *text);

/* file open dialog */
char *select_file_name(const char *title, const char *path, GtkWidget * parent);
char *select_file_with_preview(const char *title, const char *path, GtkWidget * parent);

/* executing programs */
void exec_cmd(const char *cmd, gboolean in_terminal);
void exec_cmd_silent(const char *cmd, gboolean in_terminal);

#endif /* __XFCE_SUPPORT_H__ */
