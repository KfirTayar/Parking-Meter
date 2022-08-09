#pragma once
//
#include <iostream>
#include <string>
using namespace std;

class Driver : public CObject
{
public:
	virtual int getID() = 0;
	virtual void pay() = 0;
	virtual int getDriverId() = 0;
	virtual void setId(int iId) = 0;
	virtual double getMoney() = 0;
	virtual void setMoney(double iMoney) = 0;
	virtual void Serialize(CArchive& ar) = 0;
};
