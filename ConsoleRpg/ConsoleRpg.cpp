// ConsoleRPG.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, char* argv[])
{
	COrzIo orz;
	orz.OrzOpenFile("config.ini", "r");
	orz.OrzReadFile(COrzIo::ORZFILETYPE_INI);
	orz.OrzCloseFile();
	orz.OrzOpenFile("save.ini", "w");
	orz.OrzSaveFile(COrzIo::ORZFILETYPE_INI);
	return 0;
}

