#pragma once
#include "Base.h"
class CTask :
	public CBase
{
public :
	s8 *m_lpszTaskInfo;					//������Ϣ
	u32 m_uiTaskReward;					//������
	u32 m_uiTaskSchedule;				//����
	u32 m_uiTaskType;					//����
	b1 m_bIsComplete;					//�Ƿ����
	u32 m_uiID;
	
public:
	//����һ������
	virtual void GetTask(CTask& task) = 0;
	//����, ���������Ϣ
	//void Display();
	CTask();
	virtual ~CTask();
private :
	static CTask* m_cpTaskList;
	static const u32 TASK_TYPE_COLLECT = 0x0001;
	static const u32 TASK_TYPE_KILLMONSTER = 0x0002;
	static const u32 TASK_TYPE_ARRIVEWHERE = 0x0004;
};

