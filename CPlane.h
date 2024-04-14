#ifndef C_PLANE_H
#define C_PLANE_H

#include "CVehicle.h"

class CPlane : public CVehicle {
public:
    CPlane(double price, double speed, int year, double altitude, int passengerCount);
    virtual ~CPlane();

    void SetAltitude(double altitude);
    double GetAltitude() const;

    void SetPassengerCount(int passengerCount);
    int GetPassengerCount() const;

    virtual void ShowInfo() const override;

private:
    double m_altitude;
    int m_passengerCount;
};

#endif