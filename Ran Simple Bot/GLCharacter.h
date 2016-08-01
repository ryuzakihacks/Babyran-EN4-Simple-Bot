#pragma once
#include <Windows.h>
#include "DataTypes.h"
class SSKILLFACT
{
public:
	SNATIVEID sNATIVEID;
	WORD wLEVEL; //0x0004 
	char pad_0x0006[0x2]; //0x0006
	float fAGE; //0x0008 
	DWORD emTYPE; //0x000C 
	float fMVAR; //0x0010 
	DWORD emADDON; //0x0014 
	float fADDON_VAR; //0x0018 
	DWORD emSPEC; //0x001C 
	float fSPECVAR1; //0x0020 
	char pad_0x0024[0x84]; //0x0024

};//Size=0x00A8


typedef D3DXVECTOR3 Vector3;
typedef D3DXMATRIX matrix3x4_t;

class DummyClass2
{};

class GLCharacter
{
public:
	char pad_0x0000[0xBB4]; //0x0000
	SSKILLFACT m_sSKILLFACT[14]; //0x0BB4 
	SSKILLFACT m_sPETSKILLFACT; //0x14E4 
	char pad_0x158C[0x3FC]; //0x158C
	unsigned char m_bFirstCalc; //0x1988 
	char pad_0x1989[0x3]; //0x1989
	unsigned char m_bFirstWayPointPass; //0x198C 
	char pad_0x198D[0x3]; //0x198D
	float m_fFirstPathDist; //0x1990 
	float m_fMovedDist; //0x1994 
	float m_fMovedTime; //0x1998 
	DummyClass2* m_pSkinChar; //0x199C 
	Vector3 m_vDir; //0x19A0 
	Vector3 m_vDirOrig; //0x19AC 
	Vector3 m_vPos; //0x19B8 
	matrix3x4_t m_matTrans; //0x19C4 
	Vector3 m_vServerPos; //0x1A04 
	DWORD m_Action; //0x1A10 
	DWORD m_dwActState; //0x1A14 
	STARGETID m_sTargetID; //0x1A18 
	WORD m_wTARNUM; //0x1A2C 
	char pad_0x1A2E[0x2]; //0x1A2E
	Vector3 m_vTARPOS; //0x1A30 
	STARID m_sTARIDS[24]; //0x1A3C 
	char pad_0x1A9C[0x10]; //0x1A9C
	SNATIVEID m_sRunSkill; //0x1AAC 
	SNATIVEID m_sActiveSkill; //0x1AB0
private:
	static GLCharacter *s_instance;
public:
	static GLCharacter * GetInstance();
	HRESULT ReqInvenDrug(WORD wPosX, WORD wPosY);
	Vector3 GetPosition();
	DWORD GetAction();
	void SkillReaction(const STARGETID &sTargetID, const DWORD dwMR, const bool bcontinue, BOOL &bMove, D3DXVECTOR3 &vMoveTo);
	void ReqReBirth();
};

