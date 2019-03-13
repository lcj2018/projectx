#pragma once
#pragma warning(disable:4996)
#include "afxwin.h"
#include <vector>
#include "CivSup.h"
#include <string>
#include <iostream>

using namespace std;


// CShoesDLG �Ի���

class CShoesDLG : public CDialogEx
{
	DECLARE_DYNAMIC(CShoesDLG)

public:
	CShoesDLG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CShoesDLG();

	vector<CString> getRoom(CString);

	void setUser(CivSup);

	CivSup getUser();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOES };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_cSR;
	afx_msg void OnBnClickedOk();
	CivSup curUser;
};
