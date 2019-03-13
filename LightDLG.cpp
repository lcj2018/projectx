// LightDLG.cpp : 实现文件
//

#include "stdafx.h"
#include "Project X Beta.h"
#include "LightDLG.h"
#include "afxdialogex.h"
#define ie(i,s,t) for(int i=s;i<=t;++i)

using namespace std;

// CLightDLG 对话框

IMPLEMENT_DYNAMIC(CLightDLG, CDialogEx)

CLightDLG::CLightDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Light, pParent)
{

}

CLightDLG::~CLightDLG()
{
}

void CLightDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ShowDate, m_cSD);
	DDX_Control(pDX, IDC_ShowRoom, m_cSR);
	DDX_Control(pDX, IDC_MFCEDITBROWSE1, m_Path);
}

void CLightDLG::setcurUser(CivSup tmp)
{
	curUser = tmp;
}


BEGIN_MESSAGE_MAP(CLightDLG, CDialogEx)
	ON_BN_CLICKED(IDC_addRooms, &CLightDLG::OnBnClickedaddrooms)
	ON_BN_CLICKED(IDC_Update, &CLightDLG::OnBnClickedUpdate)
	ON_BN_CLICKED(IDC_clearRooms, &CLightDLG::OnBnClickedclearrooms)
//	ON_BN_CLICKED(IDC_BUTTON3, &CLightDLG::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_Excel, &CLightDLG::OnBnClickedExcel)
END_MESSAGE_MAP()


// CLightDLG 消息处理程序


void CLightDLG::OnBnClickedaddrooms()
{
	// TODO: 在此添加控件通知处理程序代码
	m_cAR = new CAddRoomsDLG(this);
	m_cAR->Create(IDD_addRooms, this);
	m_cAR->setcurUser(curUser);
}


void CLightDLG::OnBnClickedUpdate()
{
	// TODO: 在此添加控件通知处理程序代码
	m_cSD.ResetContent();
	m_cSR.ResetContent();
	curUser = getInfo(curUser.GetStuNum());
	ie(i, 1, 59)
		if (curUser.GetRoom(i).getCnt() > 0)
		{
			CString tmpSD, tmpSR, tmp;
			tmp.Format(_T("%d"), curUser.GetFloor());
			tmpSD += tmp;
			tmp.Format(_T("%d"), i);
			if (i < 10)tmp += '0';
			tmpSD += tmp;
			m_cSD.AddString(tmpSD);
			//违纪寝室
			ie(j, 1, curUser.GetRoom(i).getCnt())
			{
				int year = curUser.GetRoom(i).getDate(j).getYear();
				int month = curUser.GetRoom(i).getDate(j).getMonth();
				int day = curUser.GetRoom(i).getDate(j).getDay();
				tmp.Format(_T("%d"), year);
				tmpSR += tmp + '/';
				tmp.Format(_T("%d"), month);
				tmpSR += tmp + '/';
				tmp.Format(_T("%d"), day);
				tmpSR += tmp + ' ' + ' ';
			}
			m_cSR.AddString(tmpSR);
		}
}


void CLightDLG::OnBnClickedclearrooms()
{
	// TODO: 在此添加控件通知处理程序代码
	m_cSD.ResetContent();
	m_cSR.ResetContent();
	CivSup tmpUser;
	Room tmpRoom;
	int tmpCnt = getCnt();
	fstream Udat("User.dat", ios::in | ios::out | ios::binary);
	ie(i, 1, tmpCnt)
	{
		bool flag = false;
		Udat.seekg(i*sizeof(CivSup));
		Udat.read(reinterpret_cast<char *>(&tmpUser), sizeof(CivSup));
		ie(j, 1, 59)
		{
			if (tmpUser.GetRoom(j).getCnt() > 0)
			{
				tmpUser.SetRoom(j, tmpRoom);
				flag = true;
			}
		}
		if (flag)
		{
			Udat.seekp(i*sizeof(CivSup));
			Udat.write(reinterpret_cast<const char *>(&tmpUser), sizeof(CivSup));
		}
	}
	Udat.close();
}


