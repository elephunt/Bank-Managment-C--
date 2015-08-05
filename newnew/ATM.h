# ifndef ATM_H
# define ATM_H
# include "Bankinterface.h"
class atm:public bankinterface
{
protected:
	static int  hundrets;
	static  int fiftes;
	static  int tweenties;
	static int balance;
	//static vector<accountinfo>accountss;
public:
	atm();
	bool checkifwithdraw(int sum);//check amount of money in atm
	void setbalance();
	int getbalance();
	int gethoundredts();
	int getfiftees();
	int gettwenties();
	bool deposit(account *a,int sum);
	bool withdraw(account *c,int sum);
	void showbalance();
	bool transfer(account *a,account *b,int sum);
	void viewbalance(account *acc);
	bool permission(int acc,int pin);
};
# endif