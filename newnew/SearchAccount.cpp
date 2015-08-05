// SearchAccount.cpp : implementation file
//

#include "stdafx.h"
#include "SearchAccount.h"
#include "afxdialogex.h"


// SearchAccount dialog

IMPLEMENT_DYNAMIC(SearchAccount, CDialogEx)

SearchAccount::SearchAccount(CWnd* pParent /*=NULL*/)
	: CDialogEx(SearchAccount::IDD, pParent)
	//, CB_SearchID(0)
	//, CB_SEARCHACCOUNTNUMBER(0)
{
	indexofall=0;
}

SearchAccount::~SearchAccount()
{
}

void SearchAccount::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COM_SEARCHACCOUNTBY, com_SearchBy);
	DDX_Control(pDX, IDC_SEARCHBYID/*IDC_EDIT1*/, e_searchbyid);
	DDX_Control(pDX, IDC_EDT_SEARCHBYFIRSTNAME, e_searchbyfristname);
	DDX_Control(pDX, IDC_EDT_SEARCHBYLASTNAME, e_searchbylastname);
	//	DDX_Control(pDX, IDC_SEARCHBYID, e_idsearch);
	//DDX_Control(pDX, IDC_RADIO1, CB_SearchName);
	//  DDX_Control(pDX, IDC_BUTTON1, e_addname);
	//	DDX_Control(pDX, IDC_RADIO12, RADBTN_SEARCHID);
	DDX_Control(pDX, IDC_LIST_PrintAccount, CL_PrintAccount);
	DDX_Control(pDX, IDC_LST_CLOSEACCOUNT, cl_closeaccount);
}
BEGIN_MESSAGE_MAP(SearchAccount, CDialogEx)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUTTON1, &SearchAccount::OnBnClickedButton1)
//	ON_EN_CHANGE(IDC_SEARCHBYID, &SearchAccount::OnEnChangeSearchbyid)
//ON_BN_CLICKED(IDC_RB_SEARCHID, &SearchAccount::OnBnClickedRbSearchid)
//ON_BN_CLICKED(IDC_RADIO12, &SearchAccount::OnBnClickedRadio12)
//ON_STN_CLICKED(IDC_STATIC_Searchbyaccountnumber, &SearchAccount::OnStnClickedStaticSearchbyaccountnumber)
ON_BN_CLICKED(IDC_BUTTON2, &SearchAccount::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON3, &SearchAccount::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BTN_EDITACCOUNT1, &SearchAccount::OnBnClickedBtnEditaccount1)
ON_BN_CLICKED(IDC_BTN_CLOSEACCOUNT, &SearchAccount::OnBnClickedBtnCloseaccount)
END_MESSAGE_MAP()


// SearchAccount message handlers


