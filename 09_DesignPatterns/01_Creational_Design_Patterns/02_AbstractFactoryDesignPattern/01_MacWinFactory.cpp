#include<iostream>
using namespace std;


class IButton
{
    public:
    virtual void press()=0;
};

class MacButton: public IButton
{
    public:
    void press()
    {
        cout<<"Mac button presssed"<<endl;
    }
};
class WinButton: public IButton
{
    public:
    void press()
    {
        cout<<"Window button presssed"<<endl;
    }
};

class ITextBox
{
    public:
    virtual void write()=0;
};

class MacTextBox: public ITextBox
{
    public:
    void write()
    {
        cout<<"Mac Text "<<endl;
    }
};
class WinTextBox: public ITextBox
{
    public:
    void write()
    {
        cout<<"Window Text "<<endl;
    }
};

class IFactory
{
    public:
    virtual IButton* CreateButton()=0;
    virtual ITextBox* CreateTextBox()=0;
};
class MacFactory:public IFactory
{
    public:
    IButton* CreateButton()
    {
        return new MacButton();
    }
    ITextBox* CreateTextBox()
    {
        return new MacTextBox();
    }
    
};
class WinFactory:public IFactory
{
    public:
    IButton* CreateButton()
    {
        return new WinButton();
    }
    ITextBox* CreateTextBox()
    {
        return new WinTextBox();
    }
    
};
class GUIAbsractFactory
{
    public:
    static IFactory * getFactory(int type)
    {
        if(type == 1)
        {
            return new MacFactory();
        }
        else if(type == 2)
        {
            return new WinFactory();
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

    IButton* button = fact->CreateButton();
    button->press();

    ITextBox* txtbox = fact->CreateTextBox();
    txtbox->write();

}