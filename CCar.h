#ifndef C_CAR_H
#define C_CAR_H

#include "CVehicle.h"

class CCar : public CVehicle {
public:
    CCar(double price, double speed, int year, int passengerCount);
    virtual ~CCar();

    void SetPassengerCount(int passengerCount);
    int GetPassengerCount() const;

    virtual void ShowInfo() const override;

private:
    int m_passengerCount;
};

#endif