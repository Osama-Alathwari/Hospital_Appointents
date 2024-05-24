#include "Doctor.h"

class Patient : public Management
{
private:
    string status;
    string sicknessType;
    float paidMoney;
    int numberOfPateints;
    int resrevationTime;

    void setPhoneNumber() { cin >> phoneNumber; }
    void setAddress() { cin >> address; }
    void setStatus() { cin >> status; }
    void setSicknessType() { cin >> sicknessType; }

    void setName()
    {
        cin >> name;
    }

    void setID()
    {
        cin >> id;
        while (id <= 0)
        {
            cout << "Inavalid ID !! ... \n"
                 << "Please Enter a valid ID greater than ZERO : ";
            cin >> id;
        }
    }

public:
    Patient()
    {
        name = phoneNumber = address = status = sicknessType = "";
        id = numberOfPateints = resrevationTime = 0;
        paidMoney = 0;
    }

protected:
    Patient *p;

    void setInfo()
    {
        cout << "Enter Number of Pateints you want to create : ";
        cin >> numberOfPateints;
        p = new Patient[numberOfPateints];
        for (int i = 0; i < numberOfPateints; i++)
        {
            system("clear");
            cout << "ID : ";
            p[i].setID();
            cout << "NAME : ";
            p[i].setName();
            cout << "Phone Number :";
            p[i].setPhoneNumber();
            cout << "Address : ";
            p[i].setAddress();
            cout << "Status : ";
            p[i].setStatus();
            cout << "Sickness Type : ";
            p[i].setSicknessType();
        }
    }

    void getInfo()
    {
        cout.setf(ios::left, ios::adjustfield);
        cout << setw(10) << " NAME " << setw(10) << " ID " << setw(14) << " Phone Number " << setw(10) << " Adress " << setw(20) << " Status " << setw(16) << " Sickness Type " << setw(14) << " Paid Money " << endl;
        for (int i = 0; i < numberOfPateints; i++)
        {
            cout.setf(ios::left, ios::adjustfield);
            cout << setw(10) << p[i].name << setw(10) << p[i].id << setw(14) << p[i].phoneNumber << setw(10) << p[i].address << setw(20) << p[i].status << setw(16) << p[i].sicknessType << setw(14) << p[i].paidMoney << endl;
        }
    }

    int getNumebrOfPateints() { return numberOfPateints; }
    float getPaidMoney(int ID) { return p[ID].paidMoney; }
    bool isEmpty() { return numberOfPateints == 0; }
    int getReservationTime(int ID) { return p[ID].resrevationTime; }
    string getName(int ID) { return p[ID].name; }

    void setPaidMoney(int ID)
    {
        cin >> p[ID].paidMoney;
        while (p[ID].paidMoney <= 0)
        {
            cout << "Inavalid Value !! ... \n"
                 << "Please Enter a valid Value greater than ZERO : ";
            cin >> p[ID].paidMoney;
        }
    }

    void setReservationTime(int ID)
    {
        cin >> p[ID].resrevationTime;
        while (p[ID].resrevationTime<0 | p[ID].resrevationTime> 23)
        {
            cout << "Inavalid Value !! ... \n"
                 << "Please Enter a valid Value greater than or Equal ZERO & less than 24 : ";
            cin >> p[ID].resrevationTime;
        }
    }
};