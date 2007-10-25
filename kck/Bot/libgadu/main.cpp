#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		WSADATA wsaData;
		WSAStartup(MAKEWORD(2, 2), &wsaData);
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		WSACleanup();
		break;
	}

	return TRUE;
}
