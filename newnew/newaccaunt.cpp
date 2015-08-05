// newaccaunt.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "newaccaunt.h"
#include "afxdialogex.h"
# include "teller.h"
using namespace std;

// newaccaunt dialog

IMPLEMENT_DYNAMIC(newaccaunt, CDialogEx)

newaccaunt::newaccaunt(CWnd* pParent /*=NULL*/)
	: CDialogEx(newaccaunt::IDD, pParent)
{

}
newaccaunt::~newaccaunt()
{
}
void newaccaunt::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDT_FIRSTNAME, e_addfirstname);
	DDX_Control(pDX, IDC_EDT_LASTNAME, e_addlastname);
	DDX_Control(pDX, IDC_EDT_ADDRESS, e_addaddress);
	DDX_Control(pDX, IDC_EDT_ID, e_addid);
	DDX_Control(pDX, IDC_EDT_phone, e_addphone);
	DDX_Control(pDX, IDC_COM_kindofclient, com_kindofclient);
	DDX_Control(pDX, IDC_EDT_ADDACCOUNT_BIRTHDAY, e_addaccountbirthday);
}
BEGIN_MESSAGE_MAP(newaccaunt, CDialogEx)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDABORT, &newaccaunt::OnBnClickedAbort)
	ON_BN_CLICKED(IDC_BUT_COMTINUE, &newaccaunt::OnBnClickedButComtinue)
	ON_BN_CLICKED(IDC_BTN_EDITACCOUNT, &newaccaunt::OnBnClickedBtnEditaccount)
	ON_BN_CLICKED(IDC_BTN_OKNEW, &newaccaunt::OnBnClickedBtnOknew)
END_MESSAGE_MAP()


// newaccaunt message handlers


void newaccaunt::OnShowWindow(BOOL bShow, UINT nStatus)
{
	//control 1 to add new account,control 2 to edit account
	CDialogEx::OnShowWindow(bShow, nStatus);//adding to combox a three kind of client
	CString t;
	CDialogEx::OnInitDialog();
	if(control==1)//
	{
		string f[3]={"Regular","Gold","Platinum"};
	for(int i=0;i<3;i++)
	{
	t=f[i].c_str();   //casting string to CString
	com_kindofclient.AddString(t);
	}
	  GetDlgItem(IDC_BUT_COMTINUE)->EnableWindow(TRUE);//enable buttone continue to add client
	  GetDlgItem(IDC_COM_kindofclient)->EnableWindow(TRUE);//enable button to combox of kind of client
	}
	if(control==2)
	{
		printineditbox(accountinfos);//print in edit boxes an infromation
		GetDlgItem(IDC_BTN_EDITACCOUNT)->EnableWindow(TRUE);//enable button of edit

	}
	// TODO: Add your message handler code here
}
void newaccaunt::OnBnClickedButton1()
{
	CDialogEx::OnOK();
	// TODO: Add your control notification handler code here
}
void newaccaunt::OnBnClickedAbort()
{

	// TODO: Add your control notification handler code here
}
void newaccaunt::OnBnClickedButComtinue()
{
	CString cs_firstname,cs_lastname,cs_adress,cs_datebirth,cs_id,cs_phone;
	CString cs_kind;
	int id=1,p=1,index;
	//-----------------------------------Geting infromatiion from EditBox (Dialog)------------------//
	e_addfirstname.GetWindowTextW(cs_firstname);//FirstName
	e_addlastname.GetWindowTextW(cs_lastname);//Lastname
	e_addaddress.GetWindowTextW(cs_adress);//Adress
	e_addaccountbirthday.GetWindowTextW(cs_datebirth);//Date of Birth
	e_addid.GetWindowTextW(cs_id);//id of person
	e_addphone.GetWindowTextW(cs_phone);//phone number of person
	//---------------------------------------------------------------------------------------//
	//-----------------------Getting infromation from Combobox of Kind of Client(regular,gold,premium)------------------//
	index=com_kindofclient.GetCurSel();          //
	com_kindofclient.GetLBText(index,cs_kind);   //
	//---------------------------Convert from Cstinrg to int----------------------------------------------------------//
	id=_ttoi(cs_id);           // CASTING CSTRING TO INT (id)  
	p=_ttoi(cs_phone);         //from cstring to int(phone number)
	//--------------------------------New object of Accountinfo-----------------------------------------------------------//
	//str_r=firstname,str_l=lastname,str_d=birthday,str_a=adress,id,p=phone,str_k=kind  
	accountinfos=new accountinfo(cs_firstname,cs_lastname,cs_datebirth,cs_adress,id,p,cs_kind);//new class of sort accountinfo
	//--------------------------------Next Diloag of kindofaccount-------------------------------------------------------------//
	kindofaccount kindofacc;//object from kindofaccount
	kindofacc.setcontrol(1);
	kindofacc.getinfo(accountinfos);//sending to the next dialog my object
	kindofacc.DoModal();
	//-----------------------After press Ok on next dialog------------------------------------------------//
	//accountinfos->accountss.push_back(accountinfos->getaccounts());//adding a new account to vector of account of accountinfo
	teller tel;//object from teller
	tel.addaccount(*accountinfos);//sending a new account to be added to data structer
	//bankinterface bkin;
	//delete (accountinfos->acc1);//release a memory for local veribale
	delete accountinfos;//release a memory for local veribale
	// TODO: Add your control notification handler code here
}
void newaccaunt::OnCbnSelchangeCmbSortofaccount()
{
	// TODO: Add your control notification handler code here
}//button of sort of account
void newaccaunt::setinfo(accountinfo *in)
{
	accountinfos=in;
}
void newaccaunt::setcontrol(int x)
{
	control=x;
}
void newaccaunt::printineditbox(accountinfo *info)
{
	CString id,phone;
	id.Format(_T("%d"),info->getid());
	phone.Format(_T("%d"),info->getp());
	e_addfirstname.SetWindowTextW(info->getf());//FirstName
	e_addlastname.SetWindowTextW(info->getl());//Lastname
	e_addaddress.SetWindowTextW(info->geta());//Adress
	e_addaccountbirthday.SetWindowTextW(info->getb());//Date of Birth
	e_addid.SetWindowTextW(id);
	e_addphone.SetWindowTextW(phone);
}
void newaccaunt::getfromeditbox()
{
	CString cs_firstname,cs_lastname,cs_adress,cs_datebirth,cs_id,cs_phone;
	e_addfirstname.GetWindowTextW(cs_firstname);//FirstName
	e_addlastname.GetWindowTextW(cs_lastname);//Lastname
	e_addaddress.GetWindowTextW(cs_adress);//Adress
	e_addaccountbirthday.GetWindowTextW(cs_datebirth);//Date of Birth
	e_addid.GetWindowTextW(cs_id);//id of person
	e_addphone.GetWindowTextW(cs_phone);
	accountinfos->setf(cs_firstname);
	accountinfos->setl(cs_lastname);
	accountinfos->seta(cs_adress);
	accountinfos->setb(cs_datebirth);
	accountinfos->setid(_ttoi(cs_id));
	accountinfos->setp(_ttoi(cs_phone));
}//to edit account
void newaccaunt::OnBnClickedBtnEditaccount()
{
	getfromeditbox();
	// TODO: Add your control notification handler code here
}


void newaccaunt::OnBnClickedBtnOknew()
{
	CDialogEx::OnOK();
	// TODO: Add your control notification handler code here
}
