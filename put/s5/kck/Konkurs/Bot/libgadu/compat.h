/* coding: UTF-8 */
/* $Id: compat.h 6003 2007-07-26 16:00:19Z ono $ */

/*
 *  (C) Copyright 2001-2002 Wojtek Kaniewski <wojtekka@irc.pl>
 *                          Robert J. Wo�ny <speedy@ziew.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License Version
 *  2.1 as published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307,
 *  USA.
 */

/**
 * \file compat.h
 *
 * \brief Makra zapewniaj�ce kompatybilno�� API na r�nych systemach
 */

#ifndef __COMPAT_H
#define __COMPAT_H

#ifdef sun
#  define INADDR_NONE   ((in_addr_t) 0xffffffff)
#endif

#endif
