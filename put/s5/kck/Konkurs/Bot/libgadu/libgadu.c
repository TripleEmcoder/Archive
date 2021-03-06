/* coding: UTF-8 */
/* $Id: libgadu.c 6003 2007-07-26 16:00:19Z ono $ */

/*
 *  (C) Copyright 2001-2006 Wojtek Kaniewski <wojtekka@irc.pl>
 *                          Robert J. Woźny <speedy@ziew.org>
 *                          Arkadiusz Miśkiewicz <arekm@pld-linux.org>
 *                          Tomasz Chiliński <chilek@chilan.com>
 *                          Adam Wysocki <gophi@ekg.chmurka.net>
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
 * \file libgadu.c
 *
 * \brief Główny moduł biblioteki
 */

#include "libgadu-config.h"

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#ifdef sun
#  include <sys/filio.h>
#endif

#include <errno.h>
#include <netdb.h>
#ifdef GG_CONFIG_HAVE_PTHREAD
#  include <pthread.h>
#endif
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#if !defined(GG_CONFIG_MIRANDA) && defined(GG_CONFIG_HAVE_OPENSSL)
#  include <openssl/err.h>
#  include <openssl/rand.h>
#endif
#ifdef GG_CONFIG_MIRANDA
#  include <time.h>
#endif

#include "compat.h"
#include "libgadu.h"

/**
 * Poziom rejestracji informacji odpluskwiających. Zmienna jest maską bitową
 * składającą się ze stałych \c GG_DEBUG_...
 *
 * \ingroup debug
 */
int gg_debug_level = 0;

/**
 * Funkcja, do której są przekazywane informacje odpluskwiające. Jeśli zarówno
 * ten \c gg_debug_handler, jak i \c gg_debug_handler_session, są równe
 * \c NULL, informacje są wysyłane do standardowego wyjścia błędu.
 *
 * \param level Poziom rejestracji
 * \param format Format wiadomości (zgodny z \c printf)
 * \param ap Lista argumentów (zgodna z \c printf)
 *
 * \note Funkcja jest przesłaniana przez \c gg_debug_handler_session.
 *
 * \ingroup debug
 */
void (*gg_debug_handler)(int level, const char *format, va_list ap) = NULL;

/**
 * Funkcja, do której są przekazywane informacje odpluskwiające. Jeśli zarówno
 * ten \c gg_debug_handler, jak i \c gg_debug_handler_session, są równe
 * \c NULL, informacje są wysyłane do standardowego wyjścia błędu.
 *
 * \param sess Sesja której dotyczy informacja lub \c NULL
 * \param level Poziom rejestracji
 * \param format Format wiadomości (zgodny z \c printf)
 * \param ap Lista argumentów (zgodna z \c printf)
 *
 * \note Funkcja przesłania przez \c gg_debug_handler_session.
 *
 * \ingroup debug
 */
void (*gg_debug_handler_session)(struct gg_session *sess, int level, const char *format, va_list ap) = NULL;

/**
 * Port gniazda nasłuchującego dla połączeń bezpośrednich.
 * 
 * \ingroup ip
 */
int gg_dcc_port = 0;

/**
 * Adres IP gniazda nasłuchującego dla połączeń bezpośrednich.
 *
 * \ingroup ip
 */
unsigned long gg_dcc_ip = 0;

/**
 * Adres lokalnego interfejsu IP, z którego wywoływane są wszystkie połączenia.
 *
 * \ingroup ip
 */
unsigned long gg_local_ip = 0;

/**
 * Flaga włączenia połączeń przez serwer pośredniczący.
 *
 * \bug Serwer pośredniczący jest wykorzystywany tylko dla połączeń z serwerem
 * Gadu-Gadu i usług HTTP, nie dla połączeń bezpośrednich.
 *
 * \bug Ustawienia serwera pośredniczącego są globalne dla wszystkich połączeń.
 *
 * \ingroup proxy
 */
int gg_proxy_enabled = 0;

/**
 * Adres serwera pośredniczącego.
 *
 * \ingroup proxy
 */
char *gg_proxy_host = NULL;

/**
 * Port serwera pośredniczącego.
 *
 * \ingroup proxy
 */
int gg_proxy_port = 0;

/**
 * Flaga używania serwera pośredniczącego jedynie dla usług HTTP.
 *
 * \ingroup proxy
 */
int gg_proxy_http_only = 0;

/**
 * Nazwa użytkownika do autoryzacji serwera pośredniczącego.
 *
 * \ingroup proxy
 */
char *gg_proxy_username = NULL;

/**
 * Hasło użytkownika do autoryzacji serwera pośredniczącego.
 *
 * \ingroup proxy
 */
char *gg_proxy_password = NULL;

#ifdef GG_CONFIG_MIRANDA
int gg_failno = 0;
#endif

#ifndef DOXYGEN

#ifndef lint
static char rcsid[]
#ifdef __GNUC__
__attribute__ ((unused))
#endif
= "$Id: libgadu.c 6003 2007-07-26 16:00:19Z ono $";
#endif

#endif /* DOXYGEN */

/**
 * Zwraca wersję biblioteki.
 *
 * \return Wskaźnik na statyczny bufor z wersją biblioteki.
 *
 * \ingroup version
 */
const char *gg_libgadu_version()
{
	return GG_LIBGADU_VERSION;
}

/**
 * Zamienia kolejność bajtów w 32-bitowym słowie.
 *
 * Ze względu na little-endianowość protokołu Gadu-Gadu, na maszynach
 * big-endianowych odwraca kolejność bajtów w słowie.
 *
 * \param x Liczba do zamiany
 *
 * \return Liczba z odpowiednią kolejnością bajtów
 *
 * \ingroup helper
 */
uint32_t gg_fix32(uint32_t x)
{
#ifndef GG_CONFIG_BIGENDIAN
	return x;
#else
	return (uint32_t)
		(((x & (uint32_t) 0x000000ffU) << 24) |
		((x & (uint32_t) 0x0000ff00U) << 8) |
		((x & (uint32_t) 0x00ff0000U) >> 8) |
		((x & (uint32_t) 0xff000000U) >> 24));
#endif
}

/**
 * Zamienia kolejność bajtów w 16-bitowym słowie.
 *
 * Ze względu na little-endianowość protokołu Gadu-Gadu, na maszynach
 * big-endianowych zamienia kolejność bajtów w słowie.
 *
 * \param x Liczba do zamiany
 *
 * \return Liczba z odpowiednią kolejnością bajtów
 *
 * \ingroup helper
 */
uint16_t gg_fix16(uint16_t x)
{
#ifndef GG_CONFIG_BIGENDIAN
	return x;
#else
	return (uint16_t)
		(((x & (uint16_t) 0x00ffU) << 8) |
		((x & (uint16_t) 0xff00U) >> 8));
#endif
}

/**
 * \internal Liczy skrót z hasła i ziarna.
 *
 * \param password Hasło
 * \param seed Ziarno podane przez serwer
 *
 * \return Wartość skrótu
 */
unsigned int gg_login_hash(const unsigned char *password, unsigned int seed)
{
	unsigned int x, y, z;

	y = seed;

	for (x = 0; *password; password++) {
		x = (x & 0xffffff00) | *password;
		y ^= x;
		y += x;
		x <<= 8;
		y ^= x;
		x <<= 8;
		y -= x;
		x <<= 8;
		y ^= x;

		z = y & 0x1F;
		y = (y << z) | (y >> (32 - z));
	}

	return y;
}

