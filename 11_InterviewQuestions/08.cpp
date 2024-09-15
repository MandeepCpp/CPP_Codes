#include<iostream>
#include <map>
#include <cstring>

using namespace std;


class Employee
{
    char *emp_name;
    int id;

public:
    // contructor
    Employee(const char *name, int id) : id(id)
    {
        emp_name = new char[strlen(name) + 1];
        strcpy(emp_name, name);
    }

    // destrcutor
    ~Employee()
    {
        delete[] emp_name;
    }
    // move constructor
    Employee(Employee &&obj)
    {
        emp_name = obj.emp_name;
        id = obj.id;
        obj.emp_name = nullptr;
    }
    // Copy constructor
    Employee(const Employee &obj) : id(obj.id)
    {
        emp_name = new char[strlen(obj.emp_name) + 1];
        strcpy(emp_name, obj.emp_name);
    }

    // Copy assignment operator
    Employee &operator=(const Employee &obj)
    {
        if (this != &obj)
        {
            delete[] emp_name; // Free existing resource
            emp_name = new char[strlen(obj.emp_name) + 1];
            strcpy(emp_name, obj.emp_name);
            id = obj.id;
        }
        return *this;
    }

    // move assignment operator
    Employee &operator=(Employee &&obj)
    {
        if (this != &obj)
        {
            delete[] emp_name;
            emp_name = obj.emp_name;
            id = obj.id;
            obj.emp_name = nullptr;
        }
        return *this;
    }

    bool operator<(const Employee &obj) const
    {
        return id < obj.id;
    }

    const char *getName() const
    {
        return emp_name;
    }

    int getId() const
    {
        return id;
    }
};

int main()
{
    std::map<Employee, Employee> emp_map;

    Employee emp1("Mandeep", 7);
    Employee emp2("Singh", 5);
    Employee emp3("Navpreet", 8);
    Employee emp4("Kaur", 4);

    emp_map.insert(make_pair(emp1, emp2));
    emp_map.insert(make_pair(emp3, emp4));

    for (const auto &pair : emp_map)
    {
        cout << pair.first.getName() << " : " << pair.second.getName() << endl;
    }
    return 0;
}