#include "stdafx.h"
#include "Role.h"
#include "Maze.h"


CRole::CRole():
m_uiHP(100), m_uiMP(30), m_uiEXP(0), m_uiLeval(0), 
m_lpszName("Orz"),
m_uiLowerMagicAttack(10), m_uiLowerPhysicsAttack(20), 
m_uiUpperMagicAttack(30), m_uiUpperPhysicsAttack(50),
m_fDeadlyRate(0.1f), m_fMissRate(0.3f), 
m_uiSpeed(300), m_uiState(ROLE_STATE_UNFLIGHT)
{
}


CRole::~CRole()
{
}


void CRole::Display()
{
	//将坐标透露给迷宫, 在迷宫中打印
}

void CRole::Move(s32 cx, s32 cy)
{
	u32 x, y;
	x = m_uiX + cx;
	y = m_uiY + cy;
	/*if (CMaze::maze->CheckBoundary(x, y))
	{
		if (CMaze::maze->CheckThrough(x, y))
		{
			m_uiX += cx;
			m_uiY += cy;
		}
	}*/
}

CBase::f32 CRole::Attrack()
{
	return 0.0f;
}