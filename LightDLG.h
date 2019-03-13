#pragma once
#pragma warning(disable:4996)

#include "AddRoomsDLG.h"
#include "CivSup.h"
#include "afxwin.h"
#include <fstream>
#include "preOutput.h"
#include "afxeditbrowsectrl.h"
#include <iostream>

using namespace std;

// CLightDLG �Ի���

class CLightDLG : public CDialogEx
{
	DECLARE_DYNAMIC(CLightDLG)

public:
	CLightDLG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLightDLG();

	void setcurUser(CivSup);

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Light };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedaddrooms();
public:
	CAddRoomsDLG *m_cAR;
private:
	CivSup curUser;
public:
	CListBox m_cSD;
	CListBox m_cSR;
	afx_msg void OnBnClickedUpdate();
	afx_msg void OnBnClickedclearrooms();
	//afx_msg void OnBnClickedButton3();
	CMFCEditBrowseCtrl m_Path;
	afx_msg void OnBnClickedExcel();
};
