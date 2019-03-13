// IndexDLG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Project X Beta.h"
#include "Project X BetaDlg.h"
#include "IndexDLG.h"
#include "afxdialogex.h"
#include <windows.h>
#define ie(i,s,t) for(int i=s;i<=t;++i)

using namespace std;


// CIndexDLG �Ի���

IMPLEMENT_DYNAMIC(CIndexDLG, CDialogEx)

CIndexDLG::CIndexDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Index, pParent)
{
}

CIndexDLG::~CIndexDLG()
{
}

void CIndexDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ShowUser, m_cShowUser);
}

BOOL CIndexDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CMFCButton *BLight = new CMFCButton;
	BLight->Create(_T("Ϩ�Ƽ��"),
		WS_VISIBLE,
		CRect(15, 15, 190, 150),
		this,
		IDC_Light);
	BLight->SetImage(IDB_BITMAP3);
	CMFCButton *BShoes = new CMFCButton;
	BShoes->Create(_T("���ȶ���"),
		WS_VISIBLE,
		CRect(205, 15, 395, 150),
		this,
		IDC_Shoes);
	BShoes->SetImage(IDB_BITMAP4);
	CMFCButton *BShop = new CMFCButton;
	BShop->Create(_T("�����嵥"),
		WS_VISIBLE,
		CRect(15, 165, 190, 300),
		this,
		IDC_Shop);
	BShop->SetImage(IDB_BITMAP5);
	CMFCButton *BChangeInfo = new CMFCButton;
	BChangeInfo->Create(_T("������Ϣ"),
		WS_VISIBLE,
		CRect(480,195,655,330),
		this,
		IDC_ChangeInfo);
		BChangeInfo->SetImage(IDB_BITMAP6);
	//ͼƬ��ť
	CString tmp;
	CString Content=_T("������");
	ie(i, 0,lstrlen(curUser.GetName()))if (curUser.GetName()[i] != '\0')Content += curUser.GetName()[i];
	Content += _T("\r\nѧ�ţ�");
	tmp.Format(_T("%lld"), curUser.GetStuNum());
	Content += tmp+ _T("\r\nѧԺ��");
	ie(i, 0, lstrlen(curUser.GetInstitute()))if (curUser.GetInstitute()[i] != '\0')Content += curUser.GetInstitute()[i];
	//tmp.Format(_T("%s"), *curUser.GetInstitute());
	Content += _T("\r\nרҵ��");
	ie(i, 0, lstrlen(curUser.GetProfess()))if (curUser.GetProfess()[i] != '\0')Content += curUser.GetProfess()[i];
	//swscanf_s(tmp, _T("%s"), curUser.GetProfess());
	//tmp.Format(_T("%s"), *curUser.GetProfess());
	Content += _T("\r\n�༶��");
	tmp.Format(_T("%d"), curUser.GetClass());
	Content += tmp + _T("\r\n�ֻ���");
	tmp.Format(_T("%lld"), curUser.GetPhone());
	Content += tmp + _T("\r\n¥���ֶӣ�");
	ie(i, 0, lstrlen(curUser.GetBuilding()))if(curUser.GetBuilding()[i]!='\0')Content += curUser.GetBuilding()[i];
	//swscanf_s(tmp, _T("%s"), curUser.GetBuilding());
	//tmp.Format(_T("%s"), *curUser.GetBuilding());
	Content +=  _T("\r\n����¥�㣺");
	tmp.Format(_T("%d"), curUser.GetFloor());
	Content += tmp + _T("\r\n");
	//SetDlgItemText(IDC_ShowUser, Content);
	m_cShowUser.SetWindowText(Content);
	//�����û���Ϣ
	return true;
}

BEGIN_MESSAGE_MAP(CIndexDLG, CDialogEx)
	ON_BN_CLICKED(IDC_Light, &CIndexDLG::OnBnClickedLight)
	ON_BN_CLICKED(IDOK, &CIndexDLG::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CIndexDLG::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_ChangeInfo, &CIndexDLG::OnBnClickedChangeinfo)
	ON_BN_CLICKED(IDC_Shoes, &CIndexDLG::OnBnClickedShoes)
	ON_BN_CLICKED(IDC_Shop, &CIndexDLG::OnBnClickedShop)
END_MESSAGE_MAP()


// CIndexDLG ��Ϣ�������

void CIndexDLG::OnBnClickedLight()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_cLD = new CLightDLG(this);
	m_cLD->Create(IDD_Light, this);
	m_cLD->setcurUser(curUser);
	//m_cLD->SetPos()
	//MessageBox(_T("Perfect!"));
}

void CIndexDLG::setcurUser(CivSup x)
{
	curUser = x;
}

/*void CIndexDLG::setFD(CProjectXBetaDlg * tmp)
{
	m_cFaDlg = tmp;
}

CProjectXBetaDlg *CIndexDLG::getFD()
{
	return m_cFaDlg;
}*/


void CIndexDLG::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//getFD()->ShowWindow(SW_SHOW);
	GetParent()->ShowWindow(SW_SHOW);
	CDialogEx::OnOK();
}


void CIndexDLG::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PostQuitMessage(0);
	CDialogEx::OnCancel();
}


void CIndexDLG::OnBnClickedChangeinfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("������Ĳ������׼���"));
	m_cCI = new CChangeInfoDLG(this);
	m_cCI->Create(IDD_CHANGEINFO, this);
	m_cCI->setStu(curUser.GetStuNum());
}


void CIndexDLG::OnBnClickedShoes()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_cSH = new CShoesDLG(this);
	m_cSH->Create(IDD_SHOES, this);
	m_cSH->setUser(curUser);
}


void CIndexDLG::OnBnClickedShop()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_cBL = new CBuyListDLG(this);
	m_cBL->Create(IDD_BUY, this);
	m_cBL->setUser(curUser);
}
