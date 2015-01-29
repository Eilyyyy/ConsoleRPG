#pragma once
#include "Base.h"
class CMaze :
	public CBase
{
	friend class CRole;
public :
	//显示迷宫
	void Display();
public:
	~CMaze();CMaze();
private :
	
	//创建迷宫
	CMaze* CreateMaze();
	static const u32 m_uiCX = 50;//迷宫长度
	static const u32 m_uiCY = 35;//迷宫宽度
	static const u32 m_uiXBlock = 20;//每屏显示的X方向块数
	static const u32 m_uiYBlock = 15;//每屏显示的Y方向块数
	static const u32 CY = m_uiCX * 3 + 1;
	static const u32 CX = m_uiCY + 1;
	u32 map[m_uiCX][m_uiCY];
	s8 m_ppMA[CX][CY];
	static CMaze *maze;//唯一迷宫实例
	//检查给定点是否在迷宫范围内
	bool CheckBoundary(u32 x, u32 y);
	//检查给定点是否可以合法通过, 可内联
	bool CheckThrough(u32 x, u32 y);
	//
	void InitMaze();
	void InitMap();
	struct SP
	{
		u32 x;
		u32 y;
		b1 flage;
		b1 pass;
		SP() :flage(false), pass(false), x(0), y(0)
		{}
		
	};
	SP mz[m_uiCX][m_uiCY];
	bool CheckSround(int x, int y)
	{
		if (CheckBoundary(x - 1, y))
		if (mz[x - 1][y].flage)
			return true;
		if (CheckBoundary(x + 1, y))
		if (mz[x + 1][y].flage)
			return true;
		if (CheckBoundary(x, y - 1))
		if (mz[x][y - 1].flage)
			return true;
		if (CheckBoundary(x, y + 1))
		if (mz[x][y + 1].flage)
			return true;
		return false;
	}
};

