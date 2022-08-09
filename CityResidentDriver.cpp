#include "pch.h"
#include "CityResidentDriver.h"

IMPLEMENT_SERIAL(CityResidentDriver, CObject, 1);

CityResidentDriver::CityResidentDriver(int iId, double iMoney, int iResidentSpecialNumber)
{
	//"In CityResidentDriver cto'r"
	setId(iId);
	setMoney(iMoney);
	setResidentSpecialNumber(iResidentSpecialNumber);
}

CityResidentDriver::~CityResidentDriver()
{
	//"In CityResidentDriver dto'r"
}

void CityResidentDriver::setResidentSpecialNumber(int iResidentSpecialNumber)
{

	if (iResidentSpecialNumber % 2 == 0 && iResidentSpecialNumber % 3 == 0) //conditions for special
	{
		MessageBox(NULL, L"Your resident special number was found in the system :)", L"Resident Message", 0);
		this->mResidentSpecialNumber = iResidentSpecialNumber;
		this->mDiscount = 10;
	}
	else
	{
		AfxMessageBox(L"Sorry, your resident special number was not found in the system :(");
		this->mResidentSpecialNumber = 0;
		this->mDiscount = 0;
	}

}

void CityResidentDriver::pay()
{
	if (this->mMoney != 0)
	{
		if (this->mDiscount == 10 && this->mMoney - 10 >= 0)
		{
			this->mMoney -= 10;
		}
		else if (this->mDiscount == 0 && this->mMoney - 20 >= 0)
		{
			this->mMoney -= 20;
		}
		else
		{
			AfxMessageBox(L"Sorry, your money is not enough...");
			this->mDiscount = 1; // If the payment not occurred.
		}
	}
	else if (this->mMoney <= 0)
	{
		AfxMessageBox(L"Sorry, your money is over...");
	}
}

void CityResidentDriver::setId(const int iId)
{
	if (iId < 100000000 || iId > 999999999)
	{
		AfxMessageBox(L"ID invalid (insert 9 number only)\nYour ID uptdate to default ID");
		this->mID = 111111111;
	}
	else
	{
		MessageBox(NULL, L"ID is valid", L"Resident Message", 0);
		this->mID = iId;
	}
}

void CityResidentDriver::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << mID;
		ar << mMoney;
		ar << mDiscount;
		ar << mResidentSpecialNumber;
	}
	else
	{
		ar >> mID;
		ar >> mMoney;
		ar >> mDiscount;
		ar >> mResidentSpecialNumber;
	}
}
