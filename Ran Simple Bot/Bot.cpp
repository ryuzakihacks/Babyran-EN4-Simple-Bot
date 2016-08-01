#include "Bot.h"
#include "GLCharacter.h"
#include "GLInventory.h"
#include "GLItemMan.h"



Bot * Bot::s_instance;

Bot* Bot::GetInstance()
{
	if (!s_instance)
		s_instance = new Bot;
	return s_instance;
}

void Bot::MainLogic(bool skill, bool pots)
{
	if (pots)
	PotLogic();
	if (skill)
	{
		BuffLogic();
		SkillLogic();
		if (GLCharacter::GetInstance()->GetAction() == 10)
			GLCharacter::GetInstance()->ReqReBirth();
	}	
}

void Bot::PotLogic()
{
	if (GLCharacter::GetInstance()->GetAction() == 10) return;
	WORD x, y;
	GetPotsPos(x, y);
	if (*(DWORD*)ADR_Health != *(DWORD*)ADR_MaxHealth)
		GLCharacter::GetInstance()->ReqInvenDrug(x, y);
}

void Bot::BuffLogic()
{
	//Reference: http://www.ramleague.net/threads/babyran-en4-skill-log.5941/
	SNATIVEID BeserkAura(33, 26);
	SNATIVEID Revitalize(33, 35);
	SNATIVEID MagneticShaft(33, 22);
	SNATIVEID ConfusionStrike(33, 32);
	SNATIVEID Focus(32, 22);
	SNATIVEID DivineShield(31, 31);
	SNATIVEID TitanWill(30, 22);
	SNATIVEID MetalBody(31, 30);
	SNATIVEID EvasiveDance(30, 29);

	CastBuff(BeserkAura);
	CastBuff(Revitalize);
	CastBuff(MagneticShaft);
	CastBuff(ConfusionStrike);
	CastBuff(Focus);
	CastBuff(DivineShield);
	CastBuff(TitanWill);
	CastBuff(MetalBody);
	CastBuff(EvasiveDance);
}


void Bot::SkillLogic()
{
	if (!GLCharacter::GetInstance()) return;
	if (GLCharacter::GetInstance()->GetAction() == 3 || GLCharacter::GetInstance()->GetAction() == 10) return;
	GLCROWLOGIC *nearestcrow = GetNearestCrow(GLCharacter::GetInstance()->GetPosition());
	STARGETID target;
	target.emCrow = CROW_MOB;
	target.dwID = nearestcrow->m_dwGlobID;
	target.vPos = nearestcrow->m_vPos;

	BOOL bmove;
	D3DXVECTOR3 moveto;
	SNATIVEID id(31, 56);
	GLCharacter::GetInstance()->m_sActiveSkill = id;
	GLCharacter::GetInstance()->m_sRunSkill = id;
	GLCharacter::GetInstance()->SkillReaction(target, 16, true, bmove, moveto);
}





void Bot::CastBuff(SNATIVEID id)
{
	if (!GLCharacter::GetInstance()) return;
	GLCROWLOGIC *nearestcrow = GetNearestCrow(GLCharacter::GetInstance()->GetPosition());
	STARGETID target;
	target.emCrow = CROW_MOB;
	target.dwID = nearestcrow->m_dwGlobID;
	target.vPos = nearestcrow->m_vPos;
	BOOL bMove;
	D3DXVECTOR3 moveto;

	if (GLCharacter::GetInstance()->GetAction() == 3 || GLCharacter::GetInstance()->GetAction() == 10) return;

	if (!IsBuffFound(id))
	{
		GLCharacter::GetInstance()->m_sActiveSkill = id;
		GLCharacter::GetInstance()->m_sRunSkill = id;
		GLCharacter::GetInstance()->SkillReaction(target, 16, true, bMove, moveto);
	}
}

GLCROWLOGIC * Bot::GetNearestCrow(D3DXVECTOR3 FromPos)
{
	DWORD glgaeaclientinstance = GLGaeaClientGetInstance();
	while (!glgaeaclientinstance) Sleep(200);
	while (!*(DWORD*)(glgaeaclientinstance + OFS_GLLandManClient)) Sleep(200);
	DWORD pCrowCur;
	float MaxDistance = 0xFFFFFFF;
	GLCROWLOGIC * nearestcrow = nullptr;
	for (pCrowCur = *(DWORD*)(*(DWORD*)(glgaeaclientinstance + OFS_GLLandManClient) + OFS_GLCROWLIST); pCrowCur; pCrowCur = *(DWORD*)(pCrowCur + 8))
	{
		DWORD pCrow = *(DWORD*)pCrowCur;
		GLCROWLOGIC * crow = (GLCROWLOGIC*)pCrow;
		float distance = CalculateDist(FromPos, crow->m_vPos);
		if (distance < MaxDistance)
		{
			MaxDistance = distance;
			nearestcrow = crow;
		}
	}
	return nearestcrow;
}


void Bot::GetPotsPos(WORD& X, WORD& Y)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		DWORD pInvenItem = GLInventory::GetInstance()->FindPosItem(x, y);
		if (!pInvenItem)
		{
			x++;
			if (x == 6)
			{
				x = 0;
				y++;
				if (y == 9)
					break;
			}
			continue;
		}

		WORD nativeid1 = *(WORD*)(pInvenItem + 0x8);
		WORD nativeid2 = *(WORD*)(pInvenItem + 0xA);

		DWORD pItem = GLItemMan::GetInstance()->GetItem(nativeid1, nativeid2);
		if (!pItem)
		{
			x++;
			if (x == 6)
			{
				x = 0;
				y++;
				if (y == 9)
					break;
			}
			continue;
		}

		DWORD EmDrug = *(DWORD*)(pItem + 0x4D4);

		if (EmDrug != 6)
		{
			x++;
			if (x == 6)
			{
				x = 0;
				y++;
				if (y == 9)
					break;
			}
			continue;
		}
		X = x;
		Y = y;

		break;
	}
}

bool Bot::IsBuffFound(SNATIVEID id)
{
	for (int i = 0; i < 14; i++)
	{
		if (id == GLCharacter::GetInstance()->m_sSKILLFACT[i].sNATIVEID)
		{
			return true;
		}
	}
	return false;
}


float Bot::CalculateDist(D3DXVECTOR3 from, D3DXVECTOR3 to)
{
	float _x, _y, _z;
	_x = to.x - from.x;
	_y = to.y - from.y;
	_z = to.z - from.z; 
	return sqrt(_x*_x + _y*_y + _z*_z);
}

