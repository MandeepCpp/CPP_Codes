#include<iostream>
using namespace std;


class Strategy
{
    public:
    virtual void AlgorithmInterface()=0;
};

class StrategyA : public Strategy
{
    public:
    void AlgorithmInterface()
    {
        cout<< "Running A Strategy"<<endl;
    }
};
class StrategyB : public Strategy
{
    public:
    void AlgorithmInterface()
    {
        cout<< "Running B Strategy"<<endl;
    }
};
class StrategyC : public Strategy
{
    public:
    void AlgorithmInterface()
    {
        cout<< "Running C Strategy"<<endl;
    }
};


class Context
{
    private:
    Strategy *stragegy;

    public:
    void SetStragegy(Strategy *obj)
    {
        stragegy = obj;
    }

    Strategy* getStrategy()
    {
        return stragegy;
    }

    void ContextInterface()
    {
        stragegy->AlgorithmInterface();
    }


};
int main()
{
   StrategyA * strat_a = new StrategyA();
   StrategyB * strat_b = new StrategyB();
   StrategyC * strat_c = new StrategyC();
   Context * contxt = new Context();




    contxt->SetStragegy(strat_a);
    contxt->ContextInterface();


    cout<<"After sometime 1"<<endl;

    contxt->SetStragegy(strat_b);
    contxt->ContextInterface();

    cout<<"After sometime 2"<<endl;

    contxt->SetStragegy(strat_c);
    contxt->ContextInterface();

    return 0;
}