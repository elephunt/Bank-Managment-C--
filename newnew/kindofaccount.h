#pragma once
#include "afxwin.h"
# include "resource.h"
# include "accountinfo.h"
# include "KindofAccount1.h"
# include "Clerck.h"
#include <string>
using namespace std;
// kindofaccount dialog

class kindofaccount : public CDialogEx
{
	DECLARE_DYNAMIC(kindofaccount)

public:
	kindofaccount(CWnd* pParent = NULL);   // standard constructor
	virtual ~kindofaccount();

// Dialog Data
	enum { IDD = IDD_KINDOFACCOUNT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	accountinfo *info;
	DECLARE_MESSAGE_MAP()
	int control;
	int numberofaccount;
public:
	CComboBox com_kindofaccount;
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//------------------------------------------------My functions------------------------------------------------//
	void setsortofaccount(CString anak);//to make a combox of sorts of account(Student,Private,buisness)
	void getinfo(accountinfo *in);//function to get an object of accountinfo from previous dialog
	void setcontrol(int x);
	void setnumberofaccount(int y);
	void printineditbox();
	void getfromedtiox();
	//------------------------------------------------------------------------------------------------------------//
	CEdit e_addbalance;
	CComboBox com_addstatus;
	afx_msg void OnBnClickedButAddacount();
	CComboBox com_addsortkind;
	CListBox CL_numberofaccount;
	CListBox CL_PINCODE;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedSaveedit();
};

