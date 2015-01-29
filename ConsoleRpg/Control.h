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
	bool GeneratTask(); //产生一个任务并让玩家接受, 失败返回FALSE
public:
	CControl();
	~CControl();
};

