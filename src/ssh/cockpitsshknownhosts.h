/*
 * This file is part of Cockpit.
 *
 * Copyright (C) 2018 Red Hat, Inc.
 *
 * Cockpit is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * Cockpit is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Cockpit; If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __COCKPIT_SSH_KNOWNHOSTS_H__
#define __COCKPIT_SSH_KNOWNHOSTS_H__

#include <gio/gio.h>

#include <libssh/libssh.h>

G_BEGIN_DECLS

#define SSH_KNOWN_HOSTS_OK TRUE

void            shim_set_knownhosts_file                   (const gchar *file);

gboolean        ssh_session_has_known_hosts_entry          (ssh_session session);

int             ssh_session_export_known_hosts_entry       (ssh_session session,
                                                            char **pentry_string);

gboolean        cockpit_is_host_known                      (const gchar *known_hosts_file,
                                                            const gchar *host,
                                                            guint port);


G_END_DECLS

#endif