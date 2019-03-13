#pragma once
#include "afxdtctl.h"
#include "afxwin.h"
#include "CivSup.h"
#include "Date.h"


// CAddRoomsDLG 对话框

class CAddRoomsDLG : public CDialogEx
{
	DECLARE_DYNAMIC(CAddRoomsDLG)

public:
	CAddRoomsDLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddRoomsDLG();

	void setcurUser(CivSup);
	Date getIntTime(CString);
	void deal(CString,Date);

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_addRooms };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CDateTimeCtrl m_cDT;
	CEdit m_cRM;
private:
	CivSup curUser;
public:
	afx_msg void OnBnClickedCancel();
};
