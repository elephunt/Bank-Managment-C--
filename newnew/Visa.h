# ifndef VISA_H
# define VISA_H
# include <CString>
# include <iostream>
using namespace std;
class visa
{
private:
	int static accnum;//account number
	int static pin;//pin code number
public:
	visa();//default constracter
	visa(int a,int b);//constracter
	//void setaccnum();//initialize account number
	//void setpin();//initialize pin code
    int getpin();
	int  getaccnum();
};



# endif