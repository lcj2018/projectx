// ChangeInfoDLG.cpp : 实现文件
//

#include "stdafx.h"
#include "Project X Beta.h"
#include "ChangeInfoDLG.h"
#include "afxdialogex.h"

using namespace std;
// CChangeInfoDLG 对话框

IMPLEMENT_DYNAMIC(CChangeInfoDLG, CDialogEx)

CChangeInfoDLG::CChangeInfoDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHANGEINFO, pParent)
{

}

CChangeInfoDLG::~CChangeInfoDLG()
{
}

void CChangeInfoDLG::setStu(LL stu)
{
	curStu = stu;
}

LL CChangeInfoDLG::getStu()
{
	return curStu;
}

void CChangeInfoDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_URName, m_Name);
	DDX_Control(pDX, IDC_URStuNum, m_StuNum);
	DDX_Control(pDX, IDC_URInstitute, m_Institute);
	DDX_Control(pDX, IDC_URProfess, m_Profess);
	DDX_Control(pDX, IDC_EDIT1, m_Class);
	DDX_Control(pDX, IDC_URPhone, m_Phone);
	DDX_Control(pDX, IDC_URBuild, m_Building);
	DDX_Control(pDX, IDC_EDIT2, m_Floor);
	DDX_Control(pDX, IDC_URPASSWORD1, m_Password1);
	DDX_Control(pDX, IDC_URPassword2, m_Password2);
	DDX_Control(pDX, IDC_URQuestion, m_Question);
	DDX_Control(pDX, IDC_URAnswer, m_Answer);
}


BEGIN_MESSAGE_MAP(CChangeInfoDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &CChangeInfoDLG::OnBnClickedOk)
END_MESSAGE_MAP()


// CChangeInfoDLG 消息处理程序

BOOL CChangeInfoDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();//*
	CSpinButtonCtrl *pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN1);//*
	pSpin->SetRange(0, 100);//*
	pSpin->SetPos(0);//*
	CString strValue;//*
	strValue.Format(L"%d", 0);//*
	pSpin->GetBuddy()->SetWindowText(strValue);//*
	CSpinButtonCtrl *pSpin2 = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN2);//*
	pSpin2->SetRange(0, 100);//*
	pSpin2->SetPos(0);//*
	CString strValue2;//*
	strValue2.Format(L"%d", 0);//*
	pSpin2->GetBuddy()->SetWindowText(strValue2);//*
	return TRUE;//*
}

void CChangeInfoDLG::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tmp1;
	m_Password1.GetWindowText(tmp1);
	CString tmp2;
	m_Password2.GetWindowText(tmp2);
	if (tmp1!=L""&&tmp2!=L""&&tmp1 != tmp2)
	{
		MessageBox(_T("两次密码不相同！\n请重新输入！"), _T("警告"));
		return;
	}
	fstream Udat("User.dat", ios::in | ios::out | ios::binary);
	CString tmp;
	CivSup tmpUser = getInfo(curStu);
	m_Class.GetWindowText(tmp);
	if (tmp != L"0")
	{
		int Class = _tcstoul(tmp, NULL, 10);
		tmpUser.SetClass(Class);
	}
	//Class
	m_Floor.GetWindowText(tmp);
	if (tmp != L"0")
	{
		int Floor = _tcstoul(tmp, NULL, 10);
		tmpUser.SetFloor(Floor);
	}
	//Floor
	m_StuNum.GetWindowText(tmp);
	if (tmp != L"")
	{
		LL StuNum;
		swscanf_s(tmp, _T("%lld"), &StuNum);
		tmpUser.SetStuNum(StuNum);
	}
	//StudentNum
	m_Phone.GetWindowText(tmp);
	if (tmp != L"")
	{
		LL Phone;
		swscanf_s(tmp, _T("%lld"), &Phone);
		tmpUser.SetPhone(Phone);
	}
	//Phone
	m_Name.GetWindowText(tmp);
	if (tmp != L"")
	{
		LPTSTR pName = new TCHAR[20];
		_stprintf_s(pName, 20, _T("%s"), tmp);
		tmpUser.SetName(pName);
	}
	//Name
	m_Institute.GetWindowText(tmp);
	if (tmp != L"")
	{
		LPTSTR pInstitute = new TCHAR[20];
		_stprintf_s(pInstitute, 20, _T("%s"), tmp);
		tmpUser.SetInstitute(pInstitute);
	}
	//Institute
	m_Profess.GetWindowText(tmp);
	if (tmp != L"")
	{
		LPTSTR pProfess = new TCHAR[20];
		_stprintf_s(pProfess, 20, _T("%s"), tmp);
		tmpUser.SetProfess(pProfess);
	}
	//Profess
	m_Building.GetWindowText(tmp);
	if (tmp != L"")
	{
		LPTSTR pBuilding = new TCHAR[20];
		_stprintf_s(pBuilding, 20, _T("%s"), tmp);
		tmpUser.SetBuilding(pBuilding);
	}
	//Building
	m_Password1.GetWindowText(tmp);
	if (tmp != L"")
	{
		/*LPTSTR pPassword = new TCHAR[20];
		_stprintf_s(pPassword, 20, _T("%s"), tmp);
		tmpUser.SetPassword(pPassword);*/
		tmpUser.SetPassword(0, tmp.GetLength());
		ie(i, 0, tmp.GetLength() - 1)
		{
			if (tmp[i] == '\0')break;
			tmpUser.SetPassword(i + 1, getFib(tmp[i], i % 2));
		}
	}
	//Password
	m_Question.GetWindowText(tmp);
	if (tmp != L"")
	{
		LPTSTR pQuestion = new TCHAR[20];
		_stprintf_s(pQuestion, 20, _T("%s"), tmp);
		tmpUser.SetQuestion(pQuestion);
	}
	//Question
	m_Answer.GetWindowText(tmp);
	if (tmp != L"")
	{
		LPTSTR pAnswer = new TCHAR[20];
		_stprintf_s(pAnswer, 20, _T("%s"), tmp);
		tmpUser.SetAnswer(pAnswer);
	}
	int pos = getPos(curStu);
	Udat.seekp(pos*sizeof(CivSup));
	Udat.write(reinterpret_cast<const char *>(&tmpUser), sizeof(CivSup));
	Udat.close();
	MessageBox(_T("部分展示信息将在程序重启后更新"), _T(">_< 灰化肥会挥发"));
	CDialogEx::OnOK();
}
