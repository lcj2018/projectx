#pragma once
#include "afxwin.h"
#include <fstream>
#include "preOutput.h"
#include "Fibonacci.h"
#define LL long long


// CChangeInfoDLG 对话框

class CChangeInfoDLG : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeInfoDLG)

public:
	CChangeInfoDLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChangeInfoDLG();
	
	void setStu(LL);

	LL getStu();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGEINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Name;
	CEdit m_StuNum;
	CEdit m_Institute;
	CEdit m_Profess;
	CEdit m_Class;
	CEdit m_Phone;
	CEdit m_Building;
	CEdit m_Floor;
	CEdit m_Password1;
	CEdit m_Password2;
	CEdit m_Question;
	CEdit m_Answer;
	LL curStu;
	afx_msg void OnBnClickedOk();
};
