#include <windows.h>

char *ws_strerror(int code)
{
	static char err_desc[1024];

	// Not a windows error display WinSock
	if(code == 0)
	{
		char buff[1024];
		int len;
		len = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,
				  NULL, WSAGetLastError(), 0, buff,
				  sizeof(buff), NULL);
		if(len == 0)
			_snprintf(err_desc, sizeof(err_desc), "WinSock %u: Unknown error.", WSAGetLastError());
		else
			_snprintf(err_desc, sizeof(err_desc), "WinSock %d: %s", WSAGetLastError(), buff);
		return err_desc;
	}

	// Return normal error
	return strerror(code);
}
