// tellertransactions.cpp : implementation file
//

#include "stdafx.h"
#include "tellertransactions.h"
#include "afxdialogex.h"


// tellertransactions dialog

IMPLEMENT_DYNAMIC(tellertransactions, CDialogEx)

tellertransactions::tellertransactions(CWnd* pParent /*=NULL*/)
	: CDialogEx(tellertransactions::IDD, pParent)
{

}

tellertransactions::~tellertransactions()
{
}

void tellertransactions::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, cl_viewbalance);
	DDX_Control(pDX, IDC_EDT_SEARCHSECONDACCOUNTNUMBER, e_secondsearchaccount);
	DDX_Control(pDX, IDC_EDT_SUMTOTRANSFER, e_sumtotransfer);
	DDX_Control(pDX, IDC_LST_STATUSOFTRANSACTION, cl_statusoftransaction);
	DDX_Control(pDX, IDC_LIST3, cl_Balance2);
	DDX_Control(pDX, IDC_EDT_SEARCHACCOUNTNUMBER, e_searchaccount);
	DDX_Control(pDX, IDC_EDT_ENTERDEPOSIT, e_enterdeposit);
	//  DDX_Control(pDX, IDC_BTN_WITHDRAW, e_withdraw);
	DDX_Control(pDX, IDC_EDT_WITHDRAW, e_withdraw);
}


BEGIN_MESSAGE_MAP(tellertransactions, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_SEARCHACCOUNT, &tellertransactions::OnBnClickedBtnSearchaccount)
	ON_BN_CLICKED(IDC_BTN_DEPOSIT, &tellertransactions::OnBnClickedBtnDeposit)
	ON_BN_CLICKED(IDC_BTN_WITHDRAW, &tellertransactions::OnBnClickedBtnWithdraw)
	ON_BN_CLICKED(IDC_BTN_TRANSFERMONEY, &tellertransactions::OnBnClickedBtnTransfermoney)
END_MESSAGE_MAP()


// tellertransactions message handlers


void tellertransactions::OnBnClickedBtnSearchaccount()
{
	CString accountnumber;
	int accnum=1;
	teller tel;
	e_searchaccount.GetWindowTextW(accountnumber);
	accnum=_ttoi(accountnumber);
	if(tel.searcbyaccountnumber(accnum))
	{
		acc1=tel.getaccount(accnum);
		accountnumber.Format(_T("%lf"),acc1->getbalance());
		cl_viewbalance.AddString(accountnumber);
		GetDlgItem(IDC_BTN_DEPOSIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_WITHDRAW)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_TRANSFER)->EnableWindow(TRUE);
	}
	// TODO: Add your control notification handler code here
}


void tellertransactions::OnBnClickedBtnDeposit()
{
	int sum1;
	teller t;
	CString sum,sucess,fail;
	sucess="sucess";
	fail="fail";
	e_enterdeposit.GetWindowTextW(sum);
	sum1=_ttoi(sum);
	if(t.checkdeposit(sum1,acc1))
	{
		t.deposit(sum1,acc1);
		cl_statusoftransaction.AddString(sucess);
	}
	else
		cl_statusoftransaction.AddString(fail);
	// TODO: Add your control notification handler code here
}


void tellertransactions::OnBnClickedBtnWithdraw()
{
	int sum1;
	teller t;
	CString sum,sucess,fail;
	sucess="sucess";
	fail="fail";
	e_withdraw.GetWindowTextW(sum);
	sum1=_ttoi(sum);
	if(t.checkwithdraw(sum1,acc1))
	{
		t.withdraw(sum1,acc1);
		cl_statusoftransaction.AddString(sucess);
	}
	else
		cl_statusoftransaction.AddString(fail);
	// TODO: Add your control notification handler code here
}


void tellertransactions::OnBnClickedBtnTransfermoney()
{
	int sum1,accountnumber2;
	CString accountnumber;
	teller tel;
	CString sum,sucess,fail;
	sucess="sucess";
	fail="fail";
	e_secondsearchaccount.GetWindowTextW(accountnumber);
	accountnumber2=_ttoi(accountnumber);
	if(tel.searcbyaccountnumber(accountnumber2))
	{
		acc2=tel.getaccount(accountnumber2);
		accountnumber.Format(_T("%lf"),acc2->getbalance());
		cl_Balance2.AddString(accountnumber);
		e_sumtotransfer.GetWindowTextW(sum);
		sum1=_ttoi(sum);
		if(tel.transfer1(acc1,acc2,sum1))
			cl_statusoftransaction.AddString(sucess);
		else 
			cl_statusoftransaction.AddString(fail);
	}
	else
		cl_statusoftransaction.AddString(fail);
	// TODO: Add your control notification handler code here
}
