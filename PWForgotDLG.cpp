// PWForgot.cpp : 实现文件
//

#include "stdafx.h"
#include "Project X Beta.h"
#include "PWForgotDLG.h"
#include "afxdialogex.h"
#include <fstream>
#include "CivSup.h"
#include "preOutput.h"
#include <windows.h>
#define LL long long 

using namespace std;

// CPWForgot 对话框

IMPLEMENT_DYNAMIC(CPWForgot, CDialogEx)

CPWForgot::CPWForgot(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PWFORGOT, pParent)
{

}

CPWForgot::~CPWForgot()
{
}

void CPWForgot::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FGUser, m_FGUser);
	DDX_Control(pDX, IDC_Question2, m_Question2);
	DDX_Control(pDX, IDC_ANSWER2, m_Answer2);
	DDX_Control(pDX, IDC_NewPassword1, m_NPW);
	DDX_Control(pDX, IDC_NewPassword2, m_NPW2);
}


BEGIN_MESSAGE_MAP(CPWForgot, CDialogEx)
	ON_BN_CLICKED(IDC_SNOK, &CPWForgot::OnBnClickedSnok)
	ON_BN_CLICKED(IDOK, &CPWForgot::OnBnClickedOk)
END_MESSAGE_MAP()


// CPWForgot 消息处理程序


void CPWForgot::OnBnClickedSnok()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tmp;//*
	m_FGUser.GetWindowText(tmp);
	//LL sn = _tcstoul(tmp, NULL, 10);
	LL sn;
	swscanf_s(tmp, _T("%lld"), &sn);
	if (sn < 201300000000 || sn>202099999999)
	{
		MessageBox(_T("学号不正确!"), _T("警告"));
		return;
	}
	//sn=sn % 100000000000 - 1300000000;
	ifstream UDat("User.dat", ios::in | ios::binary);
	if (!UDat)
	{
		MessageBox(_T("不存在该用户！请先注册！"), _T("警告"));
		UDat.close();
		return;
	}
	UDat.close();
	if (getInfo(sn).GetStuNum() == 0)
	{
		MessageBox(_T("不存在该用户！请先注册！"), _T("警告"));
		return;
	}
	GetDlgItem(IDC_Question2)->EnableWindow(true);
	GetDlgItem(IDC_ANSWER2)->EnableWindow(true);
	GetDlgItem(IDC_NewPassword1)->EnableWindow(true);
	GetDlgItem(IDC_NewPassword2)->EnableWindow(true);
	//UDat.seekg(sn*sizeof(CivSup));
	LPTSTR pWhite = new TCHAR[20];
	_stprintf_s(pWhite, 20, _T("%s"), _T(""));
	CivSup tmpUser(pWhite, 0, pWhite, pWhite, 0, 0, pWhite, 0, pWhite, pWhite);
	//UDat.read(reinterpret_cast<char *>(&tmpUser), sizeof(CivSup));
	tmpUser = getInfo(sn);
	if (tmpUser.GetName() == pWhite)
	{
		MessageBox(_T("不存在该用户！请先注册！"), _T("警告"));
		return;
	}
	SetDlgItemText(IDC_Question2, tmpUser.GetQuestion());
	m_Answer2.SetFocus();//*
}


void CPWForgot::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tmp;//*
	m_FGUser.GetWindowText(tmp);
	LL sn;
	swscanf_s(tmp, _T("%lld"), &sn);
	//sn = sn % 100000000000 - 1300000000;
	fstream UDat("User.dat", ios::in | ios::out | ios::binary);
	//UDat.seekg(sn*sizeof(CivSup));
	LPTSTR pWhite = new TCHAR[20];
	_stprintf_s(pWhite, 20, _T("%s"), _T(""));
	CivSup tmpUser(pWhite, 0, pWhite, pWhite, 0, 0, pWhite, 0, pWhite, pWhite);
	//UDat.read(reinterpret_cast<char *>(&tmpUser), sizeof(CivSup));
	tmpUser = getInfo(sn);
	m_Answer2.GetWindowText(tmp);
	if (tmpUser.GetAnswer() != tmp)
	{
		MessageBox(_T("密保答案错误！请检查后重新输入！"), _T("警告"));
		return;
	}
	m_NPW.GetWindowText(tmp);
	CString tmp2;
	m_NPW2.GetWindowText(tmp2);
	if (tmp != tmp2)
	{
		MessageBox(_T("两次密码不同！请重新输入！"), _T("警告"));
		return;
	}
	LPTSTR pTmp = new TCHAR[20];
	_tprintf_s(pTmp, 20, _T("%s"), tmp);
	//tmpUser.SetPassword(pTmp);
	tmpUser.SetPassword(0, tmp.GetLength());
	ie(i, 0, tmp.GetLength() - 1)
	{
		if (tmp[i] == '\0')break;
		tmpUser.SetPassword(i + 1, getFib(tmp[i], i % 2));
	}
	sn = getPos(sn);
	UDat.seekp(sn*sizeof(CivSup));
	UDat.write(reinterpret_cast<const char *>(&tmpUser), sizeof(CivSup));
	MessageBox(_T("找回密码成功！请重新登录！"), _T("警告"));
	CDialogEx::OnOK();
}
