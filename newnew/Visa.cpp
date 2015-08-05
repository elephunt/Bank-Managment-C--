# include "stdafx.h"
# include "Visa.h"
int visa::accnum=10000;
int visa::pin=1111;
visa::visa() 
{
	accnum++;
	pin++;
}
//visa::visa(int pinc,int acc)
//{
//	pin=pinc;
//	accnum=acc;
//}
//void visa::setaccnum()
// {
//	 cin>>accnum;
// }//initialize account number
//void visa::setpin()
//{
//	cin>>pin;
//}//initialize pin code
int  visa::getpin()
{
	return pin;
}
int  visa::getaccnum()
{
	return accnum;
}