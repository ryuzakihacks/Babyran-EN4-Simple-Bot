#include <Windows.h>
#ifndef _XOR_H_
#define _XOR_H_

#pragma once


template<INT XORSTART, INT BUFLEN, INT XREFKILLER>

class XorStr
{
private:
	XorStr();
public:
	CHAR s[BUFLEN];

	XorStr(CONST CHAR *xs);
	~XorStr()
	{
		for (INT i = 0; i < BUFLEN; i++)
			s[i] = 0;
	}
};

template<INT XORSTART, INT BUFLEN, INT XREFKILLER>

XorStr<XORSTART, BUFLEN, XREFKILLER>::XorStr(CONST CHAR *xs)
{
	INT xvalue = XORSTART;
	INT i = 0;

	for (; i < (BUFLEN - 1); i++)
	{
		s[i] = xs[i - XREFKILLER] ^ xvalue;
		xvalue += 1;
		xvalue %= 256;
	}

	s[BUFLEN - 1] = 0;
}


#endif

#define msg /*Made By Geopulse\nFacebook: www.facebook.com/geopulse.softwares\nVisit us in: www.ramleague.net\n\nHotkeys:\nInsert = Auto Pots On\nDelete = Auto Pots Off\nHome = Cast Skills On\nEnd = Cast Skills Off*/XorStr<0xB6,193,0xF994B889>("\xFB\xD6\xDC\xDC\x9A\xF9\xC5\x9D\xF9\xDA\xAF\xB1\xB7\xAF\xB7\xA0\xCC\x81\xA9\xAA\xAF\xA9\xA3\xA2\xA5\xF5\xF0\xA6\xA5\xA4\xFA\xB3\xB7\xB4\xBD\xBB\xB5\xB4\xB7\xF3\xBD\xB0\x8D\xCE\x85\x86\x8B\x95\x93\x8B\x9B\x8C\xC4\x98\x83\x8B\x9A\x98\x91\x83\x97\x80\xFE\xA3\x9F\x84\x91\x8D\xDA\x8E\x8F\xDD\x97\x91\x3A\x21\x75\x74\x73\x2B\x74\x66\x65\x65\x6F\x6A\x6B\x78\x6B\x21\x7E\x74\x66\x19\x1E\x5D\x79\x63\x73\x7C\x63\x68\x26\x17\x57\x71\x53\x44\x50\x57\x04\x18\x06\x66\x5D\x5D\x45\x0B\x7C\x42\x5A\x5C\x10\x7E\x5C\x39\x70\x50\x5A\x52\x4C\x5C\x1A\x06\x1C\x7C\x4B\x4B\x2F\x61\x12\x2C\x30\x36\x66\x08\x2E\x2F\x40\x03\x23\x20\x2B\x6F\x6D\x71\x11\x32\x27\x21\x76\x04\x33\x30\x36\x37\x2F\x7D\x11\x31\x6A\x24\x0C\x07\x44\x58\x46\x24\x09\x1A\x1E\x4B\x3F\x06\x07\x03\x1C\x02\x52\x3C\x12\x13"+0xF994B889).s
#define title /*Credits*/XorStr<0x1A,8,0x8634E906>("\x59\x69\x79\x79\x77\x6B\x53"+0x8634E906).s