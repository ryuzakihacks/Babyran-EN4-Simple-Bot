#include "GLItemMan.h"
#include "Addies.h"

GLItemMan * GLItemMan::s_instance;

GLItemMan* GLItemMan::GetInstance()
{
	if (!s_instance)
	{
		DWORD instancecall = ASM_GLItemManInstaceCall;
		DWORD addy;
		__asm
		{
			call instancecall
				mov[addy], eax
		}

		s_instance = (GLItemMan*)(addy);
	}

	if (!s_instance)
		return nullptr;

	return s_instance;
}

DWORD GLItemMan::GetItem(WORD Main, WORD Sub)
{
	if (this != nullptr)
	{
		auto GetItem = (DWORD(__thiscall*)(void*, WORD, WORD))ASM_GLItemManGetItem;
		return GetItem(this, Main, Sub);
	}
	return 0;
}


