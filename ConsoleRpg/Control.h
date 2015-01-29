#pragma once

#include"Goods.h"
#include"Maze.h"
#include"Mission.h"
#include"Role.h"
#include"Skill.h"
#include"Task.h"
class CControl
{
	static CControl *control;
	CControl* GetControl();
	CMaze *maze;
	CRole *player;
	CRole *monster[10];
	bool GeneratTask(); //����һ����������ҽ���, ʧ�ܷ���FALSE
public:
	CControl();
	~CControl();
};

