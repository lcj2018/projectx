#pragma once

#include "CivSup.h"
#include "afxwin.h"
#include "LightDLG.h"
#include "Project X BetaDlg.h"
#include "ChangeInfoDLG.h"
#include "ShoesDLG.h"
#include "BuyListDLG.h"

// CIndexDLG �Ի���

class CIndexDLG : public CDialogEx
{
	DECLARE_DYNAMIC(CIndexDLG)

public:
	CIndexDLG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CIndexDLG();

	void setcurUser(CivSup);

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Index };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLight();
	//void setFD(CProjectXBetaDlg *);
	//CProjectXBetaDlg *getFD();

private:
	CivSup curUser;
public:
	CEdit m_cShowUser;
	CLightDLG *m_cLD;
	CChangeInfoDLG *m_cCI;
	CShoesDLG *m_cSH;
	CBuyListDLG *m_cBL;
	//CProjectXBetaDlg *m_cFaDlg;
	//CProjectXBetaDlg *m_cFD;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedChangeinfo();
	afx_msg void OnBnClickedShoes();
	afx_msg void OnBnClickedShop();
};
