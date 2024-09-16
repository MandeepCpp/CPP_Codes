#include<iostream>
using namespace std;

// it creates objects for you(client), rather you initiating object directly
// FDP is used for separating object creation logic from the main client code
// for getting new object, we can call factory method and it returns the desired object
class Vehicle
{
    public:
    virtual void createVehicle()=0;
};

class Car : public Vehicle
{
    public:
    void createVehicle();
};
class Bike : public Vehicle
{
    public:
    void createVehicle();
};


void Car :: createVehicle()
{
    cout<<"creating car"<<endl;
}
void Bike :: createVehicle()
{
    cout<<"creating bike"<<endl;
}


class VehicleFactory
{
    public:
    static Vehicle* getVehicle(int vehicleType);
};

// only i need to change this part of code in future, client code will not change
Vehicle* VehicleFactory:: getVehicle(int vehicleType)
{
    Vehicle * vehicle;
    if(vehicleType==1)
    {
        vehicle = new Car();
    }
   else if(vehicleType==2)
    {
        vehicle = new Bike();
    }
    else
    {
        cout<<"this type of vehicle is not created yet"<<endl;
    }

    return vehicle;
}

int main()
{
   int input = 1;
   Vehicle * vehicle = VehicleFactory::getVehicle(input);
   vehicle->createVehicle();
    return 0;
}