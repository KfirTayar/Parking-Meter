#include "pch.h"
#include "Student.h"

IMPLEMENT_SERIAL(Student, CObject, 1);

Student::Student(CString iName, CString iAddress, int iId, double iMoney, CString iPromoCode)
	: ForeignDriver(iName, iAddress, iId, iMoney)
{
	//"In Student cto'r"
	setPromoCode(iPromoCode);
}

Student::~Student()
{
	//"In Student dto'r"
}

void Student::setPromoCode(const CString iPromoCode)
{
	if (iPromoCode == "StudentIL")
	{
		this->mDiscount = 15;
		MessageBox(NULL, L"Your student code is valid :)", L"Student Message", 0);
	}
	else
	{
		this->mDiscount = 0;
	}
}

void Student::pay()
{
	if (this->mMoney != 0)
	{
		if (this->mDiscount != 0 && this->mMoney - 10 >= 0)
		{
			this->mMoney -= 15;
		}
		if (this->mDiscount == 0 && this->mMoney - 20 >= 0)
		{
			this->mMoney -= 20;
		}
	}
	else if (this->mMoney <= 0)
	{
		AfxMessageBox(L"Sorry, your money is over...");
	}
}

void Student::setId(const int iId)
{
	ForeignDriver::setId(iId);
}

void Student::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << mAddress;
		ar << mMoney;
		ar << mName;
		ar << mID;
		ar << mDiscount;
		ar << mPromoCode;
	}
	else
	{
		ar >> mAddress;
		ar >> mMoney;
		ar >> mName;
		ar >> mID;
		ar >> mDiscount;
		ar >> mPromoCode;
	}
}