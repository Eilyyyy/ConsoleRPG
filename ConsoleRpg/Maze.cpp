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
	深度优先算法的核心是（翻译的维基）：
	1、将起点作为当前格并标记
	2、当还存在未标记的格时
	——1、如果当前格有未标记的邻格
	————1、随机选择一个未标记的邻格
	————2、将当前格入栈
	————3、移除当前格与邻格的墙
	————4、标记邻格并用它作为当前格
	——2、反之，如果栈不空
	————1、栈顶的格子出栈
	————2、令其成为当前格
	——3、反之，随机选择一个格子为当前格并标记
	*/
	std::stack<CMaze::SP> spstack;
	CMaze::SP tsp;
	//随机生成方向
	int d = rand() % 2;
	int x, y;
	while (CheckSround(tsp.x, tsp.y))
	{
		//当前哥入栈
		spstack.push(tsp);
		//随机选择一个未标记的林哥
		
		if (d)
		{
			//X方向
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
			//y方向
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
	//清屏
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