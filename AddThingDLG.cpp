// AddThingDLG.cpp : 实现文件
//

#include "stdafx.h"
#include "Project X Beta.h"
#include "AddThingDLG.h"
#include "afxdialogex.h"



// CAddThingDLG 对话框

IMPLEMENT_DYNAMIC(CAddThingDLG, CDialogEx)

CAddThingDLG::CAddThingDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADDTHING, pParent)
{

}

CAddThingDLG::~CAddThingDLG()
{
}

void CAddThingDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Name);
	DDX_Control(pDX, IDC_EDIT2, m_Times);
	DDX_Control(pDX, IDC_EDIT3, m_Time);
	DDX_Control(pDX, IDC_EDIT4, m_Cost);
}

void CAddThingDLG::setUser(CivSup user)
{
	curUser = user;
}

CivSup CAddThingDLG::getUser()
{
	return curUser;
}


BEGIN_MESSAGE_MAP(CAddThingDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddThingDLG::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddThingDLG 消息处理程序


void CAddThingDLG::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tmp;
	CivSup tmpUser = getInfo(curUser.GetStuNum());
	m_Name.GetWindowText(tmp);
	LPTSTR pName = new TCHAR[20];
	_stprintf_s(pName, 20, _T("%s"), tmp);
	m_Cost.GetWindowText(tmp);
	double Cost = _ttof(tmp);
	m_Times.GetWindowText(tmp);
	int Times = _tcstoul(tmp, NULL, 10);
	m_Time.GetWindowText(tmp);
	double Time = _ttof(tmp);
	//ready for information
	Thing tmpThing(pName, Times, Time, Cost);
	int cnt = tmpUser.GetBuyList().getCnt()+1;
	buyList tmpBuy = tmpUser.GetBuyList();
	tmpBuy.setCnt(cnt);
	tmpBuy.setThing(cnt, tmpThing);
	tmpUser.SetBuyList(tmpBuy);
	//ready for the user
	int pos = getPos(tmpUser.GetStuNum());
	fstream Udat("User.dat", ios::in | ios::out | ios::binary);
	Udat.seekp(pos*sizeof(CivSup));
	Udat.write(reinterpret_cast<const char *>(&tmpUser), sizeof(CivSup));
	Udat.close();
	display();
	//Save for changes
	CDialogEx::OnOK();
}
