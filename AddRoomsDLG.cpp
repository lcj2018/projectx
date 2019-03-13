// AddRoomsDLG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Project X Beta.h"
#include "AddRoomsDLG.h"
#include "afxdialogex.h"
#include "preOutput.h"


// CAddRoomsDLG �Ի���

IMPLEMENT_DYNAMIC(CAddRoomsDLG, CDialogEx)

CAddRoomsDLG::CAddRoomsDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_addRooms, pParent)
{

}

CAddRoomsDLG::~CAddRoomsDLG()
{
	DestroyWindow();
}

void CAddRoomsDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATETIME, m_cDT);
	DDX_Control(pDX, IDC_Room, m_cRM);
}

void CAddRoomsDLG::setcurUser(CivSup tmp)
{
	curUser = tmp;
}

Date CAddRoomsDLG::getIntTime(CString s)
{
	int n = s.GetLength(), i = 0;
	int year = 0, month = 0, day = 0;
	Date tmp;
	while ('0' <= s[i] && s[i] <= '9')
	{
		year = year * 10 + s[i] - '0';
		++i;
	}
	++i;
	while ('0' <= s[i] && s[i] <= '9')
	{
		month = month * 10 + s[i] - '0';
		++i;
	}
	++i;
	while ('0' <= s[i] && s[i] <= '9')
	{
		day = day * 10 + s[i] - '0';
		++i;
		if (i >= n)break;
	}
	tmp.setYear(year);
	tmp.setMonth(month);
	tmp.setDay(day);
	return tmp;
}

void CAddRoomsDLG::deal(CString s,Date date)
{
	int n = s.GetLength() + 1, i = 0, room;
	s += ' ';
	while (i < n)
	{
		room = 0;
		while ('0' <= s[i] && s[i] <= '9')
		{
			room = room * 10 + s[i] - '0';
			++i;
		}
		++i;
		pushRoom(curUser.GetStuNum(), room % 100, date);
	}
}

BEGIN_MESSAGE_MAP(CAddRoomsDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddRoomsDLG::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CAddRoomsDLG::OnBnClickedCancel)
END_MESSAGE_MAP()


// CAddRoomsDLG ��Ϣ�������

void CAddRoomsDLG::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTime time;
	m_cDT.GetTime(time);
	CString strTime;
	strTime = time.Format("%Y,%m,%d");
	Date tmp;
	tmp=getIntTime(strTime);
	CString str;
	m_cRM.GetWindowText(str);
	deal(str,tmp);
	MessageBox(_T("��ӳɹ������� ��ȡ �����б�"));
	CDialogEx::OnOK();
}


void CAddRoomsDLG::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
