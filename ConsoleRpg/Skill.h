#pragma once
#include "Base.h"
struct Skill :
	public CBase
{
	s8 *m_lpszSkill;				//��������
	u32 m_uiPhyAck;					//��������
	u32 m_uiMagicAck;				//ħ��������
	u32 special = 0xffff;			//����, ������������
	u32 m_uiCD;						//ID���
	u32 m_uiConsumeMP;				//MP����
	u32 m_uiConsumeHP;				//HP����
	f32 m_fHarmRadius;				//���ܷ�Χ
	u32 m_uiLimit;					//��������

	//TODO...
	void Display();
	Skill();
	~Skill();
};

