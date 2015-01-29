#pragma once
#include "Base.h"
class CRole :
	public CBase
{
	struct Skill;
	class CGoods;
	class CTask;
	/*friend bool CMaze::CheckBoundary(u32 x, u32 y);
	friend bool CMaze::CheckThrough(u32 x, u32 y);*/
public :
	u32 m_uiHP;							//角色生命值
	u32 m_uiMP;							//角色魔法值
	u32 m_uiEXP;						//橘色经验值
	u32 m_uiLeval;						//角色等级
	s8 *m_lpszName;						//橘色名字

	u32 m_uiLowerMagicAttack;			//最小魔法攻击力
	u32 m_uiLowerPhysicsAttack;			//最大物理攻击力
	u32 m_uiUpperMagicAttack;			//最大魔法攻击力
	u32 m_uiUpperPhysicsAttack;			//最大物理攻击力
	f32 m_fDeadlyRate;					//致命一击率
	f32 m_fMissRate;					//滑过率

	u32 m_uiState;						//角色当前状态
	u32 m_uiAction;						//橘色当前行动
	u32 m_uiX;							//当前坐标
	u32 m_uiY;							//当前坐标

	u32 m_uiSpeed;						//移动速度
	Skill **m_sSkills;					//橘色技能
	CGoods **m_cPakage;					//背包
	u32 m_uiPakageSize;					//背包大小
	u32 m_uiSkillNum;
public:
	//显示角色
	void Display();
	//移动橘色
	virtual void Move(s32 cx, s32 cy);
	//攻击, 返回伤害值
	virtual f32 Attrack();
	//任务, 接受一个任务对象作为参数
	virtual void ReceiveTask(CTask &task) = 0;
	CRole();
	virtual ~CRole();
private :
	const u32 ROLE_SKILL_NUM = 5;
	static const u32 ROLE_STATE_FLIGHTING = 0x0001;			//战斗中
	static const u32 ROLE_STATE_UNFLIGHT = 0x0002;			//非战斗中
	static const u32 ROLE_ACTION_NORMAL = 0x0004;			//普通攻击
	static const u32 ROLE_ACTION_DEADLY_STRIKE = 0x0008;	//致命一击
	static const u32 ROLE_ACTION_MISSING_ATTACK = 0x0010;	//滑过
};

