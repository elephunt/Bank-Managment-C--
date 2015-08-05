# include "stdafx.h"
# include  "Account.h"
account::account()
{
	balance=0;
	status="NULL";
	date="Winter";
	accnumber=v.getaccnum();
//  accnumber=v.getaccnum();
}
void account::setdate(CString x)
{
   
}//set date
void account::setstatus()
{
	
}//set status
void account::setstatus(CString x)
{
	status=x;
}//set status
void account::setbalance()
{
	cin>>balance;
}//set balance
CString account::getdate()
{
	return date;
}//get date
CString account::getstatus()
{
	return status;
}//get status
double account::getbalance()
{
	return balance;
}
void account::setbalance(double x)
{
	balance=x;
}

void account::setaccountnumber()
{
	accnumber=v.getaccnum();
}
int account::getaccountnumber()
{
	return accnumber;
}
int account::getpinvisa()
{
	return v.getpin();
}
//account::~account()
//{
//	status="not active";
//	if(morhsei!=NULL)
//	delete morhsei;
//}
account::account(CString stat,double bal,CString d)
{
	
	status=stat;
	balance=bal;
	date=d;
	accnumber=v.getaccnum();
}