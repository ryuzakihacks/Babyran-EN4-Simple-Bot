#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <vector>
#pragma comment ( lib, "d3d9.lib" )
#pragma comment ( lib, "d3dx9.lib" )

struct SNATIVEID
{
public:
	enum
	{
		ID_NULL = 0xFFFF,
	};

	union
	{
		struct
		{
			DWORD	dwID;
		};

		struct
		{
			WORD	wMainID;		//	주 ID.
			WORD	wSubID;			//	보조 ID.
		};
	};

	SNATIVEID()
		: wMainID(0)
		, wSubID(0)
	{
	}

	SNATIVEID(bool bvalid)
		: wMainID(0)
		, wSubID(0)
	{
		if (!bvalid)
		{
			wMainID = ID_NULL;
			wSubID = ID_NULL;
		}
	}

	SNATIVEID(DWORD dwid)
		: dwID(dwid)
	{
	}

	SNATIVEID(WORD wid, WORD wsubid)
		: wMainID(wid)
		, wSubID(wsubid)
	{
	}

	bool operator== (const SNATIVEID& nID) const
	{
		return (wMainID == nID.wMainID) && (wSubID == nID.wSubID);
	}

	bool operator!= (const SNATIVEID& nID) const
	{
		return !((wMainID == nID.wMainID) && (wSubID == nID.wSubID));
	}

	bool IsValidNativeID()
	{
		return ((wMainID != ID_NULL) && (wSubID != ID_NULL));
	}
};

struct NET_MSG_GENERIC
{
	DWORD		dwSize;		// Size of Message Data
	int			nType;		// Message type
};

enum EMCROW
{
	CROW_PC = 0,
	CROW_NPC = 1,
	CROW_MOB = 2,
	CROW_ITEM = 3,
	CROW_MONEY = 4,
	CROW_PET = 5,	// PetData
	CROW_SUMMON = 6,	// PetData
	CROW_MATERIAL = 7,	// 재료NPC

	CROW_NUM = 8
};



struct STARGETID
{
	EMCROW		emCrow;
	DWORD		dwID;
	D3DXVECTOR3	vPos;

	STARGETID() :
		emCrow(CROW_MOB),
		dwID(-1),
		vPos(0, 0, 0)
	{
	}

	STARGETID(EMCROW _emcrow, DWORD _dwid) :
		emCrow(_emcrow),
		dwID(_dwid),
		vPos(0, 0, 0)
	{
	}
	STARGETID(EMCROW _emcrow, DWORD _dwid, D3DXVECTOR3 _vpos) :
		emCrow(_emcrow),
		dwID(_dwid),
		vPos(_vpos)
	{
	}

	void RESET()
	{
		emCrow = CROW_MOB;
		dwID = -1;
		vPos = D3DXVECTOR3(FLT_MAX, FLT_MAX, FLT_MAX);
	}

	bool operator < (const STARGETID &starget) const
	{
		if (std::make_pair(emCrow, dwID) < std::make_pair(starget.emCrow, starget.dwID))	return true;
		return false;
	}

	bool operator == (const STARGETID &starget) const
	{
		return (starget.dwID == dwID && starget.emCrow == emCrow);
	}

	bool operator != (const STARGETID &starget) const
	{
		return (starget.dwID != dwID || starget.emCrow != emCrow);
	}
};

struct STARID
{
	WORD		wCrow;
	WORD		wID;

	STARID()
		: wCrow(0)
		, wID(USHRT_MAX)
	{
	}

	STARID(WORD _wcrow, WORD _wid)
		: wCrow(_wcrow)
		, wID(_wid)
	{
	}

	STARID(EMCROW _emcrow, DWORD _dwid)
		: wCrow((WORD)_emcrow)
		, wID((WORD)_dwid)
	{
	}

	void SET(const STARGETID &sTARID)
	{
		wCrow = static_cast<WORD>(sTARID.emCrow);
		wID = static_cast<WORD>(sTARID.dwID);
	}

	EMCROW GETCROW() const		{ return static_cast<EMCROW>(wCrow); }

};