
// Project X BetaDlg.h : ͷ�ļ�
//

#pragma once

#include "UserRegisterDLG.h"
#include "afxwin.h"
#include "PWForgotDLG.h"
#include "IndexDLG.h"
#include "About.h"

// CProjectXBetaDlg �Ի���
class CProjectXBetaDlg : public CDialogEx
{
// ����
public:
	CProjectXBetaDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECTXBETA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
