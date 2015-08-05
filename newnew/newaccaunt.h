#pragma once
#include <string>
# include "resource.h"
# include "accountinfo.h"
#include "kindofaccount.h"
# include "teller.h"
#include "afxwin.h"
// newaccaunt dialog

class newaccaunt : public CDialogEx
{
	DECLARE_DYNAMIC(newaccaunt)

public:
	newaccaunt(CWnd* pParent = NULL);   // standard constructor
	virtual ~newaccaunt();
	void setcontrol(int a);
	void setinfo(accountinfo *in);
	void printineditbox(accountinfo *in);//print all ifromation from account
	void getfromeditbox();//get infromation from all editboxes
	//-------------------------------------------------My Functions-------------------------------------
			
	//---------------------------------------------------------------------------------------------------
// Dialog Data
	enum { IDD = IDD_NEWACCOUNT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//------------------------------My function------------------------------------//
	accountinfo *accountinfos;
	int control;//1-Add new account,2-Edit Account
	
	DECLARE_MESSAGE_MAP()
public:
	CEdit e_addfirstname;
	CEdit e_addlastname;
	CEdit e_addaddress;
	CEdit e_addid;
	CEdit e_addphone;
	CComboBox com_kindofclient;
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedAbort();
	afx_msg void OnBnClickedButComtinue();
	CComboBox com_SortofAccount;
	afx_msg void OnCbnSelchangeCmbSortofaccount();
	afx_msg void OnBnClickedContinuetoaccount();
	CEdit e_addaccountbirthday;
	
	afx_msg void OnBnClickedBtnEditaccount();
	afx_msg void OnBnClickedBtnOknew();
};
