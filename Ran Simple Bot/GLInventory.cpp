#include "GLInventory.h"


GLInventory * GLInventory::s_instance;

GLInventory* GLInventory::GetInstance()
{
	if (!s_instance)
		s_instance = (GLInventory*)(ADR_GLCharacterPointer + OFS_GLInventoryInstance);

	return s_instance;
}

DWORD GLInventory::FindPosItem(const WORD wPosX, const WORD wPosY)
{
	if (this != nullptr)
	{
		auto FindPosItem = (DWORD(__thiscall*)(void*, const WORD, const WORD))ASM_FindPosItem;
		return FindPosItem(this, wPosX, wPosY);
	}
	return 0;
}

