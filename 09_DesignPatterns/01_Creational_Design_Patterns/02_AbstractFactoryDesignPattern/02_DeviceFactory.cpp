#include<iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;


class ISensor
{
    public:
    virtual void detect()=0;
};

class BMWSensor: public ISensor
{
    public:
    void detect()
    {
        cout<<"Sensor detecting with RADAR"<<endl;
    }
};
class TeslaSensor: public ISensor
{
    public:
    void detect()
    {
        cout<<"Sensor detecting with LIDAR"<<endl;
    }
};

class IControlUnit
{
    public:
    virtual void recordSignals()=0;
};

class BMWControlUnit: public IControlUnit
{
    public:
    void recordSignals()
    {
        cout<<"recoding file in rrex "<<endl;
    }
};
class TeslaControlUnit: public IControlUnit
{
    public:
    void recordSignals()
    {
        cout<<"recoding file in mp4 "<<endl;
    }
};

class IFactory
{
    public:
    virtual ISensor* CreateSensor()=0;
    virtual IControlUnit* CreateControlUnit()=0;
};
class BMWFactory:public IFactory
{
    public:
    ISensor* CreateSensor()
    {
        return new BMWSensor();
    }
    IControlUnit* CreateControlUnit()
    {
        return new BMWControlUnit();
    }
    
};
class TeslaFactory:public IFactory
{
    public:
    ISensor* CreateSensor()
    {
        return new TeslaSensor();
    }
    IControlUnit* CreateControlUnit()
    {
        return new TeslaControlUnit();
    }
    
};
class GUIAbsractFactory
{
    public:
    static IFactory * getFactory(int type)
    {
        if(type == 1)
        {
            return new BMWFactory();
        }
        else if(type == 2)
        {
            return new TeslaFactory();
        }
        else
        {
            cout<<"Nothing"<<endl;
        }
    }
};
int main()
{
    int osType = 1;
    IFactory* fact = GUIAbsractFactory::getFactory(osType);

    ISensor* sensor = fact->CreateSensor();
    sensor->detect();

    IControlUnit* ctrlunit = fact->CreateControlUnit();
    ctrlunit->recordSignals();

}