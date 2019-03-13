#pragma once
#include "afxwin.h"
#include "Fibonacci.h"


// CPWForgot 对话框

class CPWForgot : public CDialogEx
{
	DECLARE_DYNAMIC(CPWForgot)

public:
	CPWForgot(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPWForgot();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PWFORGOT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_FGUser;//*
	CEdit m_Question2;
	CEdit m_Answer2;
	afx_msg void OnBnClickedSnok();
	CEdit m_NPW;
	CEdit m_NPW2;//*
	afx_msg void OnBnClickedOk();
};
