#pragma once
#include "CivSup.h"
#include "AddThingDLG.h"
#include "afxwin.h"
#include <cmath>
#include <cstring>
#define ie(i,s,t) for(int i=s;i<=t;++i)
#define de(i,s,t) for(int i=s;i>=t;--i)

using namespace std;


// CBuyListDLG 对话框

class CBuyListDLG : public CDialogEx
{
	DECLARE_DYNAMIC(CBuyListDLG)

public:
	CBuyListDLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBuyListDLG();

	void setUser(CivSup);

	CivSup getUser();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

private:
	CivSup curUser;
	CAddThingDLG *m_cAT;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddthing();
	afx_msg void OnBnClickedButton2();
	CListBox m_SN;
	CListBox m_SC;
	afx_msg void OnBnClickedCalculate();
	CEdit m_Money;
	afx_msg void OnLbnDblclkShowname();
	afx_msg void OnLbnDblclkShowvalue();
};
