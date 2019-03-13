#pragma once
#include "CivSup.h"
#include "afxwin.h"
#include "preOutput.h"
#include <fstream>

using namespace std;
// CAddThingDLG 对话框

class CAddThingDLG : public CDialogEx
{
	DECLARE_DYNAMIC(CAddThingDLG)

public:
	CAddThingDLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddThingDLG();

	void setUser(CivSup);

	CivSup getUser();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDTHING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
