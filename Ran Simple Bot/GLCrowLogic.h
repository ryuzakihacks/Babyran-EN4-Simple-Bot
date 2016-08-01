#include "DataTypes.h"

#pragma once
class SRESIST
{
public:
	WORD nFire; //0x0000 
	WORD nIce; //0x0002 
	WORD nElectric; //0x0004 
	WORD nPoison; //0x0006 
	WORD nSpirit; //0x0008 
	WORD __pad; //0x000A 

};//Size=0x000C

class DummyClass
{
	
};



typedef D3DXVECTOR3 Vector3;
typedef D3DXMATRIX matrix3x4_t;
class GLCROWLOGIC
{
public:
	DummyClass* UnknownData; //0x0000 
	SNATIVEID m_sNativeID; //0x0004 
	DummyClass * m_pCrowData; //0x0008 
	char pad_0x000C[0x980]; //0x000C
	float m_fSTATE_MOVE; //0x098C 
	float m_fSTATE_DELAY; //0x0990 
	float m_fSTATE_DAMAGE; //0x0994 
	unsigned char m_bSTATE_PANT; //0x0998 
	char pad_0x0999[0x3]; //0x0999
	unsigned char m_bSTATE_STUN; //0x099C 
	char pad_0x099D[0x3]; //0x099D
	unsigned char m_bINVISIBLE; //0x09A0 
	char pad_0x09A1[0x3]; //0x09A1
	unsigned char m_bRECVISIBLE; //0x09A4 
	char pad_0x09A5[0x3]; //0x09A5
	float m_fATTVELO; //0x09A8 
	float m_fSKILL_MOVE; //0x09AC 
	__int32 m_nSUM_HIT; //0x09B0 
	__int32 m_nSUM_AVOID; //0x09B4 
	__int32 m_nSUM_DEFENSE; //0x09B8 
	__int32 m_nDX_DAMAGE; //0x09BC 
	SRESIST m_sSUMRESIST; //0x09C0 
	float m_nSUM_PIERCE; //0x09CC 
	float m_fSUM_TARRANGE; //0x09D0 
	float m_fDamageRate; //0x09D4 
	float m_fDefenseRate; //0x09D8 
	float m_fPsyDamageReduce; //0x09DC 
	float m_fMagicDamageReduce; //0x09E0 
	float m_fPsyDamageReflection; //0x09E4 
	float m_fPsyDamageReflectionRate; //0x09E8 
	float m_fMagicDamageReflection; //0x09EC 
	float m_fMagicDamageReflectionRate; //0x09F0 
	SNATIVEID DEFENSE_SKILL_m_dwSkillID; //0x09F4 
	WORD DEFENSE_SKILLm_wLevel; //0x09F8 
	char pad_0x09FA[0x2]; //0x09FA
	float DEFENSE_SKILL_m_fRate; //0x09FC 
	unsigned char DEFENSE_SKILL_m_bActive; //0x0A00 
	char pad_0x0A01[0x3]; //0x0A01
	DWORD m_dwAType; //0x0A04 
	DWORD m_dwNowHP; //0x0A08 
	WORD m_wNowMP; //0x0A0C 
	char pad_0x0A0E[0x2]; //0x0A0E
	WORD m_wNowSP; //0x0A10 
	char pad_0x0A12[0x2]; //0x0A12
	SNATIVEID m_idACTIVESKILL; //0x0A14 
	WORD m_wACTIVESKILL_LVL; //0x0A18 
	char pad_0x0A1A[0x2]; //0x0A1A
	float m_fIncHP; //0x0A1C 
	float m_fIncMP; //0x0A20 
	float m_fIncSP; //0x0A24 
	DummyClass* m_pd3dDevice; //0x0A28 
	DummyClass* m_Parent; //0x0A2C 
	DWORD m_CurrentCellID; //0x0A30 
	Vector3 m_Position; //0x0A34 
	Vector3 m_Movement; //0x0A40 
	Vector3 m_NextPosition; //0x0A4C 
	float m_MaxSpeed; //0x0A58 
	float m_CorrectY; //0x0A5C 
	unsigned char m_PathActive; //0x0A60 
	char pad_0x0A61[0x3B]; //0x0A61
	unsigned char m_bFirstCalc; //0x0A9C 
	char pad_0x0A9D[0x3]; //0x0A9D
	unsigned char m_bFirstWayPointPass; //0x0AA0 
	char pad_0x0AA1[0x3]; //0x0AA1
	float m_fFirstPathDist; //0x0AA4 
	float m_fMovedDist; //0x0AA8 
	float m_fMovedTime; //0x0AAC 
	DummyClass* m_pSkinChar; //0x0AB0 
	Vector3 m_vDir; //0x0AB4 
	Vector3 m_vDirOrig; //0x0AC0 
	Vector3 m_vPos; //0x0ACC 
	matrix3x4_t m_matTrans; //0x0AD8 
	float m_fScale; //0x0B18 
	Vector3 m_vServerPos; //0x0B1C 
	Vector3 m_vMaxOrg; //0x0B28 
	Vector3 m_vMinOrg; //0x0B34 
	Vector3 m_vMax; //0x0B40 
	Vector3 m_vMin; //0x0B4C 
	float m_fHeight; //0x0B58 
	DWORD m_dwGlobID; //0x0B5C 
	DWORD m_dwCeID; //0x0B60 
	DummyClass* m_pLandManClient; //0x0B64 //
	DummyClass* m_pGlobNode; //0x0B68 
	DummyClass* m_pQuadNode; //0x0B6C 
	DummyClass* m_pCellNode; //0x0B70 
	float m_fAge; //0x0B74 
	DWORD m_Action; //0x0B78 
	DWORD m_dwActState; //0x0B7C 
	STARGETID m_sTargetID; //0x0B80 
	WORD m_wTARNUM; //0x0B94 
	char pad_0x0B96[0x2]; //0x0B96
	STARID m_sTARIDS_editthis[24]; //0x0B98 
	Vector3 m_vTARPOS; //0x0BF8 
	DummyClass* m_pAttackProp; //0x0C04 
	float m_fIdleTime; //0x0C08 
	float m_fStayTimer; //0x0C0C 
	float m_fAttackTimer; //0x0C10 
	float m_fTargetTimer; //0x0C14 
	float m_fMoveDelay; //0x0C18 
};