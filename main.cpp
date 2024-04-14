/*Создать абстрактный класс CVehicle. На его основе реализовать классы CPlane, 
ССаг и CShip. Классы должны иметь возможность задавать и получать координаты, параметры средств передвижения (цена, скорость, год выпуска). Для самолета должна быть определена высота, для самолета и корабля — количество пассажиров. Для корабля — порт приписки. 
Написать программу, создающую список объектов этих классов в динамической 
памяти. Программа должна содержать меню, позволяющее осуществить проверку всех методов кла*/
#include "CPlane.h"
#include "CCar.h"
#include "CShip.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<CVehicle*> vehicles;

    // Создаем объекты классов CPlane, CCar и CShip
    CPlane* plane = new CPlane(1000000, 900, 2021, 10000, 200);
    CCar* car = new CCar(50000, 200, 2018, 5);
    CShip* ship = new CShip(2000000, 50, 2015, "New York", 500);

    // Добавляем объекты в вектор
    vehicles.push_back(plane);
    vehicles.push_back(car);
    vehicles.push_back(ship);

    int choice;
    do {
        std::cout << "Choose an option:\n"
            << "1. Set coordinates\n"
            << "2. Get coordinates\n"
            << "3. Get price\n"
            << "4. Get speed\n"
            << "5. Get year\n"
            << "6. Show info\n"
            << "0. Exit\n"
            << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            double latitude, longitude;
            std::cout << "Enter latitude: ";
            std::cin >> latitude;
            std::cout << "Enter longitude: ";
            std::cin >> longitude;

            for (auto vehicle : vehicles) {
                vehicle->SetCoordinates(latitude, longitude);
            }
            break;
        }
        case 2: {
            double latitude, longitude;
            for (auto vehicle : vehicles) {
                vehicle->GetCoordinates(latitude, longitude);
                std::cout << "Coordinates: (" << latitude << ", " << longitude << ")\n";
            }
            break;
        }
        case 3: {
            for (auto vehicle : vehicles) {
                std::cout << "Price: $" << vehicle->GetPrice() << "\n";
            }
            break;
        }
        case 4: {
            for (auto vehicle : vehicles) {
                std::cout << "Speed: " << vehicle->GetSpeed() << " km/h\n";
            }
            break;
        }
        case 5: {
            for (auto vehicle : vehicles) {
                std::cout << "Year: " << vehicle->GetYear() << "\n";
            }
            break;
        }
        case 6: {
            for (auto vehicle : vehicles) {
                vehicle->ShowInfo();
                std::cout << "\n";
            }
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }

    } while (choice != 0);

    // Удаляем объекты из вектора и освобождаем память
    for (auto vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}
