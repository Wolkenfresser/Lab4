#ifndef C_VEHICLE_H
#define C_VEHICLE_H

class CVehicle {
public:
    CVehicle(double price, double speed, int year);
    virtual ~CVehicle();

    void SetCoordinates(double latitude, double longitude);
    void GetCoordinates(double& latitude, double& longitude) const;

    double GetPrice() const;
    double GetSpeed() const;
    int GetYear() const;

    virtual void ShowInfo() const = 0; // чисто виртуальная функция
private:
    double m_latitude;
    double m_longitude;
    double m_price;
    double m_speed;
    int m_year;
};

#endif