// NEW.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "Clerck.h"
#include "afxdialogex.h"
#include "newaccaunt.h"

// NEW dialog

IMPLEMENT_DYNAMIC(NEW, CDialogEx)

NEW::NEW(CWnd* pParent /*=NULL*/)
	: CDialogEx(NEW::IDD, pParent)
{

}

NEW::~NEW()
{
}

void NEW::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NEW, CDialogEx)
	ON_BN_CLICKED(IDC_BUT_ADDACOUNT, &NEW::OnBnClickedButAddacount)
	ON_BN_CLICKED(IDC_BUTTON1, &NEW::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &NEW::OnBnClickedButton2)
END_MESSAGE_MAP()


// NEW message handlers


void NEW::OnBnClickedButAddacount()
{
	newaccaunt a;
	a.setcontrol(1);
	a.DoModal();
	// TODO: Add your control notification handler code here
}


void NEW::OnBnClickedButton1()//editaccount
{
	
	SearchAccount sear;
	sear.DoModal();
	// TODO: Add your control notification handler code here
}//edit


void NEW::OnBnClickedButton2()
{
	tellertransactions tel;
	tel.DoModal();
	// TODO: Add your control notification handler code here
}//transaction
