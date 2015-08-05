#pragma once

# include "resource.h"
#include "afxwin.h"
# include "KindofAccount1.h"
# include "teller.h"
// tellertransactions dialog

class tellertransactions : public CDialogEx
{
	DECLARE_DYNAMIC(tellertransactions)

public:
	tellertransactions(CWnd* pParent = NULL);   // standard constructor
	virtual ~tellertransactions();

// Dialog Data
	enum { IDD = IDD_TELLERTRANSACTIONS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	account *acc1;
	account *acc2;
	DECLARE_MESSAGE_MAP()
public:
//	CEdit e_eneteraccountnumber;
//	CEdit e_enterdeposit;
//	CEdit e_enterwithdraw;
	afx_msg void OnEnChangeEdtSearchaccountnumber();
	CListBox cl_viewbalance;
	CEdit e_secondsearchaccount;
	CEdit e_sumtotransfer;
	afx_msg void OnBnClickedBtnSearchaccount();
	afx_msg void OnBnClickedBtnDeposit();
	CListBox cl_statusoftransaction;
	afx_msg void OnBnClickedBtnWithdraw();
	afx_msg void OnBnClickedBtnTransfermoney();
	CListBox cl_Balance2;
	CEdit e_searchaccount;
	CEdit e_enterdeposit;
//	CButton e_withdraw;
	CEdit e_withdraw;
};
