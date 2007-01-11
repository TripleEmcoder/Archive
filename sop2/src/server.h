#pragma once

#define AFTER_LOGIN_NOTIFY      "Uzytkownik %s wszedl na serwer."
#define AFTER_LOGIN_REPLY       "Witamy!"

#define BEFORE_LOGOUT_NOTIFY    "Uzytkownik %s wyszedl z serwera."
#define BEFORE_LOGOUT_REPLY     "Zegnamy!"

#define NICK_CHANGED_NOTIFY     "Uzytkownik %s zmienil nick na %s."
#define NICK_CHANGED_REPLY      "Nick zostal zmieniony."
#define DUPLICATE_NICK_REPLY    "Nick jest juz zajety."

#define GROUP_JOINED_NOTIFY     "Uzytkownik %s wszedl do grupy %s."
#define GROUP_JOINED_REPLY      "Dolaczono do grupy."
#define ALREADY_JOINED_REPLY    "Juz nalezysz do tej grupie."

#define GROUP_PARTED_NOTIFY     "Uzytkownik %s wyszedl z grupy %s."
#define GROUP_PARTED_REPLY      "Odlaczono od grupy."
#define ALREADY_PARTED_REPLY    "Nie nalezysz do tej grupy."

#define INVALID_RECIPIENT_REPLY "Nieprawidlowy adresat wiadomosci."
#define MESSAGE_SENT_REPLY      "Wiadomosc wyslana."

#define NOT_ALLOWED_REPLY       "Ta operacja jest niedozwolona."
#define MAX_GROUPS_REACHED      "Maksymalna liczba grup osiagnieta."

#define CREATING_SERVER_QUEUE   "Creating server message queue (%d).\n"
#define REMOVING_SERVER_QUEUE   "Removing server message queue (%d).\n"
#define UNKNOWN_SERVER_REQUEST  "Unknown server request (%d).\n"

#define JOINING_CLIENT_QUEUE    "Joining client message queue (%d).\n"
#define PARTING_CLIENT_QUEUE    "Parting client message queue (%d)\n"
#define UNKNOWN_CLIENT_REQUEST  "Unknown client request (%d).\n"

#define CREATING_CLIENT_RECORD  "Creating client structures (%d).\n"
#define REMOVING_CLIENT_RECORD  "Removing client structures (%d).\n"
