#include "GGSession.h"

#include <memory.h>
#include <winsock2.h>

using namespace System;
using namespace System::Text;
using namespace System::Runtime::InteropServices;

using namespace DotTalk::GG;

array<unsigned char>^ EncodeText(String^ value)
{
	return Encoding::GetEncoding("windows-1250")->GetBytes(value);
}

GGSession::GGSession(int login, String^ password)
{
	pin_ptr<unsigned char> _password = &EncodeText(password)[0];

	gg_debug_level = 255;

	struct gg_login_params params;
	memset(&params, 0, sizeof(params));
	
	params.uin = login;
	params.password = (char*)_password;
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

void GGSession::send(int login, String^ text)
{
	pin_ptr<unsigned char> _text = &EncodeText(text)[0];
	gg_send_message(session, GG_CLASS_MSG, login, _text);
}