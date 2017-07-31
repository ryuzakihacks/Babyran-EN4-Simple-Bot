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

/*
Some Patterns for reference:
m_sSKILLFACT \x8D\x86\x00\x00\x00\x00\x50\x51\x8D\x54\x24\x28 xx????xxxxxx
m_sPETSKILLFACT \x89\x88\x00\x00\x00\x00\x8B\x96\x00\x00\x00\x00\x8B\x47\x0C xx????xx????xxx
m_sLandEffect \x8D\x9E\x00\x00\x00\x00\x55\xEB\x03 xx????xxx
m_sActiveSkill \x8D\xBD\x00\x00\x00\x00\x57\x8D\x4C\x24\x24 xx????xxxxx
m_sRunSkill \x8B\x85\x00\x00\x00\x00\x8D\xBD\x00\x00\x00\x00\x57 xx????xx????x
m_vDir \x8D\xBE\x00\x00\x00\x00\x57\x89\x54\x24\x24 xx????xxxxx
m_matTrans \x8D\x8E\x00\x00\x00\x00\x51\x8B\x8E\x00\x00\x00\x00\x8D\x96\x00\x00\x00\x00\x52\x89\x44\x24\x30 xx????xxx????xx????xxxxx
m_sSTATEBLOWS \x8D\x96\x00\x00\x00\x00\x52\x89\x44\x24\x30\x8D\x86\x00\x00\x00\x00\x50 xx????xxxxxxx????x
m_pSkinChar \x8B\x8E\x00\x00\x00\x00\x8D\x96\x00\x00\x00\x00\x52\x89\x44\x24\x30 xx????xx????xxxxx
m_vPos \x8D\x86\x00\x00\x00\x00\x8B\x08\x89\x54\x24\x18 xx????xxxxxx
m_Action \x8B\x86\x00\x00\x00\x00\x83\xC0\xFE\xB9\x00\x00\x00\x00 xx????xxxx????
m_wTARNUM \x66\xC7\x86\x00\x00\x00\x00\x00\x00\xEB\x34 xxx??????xx
m_bCanActionMove \x8B\x85\x00\x00\x00\x00\x33\xF6\x3B\xC6\x57 xx????xxxxx
(market)m_bOPEN \x8A\x85\x00\x00\x00\x00\x84\xC0\x75\x74 xx????xxxx
m_dwActState \x81\xA5\x00\x00\x00\x00\x00\x00\x00\x00\xEB\x07\x8B\xCD\xE8\x00\x00\x00\x00\x8A\x85\x00\x00\x00\x00\x84\xC0\xC7\x85\x00\x00\x00\x00\x00\x00\x00\x00 xx????????xxxxx????xx????xxxx????????
m_bSTATE_STUN \x8A\x85\x00\x00\x00\x00\x84\xC0\x75\x61 xx????xxxx
m_sTargetID (-4 from offset) \x66\x89\xB5\x00\x00\x00\x00\xEB\x13\x81\xA5\x00\x00\x00\x00\x00\x00\x00\x00\xEB\x07\x8B\xCD\xE8\x00\x00\x00\x00\x8A\x85\x00\x00\x00\x00\x84\xC0\xC7\x85\x00\x00\x00\x00\x00\x00\x00\x00 xxx????xxxx????????xxxxx????xx????xxxx????????
m_fLastMsgMoveSend \x89\x85\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\xC8\xE8\x00\x00\x00\x00\x5F xx????x????xxx????x
m_sLastMsgMoveSend \x8D\xBD\x00\x00\x00\x00\xB9\x00\x00\x00\x00\x8D\x74\x24\x2C xx????x????xxxx
m_actorMove.PathIsActive() \x8A\x85\x00\x00\x00\x00\x84\xC0\x74\x2F\x8B\x84\x24\x00\x00\x00\x00 xx????xxxxxxx????
m_vTARPOS \x8D\x95\x00\x00\x00\x00\x8B\x0A\x89\x08\x8B\x4A\x04\x8B\x52\x08\x89\x48\x04\x89\x50\x08\x8B\x85\x00\x00\x00\x00\x50\x8D\xB5\x00\x00\x00\x00 xx????xxxxxxxxxxxxxxxxxx????xxx????
m_sTARIDS \x8D\x8D\x00\x00\x00\x00\x51\x83\xEC\x0C\x8B\xC4\x8D\x95\x00\x00\x00\x00\x8B\x0A\x89\x08\x8B\x4A\x04\x8B\x52\x08\x89\x48\x04\x89\x50\x08\x8B\x85\x00\x00\x00\x00\x50\x8D\xB5\x00\x00\x00\x00 xx????xxxxxxxx????xxxxxxxxxxxxxxxxxx????xxx????
*/
