
// Project X BetaDlg.cpp : ʵ���ļ�
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


// CProjectXBetaDlg �Ի���



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


// CProjectXBetaDlg ��Ϣ�������

BOOL CProjectXBetaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SkinH_Attach();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CProjectXBetaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CProjectXBetaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProjectXBetaDlg::OnBnClickedQuit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PostQuitMessage(0);//*
}


void CProjectXBetaDlg::OnStnClickedRegister()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_cUR = new CUserRegisterDLG(this);
	m_cUR->Create(IDD_REGISTERDLG, this);//*
}


void CProjectXBetaDlg::OnEnChangeUsername()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CProjectXBetaDlg::OnStnClickedPwforgot()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_cPF = new CPWForgot(this);
	m_cPF->Create(IDD_PWFORGOT, this);//*
}


/*void CProjectXBetaDlg::OnBnClickedLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox(_T("���û�δע�ᣡ�����û��������ע�ᣡ"), _T("����"));
		return;
	}
	LPTSTR pTmp = new TCHAR[20];
	_stprintf_s(pTmp, 20, _T("%s"), tmp);
	if (*tmpUser.GetPassword() != *pTmp)
	{
		MessageBox(_T("������������û��������룡"), _T("����"));
		return;
	}//*
	MessageBox(_T("Perfect!"));
	CDialogEx::OnOK();
}*/


/*void CProjectXBetaDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	LPTSTR pTmp = new TCHAR[20];
	_stprintf_s(pTmp, 20, _T("%s"), _T("5464"));
	LPTSTR ptmp = new TCHAR[20];
	_stprintf_s(ptmp, 20, _T("%s"), _T("5464"));
	if (*pTmp == *ptmp)MessageBox(_T("Yes!")); else MessageBox(_T("No!"));
}*/


void CProjectXBetaDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox(_T("���û�δע�ᣡ�����û��������ע�ᣡ"), _T("����"));
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
		MessageBox(_T("������������û��������룡"), _T("����"));
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_cAbout = new CAbout(this);
	m_cAbout->Create(IDD_ABOUT, this);
}
