#include "CVehicle.h"

CVehicle::CVehicle(double price, double speed, int year)
    : m_latitude(0), m_longitude(0), m_price(price), m_speed(speed), m_year(year) {}

CVehicle::~CVehicle() {}

void CVehicle::SetCoordinates(double latitude, double longitude) {
    m_latitude = latitude;
    m_longitude = longitude;
}

void CVehicle::GetCoordinates(double& latitude, double& longitude) const {
    latitude = m_latitude;
    longitude = m_longitude;
}

double CVehicle::GetPrice() const {
    return m_price;
}

double CVehicle::GetSpeed() const {
    return m_speed;
}

int CVehicle::GetYear() const {
    return m_year;
}