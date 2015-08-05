#pragma once
# include "resource.h"
# include "ATM.h"

// THEATM dialog

class THEATM : public CDialogEx
{
	DECLARE_DYNAMIC(THEATM)

public:
	THEATM(CWnd* pParent = NULL);   // standard constructor
	virtual ~THEATM();

// Dialog Data
	enum { IDD = IDD_THEATM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	account *acc;
	DECLARE_MESSAGE_MAP()
public:
//	CEdit e_ACCOUNTNUMBER;
	CEdit e_ACCOUNTNUMBER;
	CEdit e_PINCODE;
	afx_msg void OnBnClickedBtnDeposit();
//	CButton b_checkbalance;
//	CButton b_deposit;
//	CButton b_login;
//	CButton b_logout;
//	CButton b_transfer;
	CEdit e_accountotransfer;
	CEdit e_mountotransfer;
	CEdit e_withdrwalanddeposit;
	afx_msg void OnBnClickedBtnLogin();
	afx_msg void OnBnClickedBtnCheckbalance();
	CListBox lb_printinfromation;
	afx_msg void OnBnClickedBtnWithdraw();
	afx_msg void OnBnClickedButApprovewithdrawl();
	afx_msg void OnBnClickedButApprovetransfer();
};
