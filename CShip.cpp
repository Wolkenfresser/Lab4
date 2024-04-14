#include "CShip.h"
#include <iostream>

CShip::CShip(double price, double speed, int year, const std::string& homePort, int passengerCount)
    : CVehicle(price, speed, year), m_homePort(homePort), m_passengerCount(passengerCount) {}

CShip::~CShip() {}

void CShip::SetHomePort(const std::string& homePort) {
    m_homePort = homePort;
}

std::string CShip::GetHomePort() const {
    return m_homePort;
}

void CShip::SetPassengerCount(int passengerCount) {
    m_passengerCount = passengerCount;
}

int CShip::GetPassengerCount() const {
    return m_passengerCount;
}

void CShip::ShowInfo() const {
    double latitude, longitude;
    GetCoordinates(latitude, longitude);
    std::cout << "Ship Info:\n"
        << "Coordinates: (" << latitude << ", " << longitude << ")\n"
        << "Price: $" << GetPrice() << "\n"
        << "Speed: " << GetSpeed() << " km/h\n"
        << "Year: " << GetYear() << "\n"
        << "Home Port: " << m_homePort << "\n"
        << "Passenger Count: " << m_passengerCount << "\n";
}