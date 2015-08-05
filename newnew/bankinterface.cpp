#include "stdafx.h"
#include "Bankinterface.h"
std::vector<accountinfo> bankinterface::accountss;
bankinterface::bankinterface()
{


}
void bankinterface::addaccount(accountinfo x)
{
	accountss.push_back(x);
	

}
accountinfo* bankinterface::searchid(int x)
{

	for(int i=0;i<accountss.size();i++)
		if(x==accountss[i].getid())
		return &(accountss[i]);	
	return &(accountss[0]);   //CHANGE
}
bool bankinterface::searchbyid(int i)
{
	for(int j=0;j<accountss.size();j++)
		if(i==accountss[j].getid())
		        return true;	
	return false;
}
bool bankinterface::searchbyname(CString f,CString l)
{
	for(int j=0;j<accountss.size();j++)
		if(f==accountss[j].getf() && l==accountss[j].getl() )
		                  return true;	
	return false;
}
bool bankinterface::searcbyaccountnumber(int acc)
{
	for(int j=0;j<accountss.size();j++)
		for(int k=0;k<accountss[j].accountss.size();k++)
		     if(acc==accountss[j].accountss[k]->getaccountnumber())//getting to accountinfo,to vector of account of person
		             return true;	
	return false;
}
accountinfo* bankinterface::searchname(CString f,CString l)
{
	for(int j=0;j<accountss.size();j++)
		if(f==accountss[j].getf() && l==accountss[j].getl() )
			return &(accountss[j]);
	return &(accountss[0]);
}
accountinfo* bankinterface::searchaccountnumber(int x)
{
	for(int j=0;j<accountss.size();j++)
		for(int k=0;k<accountss[j].accountss.size();k++)
		     if(x==accountss[j].accountss[k]->getaccountnumber())
				 return &(accountss[j]);
}
account* bankinterface::getaccount(int x)
{
	for(int j=0;j<accountss.size();j++)
		for(int k=0;k<accountss[j].accountss.size();k++)
		     if(x==accountss[j].accountss[k]->getaccountnumber())
				 return (accountss[j].accountss[k]);
}
bool bankinterface::checkwithdraw(int sum,account *ac1)
{
	
	if((ac1->getbalance()+ac1->getallow()-ac1->getf()-sum)>=0)
	{
			 return true;
	}
	else 
		return false;
}
bool bankinterface::checkdeposit(int sum,account *ac1)
{
	
	if((ac1->getbalance()+ac1->getallow()-ac1->getf()+sum)>=0)
	{
		return true;
	}
	return false;
}
bool bankinterface::transfer(account *acc1,account *acc2,int sum)
{	
	if(checkwithdraw(sum,acc1) && checkdeposit(sum,acc2))
	{
		 return true;
	}
	return false;
}