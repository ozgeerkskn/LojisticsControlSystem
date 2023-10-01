#include <iostream>
using namespace std;

class Vehicle {
public:
    Vehicle();
    Vehicle(double distance, double averageSpeed)
        : distance_(distance), averageSpeed_(averageSpeed) {}



    void information_vehicle();

    virtual double CalculateFuelConsumption() {
    double consumption, time, fuel_efficiency = 32.5;
    time = distance_ / averageSpeed_;
    consumption = time * fuel_efficiency ;

    return consumption;
}

protected:
    double distance_;
    double averageSpeed_;
};

void Vehicle::information_vehicle() {

    cout << endl;
    cout << "Please enter the information below to find out how much fuel your vehicle needs." << endl;
    cout << "Enter distance (km): ";
    cin >> distance_;
    cout << "Enter average speed (km/h): ";
    cin >> averageSpeed_;
}



class Car : public Vehicle {
public:
    Car(double distance, double averageSpeed)
        : Vehicle(distance, averageSpeed) {

    }
    virtual double CalculateFuelConsumption() {
    double consumption, time;
    double fuel_efficiency = 10.0;

    time = (distance_) / averageSpeed_;
    consumption = (time ) * fuel_efficiency;

    return consumption;
}

};

class Truck : public Vehicle {
public:
    Truck(double distance, double averageSpeed)
        : Vehicle(distance, averageSpeed) {

    }
    virtual double CalculateFuelConsumption() {
    double consumption, time, fuel_efficiency = 25.5;
    time = distance_ / averageSpeed_;
    consumption = time * fuel_efficiency ;

    return consumption;
}
};

class Transport : public Vehicle {
public:
    Transport(double distance, double averageSpeed)
        : Vehicle(distance, averageSpeed) {}

    virtual double CalculateFuelConsumption() {
    double consumption, time, fuel_efficiency = 30.0;
    time = distance_ / averageSpeed_;
    consumption = time * fuel_efficiency ;

    return consumption;
}
};

class CargoPlane : public Vehicle {
public:
    CargoPlane(double distance, double averageSpeed)
        : Vehicle(distance, averageSpeed) {

    }
    virtual double CalculateFuelConsumption() {
    double consumption, time, fuel_efficiency = 35.5 ;
    time = distance_ / averageSpeed_;
    consumption = time * fuel_efficiency ;

    return consumption;
}

};

void display_menu(int &choice) {
    cout << "1. Car " << endl;
    cout << "2. Truck " << endl;
    cout << "3. Transport " << endl;
    cout << "4. Cargo Plane " << endl;
    cout << "5. Other vehicle " << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    system("cls");
}

int main() {
    double distance{0}, averageSpeed{0};
    int choice;

    Vehicle *vehicle = new Vehicle(distance, averageSpeed);
    Vehicle *car = new Car(distance, averageSpeed);
    Vehicle *truck = new Truck(distance, averageSpeed);
    Vehicle *transport = new Transport(distance, averageSpeed);
    Vehicle *cargoplane = new CargoPlane(distance, averageSpeed);

    display_menu(choice);

    switch (choice) {
        case 1:
            {


                car ->information_vehicle();
                cout << "Fuel consumption: " << car->CalculateFuelConsumption() << " litre" << endl;

                break;
            }
        case 2:
            {
                truck ->information_vehicle();
                cout << "Fuel consumption: " << truck->CalculateFuelConsumption() << " litre" << endl;

                break;
            }
        case 3:
            {
                transport ->information_vehicle();
                cout << "Fuel consumption: " << transport->CalculateFuelConsumption() << " litre" << endl;

                break;
            }
        case 4:
            {
                cargoplane ->information_vehicle();
                cout << "Fuel consumption: " << cargoplane->CalculateFuelConsumption() << " litre" << endl;

                break;
            }
        case 5:
             vehicle->information_vehicle();
             cout << "Fuel consumption: " << vehicle->CalculateFuelConsumption() << " litre" << endl;

             break;

        default:
                  cout << "ERROR: " << endl;

    }

    return 0;
}
