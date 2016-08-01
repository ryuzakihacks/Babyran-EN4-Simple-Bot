#define ADR_GLCharacterPointer 0x281FCC0
#define ADR_Health 0x281FE00
#define ADR_MaxHealth 0x281FE04
#define ASM_GLItemManInstaceCall 0x5D0150
#define ASM_GLItemManGetItem 0x5CD120
#define ASM_FindPosItem 0x5D1830
#define ASM_GLCharacter_ReqInvenDrug 0x5C10A0
#define ASM_GLGaeaGetInstanceCall 0x575A20
#define OFS_GLInventoryInstance 0x97C
#define OFS_GLLandManClient 0x140
#define OFS_GLCROWLIST 0xA7CC
#define ASM_GLCharacter_SkillReaction 0x622E40
#define ASM_GLCharacter_ReqReBirth 0x5B9740

inline DWORD GLGaeaClientGetInstance()
{
	static DWORD instance;
	DWORD _glgaeaclientgetinstance = ASM_GLGaeaGetInstanceCall;
	__asm
	{
		call _glgaeaclientgetinstance
			mov[instance], eax
	}
	return instance;
}