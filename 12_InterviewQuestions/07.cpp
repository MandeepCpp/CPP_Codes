#include <iostream>
#include <vector>
#include <map>
#include <exception>
#include <cstring>
using namespace std;

class Pen
{
public:
    virtual void write()
    {
    }
    virtual ~Pen() {}
};
class InkPen : public Pen
{
public:
    void write()
    {
        cout << "writing with inkpen" << endl;
    }
};
class BallPen : public Pen
{
public:
    void write()
    {
        cout << "writing with ballpen" << endl;
    }
};

class Pencil : public Pen
{
public:
    void write()
    {
        cout << "writing with pencil" << endl;
    }
    void sharp()
    {
        cout << "writing after sharp" << endl;
    }
};
void insert(std::vector<Pen *> &vec, Pen *p)
{
    vec.push_back(p);
}
Pen *Read(std::vector<Pen *> &vec, int i)
{

    if (i < 0 || i >= vec.size())
    {
        // return nullptr;
        throw out_of_range("Index is out of range");
    }
    return vec[i];
}

int main()
{
    std::vector<Pen *> vec;

    InkPen inkPen;
    BallPen ballPen;
    Pencil pencil;

    insert(vec, &inkPen);
    insert(vec, &ballPen);
    insert(vec, &pencil);

    for (int i = 0; i < vec.size(); ++i)
    {
        Pen *pen = Read(vec, i);
        Pencil *pencil = dynamic_cast<Pencil *>(pen);
        if (pencil)
        {
            pencil->sharp();
        }
        pen->write();
    }

    vec.clear();

    return 0;
}