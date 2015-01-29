#include "stdafx.h"
#include "Maze.h"
#include<stack>
CMaze *CMaze::maze = NULL;
CMaze::CMaze()
{
	CreateMaze();
}

CMaze* CMaze::CreateMaze()
{
	InitMap();
	maze = this;
	return maze;
}

void CMaze::InitMaze()
{
	/*
	��������㷨�ĺ����ǣ������ά������
	1���������Ϊ��ǰ�񲢱��
	2����������δ��ǵĸ�ʱ
	����1�������ǰ����δ��ǵ��ڸ�
	��������1�����ѡ��һ��δ��ǵ��ڸ�
	��������2������ǰ����ջ
	��������3���Ƴ���ǰ�����ڸ��ǽ
	��������4������ڸ�������Ϊ��ǰ��
	����2����֮�����ջ����
	��������1��ջ���ĸ��ӳ�ջ
	��������2�������Ϊ��ǰ��
	����3����֮�����ѡ��һ������Ϊ��ǰ�񲢱��
	*/
	std::stack<CMaze::SP> spstack;
	CMaze::SP tsp;
	//������ɷ���
	int d = rand() % 2;
	int x, y;
	while (CheckSround(tsp.x, tsp.y))
	{
		//��ǰ����ջ
		spstack.push(tsp);
		//���ѡ��һ��δ��ǵ��ָ�
		
		if (d)
		{
			//X����
			if (rand() % 2)
			{
				if (CheckBoundary(tsp.x + x, tsp.y))
				{
					x = 1;
				}
			}
			else
			{
				if (CheckBoundary(tsp.x + x, tsp.y))
				{
					x = -1;
				}
			}
			y = 0;
		}
		else
		{
			//y����
			if (rand() % 2)
			{
				if (CheckBoundary(tsp.x, tsp.y + y))
				{
					y = 1;
				}
			}
			else
			{
				if (CheckBoundary(tsp.x, tsp.y + y))
				{
					y = -1;
				}
			}
			x = 0;
		}	
	}//end while (!tsp.isFlage())
	tsp.x += x;
	tsp.y += y;

}

CMaze::~CMaze()
{
}

void CMaze::InitMap()
{
	/*
	   __ __ __ __ __
	  |__ __|__|__|__|
	  |__|__|@_|__|__|
	  |__|__|__| _|__|
	  |__|__|__|__|__|
	  
	  */
	for (size_t i = 0; i < CY; i++)
	{
		if (i % 3 == 0)
		{
			m_ppMA[0][i] = ' ';
		}
		else
		{
			m_ppMA[0][i] = '_';
		}
		
		/*m_ppMA[m_uiCY][i] = '_';
		m_ppMA[i][0] = '|';*/

	}
	for (size_t i = 1; i < CX; i++)
	{
		for (size_t j = 0; j < CY; j++)
		{
			if (j % 3 == 0)
			{
				m_ppMA[i][j] = '|';
			}
			else
			{
				m_ppMA[i][j] = '_';
			}
		}
	}
	InitMaze();
}

void CMaze::Display()
{
	//����
	system("cls");
	
	for (size_t i = 0; i < m_uiYBlock + 1; i++)
	{
		for (size_t j = 0; j < m_uiXBlock * 3 + 1; j++)
		{
			std::cout << m_ppMA[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool CMaze::CheckBoundary(u32 x, u32 y)
{
	if (x <= 0 || x >= m_uiCX - 1 || y <= 0 || y >= m_uiCY - 1)
	{
		return false;
	}
	return true;
}
inline
	bool CMaze::CheckThrough(u32 x, u32 y)
{
	if (map[x][y])
	{
		return true;
	}
	return false;
}