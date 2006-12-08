#pragma once

#include <sys/msg.h>

#define MAX_NICK        10                //maksymalna dlugosc nicka
#define MAX_NICKS       50                //maksymalna ilosc uzytkownikow
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

#define SYSTEM_QID      0
#define SYSTEM_NICK     "SYSTEM"
#define USERS_GROUP     "WSZYSCY"

//wspolna struktura komunikatu/pakietu/wiadomoœci w sensie msg*()
struct packet_common
{
	long type;
	int subtype;
	char data[MAX_DATA];
};

#define MAX_PACKET      sizeof(packet_common)-sizeof(long)

//klient wysyla publicznym kanalem w celu otwarcia sesji
struct login_request
{
	pid_t pid;                              //pid wysylajacego klienta
};

//klient dostaje prywatnym kanalem jako pierwszy komunikat liste wszystkich
//pozostalych uzytkownikow
struct login_reply
{
	int count;                            //ilosc uzytkownikow
	int qids[MAX_NICKS];                  //tablica qidow
	char nicks[MAX_NICKS][MAX_NICK+1];    //tablica nickow
};

//klient wysyla prywatnym kanalem w celu zakonczenia sesji
struct logout_request
{
};

//klient wysyla prywatnym kanalem w celu zmiany 
struct nick_request
{
	char nick[MAX_NICK+1];                //nowy nick 
};

//serwer wysyla prywatnymi kanalami wszystkim klientom aby ich powiadomic
//ze uzytkownik zmienil nicka
struct nick_notify
{
	int qid;                              //qid zmieniajacego klienta
	char nick[MAX_NICK+1];                //nowy nick 
};

//klient wysyla prywatnym kanalem w celu otrzymania listy grup
struct groups_request
{
};

//serwer wysyla prywatnym kanalem aktualna liste grup
struct groups_reply
{
	int count;                            //ilosc grup
	char groups[MAX_GROUPS][MAX_GROUP+1]; //tablica nazw grup
};

//klient wysyla prywatnym kanalem w celu dolaczenia siê do grupy
//(nieistniejaca grupa jest automatycznie tworzona przez serwer)
struct join_request
{
	char group[MAX_GROUP+1];              //nazwa grupy
};

//serwer wysyla prywatnymi kanalami wszystkim klientom aby ich powiadomic
//ze do grupy dolaczyl sie nowy uzytkownik
struct join_notify
{
	char group[MAX_GROUP+1];              //nazwa grupy lub "WSZYSCY"
	int qid;                              //qid nowego klienta
};

//klient wysyla prywatnym kanalem w celu odlaczenia siê od grupy
//(pusta grupa jest automatycznie kasowana przez serwer)
struct part_request
{
	char group[MAX_GROUP+1];              //nazwa grupy
};

//serwer wysyla prywatnymi kanalami wszystkim klientom aby ich powiadomic
//ze uzytkownik odlaczyl sie od grupy
struct part_notify
{
	char group[MAX_GROUP+1];              //nazwa grupy lub "WSZYSCY"
	int qid;                              //qid nowego klienta
};


//klient wysyla prywatnym kanalem w celu otrzymania listy uzytkownikow
//dolaczonych do grupy
struct users_request
{
	char group[MAX_GROUP+1];              //nazwa grupy lub "WSZYSCY"
};

//serwer wysyla prywatnym kanalem liste uzytkownikow dolaczonych do grupy
struct users_reply
{
	char group[MAX_GROUP+1];             //nazwa grupy lub "WSZYSCY"
	int count;                           //ilosc u¿ytkownikow w grupie
	int qids[MAX_NICKS];                 //tablica qidow tych uzytkownikow
};

struct private_request
{
	int recipient;
	char message[MAX_MESSAGE+1];
};

struct private_notify
{
	int sender;
	char message[MAX_MESSAGE+1];
};

struct group_request
{
	char group[MAX_GROUP+1];	
	char message[MAX_MESSAGE+1];
};

struct group_notify
{
	int sender;
	char group[MAX_GROUP+1];	
	char message[MAX_MESSAGE+1];
};
