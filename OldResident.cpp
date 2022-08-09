#include "pch.h"
#include "OldResident.h"

IMPLEMENT_SERIAL(OldResident, CObject, 1);

OldResident::OldResident(int iId, double iMoney, int iResidentSpecialNumber, double iAge)
	: CityResidentDriver(iId, iMoney, iResidentSpecialNumber)
{
	//"In OldResident cto'r"
	setAge(iAge);
}

OldResident::~OldResident()
{
	//"In OldResident dto'r"
}

void OldResident::setAge(const double iAge)
{
	if (iAge <= 65.5)
	{
		this->mDiscount = 10;
		AfxMessageBox(L"Your age is not valid for discount...");
	}
	else if (iAge > 65.5 && iAge <= 120)
	{

		this->mDiscount = 8;
		MessageBox(NULL, L"Your age is valid for discount :)", L"Old resident Message", 0);
	}
	this->mAge = iAge;
}

void OldResident::pay()
{
	if (this->mMoney != 0)
	{
		if (this->mResidentSpecialNumber != 0 && this->mMoney - 10 >= 0)
		{
			if (this->mDiscount == 8)
			{
				this->mMoney -= 8.4;
			}
			else
			{
				this->mMoney -= 10;
			}
		}
		if (this->mResidentSpecialNumber == 0 && this->mMoney - 20 >= 0)
			this->mMoney -= 20;
	}
	else if (this->mMoney <= 0)
	{
		AfxMessageBox(L"Sorry, your money is over...");
	}
}

void OldResident::setId(const int iId)
{
	CityResidentDriver::setId(iId);
}

void OldResident::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << mID;
		ar << mMoney;
		ar << mDiscount;
		ar << mResidentSpecialNumber;
		ar << mAge;
	}
	else
	{
		ar >> mID;
		ar >> mMoney;
		ar >> mDiscount;
		ar >> mResidentSpecialNumber;
		ar >> mAge;
	}
}