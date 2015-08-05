#ifndef KINDOFACOUNT
#define KINDOFACOUNT
# include "Account.h"
class student:public account
{
protected:
	double fee;
	int  allowash;
	//what kind is account
public:
	student(double w,int s,double balance,CString status,CString date);
	student();//constructer
//	void studentbalance();//chekin balance
	double getf();
	int getallow();
};

class privatea:public student
{
protected:
public:
	privatea(double f,int a,double balance,CString status,CString date);
	privatea();
	//void checkprivate();
};

class buisness:public privatea
{
private:
public:
	buisness(double b,int ash,double balance,CString status,CString date);
};



#endif