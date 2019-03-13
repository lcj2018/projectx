#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "Fibonacci.h"


// CUserRegisterDLG 对话框

class CUserRegisterDLG : public CDialogEx
{
	DECLARE_DYNAMIC(CUserRegisterDLG)

public:
	CUserRegisterDLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUserRegisterDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REGISTERDLG };
#endif

protected:
	HICON m_hIcon;//*
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();//*

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();//*
	CSpinButtonCtrl pSpin;
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CStatic m_ClassNum;
	afx_msg void OnBnClickedOk();
	CEdit m_Class;//*
	CEdit m_Floor;
	CEdit m_Name;
	CEdit m_StuNum;
	CEdit m_Institute;
	CEdit m_Profess;
	CEdit m_Phone;
	CEdit m_Building;
	CEdit m_Password1;
	CEdit m_Password2;
	CEdit m_Question;
	CEdit m_Answer;//*
	afx_msg void OnBnClickedCancel();
};
