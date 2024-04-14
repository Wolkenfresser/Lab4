#ifndef C_SHIP_H
#define C_SHIP_H

#include "CVehicle.h"

class CShip : public CVehicle {
public:
    CShip(double price, double speed, int year, const std::string& homePort, int passengerCount);
    virtual ~CShip();

    void SetHomePort(const std::string& homePort);
    std::string GetHomePort() const;

    void SetPassengerCount(int passengerCount);
    int GetPassengerCount() const;

    virtual void ShowInfo() const override;

private:
    std::string m_homePort;
    int m_passengerCount;
};

#endif