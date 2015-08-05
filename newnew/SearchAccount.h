#pragma once
# include "resource.h"
#include "afxwin.h"
# include "teller.h"
# include "accountinfo.h"
# include "newaccaunt.h"
// SearchAccount dialog

class SearchAccount : public CDialogEx
{
	DECLARE_DYNAMIC(SearchAccount)

public:
	SearchAccount(CWnd* pParent = NULL);   // standard constructor
	virtual ~SearchAccount();
	void printlist();

// Dialog Data
	enum { IDD = IDD_SEARCHACCOUNT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	int indexofall;
	DECLARE_MESSAGE_MAP()
	accountinfo *info;
public:
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	CComboBox com_SearchBy;
	CEdit e_searchbyid;
	CEdit e_searchbyfristname;
	CEdit e_searchbylastname;
	afx_msg void OnBnClickedButton1();
//	CEdit e_idsearch;
//	afx_msg void OnEnChangeSearchbyid();
//	CButton CB_SearchName;
//	int CB_SearchID;
//	int CB_SEARCHACCOUNTNUMBER;
	//afx_msg void OnBnClickedRbSearchid();
//	CButton e_addname;
//	CButton RADBTN_SEARCHID;
	
	afx_msg void OnStnClickedStaticSearchbyaccountnumber();
	afx_msg void OnBnClickedButton2();
	CListBox CL_PrintAccount;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedBtnEditaccount1();
	CListBox cl_closeaccount;
	afx_msg void OnBnClickedBtnCloseaccount();
};
