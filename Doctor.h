#include "Management.h"
#include <fstream>

class Doctor : public Management
{
private:
    int doctorsCounter;
    float reservationCost;
    string specialization;
    int workingHours[2];
    fstream infile;

    void setName() { cin >> name; }
    void setPhoneNumber() { cin >> phoneNumber; }
    void setSpecialization() { cin >> specialization; }
    void setAddress() { cin >> address; }

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

    void setReservationCost()
    {
        cin >> reservationCost;
        while (reservationCost <= 0)
        {
            cout << "Inavalid Value !! ... \n"
                 << "Please Enter a valid Value greater than ZERO : ";
            cin >> reservationCost;
        }
    }

    void setStartingTime()
    {
        cin >> workingHours[0];
        while (workingHours[0]<0 | workingHours[0]> 23)
        {
            cout << "Inavalid Value !! ... \n"
                 << "Please Enter a valid Value greater than or Equal ZERO & less than 24 : ";
            cin >> workingHours[0];
        }
    }

    void setFinishingTime()
    {
        cin >> workingHours[1];
        while (workingHours[1]<0 | workingHours[1]> 23)
        {
            cout << "Inavalid Value !! ... \n"
                 << "Please Enter a valid Value greater than or Equal ZERO & less than 24 : ";
            cin >> workingHours[1];
        }
    }

public:
    Doctor()
    {
        name = phoneNumber = address = specialization = "";
        id = reservationCost = 0;
        Intialize();
    }

protected:
    //################### To Count the number of lines in the file , as a line holds the data of one doctor #########################
    void Intialize()
    {
        doctorsCounter = 0;
        string Data;
        infile.open("Docs_Info.txt", ios::in);
        if (!infile)
        {
            cout << "Couldn't Open the file !! ...\n";
            exit(-1);
        }

        while (getline(infile, Data))
        {
            doctorsCounter++;
        }
        Data = "";
        infile.close();
        array = new Doctors[doctorsCounter];
    }

    void getInfo()
    {
        Intialize();
        infile.open("Docs_Info.txt", ios::in);
        if (!infile)
        {
            cerr << "Couldn't open file ! \n";
            exit(-1);
        }

        cout.setf(ios::left, ios::adjustfield);
        cout << setw(20) << "|ID|" << setw(20) << "|NAME|" << setw(20) << "|Phone Number|" << setw(20) << "|Adress|" << setw(20) << "|Reservation Cost|" << setw(20) << "|Specialization|" << setw(20) << "|Start Working|" << setw(20) << "|Finish Working|" << endl;

        while (infile >> id >> name >> phoneNumber >> address >> reservationCost >> specialization >> workingHours[0] >> workingHours[1])
        {
            intializingStruct(id, name, reservationCost, workingHours[0], workingHours[1]);
            cout.setf(ios::left, ios::adjustfield);
            cout << setw(20) << id << setw(20) << name << setw(20) << phoneNumber << setw(20) << address << setw(20) << reservationCost << setw(20) << specialization << setw(20) << workingHours[0] << setw(20) << workingHours[1] << endl;
        }
        cout << endl;
        infile.close();
    }

    void setInfo()
    {
        infile.open("Docs_Info.txt", ios::out | ios::app);
        if (!infile)
        {
            cerr << "Couldn't open file ! \n";
            exit(-1);
        }
        cout << "Id : ";
        setID();
        cout << "Name : ";
        setName();
        cout << "Phone Number :";
        setPhoneNumber();
        cout << "Address : ";
        setAddress();
        cout << "Reservation Cost : ";
        setReservationCost();
        cout << "Specialization : ";
        setSpecialization();
        cout << "Start Working at : ";
        setStartingTime();
        cout << "Finish Working at : ";
        setFinishingTime();
        infile << id << " " << name << " " << phoneNumber << " " << address << " " << reservationCost << " " << specialization << " " << workingHours[0] << " " << workingHours[1] << " "
               << "\n";
        infile.close();
    }

    int getDoctorsCounter() { return doctorsCounter; }

    struct Doctors
    {
        string Name;
        double docReservation;
        int startingTime, finishingTime;
    } * array;

    void intializingStruct(int ID, string name, float reservationCost, int start, int finish)
    {
        array[id - 1].Name = name;
        array[id - 1].docReservation = reservationCost;
        array[id - 1].startingTime = start;
        array[id - 1].finishingTime = finish;
    }

};