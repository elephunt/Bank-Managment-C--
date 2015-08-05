#ifndef BANKINTERFACE_H
#define BANKINTERFACE_H

#include <iostream>
#include <vector>
#include <CString>
#include "accountinfo.h"
# include "KindofAccount1.h"
using namespace std;
class bankinterface
{
protected:
	static vector<accountinfo>accountss;
	public:
	bankinterface();
	void addaccount(accountinfo x);
	accountinfo* searchid(int x);
	accountinfo* searchname(CString n,CString l);
	accountinfo* searchaccountnumber(int accountnumber);
	void searchaccountnum(accountinfo x);
	bool searchbyid(int id);
	bool searchbyname(CString name,CString lastname);
	bool searcbyaccountnumber(int acc);
	account *getaccount(int acc);
	bool checkwithdraw(int sum,account *ac1);
	bool checkdeposit(int sum,account *ac1);
	bool transfer(account *acc1,account *acc2,int sum);
};

#endif
