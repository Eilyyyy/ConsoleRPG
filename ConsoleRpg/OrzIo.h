#pragma once
#include"Base.h"

struct CSave : public CBase
{
#define SV_HP		0x0000;
#define SV_MP		0x0001;
#define SV_EXP		0x0002;
#define SV_LEVAL	0x0003;
#define SV_NAME		0x0004;
#define SV_LOWMAG	0x0005;
#define SV_LOWPHY	0x0006;
#define SV_UPMAG	0x0007;
#define SV_UPPHY	0x0008;
#define SV_DEAD		0x0009;
#define SV_MISS		0x0010;
#define SV_X		0x0011;
#define SV_Y		0x0012;

	u32 m_uiHP;							//角色生命值
	u32 m_uiMP;							//角色魔法值
	u32 m_uiEXP;						//橘色经验值
	u32 m_uiLeval;						//角色等级
	s8 m_lpszName[16];						//橘色名字

	u32 m_uiLowerMagicAttack;			//最小魔法攻击力
	u32 m_uiLowerPhysicsAttack;			//最大物理攻击力
	u32 m_uiUpperMagicAttack;			//最大魔法攻击力
	u32 m_uiUpperPhysicsAttack;			//最大物理攻击力
	f32 m_fDeadlyRate;					//致命一击率
	f32 m_fMissRate;					//滑过率

	u32 m_uiX;							//当前坐标
	u32 m_uiY;							//当前坐标

	void SetHP(s8 *hp){ u32 t = atoi(hp); m_uiHP = t; }
	void SetMP(s8 *mp){ u32 t = atoi(mp); m_uiMP = t; }
	void SetEXP(s8 *exp){ u32 t = atoi(exp); m_uiEXP = t; }
	void SetLeval(s8 *leval){ u32 t = atoi(leval); m_uiLeval = t; }
	void SetName(s8 *name){ strcpy_s(m_lpszName, 16, name); }
	void SetLowMag(s8 *lma){ u32 t = atoi(lma); m_uiLowerMagicAttack = t; }
	void SetLowPhy(s8 *lpa){ u32 t = atoi(lpa); m_uiLowerPhysicsAttack = t; }
	void SetUpMag(s8 *uma){ u32 t = atoi(uma); m_uiUpperMagicAttack = t; }
	void SetUpPhy(s8 *upa){ u32 t = atoi(upa); m_uiUpperPhysicsAttack = t; }
	void SetDead(s8* dead){ f32 t = atof(dead); m_fDeadlyRate = t; }
	void SetMiss(s8 * miss){ f32 t = atof(miss); m_fMissRate = t; }
	void SetX(s8 * x){ u32 t = atoi(x); m_uiX = t; }
	void SetY(s8 * y){ u32 t = atoi(y); m_uiY = t; }

	typedef void(CSave::*handle)(s8 *);
	
	/*int SetString(const s8* value, const handle filed);
	int SetUnsigedInt(const unsigned int value, const handle filed);
	int SetFloat(const float value, const handle filed);
	
	handle GetIntByName(const s32 name);
	handle GetFloatByName(const s32 name);
	handle GetStringByName(const s32 name);*/
	void SetValue(handle filed, s8 *value);
	handle GetById(const s32 id);

private :
	static const handle fun[13];
};
class COrzIo : public CBase
{
public :
	FILE *m_pfOrzFile;
	static const int ORZFILETYPE_INI = 0x0001;
	static const int ORZFILETYPE_MAP = 0x0002;
public:
	//打开文件, 保存在file指针中, 返回是否成功
	int OrzOpenFile(const s8 *fileName, const s8* mode);
	//读取文件
	int OrzReadFile(const int fileType);
	//关闭文件
	int OrzCloseFile();
	//保存文件
	int OrzSaveFile(const int fileType);
	COrzIo();
	~COrzIo();
private :
	int OrzReadINI();
	int OrzReadMap();
	int OrzSaveINI();
	int OrzSaveMAP();
	CSave save;
};