/**
 * \internal Rozwiązuje nazwę serwera w osobnym procesie.
 *
 * Połączenia asynchroniczne nie mogą blokować procesu w trakcie rozwiązywania
 * nazwy serwera. W tym celu tworzony jest potok, nowy proces i dopiero w nim
 * przeprowadzane jest rozwiązywanie nazwy. Deskryptor strony do odczytu 
 * zapisuje się w strukturze sieci i czeka na dane w postaci struktury
 * \c in_addr. Jeśli nie znaleziono nazwy, zwracana jest \c INADDR_NONE.
 *
 * Podczas kompilacji mógł zostać wybrany alternatywny sposób rozwiązanywania
 * nazwy, za pomocą wątków. W takim wypadku będzie zdefiniowana dyrektywa
 * preprocesora \c GG_CONFIG_HAVE_PTHREAD.
 *
 * \param fd Wskaźnik na zmienną, gdzie zostanie umieszczony deskryptor
 *           potoku
 * \param pid Wskaźnik na zmienną, gdzie zostanie umieszczony identyfikator
 *            procesu potomnego
 * \param hostname Nazwa serwera do rozwiązania
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 */
int gg_resolve(int *fd, int *pid, const char *hostname)
{
	int pipes[2], res;
	struct in_addr a;
	int errno2;

	gg_debug(GG_DEBUG_FUNCTION, "** gg_resolve(%p, %p, \"%s\");\n", fd, pid, hostname);

	if (!fd || !pid) {
		errno = EFAULT;
		return -1;
	}

	if (pipe(pipes) == -1)
		return -1;

	if ((res = fork()) == -1) {
		errno2 = errno;
		close(pipes[0]);
		close(pipes[1]);
		errno = errno2;
		return -1;
	}

	if (!res) {
		close(pipes[0]);

		if ((a.s_addr = inet_addr(hostname)) == INADDR_NONE) {
			struct in_addr *hn;

			if (!(hn = gg_gethostbyname(hostname)))
				a.s_addr = INADDR_NONE;
			else {
				a.s_addr = hn->s_addr;
				free(hn);
			}
		}

		write(pipes[1], &a, sizeof(a));

		exit(0);
	}

	close(pipes[1]);

	*fd = pipes[0];
	*pid = res;

	return 0;
}

#ifdef GG_CONFIG_HAVE_PTHREAD

/**
 * \internal Struktura przekazywana do wątku rozwiązującego nazwę.
 */
struct gg_resolve_pthread_data {
	pthread_t thread;	/*< Identyfikator wątku */
	char *hostname;		/*< Nazwa serwera */
	int rfd;		/*< Deskryptor do odczytu */
	int wfd;		/*< Deskryptor do zapisu */
};

/**
 * \internal Usuwanie zasobów po rozwiązywaniu nazwy.
 *
 * Funkcja wywoływana po zakończeniu rozwiązanywania nazwy lub przy zwalnianiu
 * zasobów sesji podczas rozwiązywania nazwy.
 *
 * \param arg Wskaźnik na strukturę \c gg_resolve_pthread_data
 * \param kill Flaga zabicja wątku rozwiązującego i posprzątania zasobów
 */
void gg_resolve_pthread_cleanup(void *arg, int kill)
{
	struct gg_resolve_pthread_data *data = arg;

	if (kill) {
		pthread_cancel(data->thread);
		pthread_join(data->thread, NULL);
	}

	free(data->hostname);
	data->hostname = NULL;

	if (data->wfd != -1) {
		close(data->wfd);
		data->wfd = -1;
	}

	free(data);
}

/**
 * \internal Wątek rozwiązujący nazwę.
 *
 * \param arg Wskaźnik na strukturę \c gg_resolve_pthread_data
 */
static void *gg_resolve_pthread_thread(void *arg)
{
	struct gg_resolve_pthread_data *d = arg;
	struct in_addr a;

	pthread_detach(pthread_self());

	if ((a.s_addr = inet_addr(d->hostname)) == INADDR_NONE) {
		struct in_addr *hn;

		if (!(hn = gg_gethostbyname(d->hostname)))
			a.s_addr = INADDR_NONE;
		else {
			a.s_addr = hn->s_addr;
			free(hn);
		}
	}

	write(d->wfd, &a, sizeof(a));

	pthread_exit(NULL);

	return NULL;	/* żeby kompilator nie marudził */
}

/**
 * \internal Rozwiązuje nazwę serwera w osobnym wątku.
 *
 * Funkcja działa analogicznie do \c gg_resolve, z tą różnicą, że działa
 * na wątkach, nie procesach. Jest używana wyłącznie gdy podczas kompilacji
 * włączono odpowiednią opcję.
 *
 * \param fd Wskaźnik na zmienną, gdzie zostanie umieszczony deskryptor
 *           potoku
 * \param resolver Wskaźnik na zmienną, gdzie zostanie umieszczony wskaźnik
 *                 do prywatnych danych wątku rozwiązującego nazwę
 * \param hostname Nazwa serwera do rozwiązania
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 */
int gg_resolve_pthread(int *fd, void **resolver, const char *hostname)
{
	struct gg_resolve_pthread_data *data = NULL;
	int pipes[2], new_errno;

	gg_debug(GG_DEBUG_FUNCTION, "** gg_resolve_pthread(%p, %p, \"%s\");\n", fd, resolver, hostname);

	if (!resolver || !fd || !hostname) {
		gg_debug(GG_DEBUG_MISC, "// gg_resolve_pthread() invalid arguments\n");
		errno = EFAULT;
		return -1;
	}

	if (!(data = malloc(sizeof(struct gg_resolve_pthread_data)))) {
		gg_debug(GG_DEBUG_MISC, "// gg_resolve_pthread() out of memory for resolver data\n");
		return -1;
	}

	if (pipe(pipes) == -1) {
		gg_debug(GG_DEBUG_MISC, "// gg_resolve_pthread() unable to create pipes (errno=%d, %s)\n", errno, strerror(errno));
		free(data);
		return -1;
	}

	if (!(data->hostname = strdup(hostname))) {
		gg_debug(GG_DEBUG_MISC, "// gg_resolve_pthread() out of memory\n");
		new_errno = errno;
		goto cleanup;
	}

	data->rfd = pipes[0];
	data->wfd = pipes[1];

	if (pthread_create(&data->thread, NULL, gg_resolve_pthread_thread, data)) {
		gg_debug(GG_DEBUG_MISC, "// gg_resolve_phread() unable to create thread\n");
		new_errno = errno;
		goto cleanup;
	}

	gg_debug(GG_DEBUG_MISC, "// gg_resolve_pthread() %p\n", data);

	*resolver = data;

	*fd = pipes[0];

	return 0;

cleanup:
	if (data) {
		free(data->hostname);
		free(data);
	}

	close(pipes[0]);
	close(pipes[1]);

	errno = new_errno;

	return -1;
}

#endif

/**
 * \internal Odbiera od serwera dane binarne.
 *
 * Funkcja odbiera dane od serwera zajmując się TLS w razie konieczności.
 *
 * \param sess Struktura sesji
 * \param buf Bufor na danymi
 * \param length Długość bufora
 *
 * \return To samo co funkcja systemowa \c read
 */
int gg_read(struct gg_session *sess, char *buf, int length)
{
	int res;

#ifdef GG_CONFIG_HAVE_OPENSSL
	if (sess->ssl) {
		int err;

		res = SSL_read(sess->ssl, buf, length);

		if (res < 0) {
			err = SSL_get_error(sess->ssl, res);

			if (err == SSL_ERROR_WANT_READ)
				errno = EAGAIN;

			return -1;
		}
	} else
#endif
		res = read(sess->fd, buf, length);

	return res;
}

/**
 * \internal Wysyła do serwera dane binarne.
 *
 * Funkcja wysyła dane do serwera zajmując się TLS w razie konieczności.
 *
 * \param sess Struktura sesji
 * \param buf Bufor z danymi
 * \param length Długość bufora
 *
 * \return To samo co funkcja systemowa \c write
 */
