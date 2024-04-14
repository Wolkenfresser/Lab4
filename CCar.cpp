#include "CCar.h"
#include <iostream>

CCar::CCar(double price, double speed, int year, int passengerCount)
    : CVehicle(price, speed, year), m_passengerCount(passengerCount) {}

CCar::~CCar() {}

void CCar::SetPassengerCount(int passengerCount) {
    m_passengerCount = passengerCount;
}

int CCar::GetPassengerCount() const {
    return m_passengerCount;
}

void CCar::ShowInfo() const {
    double latitude, longitude;
    GetCoordinates(latitude, longitude);
    std::cout << "Car Info:\n"
        << "Coordinates: (" << latitude << ", " << longitude << ")\n"
        << "Price: $" << GetPrice() << "\n"
        << "Speed: " << GetSpeed() << " km/h\n"
        << "Year: " << GetYear() << "\n"
        << "Passenger Count: " << m_passengerCount << "\n";
}