#include "stdafx.h"
#include "MaxSkills.h"
#include "MaxSkillsDlg.h"

CMaxSkillsApp theApp;

CMaxSkillsApp::CMaxSkillsApp()
{
}

BOOL CMaxSkillsApp::InitInstance()
{
	Enable3dControls();
	CMaxSkillsDlg().DoModal();
	return FALSE;
}