void SearchAccount::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);
	CString status[3]={_T("ID"),_T("Name"),_T("AccountNumber")};//combox if account active or not active
	for(int i=0;i<3;i++)
	com_SearchBy.AddString(status[i]);
	 //TODO: Add your message handler code here
}
void SearchAccount::OnBnClickedButton1()//choose button
{
	//CString firstname,lastname,id,accountnumber,sort,status;
	int index;
	//------------------------------------------------------------------------------------------------//
	index=com_SearchBy.GetCurSel(); 
	indexofall=index;//TAKE THE COMBO BOX selection from what kind(private,busines,student);
	//----------------------------------------------------------------------------------------//
    if(index==1)//search by id(index=1)
	{
		GetDlgItem(IDC_STC_SEARCHBYID)->ShowWindow(TRUE);
		GetDlgItem(IDC_SEARCHBYID)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	}
	else
		if(index==2)//search by name(index=2)
	     {
			 GetDlgItem(IDC_STATIC_SEARCHBYFIRSTNAME)->ShowWindow(TRUE);
			 GetDlgItem(IDC_STC_SEARCHBYLASTNAME)->ShowWindow(TRUE);
			 GetDlgItem(IDC_EDT_SEARCHBYFIRSTNAME)->ShowWindow(TRUE);
			 GetDlgItem(IDC_EDT_SEARCHBYLASTNAME)->ShowWindow(TRUE);
			 GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	     }

		else
		{
			if(index==0)//search by account number(index=0)
			{
				GetDlgItem(IDC_SEARCHBYID)->ShowWindow(TRUE);
				//GetDlgItem(idc_st)->ShowWindow(TRUE);
				GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
			}
	         
		}
	// TODO: Add your control notification handler code here
}//button to choose by what you want to search
void SearchAccount::OnStnClickedStaticSearchbyaccountnumber()
{
	// TODO: Add your control notification handler code here
}
void SearchAccount::OnBnClickedButton2()//search
{
	CString firstname,lastname,id,accnumber;
	teller tel;
	//-----------------------------------Search and print by account number------------------------------------
	if(indexofall==0)//search by accountnumber
	{
		  e_searchbyid.GetWindowTextW(id);
		if(tel.searcbyaccountnumber(_ttoi(id)))//search by accoutnumber if there is in bank have one
		{
			GetDlgItem(IDC_BTN_CLOSEACCOUNT)->EnableWindow(TRUE);//if search by accountnumber,button the close will work	
			GetDlgItem(IDC_BTN_EDITACCOUNT1)->EnableWindow(TRUE);//if searc by accountnumber,button edit info of person will work
			indexofall=_ttoi(id);//save an accout number
			info=tel.searchaccountnumber(_ttoi(id));//retrun an object of accountinfo by searching number of account
			printlist();    //print all deatial from accountinfo
			GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);//makin a button edit an account work
	    }
	}
	else
		//----------------------------------Search and print by id-------------------------------//
		if(indexofall==1)//search by id
		{
			e_searchbyid.GetWindowTextW(id);
				if(tel.searchbyid(_ttoi(id)))
				{
					info=tel.searchid(_ttoi(id));
					printlist();
					GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
				}
		}
		//-----------------------Search and print by name and lastname----------------------------------//
		else
			if(indexofall==2)//search by name and lastname
		{
			e_searchbyfristname.GetWindowTextW(firstname);
			e_searchbylastname.GetWindowTextW(lastname);
			if(tel.searchbyname(firstname,lastname))
			{
				info=tel.searchname(firstname,lastname);
				printlist();
				GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
			}
		}
        //-----------------------------------------------------------------------------------------------------//
}
void SearchAccount::printlist()//printf an infromation in list 
{
   CString id,phone,accountnumber;
	CL_PrintAccount.AddString(info->getf());//print firstname
	CL_PrintAccount.AddString(info->getl());//printf lastname
	CL_PrintAccount.AddString(info->getb());//print birthday
	id.Format(_T("%d"),(info->getid()));//convert id to Cstring
	CL_PrintAccount.AddString(id);//print id 
	CL_PrintAccount.AddString(info->geta());//print address
	CL_PrintAccount.AddString(info->getkind());//print what kind a costumer
	phone.Format(_T("%d"),info->getp());//format int phone to Cstring
	CL_PrintAccount.AddString(phone);//print phone
		for(int i=0;i<info->accountss.size();i++)//print all account number of person
			{
			   accountnumber.Format(_T("%d"),info->accountss[i]->getaccountnumber());
			   CL_PrintAccount.AddString(accountnumber);
			}
}
void SearchAccount::OnBnClickedButton3()
{
	newaccaunt ac;
	ac.setinfo(info);
	ac.setcontrol(2);
	ac.DoModal();
	// TODO: Add your control notification handler code here
}


void SearchAccount::OnBnClickedBtnEditaccount1()
{
	kindofaccount k;
	k.setcontrol(2);
	k.setnumberofaccount(indexofall);
	k.getinfo(info);
	k.DoModal();
	// TODO: Add your control notification handler code here
}


void SearchAccount::OnBnClickedBtnCloseaccount()
{
	teller t;
	CString s,f;
	s="Account Closed";
	f="Failed";
	     if(t.closeaccount(indexofall))
			cl_closeaccount.AddString(s);
		else
			cl_closeaccount.AddString(f);
	// TODO: Add your control notification handler code here
}
