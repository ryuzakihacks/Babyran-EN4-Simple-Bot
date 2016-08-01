#pragma once
#include <Windows.h>
class GLItemMan
{
private:
	static GLItemMan *s_instance;
public:
	static GLItemMan * GetInstance();
	DWORD GetItem(WORD Main, WORD Sub);
};

