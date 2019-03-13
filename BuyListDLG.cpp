// BuyListDLG.cpp : 实现文件
//

#include "stdafx.h"
#include "Project X Beta.h"
#include "BuyListDLG.h"
#include "afxdialogex.h"


// CBuyListDLG 对话框

IMPLEMENT_DYNAMIC(CBuyListDLG, CDialogEx)

CBuyListDLG::CBuyListDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BUY, pParent)
{

}

CBuyListDLG::~CBuyListDLG()
{
}

void CBuyListDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOWNAME, m_SN);
	DDX_Control(pDX, IDC_SHOWVALUE, m_SC);
	DDX_Control(pDX, IDC_EDIT1, m_Money);
}

void CBuyListDLG::setUser(CivSup user)
{
	curUser = user;
}

CivSup CBuyListDLG::getUser()
{
	return curUser;
}


BEGIN_MESSAGE_MAP(CBuyListDLG, CDialogEx)
	ON_BN_CLICKED(IDC_ADDTHING, &CBuyListDLG::OnBnClickedAddthing)
	ON_BN_CLICKED(IDC_BUTTON2, &CBuyListDLG::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CALCULATE, &CBuyListDLG::OnBnClickedCalculate)
	ON_LBN_DBLCLK(IDC_SHOWNAME, &CBuyListDLG::OnLbnDblclkShowname)
	ON_LBN_DBLCLK(IDC_SHOWVALUE, &CBuyListDLG::OnLbnDblclkShowvalue)
END_MESSAGE_MAP()


// CBuyListDLG 消息处理程序


void CBuyListDLG::OnBnClickedAddthing()
{
	// TODO: 在此添加控件通知处理程序代码
	m_cAT = new CAddThingDLG(this);
	m_cAT->Create(IDD_ADDTHING, this);
	m_cAT->setUser(curUser);
}


void CBuyListDLG::OnBnClickedButton2()//Read from the file and show in the list
{
	// TODO: 在此添加控件通知处理程序代码
	m_SN.ResetContent();
	m_SC.ResetContent();
	fstream Udat("User.dat", ios::in | ios::out | ios::binary);
	CivSup tmpUser = getInfo(curUser.GetStuNum());
	buyList tmpList = tmpUser.GetBuyList();
	Thing tmpThing;
	CString tmp;
	ie(i, 1, tmpList.getCnt())
	{
		tmpThing = tmpList.getThing(i);
		tmp.Format(_T("%s"), tmpThing.getName());
		m_SN.AddString(tmp);
		tmp.Format(_T("%lf"), tmpThing.getCost());
		m_SC.AddString(tmp);
	}
	Udat.close();
}


void CBuyListDLG::OnBnClickedCalculate()//calculate
{
	// TODO: 在此添加控件通知处理程序代码
	CString tmp;
	m_Money.GetWindowText(tmp);
	int Money = _tcstoul(tmp, NULL, 10);
	CivSup tmpUser = getInfo(curUser.GetStuNum());
	buyList buy = tmpUser.GetBuyList();
	int upLimit = 0;
	ie(i, 1, buy.getCnt())
	{
		upLimit +=(int)(buy.getThing(i).getCost() * 10);
	}
	upLimit = min(upLimit, Money);
	//in search of the uplimit
	double f[60000];
	int decRec[100][60000];
	double dec;
	memset(f, 0, sizeof(f));
	memset(decRec, 0, sizeof(decRec));
	ie(i, 1, buy.getCnt())
		de(j, upLimit*10, (int)(buy.getThing(i).getCost() * 10))
		{
			dec = f[j - (int)(buy.getThing(i).getCost() * 10)] + buy.getThing(i).getValue();
			if (dec > f[j])
			{
				decRec[i][j] = 1;
				f[j] = dec;
			}
			else
			{
				decRec[i][j] = 0;
			}
	}
	//f[j] = max(f[j], f[j -(int)(buy.getThing(i).getCost() * 10)] + buy.getThing(i).getValue());
	//Dynamic Programming O(nm)
	int t = upLimit*10, cnt = 0;;
	CString Content = L"";
	de(i, buy.getCnt(), 1)
	{
		if (decRec[i][t])
		{
			++cnt;
			tmp.Format(_T("#%d："), cnt);
			Content += tmp;
			tmp.Format(_T("%s\r\n"), buy.getThing(i).getName());
			Content += tmp;
			t -= (int)(buy.getThing(i).getCost()*10);
		}
	}
	SetDlgItemText(IDC_SHOWTIP, Content);
	//Show the arrangement
}


void CBuyListDLG::OnLbnDblclkShowname()
{
	// TODO: 在此添加控件通知处理程序代码
	int pos = m_SN.GetCurSel();
	CString name;
	m_SN.GetText(pos, name);
	m_SN.DeleteString(pos);
	m_SC.DeleteString(pos);
	//Update the lists
	CivSup tmpUser = getInfo(curUser.GetStuNum());
	//Gain the latest information of the current user.
	buyList tmpList = tmpUser.GetBuyList();
	tmpList.delThing(name);
	tmpUser.SetBuyList(tmpList);
	//Update the list
	pos = getPos(tmpUser.GetStuNum());
	fstream Udat("User.dat", ios::in | ios::out | ios::binary);
	Udat.seekp(pos*sizeof(CivSup));
	Udat.write(reinterpret_cast<const char *>(&tmpUser), sizeof(CivSup));
	Udat.close();
	//Update the file
}


void CBuyListDLG::OnLbnDblclkShowvalue()
{
	// TODO: 在此添加控件通知处理程序代码
	int pos = m_SC.GetCurSel();
	CString name;
	m_SN.GetText(pos, name);
	m_SN.DeleteString(pos);
	m_SC.DeleteString(pos);
	//Update the lists
	CivSup tmpUser = getInfo(curUser.GetStuNum());
	//Gain the latest information of the current user.
	buyList tmpList = tmpUser.GetBuyList();
	tmpList.delThing(name);
	tmpUser.SetBuyList(tmpList);
	//Update the list
	pos = getPos(tmpUser.GetStuNum());
	fstream Udat("User.dat", ios::in | ios::out | ios::binary);
	Udat.seekp(pos*sizeof(CivSup));
	Udat.write(reinterpret_cast<const char *>(&tmpUser), sizeof(CivSup));
	Udat.close();
	//Update the file
}

