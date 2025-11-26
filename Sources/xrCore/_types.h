#pragma once

// Type defs
typedef	signed		char	s8;
typedef	unsigned	char	u8;

typedef	signed		short	s16;
typedef	unsigned	short	u16;

typedef	signed		int		s32;
typedef	unsigned	int		u32;

typedef	signed		__int64	s64;
typedef	unsigned	__int64	u64;

typedef float				f32;
typedef double				f64;

typedef char*				pstr;
typedef const char*			pcstr;

typedef void*				pvoid;
typedef const void*			pcvoid;

// windoze stuff
#ifndef _WINDOWS_
	typedef	int				BOOL;
	typedef pstr			LPSTR;
	typedef pcstr			LPCSTR;
	#define TRUE			true
	#define FALSE			false
#endif

typedef	char	string8		[8];
typedef	char	string16	[16];
typedef	char	string32	[32];
typedef	char	string64	[64];
typedef	char	string128	[128];
typedef	char	string256	[256];
typedef	char	string512	[512];
typedef	char	string1024	[1024];
typedef	char	string2048	[2048];
typedef	char	string4096	[4096];

typedef	char	string_path	[_MAX_PATH];