int gg_write(struct gg_session *sess, const char *buf, int length)
{
	int res = 0;

#ifdef GG_CONFIG_HAVE_OPENSSL
	if (sess->ssl) {
		int err;

		res = SSL_write(sess->ssl, (void *)buf, length);

		if (res < 0) {
			err = SSL_get_error(sess->ssl, res);

			if (err == SSL_ERROR_WANT_WRITE)
				errno = EAGAIN;

			return -1;
		}
	} else
#endif
	{
		if (!sess->async) {
			int written = 0;

			while (written < length) {
				res = write(sess->fd, buf + written, length - written);

				if (res == -1) {
					if (errno != EINTR)
						break;

					continue;
				}

				written += res;
				res = written;
			}
		} else {
			if (!sess->send_buf)
				res = write(sess->fd, buf, length);
			else
				res = 0;

			if (res == -1) {
				if (errno != EAGAIN)
					return res;

				res = 0;
			}

			if (res < length) {
				char *tmp;

				if (!(tmp = realloc(sess->send_buf, sess->send_left + length - res))) {
					errno = ENOMEM;
					return -1;
				}

				sess->send_buf = tmp;

				memcpy(sess->send_buf + sess->send_left, buf, length - res);

				sess->send_left += length - res;

				return 0;
			}
		}
	}

	return res;
}

/**
 * \internal Odbiera pakiet od serwera.
 *
 * Funkcja odczytuje nagłówek pakietu, a następnie jego zawartość i zwraca
 * w zaalokowanym buforze.
 *
 * Przy połączeniach asynchronicznych, funkcja może nie być w stanie
 * skompletować całego pakietu -- w takim przypadku zwróci -1, a kodem błędu
 * będzie \c EAGAIN.
 *
 * \param sess Struktura sesji
 *
 * \return Wskaźnik do zaalokowanego bufora
 */
void *gg_recv_packet(struct gg_session *sess)
{
	struct gg_header h;
	char *buf = NULL;
	int ret = 0;
	unsigned int offset, size = 0;

	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_recv_packet(%p);\n", sess);

	if (!sess) {
		errno = EFAULT;
		return NULL;
	}

	if (sess->recv_left < 1) {
		if (sess->header_buf) {
			memcpy(&h, sess->header_buf, sess->header_done);
			gg_debug_session(sess, GG_DEBUG_MISC, "// gg_recv_packet() header recv: resuming last read (%d bytes left)\n", sizeof(h) - sess->header_done);
			free(sess->header_buf);
			sess->header_buf = NULL;
		} else
			sess->header_done = 0;

		while (sess->header_done < sizeof(h)) {
			ret = gg_read(sess, (char*) &h + sess->header_done, sizeof(h) - sess->header_done);

			gg_debug_session(sess, GG_DEBUG_MISC, "// gg_recv_packet() header recv(%d,%p,%d) = %d\n", sess->fd, &h + sess->header_done, sizeof(h) - sess->header_done, ret);

			if (!ret) {
				errno = ECONNRESET;
				gg_debug_session(sess, GG_DEBUG_MISC, "// gg_recv_packet() header recv() failed: connection broken\n");
				return NULL;
			}

			if (ret == -1) {
				if (errno == EINTR) {
					gg_debug_session(sess, GG_DEBUG_MISC, "// gg_recv_packet() header recv() interrupted system call, resuming\n");
					continue;
				}

				if (errno == EAGAIN) {
					gg_debug_session(sess, GG_DEBUG_MISC, "// gg_recv_packet() header recv() incomplete header received\n");

					if (!(sess->header_buf = malloc(sess->header_done))) {
						gg_debug_session(sess, GG_DEBUG_MISC, "// gg_recv_packet() header recv() not enough memory\n");
						return NULL;
					}

					memcpy(sess->header_buf, &h, sess->header_done);

					errno = EAGAIN;

					return NULL;
				}

				gg_debug_session(sess, GG_DEBUG_MISC, "// gg_recv_packet() header recv() failed: errno=%d, %s\n", errno, strerror(errno));

				return NULL;
			}

			sess->header_done += ret;

		}

		h.type = gg_fix32(h.type);
		h.length = gg_fix32(h.length);
	} else
		memcpy(&h, sess->recv_buf, sizeof(h));

	/* jakieś sensowne limity na rozmiar pakietu */
	if (h.length > 65535) {
		gg_debug_session(sess, GG_DEBUG_MISC, "// gg_recv_packet() invalid packet length (%d)\n", h.length);
		errno = ERANGE;
		return NULL;
	}

	if (sess->recv_left > 0) {
		gg_debug_session(sess, GG_DEBUG_MISC, "// gg_recv_packet() resuming last gg_recv_packet()\n");
		size = sess->recv_left;
		offset = sess->recv_done;
		buf = sess->recv_buf;
	} else {
		if (!(buf = malloc(sizeof(h) + h.length + 1))) {
			gg_debug_session(sess, GG_DEBUG_MISC, "// gg_recv_packet() not enough memory for packet data\n");
			return NULL;
		}

		memcpy(buf, &h, sizeof(h));

		offset = 0;
		size = h.length;
	}

	while (size > 0) {
		ret = gg_read(sess, buf + sizeof(h) + offset, size);
		gg_debug_session(sess, GG_DEBUG_MISC, "// gg_recv_packet() body recv(%d,%p,%d) = %d\n", sess->fd, buf + sizeof(h) + offset, size, ret);
		if (!ret) {
			gg_debug_session(sess, GG_DEBUG_MISC, "// gg_recv_packet() body recv() failed: connection broken\n");
			errno = ECONNRESET;
			return NULL;
		}
		if (ret > -1 && ret <= (int)size) {
			offset += ret;
			size -= ret;
		} else if (ret == -1) {
			int errno2 = errno;

			gg_debug_session(sess, GG_DEBUG_MISC, "// gg_recv_packet() body recv() failed (errno=%d, %s)\n", errno, strerror(errno));
			errno = errno2;

			if (errno == EAGAIN) {
				gg_debug_session(sess, GG_DEBUG_MISC, "// gg_recv_packet() %d bytes received, %d left\n", offset, size);
				sess->recv_buf = buf;
				sess->recv_left = size;
				sess->recv_done = offset;
				return NULL;
			}
			if (errno != EINTR) {
				free(buf);
				return NULL;
			}
		}
	}

	sess->recv_left = 0;

	if ((gg_debug_level & GG_DEBUG_DUMP)) {
		unsigned int i;

		gg_debug_session(sess, GG_DEBUG_DUMP, "// gg_recv_packet(%.2x)", h.type);
		for (i = 0; i < sizeof(h) + h.length; i++)
			gg_debug_session(sess, GG_DEBUG_DUMP, " %.2x", (unsigned char) buf[i]);
		gg_debug_session(sess, GG_DEBUG_DUMP, "\n");
	}

	return buf;
}

