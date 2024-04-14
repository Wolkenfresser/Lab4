#include "CPlane.h"
#include <iostream>

CPlane::CPlane(double price, double speed, int year, double altitude, int passengerCount)
    : CVehicle(price, speed, year), m_altitude(altitude), m_passengerCount(passengerCount) {}

CPlane::~CPlane() {}

void CPlane::SetAltitude(double altitude) {
    m_altitude = altitude;
}

double CPlane::GetAltitude() const {
    return m_altitude;
}

void CPlane::SetPassengerCount(int passengerCount) {
    m_passengerCount = passengerCount;
}

int CPlane::GetPassengerCount() const {
    return m_passengerCount;
}

void CPlane::ShowInfo() const {
    double latitude, longitude;
    GetCoordinates(latitude, longitude);
    std::cout << "Plane Info:\n"
        << "Coordinates: (" << latitude << ", " << longitude << ")\n"
        << "Price: $" << GetPrice() << "\n"
        << "Speed: " << GetSpeed() << " km/h\n"
        << "Year: " << GetYear() << "\n"
        << "Altitude: " << m_altitude << " meters\n"
        << "Passenger Count: " << m_passengerCount << "\n";
}