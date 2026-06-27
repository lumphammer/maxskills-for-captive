#if !defined(AFX_MAXSKILLSDLG_H__1794931D_0B23_470C_A025_A2A151EC2C6E__INCLUDED_)
#define AFX_MAXSKILLSDLG_H__1794931D_0B23_470C_A025_A2A151EC2C6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif

class CMaxSkillsDlg : public CDialog
{
public:
	CMaxSkillsDlg();

protected:
	afx_msg void OnButtonGenerate();
	DECLARE_MESSAGE_MAP()

private:
   void        GenerateName( char* pBuffer, int BufferSize );
   void        GetSkills( const char* Name, int& Dexterity, int& Vitality, int& Wisdom );
};

#endif // !defined(AFX_MAXSKILLSDLG_H__1794931D_0B23_470C_A025_A2A151EC2C6E__INCLUDED_)
