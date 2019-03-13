// PWForgot.cpp : ʵ���ļ�
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

// CPWForgot �Ի���

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


// CPWForgot ��Ϣ�������


void CPWForgot::OnBnClickedSnok()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tmp;//*
	m_FGUser.GetWindowText(tmp);
	//LL sn = _tcstoul(tmp, NULL, 10);
	LL sn;
	swscanf_s(tmp, _T("%lld"), &sn);
	if (sn < 201300000000 || sn>202099999999)
	{
		MessageBox(_T("ѧ�Ų���ȷ!"), _T("����"));
		return;
	}
	//sn=sn % 100000000000 - 1300000000;
	ifstream UDat("User.dat", ios::in | ios::binary);
	if (!UDat)
	{
		MessageBox(_T("�����ڸ��û�������ע�ᣡ"), _T("����"));
		UDat.close();
		return;
	}
	UDat.close();
	if (getInfo(sn).GetStuNum() == 0)
	{
		MessageBox(_T("�����ڸ��û�������ע�ᣡ"), _T("����"));
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
		MessageBox(_T("�����ڸ��û�������ע�ᣡ"), _T("����"));
		return;
	}
	SetDlgItemText(IDC_Question2, tmpUser.GetQuestion());
	m_Answer2.SetFocus();//*
}


void CPWForgot::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox(_T("�ܱ��𰸴���������������룡"), _T("����"));
		return;
	}
	m_NPW.GetWindowText(tmp);
	CString tmp2;
	m_NPW2.GetWindowText(tmp2);
	if (tmp != tmp2)
	{
		MessageBox(_T("�������벻ͬ�����������룡"), _T("����"));
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
	MessageBox(_T("�һ�����ɹ��������µ�¼��"), _T("����"));
	CDialogEx::OnOK();
}
