#pragma once
#include "Base.h"
class CGoods :
	public CBase
{
public :
	s8 *m_lpszName;					//名称
	u32 m_uiID;						//ID, 唯一标示
	u32 m_uiPrice;					//物品售价
	b1 m_bCouldUse;					//是否可使用
	b1 m_bCouldWear;				//是否可装备
	u32 m_uiUseLeval;				//使用等级
	b1 m_bCouldTrade;				//是否可交易

	static CGoods *m_scGoodList;	//物品列表
public:
	CGoods();
	virtual ~CGoods();
};

