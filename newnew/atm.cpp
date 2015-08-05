# include "stdafx.h"
# include "ATM.h"
//std::vector<accountinfo> bankinterface::accountss;
int atm::hundrets=500;
int  atm::tweenties=500;
int atm::fiftes=500;
int atm::balance=85000;
atm::atm()
{
	hundrets=500;
	fiftes=500;
	tweenties=500;
	balance=85000;
}
void atm::viewbalance(account *acc)
{
	acc->getbalance();
}
bool atm::permission(int acc,int pin)
{
	account *accoun;
	if(searcbyaccountnumber(acc))
	{
		accoun=getaccount(acc);
		if(accoun->getpinvisa()==pin)
			return true;
	}
	return false;
}
bool atm::withdraw(account *k,int sum)
{
	if(checkwithdraw(sum,k) && checkifwithdraw(sum))
	{
		k->setbalance((k->getbalance())-sum-(k->getf()));
		return true;
	}
	return false;
}
bool atm::checkifwithdraw(int sum)
{
	int counttw=0,countfift=0,counthun=0;
	if(balance<sum || sum%10!=0 || sum<10)
		return false;
	while(sum>0)
	{
     if(sum%100==0)
	 {
		 counthun=sum/100;
		 hundrets-counthun;
		 tweenties-counttw;
		 return true;
	 }
	 else if(sum%50==0)
	 {
		 countfift=sum/50;
		 fiftes-countfift;
		 tweenties-counttw;
		 return true;
	 }
		 sum-20;
		 counttw++;
		 if(sum==0)
		 {
          tweenties-counttw;
		  return true;
		 }
	
	}
	return false;
}
bool atm::transfer(account *a,account *b,int sum)
{

	if(withdraw(a,sum) && deposit(b,sum))
	{
		return true;
	}
	return false;
}

bool atm::deposit(account *a,int sum)
{
	if(checkdeposit(sum,a) )
	{
		a->setbalance((a->getbalance())+sum-(a->getf()));
		return true;
	}
	return false;

}
