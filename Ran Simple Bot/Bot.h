#pragma once
#include <Windows.h>
#include "DataTypes.h"
#include "GLCrowLogic.h"
class Bot
{
private:
	void GetPotsPos(WORD &x, WORD&y);
	void CastBuff(SNATIVEID id);
	static Bot *s_instance;
	GLCROWLOGIC * GetNearestCrow(D3DXVECTOR3 FromPos);
	float CalculateDist(D3DXVECTOR3 from, D3DXVECTOR3 to);
	bool IsBuffFound(SNATIVEID id);
	void PotLogic();
	void BuffLogic();
	void SkillLogic();
public:
	static Bot * GetInstance();
	void MainLogic(bool skill, bool pots);
};

