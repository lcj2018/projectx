#pragma once
#include "afxwin.h"
#include "Fibonacci.h"


// CPWForgot �Ի���

class CPWForgot : public CDialogEx
{
	DECLARE_DYNAMIC(CPWForgot)

public:
	CPWForgot(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPWForgot();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PWFORGOT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
