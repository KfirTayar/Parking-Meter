#pragma once
#include "ForeignDriver.h"
class Student :
    public ForeignDriver
{
private:
    DECLARE_SERIAL(Student)
    CString mPromoCode;
    int mDiscount = 0;

public:
    Student() {} //for serialization
    Student(CString iName, CString iAddress, int iId = 111111111, double iMoney = 0, CString iPromoCode = _T("Not a student"));
    ~Student();

    CString getPromoCode() const { return this->mPromoCode; }
    void setPromoCode(const CString iPromoCode);

    // virtual functions
    virtual void pay();
    virtual int getID() { return this->mID; }
    virtual int getDriverId() { return mID; }
    virtual void setId(const int iId);
    virtual double getMoney() { return mMoney; }
    virtual void setMoney(const double iMoney) { this->mMoney = iMoney; }
    virtual void Serialize(CArchive& ar);
};


