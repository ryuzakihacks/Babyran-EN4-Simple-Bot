#include "GLCharacter.h"
#include "Addies.h"


GLCharacter * GLCharacter::s_instance;

DWORD GLCharacter::GetAction()
{
	if (this != nullptr)
		return m_Action;

	return 10;
}


GLCharacter* GLCharacter::GetInstance()
{
	if (!s_instance)
		s_instance = (GLCharacter*)ADR_GLCharacterPointer;

	return s_instance;
}

Vector3 GLCharacter::GetPosition()
{
	if (this != nullptr)
		return m_vPos;

	return D3DXVECTOR3(0, 0, 0);
}


HRESULT GLCharacter::ReqInvenDrug(WORD wPosX, WORD wPosY)
{
	if (this != nullptr)
	{
		auto ReqInvenDrug = (HRESULT(__thiscall*)(void*, WORD, WORD))ASM_GLCharacter_ReqInvenDrug;
		return ReqInvenDrug(this, wPosX, wPosY);
	}
	return 0;
}

void GLCharacter::SkillReaction(const STARGETID& sTargetID, const DWORD dwMR, const bool bcontinue, BOOL& bMove, D3DXVECTOR3& vMoveTo)
{
	auto SkillReaction = (void(__thiscall*)(void*, const STARGETID &, const DWORD, const bool, BOOL &, D3DXVECTOR3 &))ASM_GLCharacter_SkillReaction;
	SkillReaction(this, sTargetID, dwMR, bcontinue, bMove, vMoveTo);
}

void GLCharacter::ReqReBirth()
{
	auto ReqReBirth = (void(__thiscall*)(void*))ASM_GLCharacter_ReqReBirth;
	ReqReBirth(this);
}


