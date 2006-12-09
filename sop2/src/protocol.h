#pragma once

#include <sys/msg.h>

#define MAX_NICK        10                //maksymalna dlugosc nicka
#define MAX_NICKS       20                //maksymalna ilosc uzytkownikow
#define MAX_GROUP       10                //maksymalna dlugosc nazwy grupy
#define MAX_GROUPS      10                //maksymalna ilosc grup
#define MAX_MESSAGE     500              //maksymalna dlugosc wiadomosci
#define MAX_DATA		700              //maksymalna dlugosc danych

#define SERVER_KEY      23                //klucz kolejki publicznej
#define REQUEST_TYPE    1                 //typ komunikatu do serwera
#define REPLY_TYPE      2                 //typ odpowiedzi na komunikat
#define NOTIFY_TYPE     2                 //typ powiadomienia o zdarzeniu

#define LOGIN_SUBTYPE   1                 //podtyp logowania
#define LOGOUT_SUBTYPE  2                 //podtyp wylogowania
#define NICK_SUBTYPE    3                 //podtyp zmiany nicka
#define GROUPS_SUBTYPE  4                 //podtyp listy group
#define JOIN_SUBTYPE    5                 //podtyp dolaczenia do grupy
#define PART_SUBTYPE    6                 //podtyp odlaczenia od grupy
#define USERS_SUBTYPE   7                 //podtyp listy userow
#define PRIVATE_SUBTYPE 8                 //podtyp wiadomosci prywatnej
#define GROUP_SUBTYPE   9                 //podtyp wiadomosci grupowej

#define SYSTEM_NICK     "SYSTEM"          //nick w wiadomosciach od serwera
#define SYSTEM_GROUP    "WSZYSCY"         //nazwa grupy ze wszystkimi

//wspolna struktura komunikatu/pakietu/wiadomoœci w sensie msg*()
struct packet_common
{
	long type;
	int subtype;
	char data[MAX_DATA];
};

#define MAX_PACKET      sizeof(struct packet_common)-sizeof(long)

//klient wysyla publicznym kanalem w celu otwarcia sesji
struct login_request
{
	pid_t pid;                             //pid wysylajacego klienta
};

//klient wysyla prywatnym kanalem w celu zakonczenia sesji
struct logout_request
{
};

//klient wysyla prywatnym kanalem w celu zmiany nicka
struct nick_request
{
	char nick[MAX_NICK+1];                //nowy nick 
};

//klient wysyla prywatnym kanalem w celu otrzymania listy grup
struct groups_request
{
};

//serwer wysyla prywatnym kanalem aktualna liste grup
struct groups_reply
{
	int count;                             //ilosc grup
	char groups[MAX_GROUPS][MAX_GROUP+1]; //tablica nazw grup
};

//klient wysyla prywatnym kanalem w celu dolaczenia siê do grupy
//(nieistniejaca grupa jest automatycznie tworzona przez serwer)
struct join_request
{
	char group[MAX_GROUP+1];              //nazwa grupy
};

//klient wysyla prywatnym kanalem w celu odlaczenia siê od grupy
//(pusta grupa jest automatycznie kasowana przez serwer)
struct part_request
{
	char group[MAX_GROUP+1];              //nazwa grupy
};

//klient wysyla prywatnym kanalem w celu otrzymania listy uzytkownikow
//dolaczonych do grupy lub wszystkich uzytkownikow
struct users_request
{
	char group[MAX_GROUP+1];              //nazwa grupy lub SYSTEM_GROUP
};

//serwer wysyla prywatnym kanalem liste uzytkownikow dolaczonych do grupy
struct users_reply
{
	char group[MAX_GROUP+1];             //nazwa grupy lub SYSTEM_GROUP
	int count;                           //ilosc u¿ytkownikow w grupie
	char nicks[MAX_NICKS][MAX_NICK+1];   //tablica qidow tych uzytkownikow
};

//klient wysyla prywatnym kanalem w celu przekazania prywatnej wiadomoœci
struct private_request
{
	char nick[MAX_NICK+1];               //nick odbiorcy
	char message[MAX_MESSAGE+1];         //tresc wiadomosci
};

//serwer wysyla prywatnym kanalem w celu przekazania prywatnej wiadomoœci
struct private_notify
{
	char nick[MAX_NICK+1];               //nick nadawcy
	char message[MAX_MESSAGE+1];         //tresc wiadomosci
};

//klient wysyla prywatnym kanalem w celu przekazania grupowej wiadomoœci
struct group_request
{
	char group[MAX_GROUP+1];             //nazwa grupy docelowej
	char message[MAX_MESSAGE+1];         //tresc wiadomosci
};

//serwer wysyla prywatnym kanalem w celu przekazania grupowej wiadomoœci
struct group_notify
{
	char nick[MAX_NICK+1];               //nick nadawcy
	char group[MAX_GROUP+1];             //nazwa grupy
	char message[MAX_MESSAGE+1];         //tresc wiadomosci
};


