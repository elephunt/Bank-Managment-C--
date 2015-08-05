#include "stdafx.h"
#include  "teller.h"

teller::teller()
{

}
void teller::addaccountbyteller(accountinfo x)
{

	accountinfo y(x);
	addaccount(y);
}
bool teller::closeaccount(int x)
{
	CString a;
	a="NotActive";
	account *acc;
	acc=getaccount(x);
	if(acc->getbalance()==0)
	{
		acc->setstatus(a);
		return true;
	}
	return false;
}


void teller::deposit(int sum,account  *acc1)
{
	if(checkdeposit(sum,acc1))
	{
		acc1->setbalance((acc1->getbalance())+sum-(acc1->getf()));
	}
}
void teller::withdraw(int sum,account *acc1)
{
	if(checkwithdraw(sum,acc1))
	{
		acc1->setbalance((acc1->getbalance())-sum-(acc1->getf()));
	}
}
bool teller::transfer1(account *acc1,account *acc2,int sum)
{
	if(transfer(acc1,acc2,sum))
	{
         withdraw(sum,acc1);
		 deposit(sum,acc2);
		 return true;
	}
	return false;
}