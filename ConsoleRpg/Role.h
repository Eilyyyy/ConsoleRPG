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
	u32 m_uiHP;							//��ɫ����ֵ
	u32 m_uiMP;							//��ɫħ��ֵ
	u32 m_uiEXP;						//��ɫ����ֵ
	u32 m_uiLeval;						//��ɫ�ȼ�
	s8 *m_lpszName;						//��ɫ����

	u32 m_uiLowerMagicAttack;			//��Сħ��������
	u32 m_uiLowerPhysicsAttack;			//�����������
	u32 m_uiUpperMagicAttack;			//���ħ��������
	u32 m_uiUpperPhysicsAttack;			//�����������
	f32 m_fDeadlyRate;					//����һ����
	f32 m_fMissRate;					//������

	u32 m_uiState;						//��ɫ��ǰ״̬
	u32 m_uiAction;						//��ɫ��ǰ�ж�
	u32 m_uiX;							//��ǰ����
	u32 m_uiY;							//��ǰ����

	u32 m_uiSpeed;						//�ƶ��ٶ�
	Skill **m_sSkills;					//��ɫ����
	CGoods **m_cPakage;					//����
	u32 m_uiPakageSize;					//������С
	u32 m_uiSkillNum;
public:
	//��ʾ��ɫ
	void Display();
	//�ƶ���ɫ
	virtual void Move(s32 cx, s32 cy);
	//����, �����˺�ֵ
	virtual f32 Attrack();
	//����, ����һ�����������Ϊ����
	virtual void ReceiveTask(CTask &task) = 0;
	CRole();
	virtual ~CRole();
private :
	const u32 ROLE_SKILL_NUM = 5;
	static const u32 ROLE_STATE_FLIGHTING = 0x0001;			//ս����
	static const u32 ROLE_STATE_UNFLIGHT = 0x0002;			//��ս����
	static const u32 ROLE_ACTION_NORMAL = 0x0004;			//��ͨ����
	static const u32 ROLE_ACTION_DEADLY_STRIKE = 0x0008;	//����һ��
	static const u32 ROLE_ACTION_MISSING_ATTACK = 0x0010;	//����
};