/*void CLightDLG::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("未完待续 ToT -1s"),_T("警告"));
}*/


void CLightDLG::OnBnClickedExcel()
{
	// TODO: 在此添加控件通知处理程序代码
	bool flag = true;
	ie(i,1,59)
		if (curUser.GetRoom(i).getCnt() > 0)
		{
			flag = false;
			break;
		}
	if (flag)return;
	CString Content = L"华南理工大学大学城校区学生宿舍文明督导工作记录表\n楼栋,检查日期,,问题类型,存在问题宿舍,持续天数,表现优秀宿舍典型（选填）,检查人\n";
	CString tmp;
	CString building;
	building.Format(_T("%s"), curUser.GetBuilding());
	Room tmpRoom;
	Date tmpDate, last;
	ie(i, 1, 59)
	{
		tmpRoom = curUser.GetRoom(i);
		last = tmpRoom.getDate(0);
		if (tmpRoom.getCnt())
		{
			Content += building + ',';
		}
		//building
		ie(j, 1, tmpRoom.getCnt())
		{
			tmpDate = tmpRoom.getDate(j);
			if (tmpDate.getYear() == last.getYear() && tmpDate.getMonth() == last.getMonth())
			{
				tmp.Format(_T("%d"), tmpDate.getDay());
				Content += '/' + tmp;
			}
			if (tmpDate.getYear() == last.getYear() && tmpDate.getMonth() != last.getMonth()) 
			{
				tmp.Format(_T("%d"), tmpDate.getMonth());
				Content += '.' + tmp + '.';
				tmp.Format(_T("%d"), tmpDate.getDay());
				Content += tmp;
			}
			if (tmpDate.getYear() != last.getYear()) 
			{
				tmp.Format(_T("%d"), tmpDate.getYear());
				if (j > 1)Content += '.' + tmp + '.'; else Content += tmp + '.';
				tmp.Format(_T("%d"), tmpDate.getMonth());
				Content += tmp + '.';
				tmp.Format(_T("%d"), tmpDate.getDay());
				Content += tmp;
			}
			last = tmpDate;
		}
		//Date
		if (tmpRoom.getCnt())
		{
			Content += L",熄灯检查,未熄灯宿舍,";
			//苟
			tmp.Format(_T("%d"), i);
			if (tmp.GetLength() == 1)tmp = '0' + tmp;
			tmp = (char)('0' + curUser.GetFloor()) + tmp;
			Content += tmp + ',';
			//Room
			tmp.Format(_T("%d"), tmpRoom.getCnt());
			Content += tmp + L",,";
			//Times
			tmp.Format(_T("%s"), curUser.GetName());
			Content += tmp + '\n';
		}
	}
	//Content of the file
	CString fileName = L"";
	CString curDate;
	CTime time;
	time = CTime::GetCurrentTime();
	curDate = time.Format("%Y%m%d");
	tmp.Format(_T("F%d"), curUser.GetFloor());
	fileName = curDate + tmp + L"Worksheets.csv";
	CString path;
	GetDlgItemText(IDC_PATH, path);
	CString tmpath = path;
	if (path[path.GetLength() - 1] == '\\')tmpath += fileName; else tmpath += '\\' + fileName;
	char *pPath = new char[tmpath.GetLength()];
	ie(i, 0, tmpath.GetLength())
	{
		pPath[i] = tmpath[i];
		if (tmpath[i] == '\0')break;
	}
	const char *filePath = pPath;
	freopen(filePath, "w", stdout);
	//string Sheet = *Content.GetBuffer(0);
	//cout << Sheet.c_str() << endl;
	wcout.imbue(std::locale("chs"));
	wcout << Content.GetBuffer() << endl;
	freopen("CON", "w", stdout);
	//Output the content
	MessageBox(_T("老哥 稳"));
}
