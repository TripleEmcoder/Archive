#include "GGSession.h"

#include <memory.h>
#include <winsock2.h>

using namespace System;
using namespace System::Runtime::InteropServices;

using namespace InstantMessaging::Protocols::GG;

GGSession::GGSession()
{
	gg_debug_level = 255;

	struct gg_login_params params;
	memset(&params, 0, sizeof(params));
	
	params.uin = 9444333;
	params.password = "alamakota";
	params.server_addr = inet_addr("217.17.45.145");
	params.server_port = 443;
	
	session = gg_login(&params);

	if (session == NULL)
		throw gcnew Exception("Error connecting!");
}

GGSession::~GGSession()
{
	gg_logoff(session);
	gg_free_session(session);
}

void GGSession::send(String^ text)
{
	char* text2 = (char*)(void*)Marshal::StringToHGlobalAnsi(text);
	gg_send_message(session, GG_CLASS_MSG, 1817471, (const unsigned char*)text2);
	Marshal::FreeHGlobal((IntPtr)text2);
}