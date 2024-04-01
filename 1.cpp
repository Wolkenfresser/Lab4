/*Создать абстрактный класс CVehicle. На его основе реализовать классы CPlane, 
ССаг и CShip. Классы должны иметь возможность задавать и получать координаты, параметры средств передвижения (цена, скорость, год выпуска). Для самолета должна быть определена высота, для самолета и корабля — количество пассажиров. Для корабля — порт приписки. 
Написать программу, создающую список объектов этих классов в динамической 
памяти. Программа должна содержать меню, позволяющее осуществить проверку всех методов кла*/
#include <iostream>
#include <string>
#include <vector>

class CVehicle {
protected:
    double price;
    double speed;
    int year;

public:
    CVehicle(double _price, double _speed, int _year) : price(_price), speed(_speed), year(_year) {}
    virtual ~CVehicle() {}

    virtual void SetCoordinates(double lat, double lon) = 0;
    virtual void GetCoordinates() const = 0;
    virtual void DisplayInfo() const {
        std::cout << "Price: " << price << std::endl;
        std::cout << "Speed: " << speed << std::endl;
        std::cout << "Year: " << year << std::endl;
    }
};

class CPlane : public CVehicle {
private:
    double altitude;

public:
    CPlane(double _price, double _speed, int _year, double _altitude) : CVehicle(_price, _speed, _year), altitude(_altitude) {}

    void SetCoordinates(double lat, double lon) override {
        // implement coordinates setting for plane
    }

    void GetCoordinates() const override {
        // implement coordinates getting for plane
    }

    void DisplayInfo() const override {
        CVehicle::DisplayInfo();
        std::cout << "Altitude: " << altitude << std::endl;
    }
};

class CCar : public CVehicle {
private:
    int passengers;

public:
    CCar(double _price, double _speed, int _year, int _passengers) : CVehicle(_price, _speed, _year), passengers(_passengers) {}

    void SetCoordinates(double lat, double lon) override {
        // implement coordinates setting for car
    }

    void GetCoordinates() const override {
        // implement coordinates getting for car
    }

    void DisplayInfo() const override {
        CVehicle::DisplayInfo();
        std::cout << "Passengers: " << passengers << std::endl;
    }
};

class CShip : public CVehicle {
private:
    int passengers;
    std::string port;

public:
    CShip(double _price, double _speed, int _year, int _passengers, const std::string& _port) : CVehicle(_price, _speed, _year), passengers(_passengers), port(_port) {}

    void SetCoordinates(double lat, double lon) override {
        // implement coordinates setting for ship
    }

    void GetCoordinates() const override {
        // implement coordinates getting for ship
    }

    void DisplayInfo() const override {
        CVehicle::DisplayInfo();
        std::cout << "Passengers: " << passengers << std::endl;
        std::cout << "Port: " << port << std::endl;
    }
};

int main() {
    std::vector<CVehicle*> vehicles;
    char choice;

    do {
        std::cout << "1. Add a plane\n"
            << "2. Add a car\n"
            << "3. Add a ship\n"
            << "4. Display all vehicles\n"
            << "5. Exit\n"
            << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case '1': {
            double price, speed, altitude;
            int year;
            std::cout << "Enter price, speed, year, altitude: ";
            std::cin >> price >> speed >> year >> altitude;
            vehicles.push_back(new CPlane(price, speed, year, altitude));
            break;
        }
        case '2': {
            double price, speed;
            int year, passengers;
            std::cout << "Enter price, speed, year, passengers: ";
            std::cin >> price >> speed >> year >> passengers;
            vehicles.push_back(new CCar(price, speed, year, passengers));
            break;
        }
        case '3': {
            double price, speed;
            int year, passengers;
            std::string port;
            std::cout << "Enter price, speed, year, passengers, port: ";
            std::cin >> price >> speed >> year >> passengers >> port;
            vehicles.push_back(new CShip(price, speed, year, passengers, port));
            break;
        }
        case '4':
            for (const auto& vehicle : vehicles) {
                vehicle->DisplayInfo();
                std::cout << std::endl;
            }
            break;
        case '5':
            // Clean up dynamically allocated memory
            for (auto& vehicle : vehicles) {
                delete vehicle;
            }
            vehicles.clear();
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != '5');

    return 0;
}
