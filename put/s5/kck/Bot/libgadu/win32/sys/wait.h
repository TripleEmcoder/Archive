/*
 * <sys/wait.h>
 *
 * funkcje wait() i waitpid() zwracaj± -1. tyle wystarczy, ¿eby skompilowaæ
 * obs³ugê synchronicznych po³±czeñ.
 *
 * $Id: wait.h 2874 2006-05-16 21:38:00Z ghazan $
 */

#ifndef COMPAT_SYS_WAIT_H
#define COMPAT_SYS_WAIT_H

#define WHOHANG 0

static int wait(int *x)
{
	return -1;
};

static int waitpid(int x, int *y, int z)
{
	return -1;
}

#endif /* COMPAT_SYS_WAIT_H */
