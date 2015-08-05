# ifndef accountinfoINFO_H
# define accountinfoINFO_H
#include <CString>
#include <vector>
#include <iostream>
#include "KindofAccount1.h"

using namespace std;

class accountinfo
{
private:

protected:
	
	CString firstn,lastn,birth,adress;
	CString  kind;
	int phone;
	int id;
	
	
public:
	account *acc1;
	vector<account*>accountss;
	//------------------------------------Info of person----------------------------//
	accountinfo();//default constructer
	accountinfo(CString e,CString b,CString c,CString d,int id,int phone,CString kind);
	//accountinfo(CString a,CString b);//first name and last name
	accountinfo(const  accountinfo &acc);//copy constructer
	void setf(CString f);//set first name
	void setl(CString l);//set last name
	void setb(CString b);//set birth date
	void seta(CString ad);//set an adress
	void setp(int p);//set phone number
	void setid(int i);//set ID number
	CString getf();//get a first name
	CString getl();//get last name
	CString getb();//get birth date
	CString geta();//get an adress
	int getp();//get phone number
	int getid();//get ID number
	account* getaccounts();
	
	//------------------------------Info of kind of costumer--------------------------------------------------//
	CString getkind();//what kind an account(gold,premium,regular)
	void setkind(CString cool);//set kind of account(gold,premium,regular)
};
# endif