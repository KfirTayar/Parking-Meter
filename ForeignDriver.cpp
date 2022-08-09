#include "pch.h"
#include "ForeignDriver.h"

IMPLEMENT_SERIAL(ForeignDriver, CObject, 1);

ForeignDriver::ForeignDriver(CString iName, CString iAddress, int iId, double iMoney)
{
	//"In ForeignDriver cto'r"
	setAddress(iAddress);
	setName(iName);
	setId(iId);
	setMoney(iMoney);
}

ForeignDriver::~ForeignDriver()
{
	//"In ForeignDriver dto'r"
}

void ForeignDriver::setName(const CString& iName)
{
	if (iName == "")
	{
		AfxMessageBox(L"Your name is invalid!\nUpdateing a defualt name to Person");
		this->mName = "Person";
	}
	else
	{
		this->mName = iName;
	}
}

void ForeignDriver::pay()
{
	if (this->mMoney != 0 && this->mMoney - 20 >= 0)
	{
		this->mMoney -= 20;
	}
	else if (this->mMoney > 0 && this->mMoney < 20)
	{
		AfxMessageBox(L"Sorry, your money is not enough...");
	}
	else
	{
		AfxMessageBox(L"Sorry, your money is over...");
	}
}

void ForeignDriver::setId(int iId)
{
	if (iId < 100000000 || iId > 999999999)
	{
		AfxMessageBox(L"ID invalid (insert 9 number only)\nYour ID uptdate to default ID");
		this->mID = 111111111;
	}
	else
	{
		MessageBox(NULL, L"ID is valid", L"Foreign Message", 0);
		this->mID = iId;
	}
}

void ForeignDriver::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << mAddress;
		ar << mName;
		ar << mMoney;
		ar << mID;
	}
	else
	{
		ar >> mAddress;
		ar >> mName;
		ar >> mMoney;
		ar >> mID;
	}
}