/**
 * \internal Wysyła pakiet do serwera.
 *
 * Funkcja konstruuje pakiet do wysłania z dowolnej liczby fragmentów. Jeśli
 * rozmiar pakietu jest za duży, by móc go wysłać za jednym razem, pozostała
 * część zostanie zakolejkowana i wysłana, gdy będzie to możliwe.
 *
 * \param sess Struktura sesji
 * \param type Rodzaj pakietu
 * \param ... Lista kolejnych części pakietu (wskaźnik na bufor i długość
 *            typu \c int) zakończona \c NULL
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 */
int gg_send_packet(struct gg_session *sess, int type, ...)
{
	struct gg_header *h;
	char *tmp;
	unsigned int tmp_length;
	void *payload;
	unsigned int payload_length;
	va_list ap;
	int res;

	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_send_packet(%p, 0x%.2x, ...);\n", sess, type);

	tmp_length = sizeof(struct gg_header);

	if (!(tmp = malloc(tmp_length))) {
		gg_debug_session(sess, GG_DEBUG_MISC, "// gg_send_packet() not enough memory for packet header\n");
		return -1;
	}

	va_start(ap, type);

	payload = va_arg(ap, void *);

	while (payload) {
		char *tmp2;

		payload_length = va_arg(ap, unsigned int);

		if (!(tmp2 = realloc(tmp, tmp_length + payload_length))) {
			gg_debug_session(sess, GG_DEBUG_MISC, "// gg_send_packet() not enough memory for payload\n");
			free(tmp);
			va_end(ap);
			return -1;
		}

		tmp = tmp2;

		memcpy(tmp + tmp_length, payload, payload_length);
		tmp_length += payload_length;

		payload = va_arg(ap, void *);
	}

	va_end(ap);

	h = (struct gg_header*) tmp;
	h->type = gg_fix32(type);
	h->length = gg_fix32(tmp_length - sizeof(struct gg_header));

	if ((gg_debug_level & GG_DEBUG_DUMP)) {
		unsigned int i;

		gg_debug_session(sess, GG_DEBUG_DUMP, "// gg_send_packet(0x%.2x)", gg_fix32(h->type));
		for (i = 0; i < tmp_length; ++i)
			gg_debug_session(sess, GG_DEBUG_DUMP, " %.2x", (unsigned char) tmp[i]);
		gg_debug_session(sess, GG_DEBUG_DUMP, "\n");
	}

	res = gg_write(sess, tmp, tmp_length);

	free(tmp);

	if (res == -1) {
		gg_debug_session(sess, GG_DEBUG_MISC, "// gg_send_packet() write() failed. res = %d, errno = %d (%s)\n", res, errno, strerror(errno));
		return -1;
	}

	if (res == 0 && sess->async)
		gg_debug_session(sess, GG_DEBUG_MISC, "// gg_send_packet() partial write(), %d sent, %d left\n", res, tmp_length - res);

	if (sess->send_buf)
		sess->check |= GG_CHECK_WRITE;

	return 0;
}

/**
 * \internal Funkcja zwrotna sesji.
 *
 * Pole \c callback struktury \c gg_session zawiera wskaźnik do tej funkcji.
 * Wywołuje ona \c gg_watch_fd i zachowuje wynik w polu \c event.
 *
 * \param sess Struktura sesji
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 */
static int gg_session_callback(struct gg_session *sess)
{
	if (!sess) {
		errno = EFAULT;
		return -1;
	}

	return ((sess->event = gg_watch_fd(sess)) != NULL) ? 0 : -1;
}

/**
 * Łączy się z serwerem Gadu-Gadu.
 *
 * Przy połączeniu synchronicznym funkcja zakończy działanie po nawiązaniu
 * połączenia lub gdy wystąpi błąd. Po udanym połączeniu należy wywoływać
 * funkcję \c gg_watch_fd, która odbiera informacje od serwera i zwraca
 * informacje o zdarzeniach.
 *
 * Przy połączeniu asynchronicznym funkcja rozpocznie procedurę połączenia
 * i zwróci zaalokowaną strukturę. Pole \c fd struktury \c gg_session zawiera
 * deskryptor, który należy obserwować funkcją \c select, \c poll lub za
 * pomocą mechanizmów użytej pętli zdarzeń (Glib, Qt itp.). Pole \c check
 * jest maską bitową mówiącą, czy biblioteka chce być informowana o możliwości
 * odczytu danych (\c GG_CHECK_READ) czy zapisu danych (\c GG_CHECK_WRITE).
 * Po zaobserwowaniu zmian na deskryptorze należy wywołać funkcję
 * \c gg_watch_fd. Podczas korzystania z połączeń asynchronicznych, w trakcie
 * połączenia może zostać stworzony dodatkowy proces rozwiązujący nazwę
 * serwera -- z tego powodu program musi poprawnie obsłużyć sygnał SIGCHLD.
 *
 * Po nawiązaniu połączenia z serwerem należy wysłać listę kontaktów za pomocą
 * funkcji \c gg_notify lub \c gg_notify_ex.
 *
 * \param p Struktura opisująca parametry połączenia. Wymagane pola: uin,
 *          password, async.
 *
 * \return Wskaźnik do zaalokowanej struktury sesji \c gg_session lub NULL
 *         w przypadku błędu.
 *
 * \ingroup login
 */
struct gg_session *gg_login(const struct gg_login_params *p)
{
	struct gg_session *sess = NULL;
	char *hostname;
	int port;

	if (!p) {
		gg_debug(GG_DEBUG_FUNCTION, "** gg_login(%p);\n", p);
		errno = EFAULT;
		return NULL;
	}

	gg_debug(GG_DEBUG_FUNCTION, "** gg_login(%p: [uin=%u, async=%d, ...]);\n", p, p->uin, p->async);

	if (!(sess = malloc(sizeof(struct gg_session)))) {
		gg_debug(GG_DEBUG_MISC, "// gg_login() not enough memory for session data\n");
		goto fail;
	}

	memset(sess, 0, sizeof(struct gg_session));

	if (!p->password || !p->uin) {
		gg_debug(GG_DEBUG_MISC, "// gg_login() invalid arguments. uin and password needed\n");
		errno = EFAULT;
		goto fail;
	}

	if (!(sess->password = strdup(p->password))) {
		gg_debug(GG_DEBUG_MISC, "// gg_login() not enough memory for password\n");
		goto fail;
	}

	if (p->status_descr && !(sess->initial_descr = strdup(p->status_descr))) {
		gg_debug(GG_DEBUG_MISC, "// gg_login() not enough memory for status\n");
		goto fail;
	}

	if (p->hash_type < 0 || p->hash_type > GG_LOGIN_HASH_SHA1) {
		gg_debug(GG_DEBUG_MISC, "// gg_login() invalid arguments. unknown hash type (%d)\n", p->hash_type);
		errno = EFAULT;
		goto fail;
	}

	sess->uin = p->uin;
	sess->state = GG_STATE_RESOLVING;
	sess->check = GG_CHECK_READ;
	sess->timeout = GG_DEFAULT_TIMEOUT;
	sess->async = p->async;
	sess->type = GG_SESSION_GG;
	sess->initial_status = p->status;
	sess->callback = gg_session_callback;
	sess->destroy = gg_free_session;
	sess->port = (p->server_port) ? p->server_port : ((gg_proxy_enabled) ? GG_HTTPS_PORT : GG_DEFAULT_PORT);
	sess->server_addr = p->server_addr;
	sess->external_port = p->external_port;
	sess->external_addr = p->external_addr;
	sess->protocol_version = (p->protocol_version) ? p->protocol_version : GG_DEFAULT_PROTOCOL_VERSION;
	if (p->era_omnix)
		sess->protocol_version |= GG_ERA_OMNIX_MASK;
	if (p->has_audio)
		sess->protocol_version |= GG_HAS_AUDIO_MASK;
	sess->client_version = (p->client_version) ? strdup(p->client_version) : NULL;
	sess->last_sysmsg = p->last_sysmsg;
	sess->image_size = p->image_size;
	sess->pid = -1;

	if (p->tls == 1) {
#ifdef GG_CONFIG_HAVE_OPENSSL
		char buf[1024];

		OpenSSL_add_ssl_algorithms();

		if (!RAND_status()) {
			char rdata[1024];
			struct {
				time_t time;
				void *ptr;
			} rstruct;

			time(&rstruct.time);
			rstruct.ptr = (void *) &rstruct;

			RAND_seed((void *) rdata, sizeof(rdata));
			RAND_seed((void *) &rstruct, sizeof(rstruct));
		}

		sess->ssl_ctx = SSL_CTX_new(TLSv1_client_method());

		if (!sess->ssl_ctx) {
			ERR_error_string_n(ERR_get_error(), buf, sizeof(buf));
			gg_debug(GG_DEBUG_MISC, "// gg_login() SSL_CTX_new() failed: %s\n", buf);
			goto fail;
		}

		SSL_CTX_set_verify(sess->ssl_ctx, SSL_VERIFY_NONE, NULL);

		sess->ssl = SSL_new(sess->ssl_ctx);

		if (!sess->ssl) {
			ERR_error_string_n(ERR_get_error(), buf, sizeof(buf));
			gg_debug(GG_DEBUG_MISC, "// gg_login() SSL_new() failed: %s\n", buf);
			goto fail;
		}
#else
		gg_debug(GG_DEBUG_MISC, "// gg_login() client requested TLS but no support compiled in\n");
#endif
	}

