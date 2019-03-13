// ShoesDLG.cpp : 实现文件
//

#include "stdafx.h"
#include "Project X Beta.h"
#include "ShoesDLG.h"
#include "afxdialogex.h"
#define pb push_back
#define ie(i,s,t) for(int i=s;i<=t;++i)
#define de(i,s,t) for(int i=s;i>=t;--i)

// CShoesDLG 对话框

IMPLEMENT_DYNAMIC(CShoesDLG, CDialogEx)

CShoesDLG::CShoesDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHOES, pParent)
{

}

CShoesDLG::~CShoesDLG()
{
}

void CShoesDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_cSR);
}

vector<CString> CShoesDLG::getRoom(CString s)
{
	int n = s.GetLength() + 1, i = 0;
	vector<CString> tmpRoom; 
	CString tmp;
	tmpRoom.clear();
	s += ' ';
	while (i < n)
	{
		tmp = L"";
		while ('0' <= s[i] && s[i] <= '9')
		{
			tmp += s[i];
			++i;
		}
		++i;
		tmpRoom.pb(tmp);
	}
	return tmpRoom;
}

void CShoesDLG::setUser(CivSup tmp)
{
	curUser = tmp;
}

CivSup CShoesDLG::getUser()
{
	return curUser;
}


BEGIN_MESSAGE_MAP(CShoesDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &CShoesDLG::OnBnClickedOk)
END_MESSAGE_MAP()


// CShoesDLG 消息处理程序


void CShoesDLG::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tmp;
	m_cSR.GetWindowText(tmp);
	vector<CString> midName;
	midName = getRoom(tmp);
	CString building=L"";
	ie(i, 0, lstrlen(curUser.GetBuilding()))if (curUser.GetBuilding()[i] != '\0')building += curUser.GetBuilding()[i];
	building += '-';
	CString curDate;
	CTime time;
	time = CTime::GetCurrentTime();
	curDate = time.Format("-%Y%m%d.jpg");
	//MessageBox(curDate);
	string oldName;
	CString newName,path,cmd;
	GetDlgItemText(IDC_PHOTOPATH, path);
	cmd = L"dir " + path + L" /B /OD >"+path;
	if (path[path.GetLength() - 1] == '\\')cmd += L"_tmp.txt"; else cmd += L"\\_tmp.txt";
	//cmd = L"pause";
	//LPTSTR pCmd = new TCHAR[100];
	//_stprintf_s(pCmd, 100, _T("%s"), cmd);
	char *pCmd = new char[cmd.GetLength()];
	//cmd.GetLength();
	ie(i, 0, cmd.GetLength())
	{
		pCmd[i] = cmd[i];
		if (cmd[i] == '\0')break;
	}
	const char *Command = pCmd;
	system(Command);
	//新建dir->_tmp.txt
	CString tmpath=path;
	if (path[path.GetLength() - 1] == '\\')tmpath += L"_tmp.txt"; else tmpath += L"\\_tmp.txt";
	char *pPath = new char[tmpath.GetLength()];
	ie(i, 0, tmpath.GetLength())
	{
		pPath[i] = tmpath[i];
		if (tmpath[i] == '\0')break;
	}
	const char *filePath = pPath;
	freopen(filePath, "r", stdin);
	//txt目录读入
	//cin >> oldName;//去除第一个txt
	for (vector<CString>::iterator iter = midName.begin(); iter < midName.end(); ++iter)
	{
		newName =  building + *iter + curDate;
		//new name
		cin >>oldName;
		if (path[path.GetLength()] != '\\')oldName = '\\' + oldName;
		de(i, path.GetLength(), 0)
		{
			if((char)path[i]!='\0')oldName = (char)(path[i]) + oldName;
		}
		cmd = oldName.c_str();
		cmd = L"rename " + cmd + L" " + newName;
		char *pCmd = new char[cmd.GetLength()];
		ie(i, 0, cmd.GetLength())
		{
			pCmd[i] = cmd[i];
			if (cmd[i] == '\0')break;
		}
		//preparation
		const char *Command = pCmd;
		system(Command);
		//happy
	}
	freopen("CON", "r", stdin);
	cmd = L"del " + path;
	if (path[path.GetLength() - 1] == '\\')cmd += L"_tmp.txt"; else cmd += L"\\_tmp.txt";
	char *pCmdd = new char[cmd.GetLength()];
	ie(i, 0, cmd.GetLength())
	{
		pCmdd[i] = cmd[i];
		if (cmd[i] == '\0')break;
	}
	//prepare for del
	const char *Commandd = pCmdd;
	system(Commandd);
	//happy
	CDialogEx::OnOK();
}
