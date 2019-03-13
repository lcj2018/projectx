// UserRegisterDLG.cpp : 实现文件
//

#include "stdafx.h"
#include "Project X Beta.h"
#include "UserRegisterDLG.h"
#include "afxdialogex.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "CivSup.h"
#include <cstdlib>
#include <tchar.h>
#include "preOutput.h"
#define ie(i,s,t) for(int i=s;i<=t;++i)

using namespace std;

// CUserRegisterDLG 对话框

IMPLEMENT_DYNAMIC(CUserRegisterDLG, CDialogEx)

CUserRegisterDLG::CUserRegisterDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_REGISTERDLG, pParent)
{

}

CUserRegisterDLG::~CUserRegisterDLG()
{
}

void CUserRegisterDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN1, pSpin);
	DDX_Control(pDX, IDC_EDIT1, m_Class);
	DDX_Control(pDX, IDC_EDIT2, m_Floor);
	DDX_Control(pDX, IDC_URName, m_Name);
	DDX_Control(pDX, IDC_URStuNum, m_StuNum);
	DDX_Control(pDX, IDC_URInstitute, m_Institute);
	DDX_Control(pDX, IDC_URProfess, m_Profess);
	DDX_Control(pDX, IDC_URPhone, m_Phone);
	DDX_Control(pDX, IDC_URBuild, m_Building);
	DDX_Control(pDX, IDC_URPASSWORD1, m_Password1);
	DDX_Control(pDX, IDC_URPassword2, m_Password2);
	DDX_Control(pDX, IDC_URQuestion, m_Question);
	DDX_Control(pDX, IDC_URAnswer, m_Answer);
}


BEGIN_MESSAGE_MAP(CUserRegisterDLG, CDialogEx)
	ON_WM_CLOSE()
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDOK, &CUserRegisterDLG::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CUserRegisterDLG::OnBnClickedCancel)
END_MESSAGE_MAP()


// CUserRegisterDLG 消息处理程序
BOOL CUserRegisterDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();//*
    SetIcon(m_hIcon, TRUE);	//*
	SetIcon(m_hIcon, FALSE);//*	
	CSpinButtonCtrl *pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN1);//*
	pSpin->SetRange(0, 100);//*
	pSpin->SetPos(0);//*
	CString strValue;//*
	strValue.Format(L"%d", 1);//*
	pSpin->GetBuddy()->SetWindowText(strValue);//*
	CSpinButtonCtrl *pSpin2 = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN2);//*
	pSpin2->SetRange(0, 100);//*
	pSpin2->SetPos(0);//*
	CString strValue2;//*
	strValue2.Format(L"%d", 1);//*
	pSpin2->GetBuddy()->SetWindowText(strValue2);//*
	return TRUE;//*
}

void CUserRegisterDLG::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialogEx::OnClose();
}


void CUserRegisterDLG::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pScrollBar->GetDlgCtrlID() == IDC_SPIN1)//*
	{
		CString strValue;//*
		strValue.Format(L"%d", nPos);//*
		((CSpinButtonCtrl *)pScrollBar)->GetBuddy()->SetWindowText(strValue);//*
	}
	if (pScrollBar->GetDlgCtrlID() == IDC_SPIN2)//*
	{
		CString strValue;//*
		strValue.Format(L"%d", nPos);//*
		((CSpinButtonCtrl *)pScrollBar)->GetBuddy()->SetWindowText(strValue);//*
	}
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CUserRegisterDLG::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tmp1;
	m_Password1.GetWindowText(tmp1);
	CString tmp2;
	m_Password2.GetWindowText(tmp2);
	if (tmp1 != tmp2)
	{
		MessageBox(_T("两次密码不相同！\n请重新输入！"), _T("警告"));
		return;
	}
	ifstream tmpFile("User.dat", ios::in | ios::binary);
	fstream inOutCredit("User.dat",ios::in | ios::out | ios::binary);
	//if (!inOutCredit)MessageBox(_T("!o"),_T("警告")); else MessageBox(_T("o"),_T("警告"));
	if (!inOutCredit)
	{
		MessageBox(_T("创建文件失败！请稍候重试！"), _T("警告"));
		return;
	}
	LPTSTR pWhite = new TCHAR[20];
	_stprintf_s(pWhite, 20, _T("%s"), _T(""));
	if (!tmpFile)
	{
		tmpFile.close();
		CivSup tperson(pWhite, 0, pWhite, pWhite, 0, 0, pWhite, 0, pWhite, pWhite);
		inOutCredit.seekp(0);
		inOutCredit.write(reinterpret_cast<const char *>(&tperson), sizeof(CivSup));
	}
	tmpFile.close();
	CString tmp;
	m_Class.GetWindowText(tmp);
	int Class = _tcstoul(tmp, NULL, 10);
	//Class
	m_Floor.GetWindowText(tmp);
	int Floor = _tcstoul(tmp, NULL, 10);
	//Floor
	m_StuNum.GetWindowText(tmp);
	LL StuNum;
	swscanf_s(tmp, _T("%lld"), &StuNum);
	//LL StuNum = _tcstoul(tmp, NULL, 10);
	//StudentNum
	m_Phone.GetWindowText(tmp);
	LL Phone;
	swscanf_s(tmp, _T("%lld"), &Phone);
	//Phone
	m_Name.GetWindowText(tmp);
	LPTSTR pName = new TCHAR[20];
	_stprintf_s(pName, 20, _T("%s"), tmp);
	//Name
	m_Institute.GetWindowText(tmp);
	LPTSTR pInstitute = new TCHAR[20];
	_stprintf_s(pInstitute, 20, _T("%s"), tmp);
	//Institute
	m_Profess.GetWindowText(tmp);
	LPTSTR pProfess = new TCHAR[20];
	_stprintf_s(pProfess, 20, _T("%s"), tmp);
	//Profess
	m_Building.GetWindowText(tmp);
	LPTSTR pBuilding = new TCHAR[20];
	_stprintf_s(pBuilding, 20, _T("%s"), tmp);
	//Building
	m_Question.GetWindowText(tmp);
	LPTSTR pQuestion = new TCHAR[20];
	_stprintf_s(pQuestion, 20, _T("%s"), tmp);
	//Question
	m_Answer.GetWindowText(tmp);
	LPTSTR pAnswer = new TCHAR[20];
	_stprintf_s(pAnswer, 20, _T("%s"), tmp);
	//Answer
	int cnt = getCnt()+1;
	CivSup tmpUser(pWhite, cnt, pWhite, pWhite, 0, 0, pWhite, 0, pWhite, pWhite);
	CivSup CSuser(pName, StuNum, pInstitute, pProfess, Class, Phone, pBuilding, Floor, pQuestion, pAnswer);
	//New User
	m_Password1.GetWindowText(tmp);
	//LPTSTR pPassword = new TCHAR[20];
	//_stprintf_s(pPassword, 20, _T("%s"), tmp);
	CSuser.SetPassword(0, tmp.GetLength());
	ie(i, 0, tmp.GetLength() - 1)
	{
		if (tmp[i] == '\0')break;
		CSuser.SetPassword(i + 1, getFib(tmp[i], i % 2));
	}
	//Password
	inOutCredit.seekp(0);
	inOutCredit.write(reinterpret_cast<const char*>(&tmpUser), sizeof(CivSup));
	inOutCredit.seekp(cnt*sizeof(CivSup));
	inOutCredit.write(reinterpret_cast<const char *>(&CSuser), sizeof(CivSup));
	inOutCredit.close();
	CDialogEx::OnOK();
}


void CUserRegisterDLG::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
