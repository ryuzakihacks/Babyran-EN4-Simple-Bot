
#include "Bot.h"
#include "Xor.h"

bool skill, pots;
void Main()
{
	while (1)
	{
		if (GetAsyncKeyState(VK_INSERT) & 1)
			pots = true;

		if (GetAsyncKeyState(VK_DELETE) & 1)
			pots = false;

		if (GetAsyncKeyState(VK_HOME) & 1)
			skill = true;

		if (GetAsyncKeyState(VK_END) & 1)
			skill = false;


		Bot::GetInstance()->MainLogic(skill,pots);
		Sleep(50);
	}
}


BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		MessageBoxA(0, msg, title, 0);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Main, NULL, NULL, NULL);
	}
	return true;
}