	if (gg_proxy_enabled) {
		hostname = gg_proxy_host;
		sess->proxy_port = port = gg_proxy_port;
	} else {
		hostname = GG_APPMSG_HOST;
		port = GG_APPMSG_PORT;
	}

	if (p->hash_type)
		sess->hash_type = p->hash_type;
	else
		sess->hash_type = GG_LOGIN_HASH_SHA1;

	if (!p->async) {
		struct in_addr a;

		if (!p->server_addr || !p->server_port) {
			if ((a.s_addr = inet_addr(hostname)) == INADDR_NONE) {
				struct in_addr *hn;

				if (!(hn = gg_gethostbyname(hostname))) {
					gg_debug(GG_DEBUG_MISC, "// gg_login() host \"%s\" not found\n", hostname);
					goto fail;
				} else {
					a.s_addr = hn->s_addr;
					free(hn);
				}
			}
		} else {
			a.s_addr = p->server_addr;
			port = p->server_port;
		}

		sess->hub_addr = a.s_addr;

		if (gg_proxy_enabled)
			sess->proxy_addr = a.s_addr;

		if ((sess->fd = gg_connect(&a, port, 0)) == -1) {
			gg_debug(GG_DEBUG_MISC, "// gg_login() connection failed (errno=%d, %s)\n", errno, strerror(errno));
			goto fail;
		}

		if (p->server_addr && p->server_port)
			sess->state = GG_STATE_CONNECTING_GG;
		else
			sess->state = GG_STATE_CONNECTING_HUB;

		while (sess->state != GG_STATE_CONNECTED) {
			struct gg_event *e;

			if (!(e = gg_watch_fd(sess))) {
				gg_debug(GG_DEBUG_MISC, "// gg_login() critical error in gg_watch_fd()\n");
				goto fail;
			}

			if (e->type == GG_EVENT_CONN_FAILED) {
				errno = EACCES;
				gg_debug(GG_DEBUG_MISC, "// gg_login() could not login\n");
				gg_event_free(e);
				goto fail;
			}

			gg_event_free(e);
		}

		return sess;
	}

