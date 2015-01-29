#pragma once
#include "Base.h"
class CMaze :
	public CBase
{
	friend class CRole;
public :
	//��ʾ�Թ�
	void Display();
public:
	~CMaze();CMaze();
private :
	
	//�����Թ�
	CMaze* CreateMaze();
	static const u32 m_uiCX = 50;//�Թ�����
	static const u32 m_uiCY = 35;//�Թ����
	static const u32 m_uiXBlock = 20;//ÿ����ʾ��X�������
	static const u32 m_uiYBlock = 15;//ÿ����ʾ��Y�������
	static const u32 CY = m_uiCX * 3 + 1;
	static const u32 CX = m_uiCY + 1;
	u32 map[m_uiCX][m_uiCY];
	s8 m_ppMA[CX][CY];
	static CMaze *maze;//Ψһ�Թ�ʵ��
	//���������Ƿ����Թ���Χ��
	bool CheckBoundary(u32 x, u32 y);
	//���������Ƿ���ԺϷ�ͨ��, ������
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

