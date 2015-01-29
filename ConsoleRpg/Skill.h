#pragma once
#include "Base.h"
struct Skill :
	public CBase
{
	s8 *m_lpszSkill;				//技能名称
	u32 m_uiPhyAck;					//物理攻击力
	u32 m_uiMagicAck;				//魔法攻击力
	u32 special = 0xffff;			//保留, 增加特殊属性
	u32 m_uiCD;						//ID编号
	u32 m_uiConsumeMP;				//MP消耗
	u32 m_uiConsumeHP;				//HP消耗
	f32 m_fHarmRadius;				//技能范围
	u32 m_uiLimit;					//人数限制

	//TODO...
	void Display();
	Skill();
	~Skill();
};

