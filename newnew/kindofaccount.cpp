// kindofaccount.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "kindofaccount.h"
#include "afxdialogex.h"
using namespace std;

// kindofaccount dialog

IMPLEMENT_DYNAMIC(kindofaccount, CDialogEx)

kindofaccount::kindofaccount(CWnd* pParent /*=NULL*/)
	: CDialogEx(kindofaccount::IDD, pParent)
{
  control=0;
  numberofaccount=0;
}

kindofaccount::~kindofaccount()
{
}

void kindofaccount::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//	DDX_Control(pDX, IDC_COM_KINDOFACCOUNT, com_kindofaccount);
	DDX_Control(pDX, IDC_EDT_BALANCE, e_addbalance);
	DDX_Control(pDX, IDC_COM_STATUS, com_addstatus);
	DDX_Control(pDX, IDC_COMBO1, com_addsortkind);
	DDX_Control(pDX, IDC_LIS_NUMBEROFACCOUNT, CL_numberofaccount);
	DDX_Control(pDX, IDC_LIST2, CL_PINCODE);
}

BEGIN_MESSAGE_MAP(kindofaccount, CDialogEx)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUT_ADDACOUNT, &kindofaccount::OnBnClickedButAddacount)
	ON_BN_CLICKED(BTN_OK, &kindofaccount::OnBnClickedOk)
	ON_BN_CLICKED(IDC_SAVEEDIT, &kindofaccount::OnBnClickedSaveedit)
END_MESSAGE_MAP()


// kindofaccount message handlers


void kindofaccount::OnShowWindow(BOOL bShow, UINT nStatus)
{
	//control=1 set sort for new account,2 edit account
	CDialogEx::OnShowWindow(bShow, nStatus);
	CString status[2]={_T("Active"),_T("Not active")};//combox if account active or not active
	for(int i=0;i<2;i++)
	com_addstatus.AddString(status[i]);
	if(control==1)
	{
	    setsortofaccount(info->getkind());
		GetDlgItem(IDC_SAVEEDIT)->EnableWindow(FALSE);
	}//sending a kind of client to get a choose of sort of account
	if(control==2)
	{
		GetDlgItem(IDC_COMBO1)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUT_ADDACOUNT)->EnableWindow(FALSE);
		printineditbox();
	}
}
void kindofaccount::OnBnClickedButAddacount()
{
	CString balance,status,sort,date,numberofaccount,pincode;
	int index;
	double balance1;
   //------------------------------------Get infromation fro comboxes(Sort of account,Status of account---------------//
	index=com_addsortkind.GetCurSel();        //TAKE THE COMBO BOX selection from what kind(private,busines,student);
	com_addsortkind.GetLBText(index,sort);
	index=com_addstatus.GetCurSel();        //TAKE THE COMBO BOX selection status of account (Active,Not Acctive)
	com_addstatus.GetLBText(index,status);
	//---------------------------Gettin a balance from editbox and convert this to double----------------------------------------------------//
	e_addbalance.GetWindowTextW(balance);//take from edit a balance in account
	balance1=_wtof(balance);
	//---------------------------------Convert Cstring to String---------------------------------------------------//
	CT2CA p(sort);          // from cstring to string sort of account
	std::string str_sort(p);
	//------------------------Makes new object from account--------------------------------------//
	//CString balance,status,sort,date,numberofaccount,pincode;
	if(sort=="Student")
		info->acc1=new student(0,0,balance1,status,_T("Winter"));
	else
		if(sort=="Private")
			info->acc1=new privatea(4.5,5000,balance1,status,_T("Today"));
		else
			if(sort=="Buisness")
				info->acc1=new buisness(6.5,10000,balance1,status,_T("Today"));
	info->accountss.push_back(info->acc1);
	//------------------Convert a number of account,pincode to Cstring ---------------------------------------//
	numberofaccount.Format(_T("%d"),(info->acc1->getaccountnumber()));
	pincode.Format(_T("%d"),(info->acc1->getpinvisa()));
	CL_numberofaccount.AddString(numberofaccount);//sent an information about Account number
	CL_PINCODE.AddString(pincode);//sent infromation about pincode
	//------------------------------------------------------------------------------------------------------//
	//GetDlgItem(IDC_BUT_ADDACOUNT)->ShowWindow(SW_HIDE);
	// TODO: Add your control notification handler code here
}
void kindofaccount::setsortofaccount(CString k)//function to add choise to combox of sorts(student,private,buisness)
{
	CString foll[3]={_T("Student"),_T("Private"),_T("Buisness")};
	if(k=="Regular")
	{
		for(int i=0;i<2;i++)
			com_addsortkind.AddString(foll[i]);
	}
	if(k=="Gold" || k=="Platinum")
	{
       for(int i=1;i<3;i++)
		   com_addsortkind.AddString(foll[i]);
    }
}
void kindofaccount::OnBnClickedOk()
{
	CDialogEx::OnOK();
	// TODO: Add your control notification handler code here
}
void kindofaccount::getinfo(accountinfo *in)
{
	info=in;
}
void kindofaccount::setnumberofaccount(int y)
{
	numberofaccount=y;
}
void kindofaccount::setcontrol(int y)
{
	control=y;
}
void kindofaccount::printineditbox()
{
	teller tel;
	CString balance,accountnum,pincode;
	account *a;
	a=tel.getaccount(numberofaccount);
	balance.Format(_T("%lf"),a->getbalance());
	e_addbalance.SetWindowTextW(balance);
	com_addstatus.SetWindowTextW(a->getstatus());
	accountnum.Format(_T("%d"),(a->getaccountnumber()));
	pincode.Format(_T("%d"),(a->getpinvisa()));
	CL_numberofaccount.AddString(accountnum);//sent an information about Account number
	CL_PINCODE.AddString(pincode);//s
}
void kindofaccount::getfromedtiox()
{
	CString balance,status;
	teller tel;
	account *a;
	int index;
	double balance1;
	a=tel.getaccount(numberofaccount);
	e_addbalance.GetWindowTextW(balance);
	index=com_addstatus.GetCurSel();        //TAKE THE COMBO BOX selection status of account (Active,Not Acctive)
	com_addstatus.GetLBText(index,status);
	balance1=_wtof(balance);
	a->setbalance(balance1);
	a->setstatus(status);
}

void kindofaccount::OnBnClickedSaveedit()
{
	getfromedtiox();
	// TODO: Add your control notification handler code here
}
