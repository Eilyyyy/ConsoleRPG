#include "stdafx.h"
#include "Control.h"

CControl *CControl::control = NULL;

CControl* CControl::GetControl()
{
	if (control == NULL)
	{
		control = new CControl();
	}
	return control;
}
CControl::CControl()
{
	//TODO
	
}


CControl::~CControl()
{
}
