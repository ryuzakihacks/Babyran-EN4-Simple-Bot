#pragma once
#include <Windows.h>
#include "Addies.h"
class GLInventory
{
private:
	static GLInventory *s_instance;
public:
	static GLInventory * GetInstance();
	DWORD FindPosItem(const WORD wPosX, const WORD wPosY);
};

