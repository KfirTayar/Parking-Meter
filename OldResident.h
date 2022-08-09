#pragma once
#include "CityResidentDriver.h"
class OldResident :
    public CityResidentDriver
{
private:
    DECLARE_SERIAL(OldResident)
    double mAge;

public:
    OldResident() {} //for serialization
    OldResident(int iId, double iMoney = 0, int iResidentSpecialNumber = 0, double iAge = 0);
    ~OldResident();

    int getResidentSpecialNumber() const { return mResidentSpecialNumber; }
    double getAge() const { return this->mAge; }
    void setAge(const double iAge);

    // virtual functions
    virtual void pay();
    virtual int getID() { return this->mID; }
    virtual int getDriverId() { return mID; }
    virtual void setId(const int iId);
    virtual double getMoney() { return mMoney; }
    virtual void setMoney(const double iMoney) { this->mMoney = iMoney; }
    virtual void Serialize(CArchive& ar);
};

