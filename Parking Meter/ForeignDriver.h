#pragma once
#include "Driver.h"
class ForeignDriver :
    public Driver
{
private:
    DECLARE_SERIAL(ForeignDriver)
    CString mAddress;
    CString mName;
    double mMoney;
    int mID;

public:
    ForeignDriver() {} //for serialization
    ForeignDriver(CString iName, CString iAddress, int iId = 111111111, double iMoney = 0);
    ~ForeignDriver();

    //Setters & getters
    CString getAddress() const { return mAddress; }
    void setAddress(const CString& iAddress) { this->mAddress = iAddress; }
    CString getName()const { return mName; }
    void setName(const CString& iName);

    //virtual functions
    virtual void pay();
    virtual int getID() { return this->mID; }
    virtual void setId(int iId);
    virtual double getMoney() { return mMoney; }
    virtual void setMoney(double iMoney) { this->mMoney = iMoney; }
    virtual int getDriverId() { return mID; }
    virtual void Serialize(CArchive& ar);
};



