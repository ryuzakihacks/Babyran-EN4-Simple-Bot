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

/*
These addies are scanned through cheat engine and olly, you have to bypass the protection of babyran first 
before you can attach these debuggers. The Health can be scanned using cheat engine easily, and there's a workaround 
to get the GLCharacterPointer without using olly, but I'm too busy to find the function to get it because I'm busy 
in school, I'll find it again if I'm on vacation ;).

The rest can be pattern scanned. Here's the patterns:
#define pat_GLItemMan_Instance FindPattern(EntryPoint, 0xFFFFFF,(PBYTE)"\xFF\x92\x00\x00\x00\x00\x8B\x8C\x24\x00\x00\x00\x00\x5F\x5E\xB8\x00\x00\x00\x00\x64\x89\x0D\x00\x00\x00\x00\x5B\x8B\xE5\x5D\xC2\x0C\x00", "xx????xxx????xxx????xxx????xxxxxxx") + 0x2A
#define pat_GLItemMan_GetItem FindPattern(EntryPoint, 0xFFFFFF,(PBYTE)"\x8B\x91\x00\x00\x00\x00\x85\xD2\x75\x05\x33\xC0", "xx????xxxxxx")
#define pat_GLInventory_FindPosItem FindPattern(EntryPoint, 0xFFFFFF,(PBYTE)"\x83\xEC\x0C\x53\x66\x8B\x5C\x24\x00\x66\x3B\x19", "xxxxxxxx?xxx")
#define pat_GLCharacter_ReqInvenDrug FindPattern(EntryPoint, 0xFFFFFF,(PBYTE)"\x83\xEC\x10\x53\x8B\xD9\xE8\x00\x00\x00\x00", "xxxxxxx????")
#define pat_GLGaeaClient_GetInstance FindPattern(EntryPoint, 0xFFFFFF,(PBYTE)"\xE8\x00\x00\x00\x00\x8B\x4C\x24\x10\x5F\x8B\xC6\x5E\x5B\x64\x89\x0D\x00\x00\x00\x00\x83\xC4\x10\xC2\x04\x00\xCC\x64\xA1\x00\x00\x00\x00", "x????xxxxxxxxxxxx????xxxxxxxxx????") + 0x1C
#define pat_GLCharacter_GLInventoryInstanceOffset FindPattern(EntryPoint, 0xFFFFFF,(PBYTE)"\x8D\x8B\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\xE8\x85\xED\x75\x0D", "xx????x????xxxxxx")
#define pat_GLCROWLOGIC_m_pLandManClient FindPattern(EntryPoint, 0xFFFFFF,(PBYTE)"\x89\x86\x00\x00\x00\x00\x89\x8E\x00\x00\x00\x00\x8B\x17\x52", "xx????xx????xxx")
#define pat_GLCharacter_ReqRebirth FindPattern(EntryPoint, 0xFFFFFF,(PBYTE)"\x8B\x86\x00\x00\x00\x00\x8D\x8E\x00\x00\x00\x00\x6A\x0A\xFF\x50\x24\x85\xC0\x0F\x84\x00\x00\x00\x00", "xx????xx????xxxxxxxxx????") - 0x1E
#define pat_GLCharacter_SkillReaction FindPattern(EntryPoint, 0xFFFFFF,(PBYTE)"\x6A\xFF\x64\xA1\x00\x00\x00\x00\x68\x00\x00\x00\x00\x50\x64\x89\x25\x00\x00\x00\x00\x81\xEC\x00\x00\x00\x00\x53\x55\x8B\xE9\x8A\x85\x00\x00\x00\x00\x84\xC0\x56\x57\x0F\x85\x00\x00\x00\x00\x8A\x85\x00\x00\x00\x00", "xxxx????x????xxxx????xx????xxxxxx????xxxxxx????xx????")
*/