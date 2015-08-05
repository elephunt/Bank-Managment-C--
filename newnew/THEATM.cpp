// THEATM.cpp : implementation file
//

#include "stdafx.h"
#include "THEATM.h"
#include "afxdialogex.h"


// THEATM dialog

IMPLEMENT_DYNAMIC(THEATM, CDialogEx)

THEATM::THEATM(CWnd* pParent /*=NULL*/)
	: CDialogEx(THEATM::IDD, pParent)
{

}

THEATM::~THEATM()
{
}

void THEATM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDT_ENETERPINCODE, e_ACCOUNTNUMBER);
	DDX_Control(pDX, IDC_EDT_ENTERACCOUNTNUMBER, e_ACCOUNTNUMBER);
	DDX_Control(pDX, IDC_EDT_ENETERPINCODE, e_PINCODE);
	//  DDX_Control(pDX, IDC_BTN_CHECKBALANCE, b_checkbalance);
	//  DDX_Control(pDX, IDC_BTN_DEPOSIT, b_deposit);
	//  DDX_Control(pDX, IDC_BTN_LOGIN, b_login);
	//  DDX_Control(pDX, IDC_BTN_LOGOUT, b_logout);
	//  DDX_Control(pDX, IDC_BTN_TRANSFER, b_transfer);
	DDX_Control(pDX, IDC_EDT_ACCOUNTTOTRANSFER, e_accountotransfer);
	DDX_Control(pDX, IDC_EDT_MOUNTTOTRANSFER, e_mountotransfer);
	DDX_Control(pDX, IDC_EDT_WITHDRAWAL, e_withdrwalanddeposit);
	DDX_Control(pDX, IDC_LIST1, lb_printinfromation);
}


BEGIN_MESSAGE_MAP(THEATM, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_DEPOSIT, &THEATM::OnBnClickedBtnDeposit)
	ON_BN_CLICKED(IDC_BTN_LOGIN, &THEATM::OnBnClickedBtnLogin)
	ON_BN_CLICKED(IDC_BTN_CHECKBALANCE, &THEATM::OnBnClickedBtnCheckbalance)
	ON_BN_CLICKED(IDC_BTN_WITHDRAW, &THEATM::OnBnClickedBtnWithdraw)
	ON_BN_CLICKED(IDC_BUT_APPROVEWITHDRAWL, &THEATM::OnBnClickedButApprovewithdrawl)
	ON_BN_CLICKED(IDC_BUT_APPROVETRANSFER, &THEATM::OnBnClickedButApprovetransfer)
END_MESSAGE_MAP()


// THEATM message handlers


void THEATM::OnBnClickedBtnDeposit()
{
	// TODO: Add your control notification handler code here
}


void THEATM::OnBnClickedBtnLogin()
{
	atm a;
	int pin,accnum;
	CString accountnumber,pincode;
	e_ACCOUNTNUMBER.GetWindowTextW(accountnumber);
	e_PINCODE.GetWindowTextW(pincode);
	accnum=_ttoi(accountnumber);
	pin=_ttoi(pincode);
	if(a.searcbyaccountnumber(accnum))
	{
		acc=a.getaccount(accnum);
		if(a.permission(accnum,pin))
		{
			GetDlgItem(IDC_BTN_CHECKBALANCE)->EnableWindow(TRUE);
			GetDlgItem(IDC_BTN_WITHDRAW)->EnableWindow(TRUE);
			GetDlgItem(IDC_BTN_DEPOSIT)->EnableWindow(TRUE);
			GetDlgItem(IDC_BTN_TRANSFER)->EnableWindow(TRUE);
			GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(FALSE);

		}
	}

	// TODO: Add your control notification handler code here
}

void THEATM::OnBnClickedBtnCheckbalance()//print int list of information
{
	double bal;
	CString cs_balance;
	bal=acc->getbalance();
	cs_balance.Format(_T("%lf"),bal);
	lb_printinfromation.DeleteString(0);
	lb_printinfromation.AddString(cs_balance);
	// TODO: Add your control notification handler code here
}




void THEATM::OnBnClickedBtnWithdraw()
{
	GetDlgItem(IDC_BUT_APPROVEWITHDRAWL)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDT_WITHDRAWAL)->ShowWindow(TRUE);
	GetDlgItem(IDC_STC_HOWMUCHTOWITHDRAWL)->ShowWindow(TRUE);
	// TODO: Add your control notification handler code here
}


void THEATM::OnBnClickedButApprovewithdrawl()
{
	atm a;
	CString sum,massage;
	int in_sum;
	e_withdrwalanddeposit.GetWindowTextW(sum);
	in_sum=(_ttoi(sum));
	if(a.withdraw(acc,in_sum))
	{
		massage="Succses to Withdraw";
		lb_printinfromation.DeleteString(0);
		lb_printinfromation.AddString(massage);
	}
	else
	 {
	    massage="Fail to Withdraw";
	    lb_printinfromation.DeleteString(0);
		lb_printinfromation.AddString(massage);
	  }
}


void THEATM::OnBnClickedButApprovetransfer()
{
	atm b;
	CString Traacc,mount;
	int sum;
	account *ac;
	e_accountotransfer.GetWindowTextW(Traacc);
	ac=b.getaccount(_ttoi(Traacc));
	e_mountotransfer.GetWindowTextW(mount);

}
