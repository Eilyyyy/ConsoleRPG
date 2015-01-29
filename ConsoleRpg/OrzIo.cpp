#include "stdafx.h"
#include "OrzIo.h"

const CSave::handle CSave::fun[13] =
{ 
	&CSave::SetHP, &CSave::SetMP, &CSave::SetEXP, &CSave::SetLeval, &CSave::SetName,
	&CSave::SetLowMag, &CSave::SetLowPhy, &CSave::SetUpMag, &CSave::SetUpPhy,
	&CSave::SetDead, &CSave::SetMiss, &CSave::SetX, &CSave::SetY
};

void CSave::SetValue(handle filed, s8 *value)
{
	(this->*filed)(value);
}
CSave::handle CSave::GetById(const s32 id)
{
	return fun[id % 13];
}

COrzIo::COrzIo()
{
	m_pfOrzFile = NULL;
}


COrzIo::~COrzIo()
{
	if (m_pfOrzFile != NULL)
	{
		fclose(m_pfOrzFile);
		m_pfOrzFile = NULL;
	}
	
}

int COrzIo::OrzSaveFile(const int fileType)
{
	fseek(m_pfOrzFile, 0, SEEK_SET);
	if (fileType == 0x0001)
	{
		return	OrzSaveINI();
	}
	else
	{
		return OrzSaveMAP();
	}
	return -2;
}
int COrzIo::OrzOpenFile(const s8 *fileName, const s8* mode)
{
	if (fileName == NULL)
	{
		return 0;
	}
	//若已经有打开的文件则先关闭当前文件
	if (m_pfOrzFile != NULL)
	{
		fclose(m_pfOrzFile);
	}
	return fopen_s(&m_pfOrzFile, fileName, mode);
}
int COrzIo::OrzReadFile(const int fileType)
{
	if (fileType == 0x0001)
	{
		return	OrzReadINI();
	}
	else
	{
		return OrzReadMap();
	}
	return -2;
}
int COrzIo::OrzReadINI()
{
	int count = 0; int i = 0;
	while (count != EOF && i < 13)
	{
		s8 buffer[32] = { '\0' };
		s8 value[16] = {'\0'};
		count = fscanf_s(m_pfOrzFile, "[%s]", buffer, _countof(buffer));
		count = fscanf_s(m_pfOrzFile, " = ");
		count = fscanf_s(m_pfOrzFile, "%s", value, _countof(value));
		save.SetValue(save.GetById(i++), value);
		while (count != EOF && fgetc(m_pfOrzFile) != '\n')
			;
	}
	return 1;
}
int COrzIo::OrzSaveINI()
{
	fprintf_s(m_pfOrzFile, "[hp] = %d\n", save.m_uiHP);
	fprintf_s(m_pfOrzFile, "[mp] = %d\n", save.m_uiMP);
	fprintf_s(m_pfOrzFile, "[exp] = %d\n", save.m_uiEXP);
	fprintf_s(m_pfOrzFile, "[leval] = %d\n", save.m_uiLeval);
	fprintf_s(m_pfOrzFile, "[name] = %s\n", save.m_lpszName);
	fprintf_s(m_pfOrzFile, "[lowMagic] = %d\n", save.m_uiLowerMagicAttack);
	fprintf_s(m_pfOrzFile, "[lowPhyc] = %d\n", save.m_uiLowerPhysicsAttack);
	fprintf_s(m_pfOrzFile, "[upMagic] = %d\n", save.m_uiUpperMagicAttack);
	fprintf_s(m_pfOrzFile, "[upPhyc] = %d\n", save.m_uiUpperPhysicsAttack);
	fprintf_s(m_pfOrzFile, "[dead] = %f\n", save.m_fDeadlyRate);
	fprintf_s(m_pfOrzFile, "[miss] = %f\n", save.m_fMissRate);
	fprintf_s(m_pfOrzFile, "[x] = %d\n", save.m_uiX);
	fprintf_s(m_pfOrzFile, "[y] = %d\n", save.m_uiY);
	return 1;
}
int COrzIo::OrzReadMap()
{
	return 1;
}
int COrzIo::OrzSaveMAP()
{
	return 1;
}
int COrzIo::OrzCloseFile()
{
	if (m_pfOrzFile != NULL)
	{
		fclose(m_pfOrzFile);
		m_pfOrzFile = NULL;
	}
	return 1;
}
//CSave::handle CSave::GetFloatByName(const int name)
//{
//	return 
//}