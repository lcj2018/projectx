#pragma once
#include "CivSup.h"
#include "afxwin.h"
#include "preOutput.h"
#include <fstream>

using namespace std;
// CAddThingDLG �Ի���

class CAddThingDLG : public CDialogEx
{
	DECLARE_DYNAMIC(CAddThingDLG)

public:
	CAddThingDLG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddThingDLG();

	void setUser(CivSup);

	CivSup getUser();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDTHING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CivSup curUser;
public:
	afx_msg void OnBnClickedOk();
	CEdit m_Name;
	CEdit m_Times;
	CEdit m_Time;
	CEdit m_Cost;
};
