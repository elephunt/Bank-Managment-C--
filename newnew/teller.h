#ifndef TELLER_H
#define TELLER_H
#include "Bankinterface.h"

class teller:public bankinterface
{
public:
	teller();
	bool checkbalance(account *ac1,int sum);
	void addaccountbyteller(accountinfo x);
	bool closeaccount(int acc);
	//get to account number to transfer
	void withdraw(int sum,account *acc1);
	void deposit(int sum,account *acc1);
	bool transfer1(account *acc1,account *acc2,int sum);
};
#endif 