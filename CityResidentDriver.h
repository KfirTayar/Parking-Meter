#pragma once
#include "pch.h"
#include "Driver.h"
class CityResidentDriver :
    public Driver
{
private:
    DECLARE_SERIAL(CityResidentDriver)
    int mID;
    double mMoney;
    int mDiscount;
    int mResidentSpecialNumber;

public:
    CityResidentDriver() {} //for serialization
    CityResidentDriver(int iId, double iMoney = 0, int iResidentSpecialNumber = 0);
    ~CityResidentDriver();

    int getResidentSpecialNumber() const { return mResidentSpecialNumber; }
    void setResidentSpecialNumber(const int iResidentSpecialNumber);

    // virtual functions
    virtual void pay();
    virtual int getID() { return this->mID; }
    virtual int getDriverId() { return mID; }
    virtual void setId(const int iId);
    virtual double getMoney() { return mMoney; }
    virtual void setMoney(const double iMoney) { this->mMoney = iMoney; }
    virtual void Serialize(CArchive& ar);
};


