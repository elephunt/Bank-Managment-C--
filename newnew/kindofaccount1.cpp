#include "stdafx.h"
#include "KindofAccount1.h"
student::student()
{
	fee=0;
	allowash=0;
}
student::student(double f,int w,double balance,CString status,CString date):fee(f),allowash(w),account(status,balance,date)
{
	
}

int student::getallow()
{
	return allowash;
}
double student::getf()
	
{
	return fee;
}


privatea::privatea(double fee1,int ashrai,double balance,CString status,CString date):student(fee1,ashrai,balance,status,date)
{
}


buisness::buisness(double fee1,int ahsrai,double balance,CString status,CString date):privatea(fee1,ahsrai,balance,status,date)
{

}