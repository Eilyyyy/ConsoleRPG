#pragma once
#include "Base.h"
class CGoods :
	public CBase
{
public :
	s8 *m_lpszName;					//����
	u32 m_uiID;						//ID, Ψһ��ʾ
	u32 m_uiPrice;					//��Ʒ�ۼ�
	b1 m_bCouldUse;					//�Ƿ��ʹ��
	b1 m_bCouldWear;				//�Ƿ��װ��
	u32 m_uiUseLeval;				//ʹ�õȼ�
	b1 m_bCouldTrade;				//�Ƿ�ɽ���

	static CGoods *m_scGoodList;	//��Ʒ�б�
public:
	CGoods();
	virtual ~CGoods();
};

