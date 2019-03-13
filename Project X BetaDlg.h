
// Project X BetaDlg.h : 头文件
//

#pragma once

#include "UserRegisterDLG.h"
#include "afxwin.h"
#include "PWForgotDLG.h"
#include "IndexDLG.h"
#include "About.h"

// CProjectXBetaDlg 对话框
class CProjectXBetaDlg : public CDialogEx
{
// 构造
public:
	CProjectXBetaDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECTXBETA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedQuit();//*
	afx_msg void OnStnClickedRegister();//*
	afx_msg void OnEnChangeUsername();//*
	afx_msg void OnStnClickedPwforgot();//*
	CUserRegisterDLG *m_cUR;//*
	CPWForgot *m_cPF;//*
	CIndexDLG *m_cIndex;
	afx_msg void OnBnClickedLogin();//*
	CEdit m_Lger;
	CEdit m_Lgpass;
	CAbout *m_cAbout;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnStnClickedAbout();
};
