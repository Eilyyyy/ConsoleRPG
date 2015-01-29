#pragma once
class CBase
{
public :
	typedef unsigned int u32;
	typedef char		 s8;
	typedef int			 s32;
	typedef float		 f32;
	typedef bool		 b1;
	virtual void Display();
public:
	CBase();
	virtual ~CBase();
};

