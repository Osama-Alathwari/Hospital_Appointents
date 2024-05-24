#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class Management
{
protected:
    string name;
    int id;
    string phoneNumber;
    string address;

    virtual void setInfo() = 0;
    virtual void getInfo() = 0;
    virtual void setName() = 0;
    virtual void setID() = 0;
    virtual void setPhoneNumber() = 0;
    virtual void setAddress() = 0;
};