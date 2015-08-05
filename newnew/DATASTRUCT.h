#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <iostream>
#include <vector>
#include "accountinfo.h"
using namespace std;
class datastruct
{
protected:
	vector<accountinfo*>accounts;
	vector<accountinfo*>::iterator ptr;
public:
	datastruct();
	accountinfo searchid(int id);
	accountinfo searchaccounnum(int acountnum);
	accountinfo searchphone(int phone);
	accountinfo searchfirstname(int firstname);
	accountinfo searchlastname(int lastname);
};
#endif