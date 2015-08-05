#include "stdafx.h"
# include "AccountInfo.h"
void accountinfo::setf(CString f)
{
   firstn=f;
}//set first name
void accountinfo::setl(CString l)
	{

			lastn=l;
	}//set last name
void accountinfo::setb(CString bir)
	{
		birth=bir;
	}//set birth date
void accountinfo:: seta(CString ad)
{
	adress=ad;
}//set an adress
void accountinfo::setp(int p)
{
	phone=p;
}//set phone number
void accountinfo::setid(int i)
{
	id=i;
}
CString accountinfo::getf()
{
	return firstn;
}//get a first name
CString accountinfo::getl()
{
	return lastn;
}//get last name
CString  accountinfo::getb()
{
	return birth;
}//get birth date
CString accountinfo::geta()
{
	return adress;
}//get an adress
int accountinfo ::getp()
{
		return phone;
}//g
CString accountinfo::getkind()
{
	return kind;
}
void accountinfo::setkind(CString k)
{
	kind=k;
}
int accountinfo::getid()
{
	return id;
}
accountinfo::accountinfo()
{
	firstn="John";
	lastn="Smith";
	birth="1.1.1";
	adress="Wall Street";
	phone=666;
	id=1;
	kind="Regular";
}
accountinfo::accountinfo(CString e,CString b,CString c,CString d,int id,int phone,CString kind)
{
	setf(e);
	setl(b);
	setb(c);
	seta(d);
    setid(id); 
	setp(phone);
	setkind(kind);
}
account* accountinfo::getaccounts()
{
	return acc1;
}
accountinfo::accountinfo(const accountinfo & x)
{
	this->firstn=x.firstn;
	this->lastn=x.lastn;
	this->birth=x.birth;
	this->adress=x.adress;
	this->phone=x.phone;
	this->id=x.id;
	this->kind=x.kind;
	this->accountss=x.accountss;
}