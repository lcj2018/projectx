
// Project X BetaDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Project X Beta.h"
#include "Project X BetaDlg.h"
#include "afxdialogex.h"
#include "UserRegisterDLG.h"
#include "CivSup.h"
#include "PWForgotDLG.h"
#include <fstream>
#include <cstdlib>
#include <tchar.h>
#include "preOutput.h"
#include "SkinH.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;


// CProjectXBetaDlg 对话框



CProjectXBetaDlg::CProjectXBetaDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROJECTXBETA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProjectXBetaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_USERNAME, m_Lger);
	DDX_Control(pDX, IDC_PASSWORD, m_Lgpass);
}

BEGIN_MESSAGE_MAP(CProjectXBetaDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_QUIT, &CProjectXBetaDlg::OnBnClickedQuit)
	ON_STN_CLICKED(IDC_REGISTER, &CProjectXBetaDlg::OnStnClickedRegister)
	ON_EN_CHANGE(IDC_USERNAME, &CProjectXBetaDlg::OnEnChangeUsername)
	ON_STN_CLICKED(IDC_PWFORGOT, &CProjectXBetaDlg::OnStnClickedPwforgot)
	//ON_BN_CLICKED(IDC_LOGIN, &CProjectXBetaDlg::OnBnClickedLogin)
	//ON_BN_CLICKED(IDC_BUTTON1, &CProjectXBetaDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CProjectXBetaDlg::OnBnClickedOk)
	ON_STN_CLICKED(IDC_ABOUT, &CProjectXBetaDlg::OnStnClickedAbout)
END_MESSAGE_MAP()


// CProjectXBetaDlg 消息处理程序

BOOL CProjectXBetaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SkinH_Attach();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CProjectXBetaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CProjectXBetaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProjectXBetaDlg::OnBnClickedQuit()
{
	// TODO: 在此添加控件通知处理程序代码
	PostQuitMessage(0);//*
}


void CProjectXBetaDlg::OnStnClickedRegister()
{
	// TODO: 在此添加控件通知处理程序代码
	m_cUR = new CUserRegisterDLG(this);
	m_cUR->Create(IDD_REGISTERDLG, this);//*
}


void CProjectXBetaDlg::OnEnChangeUsername()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CProjectXBetaDlg::OnStnClickedPwforgot()
{
	// TODO: 在此添加控件通知处理程序代码
	m_cPF = new CPWForgot(this);
	m_cPF->Create(IDD_PWFORGOT, this);//*
}


/*void CProjectXBetaDlg::OnBnClickedLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	ifstream UDat("User.dat", ios::in | ios :: binary);//*
	LPTSTR pWhite = new TCHAR[20];
	_stprintf_s(pWhite, 20, _T("%s"), _T(""));
	CString tmp;
	m_Lger.GetWindowText(tmp);
	//int UNum = _tcstoul(tmp, NULL, 10);
	LL UNum;
	swscanf_s(tmp, _T("%lld"), &UNum);
	m_Lgpass.GetWindowText(tmp);
	CivSup tmpUser(pWhite, 0, pWhite, pWhite, 0, 0, pWhite, 0, pWhite,pWhite,pWhite);
	tmpUser = getInfo(UNum);*/
/*	CString ppt;
	LPTSTR pp = new TCHAR[20];
	ppt.Format(L"%d", tmpUser.GetClass());
	_stprintf_s(pp, 20, _T("%s"), ppt);
	MessageBox(pp);*/
/*	if (*tmpUser.GetName() == *pWhite||!UDat)
	{
		MessageBox(_T("该用户未注册！请检查用户名或进行注册！"), _T("警告"));
		return;
	}
	LPTSTR pTmp = new TCHAR[20];
	_stprintf_s(pTmp, 20, _T("%s"), tmp);
	if (*tmpUser.GetPassword() != *pTmp)
	{
		MessageBox(_T("密码错误！请检查用户名及密码！"), _T("警告"));
		return;
	}//*
	MessageBox(_T("Perfect!"));
	CDialogEx::OnOK();
}*/


/*void CProjectXBetaDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	LPTSTR pTmp = new TCHAR[20];
	_stprintf_s(pTmp, 20, _T("%s"), _T("5464"));
	LPTSTR ptmp = new TCHAR[20];
	_stprintf_s(ptmp, 20, _T("%s"), _T("5464"));
	if (*pTmp == *ptmp)MessageBox(_T("Yes!")); else MessageBox(_T("No!"));
}*/


void CProjectXBetaDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	LPTSTR pWhite = new TCHAR[20];
	_stprintf_s(pWhite, 20, _T("%s"), _T(""));
	CString tmp;
	m_Lger.GetWindowText(tmp);
	//int UNum = _tcstoul(tmp, NULL, 10);
	LL UNum;
	swscanf_s(tmp, _T("%lld"), &UNum);
	CivSup tmpUser(pWhite, 0, pWhite, pWhite, 0, 0, pWhite, 0, pWhite, pWhite);
	tmpUser = getInfo(UNum);
	/*	CString ppt;
	LPTSTR pp = new TCHAR[20];
	ppt.Format(L"%d", tmpUser.GetClass());
	_stprintf_s(pp, 20, _T("%s"), ppt);
	MessageBox(pp);*/
	ifstream UDat("User.dat", ios::in | ios::binary);//*
	if (*tmpUser.GetName() == *pWhite || !UDat)
	{
		MessageBox(_T("该用户未注册！请检查用户名或进行注册！"), _T("警告"));
		UDat.close();
		return;
	}
	UDat.close();
	m_Lgpass.GetWindowText(tmp);
	//LPTSTR pTmp = new TCHAR[20];
	//_stprintf_s(pTmp, 20, _T("%s"), tmp);
	/***************************************************************/
	bool flag = true;
	if (tmpUser.GetPassword(0) != tmp.GetLength())
	{
		flag = false;
	}
	else
	{
		ie(i, 0, tmp.GetLength() - 1)
		{
			if (tmp[i] == '\0')break;
			if (tmpUser.GetPassword(i + 1) != getFib(tmp[i], i % 2))
			{
				flag = false;
				break;
			}
		}
	}
	/*************************************************************Compare the passwords*/
	if (/*!cmpstr(tmpUser.GetPassword(),pTmp)*/!flag)
	{
		MessageBox(_T("密码错误！请检查用户名及密码！"), _T("警告"));
		return;
	}//*
	this->ShowWindow(SW_HIDE);
	m_cIndex = new CIndexDLG(this);
	m_cIndex->setcurUser(tmpUser);
//	m_cIndex->setFD(this);
	m_cIndex->Create(IDD_Index, this);
	m_Lgpass.SetWindowText(L"");
	//MessageBox(_T("Well Done!"));
	//CDialogEx::OnOK();
}


void CProjectXBetaDlg::OnStnClickedAbout()
{
	// TODO: 在此添加控件通知处理程序代码
	m_cAbout = new CAbout(this);
	m_cAbout->Create(IDD_ABOUT, this);
}
