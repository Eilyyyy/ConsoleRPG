#pragma once
#include "Base.h"
class CTask :
	public CBase
{
public :
	s8 *m_lpszTaskInfo;					//任务信息
	u32 m_uiTaskReward;					//任务奖励
	u32 m_uiTaskSchedule;				//进度
	u32 m_uiTaskType;					//类型
	b1 m_bIsComplete;					//是否完成
	u32 m_uiID;
	
public:
	//创建一个任务
	virtual void GetTask(CTask& task) = 0;
	//清屏, 输出任务信息
	//void Display();
	CTask();
	virtual ~CTask();
private :
	static CTask* m_cpTaskList;
	static const u32 TASK_TYPE_COLLECT = 0x0001;
	static const u32 TASK_TYPE_KILLMONSTER = 0x0002;
	static const u32 TASK_TYPE_ARRIVEWHERE = 0x0004;
};

