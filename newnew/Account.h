# ifndef ACCOUNT_H
# define ACCOUNT_H
# include "stdafx.h"
# include "Visa.h"
# include <iostream>
using namespace std;
class account
{
private:
		visa v;
protected:	
	int accnumber;//account number
	CString date,status;//data of opening account,status of account
	double balance;//balance on account
public:
	//vector<accountinfo>hatima;
	account(CString stat,double bal,CString d);
	account();//constructer
	void setdate(CString x);//set date
	void setstatus();//set status
	void setstatus(CString x);
	void setbalance();//set balance
	CString getdate();//get date
	CString getstatus();//get status
	double getbalance();//get balance
	void setbalance(double x);
	void setaccountnumber();
	int getaccountnumber();
	 int getpinvisa();
	//~account();//destructor
	//---------------------------------------student--------------------//
//	virtual void studentbalance()=0;//checkin balance of student
	virtual double getf()=0;//to get a fee
	virtual int getallow()=0;//get allow ashari
	//-----------------------------------------check account--------------//
};
# endif