	if (!sess->server_addr || gg_proxy_enabled) {
#ifndef GG_CONFIG_HAVE_PTHREAD
		if (gg_resolve(&sess->fd, &sess->pid, hostname)) {
#else
		if (gg_resolve_pthread(&sess->fd, &sess->resolver, hostname)) {
#endif
			gg_debug(GG_DEBUG_MISC, "// gg_login() resolving failed (errno=%d, %s)\n", errno, strerror(errno));
			goto fail;
		}
	} else {
		if ((sess->fd = gg_connect(&sess->server_addr, sess->port, sess->async)) == -1) {
			gg_debug(GG_DEBUG_MISC, "// gg_login() direct connection failed (errno=%d, %s)\n", errno, strerror(errno));
			goto fail;
		}
		sess->state = GG_STATE_CONNECTING_GG;
		sess->check = GG_CHECK_WRITE;
	}

	return sess;

fail:
	if (sess) {
		if (sess->password)
			free(sess->password);
		if (sess->initial_descr)
			free(sess->initial_descr);
		free(sess);
	}

	return NULL;
}

/**
 * Wysyła do serwera pakiet utrzymania połączenia.
 *
 * Klient powinien regularnie co minutę wysyłać pakiet utrzymania połączenia,
 * inaczej serwer uzna, że klient stracił łączność z siecią i zerwie
 * połączenie.
 *
 * \param sess Struktura sesji
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 *
 * \ingroup login
 */
int gg_ping(struct gg_session *sess)
{
	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_ping(%p);\n", sess);

	if (!sess) {
		errno = EFAULT;
		return -1;
	}

	if (sess->state != GG_STATE_CONNECTED) {
		errno = ENOTCONN;
		return -1;
	}

	return gg_send_packet(sess, GG_PING, NULL);
}

/**
 * Kończy połączenie z serwerem.
 *
 * Funkcja nie zwalnia zasobów, więc po jej wywołaniu należy użyć
 * \c gg_free_session. Jeśli chce się ustawić opis niedostępności, należy
 * wcześniej wywołać funkcję \c gg_change_status_descr lub
 * \c gg_change_status_descr_time.
 *
 * \param sess Struktura sesji
 *
 * \ingroup login
 */
void gg_logoff(struct gg_session *sess)
{
	if (!sess)
		return;

	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_logoff(%p);\n", sess);

	if (GG_S_NA(sess->status & ~GG_STATUS_FRIENDS_MASK))
		gg_change_status(sess, GG_STATUS_NOT_AVAIL);

#ifdef GG_CONFIG_HAVE_OPENSSL
	if (sess->ssl)
		SSL_shutdown(sess->ssl);
#endif

#ifdef GG_CONFIG_HAVE_PTHREAD
	if (sess->resolver) {
		gg_resolve_pthread_cleanup(sess->resolver, 1);
		sess->resolver = NULL;
	}
#else
	if (sess->pid != -1) {
		kill(sess->pid, SIGKILL);
		waitpid(sess->pid, NULL, WNOHANG);
		sess->pid = -1;
	}
#endif

	if (sess->fd != -1) {
		shutdown(sess->fd, SHUT_RDWR);
		close(sess->fd);
		sess->fd = -1;
	}

	if (sess->send_buf) {
		free(sess->send_buf);
		sess->send_buf = NULL;
		sess->send_left = 0;
	}
}

/**
 * Zwalnia zasoby używane przez połączenie z serwerem. Funkcję należy wywołać
 * po zamknięciu połączenia z serwerem, by nie doprowadzić do wycieku zasobów
 * systemowych.
 *
 * \param sess Struktura sesji
 *
 * \ingroup login
 */
void gg_free_session(struct gg_session *sess)
{
	struct gg_dcc7 *dcc;

	if (!sess)
		return;

	/* XXX dopisać zwalnianie i zamykanie wszystkiego, co mogło zostać */

	if (sess->password)
		free(sess->password);

	if (sess->initial_descr)
		free(sess->initial_descr);

	if (sess->client_version)
		free(sess->client_version);

	if (sess->header_buf)
		free(sess->header_buf);

#ifdef GG_CONFIG_HAVE_OPENSSL
	if (sess->ssl)
		SSL_free(sess->ssl);

	if (sess->ssl_ctx)
		SSL_CTX_free(sess->ssl_ctx);
#endif

#ifdef GG_CONFIG_HAVE_PTHREAD
	if (sess->resolver) {
		gg_resolve_pthread_cleanup(sess->resolver, 1);
		sess->resolver = NULL;
	}
#else
	if (sess->pid != -1) {
		kill(sess->pid, SIGKILL);
		waitpid(sess->pid, NULL, WNOHANG);
	}
#endif

	if (sess->fd != -1)
		close(sess->fd);

	while (sess->images)
		gg_image_queue_remove(sess, sess->images, 1);

	if (sess->send_buf)
		free(sess->send_buf);

	for (dcc = sess->dcc7_list; dcc; dcc = dcc->next)
		dcc->sess = NULL;

	free(sess);
}

/**
 * Zmienia status użytkownika.
 *
 * \param sess Struktura sesji
 * \param status Nowy status użytkownika
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 *
 * \ingroup status
 */
int gg_change_status(struct gg_session *sess, int status)
{
	struct gg_new_status p;

	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_change_status(%p, %d);\n", sess, status);

	if (!sess) {
		errno = EFAULT;
		return -1;
	}

	if (sess->state != GG_STATE_CONNECTED) {
		errno = ENOTCONN;
		return -1;
	}

	// dodaj flagę obsługi połączeń głosowych zgodną z GG 7.x
	
	if ((sess->protocol_version & 0xff) >= 0x2a && (sess->protocol_version & GG_HAS_AUDIO_MASK) && !GG_S_I(status))
		status |= 0x20000;

	p.status = gg_fix32(status);

	sess->status = status;

	return gg_send_packet(sess, GG_NEW_STATUS, &p, sizeof(p), NULL);
}

/**
 * Zmienia status użytkownika na status opisowy.
 *
 * \param sess Struktura sesji
 * \param status Nowy status użytkownika
 * \param descr Opis statusu użytkownika
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 *
 * \ingroup status
 */
int gg_change_status_descr(struct gg_session *sess, int status, const char *descr)
{
	struct gg_new_status p;

	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_change_status_descr(%p, %d, \"%s\");\n", sess, status, descr);

	if (!sess || !descr) {
		errno = EFAULT;
		return -1;
	}

	if (sess->state != GG_STATE_CONNECTED) {
		errno = ENOTCONN;
		return -1;
	}

	p.status = gg_fix32(status);

	sess->status = status;

	return gg_send_packet(sess, GG_NEW_STATUS, &p, sizeof(p), descr, (strlen(descr) > GG_STATUS_DESCR_MAXSIZE) ? GG_STATUS_DESCR_MAXSIZE : strlen(descr), NULL);
}

/**
 * Zmienia status użytkownika na status opisowy z podanym czasem powrotu.
 *
 * \param sess Struktura sesji
 * \param status Nowy status użytkownika
 * \param descr Opis statusu użytkownika
 * \param time Czas powrotu w formacie uniksowego znacznika czasu
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 *
 * \ingroup status
 */
int gg_change_status_descr_time(struct gg_session *sess, int status, const char *descr, int time)
{
	struct gg_new_status p;
	uint32_t newtime;

	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_change_status_descr_time(%p, %d, \"%s\", %d);\n", sess, status, descr, time);

	if (!sess || !descr || !time) {
		errno = EFAULT;
		return -1;
	}

	if (sess->state != GG_STATE_CONNECTED) {
		errno = ENOTCONN;
		return -1;
	}

	p.status = gg_fix32(status);

	sess->status = status;

	newtime = gg_fix32(time);

	return gg_send_packet(sess, GG_NEW_STATUS, &p, sizeof(p), descr, (strlen(descr) > GG_STATUS_DESCR_MAXSIZE) ? GG_STATUS_DESCR_MAXSIZE : strlen(descr), &newtime, sizeof(newtime), NULL);
}

/**
 * Wysyła wiadomość do użytkownika.
 *
 * Zwraca losowy numer sekwencyjny, który można zignorować albo wykorzystać
 * do potwierdzenia.
 *
 * \param sess Struktura sesji
 * \param msgclass Klasa wiadomości
 * \param recipient Numer adresata
 * \param message Treść wiadomości
 *
 * \return Numer sekwencyjny wiadomości lub -1 w przypadku błędu.
 *
 * \ingroup messages
 */
int gg_send_message(struct gg_session *sess, int msgclass, uin_t recipient, const unsigned char *message)
{
	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_send_message(%p, %d, %u, %p)\n", sess, msgclass, recipient, message);

	return gg_send_message_richtext(sess, msgclass, recipient, message, NULL, 0);
}

/**
 * Wysyła wiadomość formatowaną.
 *
 * Zwraca losowy numer sekwencyjny, który można zignorować albo wykorzystać
 * do potwierdzenia.
 *
 * \param sess Struktura sesji
 * \param msgclass Klasa wiadomości
 * \param recipient Numer adresata
 * \param message Treść wiadomości
 * \param format Informacje o formatowaniu
 * \param formatlen Długość informacji o formatowaniu
 *
 * \return Numer sekwencyjny wiadomości lub -1 w przypadku błędu.
 *
 * \ingroup messages
 */
int gg_send_message_richtext(struct gg_session *sess, int msgclass, uin_t recipient, const unsigned char *message, const unsigned char *format, int formatlen)
{
	struct gg_send_msg s;

	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_send_message_richtext(%p, %d, %u, %p, %p, %d);\n", sess, msgclass, recipient, message, format, formatlen);

	if (!sess) {
		errno = EFAULT;
		return -1;
	}

	if (sess->state != GG_STATE_CONNECTED) {
		errno = ENOTCONN;
		return -1;
	}

	if (!message) {
		errno = EFAULT;
		return -1;
	}

	s.recipient = gg_fix32(recipient);
	if (!sess->seq)
		sess->seq = 0x01740000 | (rand() & 0xffff);
	s.seq = gg_fix32(sess->seq);
	s.msgclass = gg_fix32(msgclass);
	sess->seq += (rand() % 0x300) + 0x300;

	if (gg_send_packet(sess, GG_SEND_MSG, &s, sizeof(s), message, strlen((char*) message) + 1, format, formatlen, NULL) == -1)
		return -1;

	return gg_fix32(s.seq);
}

/**
 * Wysyła wiadomość w ramach konferencji.
 *
 * Zwraca losowy numer sekwencyjny, który można zignorować albo wykorzystać
 * do potwierdzenia.
 *
 * \param sess Struktura sesji
 * \param msgclass Klasa wiadomości
 * \param recipients_count Liczba adresatów
 * \param recipients Wskaźnik do tablicy z numerami adresatów
 * \param message Treść wiadomości
 *
 * \return Numer sekwencyjny wiadomości lub -1 w przypadku błędu.
 *
 * \ingroup messages
 */
int gg_send_message_confer(struct gg_session *sess, int msgclass, int recipients_count, uin_t *recipients, const unsigned char *message)
{
	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_send_message_confer(%p, %d, %d, %p, %p);\n", sess, msgclass, recipients_count, recipients, message);

	return gg_send_message_confer_richtext(sess, msgclass, recipients_count, recipients, message, NULL, 0);
}

/**
 * Wysyła wiadomość formatowaną w ramach konferencji.
 *
 * Zwraca losowy numer sekwencyjny, który można zignorować albo wykorzystać
 * do potwierdzenia.
 *
 * \param sess Struktura sesji
 * \param msgclass Klasa wiadomości
 * \param recipients_count Liczba adresatów
 * \param recipients Wskaźnik do tablicy z numerami adresatów
 * \param message Treść wiadomości
 * \param format Informacje o formatowaniu
 * \param formatlen Długość informacji o formatowaniu
 *
 * \return Numer sekwencyjny wiadomości lub -1 w przypadku błędu.
 * 
 * \ingroup messages
 */
int gg_send_message_confer_richtext(struct gg_session *sess, int msgclass, int recipients_count, uin_t *recipients, const unsigned char *message, const unsigned char *format, int formatlen)
{
	struct gg_send_msg s;
	struct gg_msg_recipients r;
	int i, j, k;
	uin_t *recps;

	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_send_message_confer_richtext(%p, %d, %d, %p, %p, %p, %d);\n", sess, msgclass, recipients_count, recipients, message, format, formatlen);

	if (!sess) {
		errno = EFAULT;
		return -1;
	}

	if (sess->state != GG_STATE_CONNECTED) {
		errno = ENOTCONN;
		return -1;
	}

	if (!message || recipients_count <= 0 || recipients_count > 0xffff || !recipients) {
		errno = EINVAL;
		return -1;
	}

	r.flag = 0x01;
	r.count = gg_fix32(recipients_count - 1);

	if (!sess->seq)
		sess->seq = 0x01740000 | (rand() & 0xffff);
	s.seq = gg_fix32(sess->seq);
	s.msgclass = gg_fix32(msgclass);

	recps = malloc(sizeof(uin_t) * recipients_count);
	if (!recps)
		return -1;

	for (i = 0; i < recipients_count; i++) {

		s.recipient = gg_fix32(recipients[i]);

		for (j = 0, k = 0; j < recipients_count; j++)
			if (recipients[j] != recipients[i]) {
				recps[k] = gg_fix32(recipients[j]);
				k++;
			}

		if (!i)
			sess->seq += (rand() % 0x300) + 0x300;

		if (gg_send_packet(sess, GG_SEND_MSG, &s, sizeof(s), message, strlen((char*) message) + 1, &r, sizeof(r), recps, (recipients_count - 1) * sizeof(uin_t), format, formatlen, NULL) == -1) {
			free(recps);
			return -1;
		}
	}

	free(recps);

	return gg_fix32(s.seq);
}

/**
 * Wysyła wiadomość binarną przeznaczoną dla klienta.
 *
 * Wiadomości między klientami przesyła się np. w celu wywołania zwrotnego
 * połączenia bezpośredniego. Funkcja zwraca losowy numer sekwencyjny,
 * który można zignorować albo wykorzystać do potwierdzenia.
 *
 * \param sess Struktura sesji
 * \param msgclass Klasa wiadomości
 * \param recipient Numer adresata
 * \param message Treść wiadomości
 * \param message_len Długość wiadomości
 *
 * \return Numer sekwencyjny wiadomości lub -1 w przypadku błędu.
 *
 * \ingroup messages
 */
int gg_send_message_ctcp(struct gg_session *sess, int msgclass, uin_t recipient, const unsigned char *message, int message_len)
{
	struct gg_send_msg s;

	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_send_message_ctcp(%p, %d, %u, ...);\n", sess, msgclass, recipient);

	if (!sess) {
		errno = EFAULT;
		return -1;
	}

	if (sess->state != GG_STATE_CONNECTED) {
		errno = ENOTCONN;
		return -1;
	}

	s.recipient = gg_fix32(recipient);
	s.seq = gg_fix32(0);
	s.msgclass = gg_fix32(msgclass);

	return gg_send_packet(sess, GG_SEND_MSG, &s, sizeof(s), message, message_len, NULL);
}

/**
 * Wysyła żądanie obrazka o podanych parametrach.
 *
 * Wiadomości obrazkowe nie zawierają samych obrazków, a tylko ich rozmiary
 * i sumy kontrolne. Odbiorca najpierw szuka obrazków w swojej pamięci
 * podręcznej i dopiero gdy ich nie znajdzie, wysyła żądanie do nadawcy.
 * Wynik zostanie przekazany zdarzeniem \c GG_EVENT_IMAGE_REPLY.
 *
 * \param sess Struktura sesji
 * \param recipient Numer adresata
 * \param size Rozmiar obrazka w bajtach
 * \param crc32 Suma kontrola obrazka
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 *
 * \ingroup messages
 */
int gg_image_request(struct gg_session *sess, uin_t recipient, int size, uint32_t crc32)
{
	struct gg_send_msg s;
	struct gg_msg_image_request r;
	char dummy = 0;
	int res;

	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_image_request(%p, %d, %u, 0x%.4x);\n", sess, recipient, size, crc32);

	if (!sess) {
		errno = EFAULT;
		return -1;
	}

	if (sess->state != GG_STATE_CONNECTED) {
		errno = ENOTCONN;
		return -1;
	}

	if (size < 0) {
		errno = EINVAL;
		return -1;
	}

	s.recipient = gg_fix32(recipient);
	s.seq = gg_fix32(0);
	s.msgclass = gg_fix32(GG_CLASS_MSG);

	r.flag = 0x04;
	r.size = gg_fix32(size);
	r.crc32 = gg_fix32(crc32);

	res = gg_send_packet(sess, GG_SEND_MSG, &s, sizeof(s), &dummy, 1, &r, sizeof(r), NULL);

	if (!res) {
		struct gg_image_queue *q = malloc(sizeof(*q));
		char *buf;

		if (!q) {
			gg_debug_session(sess, GG_DEBUG_MISC, "// gg_image_request() not enough memory for image queue\n");
			return -1;
		}

		buf = malloc(size);
		if (size && !buf)
		{
			gg_debug_session(sess, GG_DEBUG_MISC, "// gg_image_request() not enough memory for image\n");
			free(q);
			return -1;
		}

		memset(q, 0, sizeof(*q));

		q->sender = recipient;
		q->size = size;
		q->crc32 = crc32;
		q->image = buf;

		if (!sess->images)
			sess->images = q;
		else {
			struct gg_image_queue *qq;

			for (qq = sess->images; qq->next; qq = qq->next)
				;

			qq->next = q;
		}
	}

	return res;
}

/**
 * Wysyła żądany obrazek.
 *
 * \param sess Struktura sesji
 * \param recipient Numer adresata
 * \param filename Nazwa pliku
 * \param image Bufor z obrazkiem
 * \param size Rozmiar obrazka
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 *
 * \ingroup messages
 */
int gg_image_reply(struct gg_session *sess, uin_t recipient, const char *filename, const char *image, int size)
{
	struct gg_msg_image_reply *r;
	struct gg_send_msg s;
	const char *tmp;
	char buf[1910];
	int res = -1;

	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_image_reply(%p, %d, \"%s\", %p, %d);\n", sess, recipient, filename, image, size);

	if (!sess || !filename || !image) {
		errno = EFAULT;
		return -1;
	}

	if (sess->state != GG_STATE_CONNECTED) {
		errno = ENOTCONN;
		return -1;
	}

	if (size < 0) {
		errno = EINVAL;
		return -1;
	}

	/* wytnij ścieżki, zostaw tylko nazwę pliku */
	while ((tmp = strrchr(filename, '/')) || (tmp = strrchr(filename, '\\')))
		filename = tmp + 1;

	if (strlen(filename) < 1 || strlen(filename) > 1024) {
		errno = EINVAL;
		return -1;
	}

	s.recipient = gg_fix32(recipient);
	s.seq = gg_fix32(0);
	s.msgclass = gg_fix32(GG_CLASS_MSG);

	buf[0] = 0;
	r = (void*) &buf[1];

	r->flag = 0x05;
	r->size = gg_fix32(size);
	r->crc32 = gg_fix32(gg_crc32(0, (unsigned char*) image, size));

	while (size > 0) {
		int buflen, chunklen;

		/* \0 + struct gg_msg_image_reply */
		buflen = sizeof(struct gg_msg_image_reply) + 1;

		/* w pierwszym kawałku jest nazwa pliku */
		if (r->flag == 0x05) {
			strcpy(buf + buflen, filename);
			buflen += strlen(filename) + 1;
		}

		chunklen = (size >= (int)sizeof(buf) - buflen) ? ((int)sizeof(buf) - buflen) : size;

		memcpy(buf + buflen, image, chunklen);
		size -= chunklen;
		image += chunklen;

		res = gg_send_packet(sess, GG_SEND_MSG, &s, sizeof(s), buf, buflen + chunklen, NULL);

		if (res == -1)
			break;

		r->flag = 0x06;
	}

	return res;
}

/**
 * Wysyła do serwera listę kontaktów.
 *
 * Funkcja informuje serwer o liście kontaktów, których statusy będą
 * obserwowane lub kontaktów, które bedą blokowane. Dla każdego z \c count
 * kontaktów tablica \c userlist zawiera numer, a tablica \c types rodzaj
 * kontaktu (\c GG_USER_NORMAL, \c GG_USER_OFFLINE, \c GG_USER_BLOCKED).
 *
 * Listę kontaktów należy \b zawsze wysyłać po połączeniu, nawet jeśli
 * jest pusta.
 *
 * \param sess Struktura sesji
 * \param userlist Wskaźnik do tablicy numerów kontaktów
 * \param types Wskaźnik do tablicy rodzajów kontaktów
 * \param count Liczba kontaktów
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 *
 * \ingroup contacts
 */
int gg_notify_ex(struct gg_session *sess, uin_t *userlist, char *types, int count)
{
	struct gg_notify *n;
	uin_t *u;
	char *t;
	int i, res = 0;

	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_notify_ex(%p, %p, %p, %d);\n", sess, userlist, types, count);

	if (!sess) {
		errno = EFAULT;
		return -1;
	}

	if (sess->state != GG_STATE_CONNECTED) {
		errno = ENOTCONN;
		return -1;
	}

	if (!userlist || !count)
		return gg_send_packet(sess, GG_LIST_EMPTY, NULL);

	while (count > 0) {
		int part_count, packet_type;

		if (count > 400) {
			part_count = 400;
			packet_type = GG_NOTIFY_FIRST;
		} else {
			part_count = count;
			packet_type = GG_NOTIFY_LAST;
		}

		if (!(n = (struct gg_notify*) malloc(sizeof(*n) * part_count)))
			return -1;

		for (u = userlist, t = types, i = 0; i < part_count; u++, t++, i++) {
			n[i].uin = gg_fix32(*u);
			n[i].dunno1 = *t;
		}

		if (gg_send_packet(sess, packet_type, n, sizeof(*n) * part_count, NULL) == -1) {
			free(n);
			res = -1;
			break;
		}

		count -= part_count;
		userlist += part_count;
		types += part_count;

		free(n);
	}

	return res;
}

/**
 * Wysyła do serwera listę kontaktów.
 *
 * Funkcja jest odpowiednikiem \c gg_notify_ex, gdzie wszystkie kontakty
 * są rodzaju \c GG_USER_NORMAL.
 *
 * \param sess Struktura sesji
 * \param userlist Wskaźnik do tablicy numerów kontaktów
 * \param count Liczba kontaktów
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 *
 * \ingroup contacts
 */
int gg_notify(struct gg_session *sess, uin_t *userlist, int count)
{
	struct gg_notify *n;
	uin_t *u;
	int i, res = 0;

	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_notify(%p, %p, %d);\n", sess, userlist, count);

	if (!sess) {
		errno = EFAULT;
		return -1;
	}

	if (sess->state != GG_STATE_CONNECTED) {
		errno = ENOTCONN;
		return -1;
	}

	if (!userlist || !count)
		return gg_send_packet(sess, GG_LIST_EMPTY, NULL);

	while (count > 0) {
		int part_count, packet_type;

		if (count > 400) {
			part_count = 400;
			packet_type = GG_NOTIFY_FIRST;
		} else {
			part_count = count;
			packet_type = GG_NOTIFY_LAST;
		}

		if (!(n = (struct gg_notify*) malloc(sizeof(*n) * part_count)))
			return -1;

		for (u = userlist, i = 0; i < part_count; u++, i++) {
			n[i].uin = gg_fix32(*u);
			n[i].dunno1 = GG_USER_NORMAL;
		}

		if (gg_send_packet(sess, packet_type, n, sizeof(*n) * part_count, NULL) == -1) {
			res = -1;
			free(n);
			break;
		}

		free(n);

		userlist += part_count;
		count -= part_count;
	}

	return res;
}

/**
 * Dodaje kontakt.
 *
 * Dodaje do listy kontaktów dany numer w trakcie połączenia. Aby zmienić
 * rodzaj kontaktu (np. z normalnego na zablokowany), należy najpierw usunąć
 * poprzedni rodzaj, ponieważ serwer operuje na maskach bitowych.
 *
 * \param sess Struktura sesji
 * \param uin Numer kontaktu
 * \param type Rodzaj kontaktu
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 *
 * \ingroup contacts
 */
int gg_add_notify_ex(struct gg_session *sess, uin_t uin, char type)
{
	struct gg_add_remove a;

	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_add_notify_ex(%p, %u, %d);\n", sess, uin, type);

	if (!sess) {
		errno = EFAULT;
		return -1;
	}

	if (sess->state != GG_STATE_CONNECTED) {
		errno = ENOTCONN;
		return -1;
	}

	a.uin = gg_fix32(uin);
	a.dunno1 = type;

	return gg_send_packet(sess, GG_ADD_NOTIFY, &a, sizeof(a), NULL);
}

/**
 * Dodaje kontakt.
 *
 * Funkcja jest odpowiednikiem \c gg_add_notify_ex, gdzie wszystkie rodzaj
 * kontaktu to \c GG_USER_NORMAL.
 *
 * \param sess Struktura sesji
 * \param uin Numer kontaktu
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 *
 * \ingroup contacts
 */
int gg_add_notify(struct gg_session *sess, uin_t uin)
{
	return gg_add_notify_ex(sess, uin, GG_USER_NORMAL);
}

/**
 * Usuwa kontakt.
 *
 * Usuwa z listy kontaktów dany numer w trakcie połączenia.
 *
 * \param sess Struktura sesji
 * \param uin Numer kontaktu
 * \param type Rodzaj kontaktu
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 *
 * \ingroup contacts
 */
int gg_remove_notify_ex(struct gg_session *sess, uin_t uin, char type)
{
	struct gg_add_remove a;

	gg_debug_session(sess, GG_DEBUG_FUNCTION, "** gg_remove_notify_ex(%p, %u, %d);\n", sess, uin, type);

	if (!sess) {
		errno = EFAULT;
		return -1;
	}

	if (sess->state != GG_STATE_CONNECTED) {
		errno = ENOTCONN;
		return -1;
	}

	a.uin = gg_fix32(uin);
	a.dunno1 = type;

	return gg_send_packet(sess, GG_REMOVE_NOTIFY, &a, sizeof(a), NULL);
}

/**
 * Usuwa kontakt.
 *
 * Funkcja jest odpowiednikiem \c gg_add_notify_ex, gdzie wszystkie rodzaj
 * kontaktu to \c GG_USER_NORMAL.
 *
 * \param sess Struktura sesji
 * \param uin Numer kontaktu
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 *
 * \ingroup contacts
 */
int gg_remove_notify(struct gg_session *sess, uin_t uin)
{
	return gg_remove_notify_ex(sess, uin, GG_USER_NORMAL);
}

/**
 * Wysyła do serwera zapytanie dotyczące listy kontaktów.
 *
 * Funkcja służy do importu lub eksportu listy kontaktów do serwera.
 * W odróżnieniu od funkcji \c gg_notify, ta lista kontaktów jest przez
 * serwer jedynie przechowywana i nie ma wpływu na połączenie. Format
 * listy kontaktów jest ignorowany przez serwer, ale ze względu na
 * kompatybilność z innymi klientami, należy przechowywać dane w tym samym
 * formacie co oryginalny klient Gadu-Gadu.
 *
 * Program nie musi się przejmować fragmentacją listy kontaktów wynikającą
 * z protokołu -- wysyła i odbiera kompletną listę.
 *
 * \param sess Struktura sesji
 * \param type Rodzaj zapytania
 * \param request Treść zapytania (może być równe NULL)
 *
 * \return 0 jeśli się powiodło, -1 w przypadku błędu
 *
 * \ingroup importexport
 */
int gg_userlist_request(struct gg_session *sess, char type, const char *request)
{
	int len;

	if (!sess) {
		errno = EFAULT;
		return -1;
	}

	if (sess->state != GG_STATE_CONNECTED) {
		errno = ENOTCONN;
		return -1;
	}

	if (!request) {
		sess->userlist_blocks = 1;
		return gg_send_packet(sess, GG_USERLIST_REQUEST, &type, sizeof(type), NULL);
	}

	len = strlen(request);

	sess->userlist_blocks = 0;

	while (len > 2047) {
		sess->userlist_blocks++;

		if (gg_send_packet(sess, GG_USERLIST_REQUEST, &type, sizeof(type), request, 2047, NULL) == -1)
			return -1;

		if (type == GG_USERLIST_PUT)
			type = GG_USERLIST_PUT_MORE;

		request += 2047;
		len -= 2047;
	}

	sess->userlist_blocks++;

	return gg_send_packet(sess, GG_USERLIST_REQUEST, &type, sizeof(type), request, len, NULL);
}

/* @} */

/*
 * Local variables:
 * c-indentation-style: k&r
 * c-basic-offset: 8
 * indent-tabs-mode: notnil
 * End:
 *
 * vim: shiftwidth=8:
 */
