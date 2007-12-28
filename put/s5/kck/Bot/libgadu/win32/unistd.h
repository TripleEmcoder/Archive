/* 
 * <unistd.h>
 *
 * na win32 widocznie nie ma strncasecmp().
 *
 * $Id: unistd.h 2874 2006-05-16 21:38:00Z ghazan $
 */

#ifndef COMPAT_UNISTD_H
#define COMPAT_UNISTD_H

#define strncasecmp strnicmp

#endif /* COMPAT_UNISTD_H */
