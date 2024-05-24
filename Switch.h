#include "MENU.h"

class Switch : public Doctor, public Patient, public Menu
{
private:
    int pID, dID, change; // Pateint ID, Doctor ID
    bool *reserved;       // A Dynamic array to store the status of doctors whether they're free or not , true = busy , false = free
    int *patientReservationTime;
    friend void doctorMenu();

    // ######################### Pateint Switch ###############################3
    void pateintSwitch()
    {
        int choice;
    bp02:
        do
        {
            pateintMenu();
            cin >> choice;
            switch (choice)
            {
            case 0:
                break;

            case 1:
                Patient::setInfo();
                break;

            case 2:
                if (isEmpty())
                {
                    cout << "Pateints Database is Empty !! ... \n";
                    break;
                }
                reserveAppointment();
                break;

            case 3:
                if (isEmpty())
                {
                    cout << "Pateints Database is Empty !! ... \n";
                    break;
                }
                Patient::getInfo();
                break;

            default:
                cerr << "Invalid Range\n";
                goto bp02;
                break;
            }
        } while (choice < 4 & choice > 0);
    }

    // ####################### Doctor Switch ###########################
    void doctorSwitch()
    {
        int choice;
    bp03:
        do
        {
            doctorMenu();
            cin >> choice;
            switch (choice)
            {
            case 0:
                break;

            case 1:
                Doctor::setInfo();
                Switch();
                break;

            default:
                cerr << "Invalid Range\n";
                goto bp03;
                break;
            }
        } while (choice < 2 & choice > 0);
    }

    // ######################### Reservation Function ############################3
    void reserveAppointment()
    {

        Doctor::getInfo();
        Patient::getInfo();

        cout << "\nStarting from [ 1 ] to [ " << getNumebrOfPateints() << " ] "
             << "Enter Pateint's ID : ";
        exceptionHandeling(pID, getNumebrOfPateints());

    bp05:
        cout << "\nStarting from [ 1 ] to [ " << getDoctorsCounter() << " ] "
             << "Enter Doctor's ID : ";
        exceptionHandeling(dID, getDoctorsCounter());
    bp07:
        cout << "Choose your time : ";
        setReservationTime(pID - 1);

        if (checkReservation())
        {
            cout << "Pleas Choose a valid time shown in the list for Dr. ' " << array[dID - 1].Name << " ' \n";
            goto bp07;
        }

        if (isReserved(dID, getReservationTime(pID - 1)))
        {
            cout << "Doctor ' " << array[dID - 1].Name << " ' has another is busy now !! ... Pleas choose another Doctor or another time\n";
            goto bp05;
        }

        patientReservationTime[dID - 1] = getReservationTime(pID - 1);
        cout << "The Reservation Cost for Dr ' " << array[dID - 1].Name << " ' is " << array[dID - 1].docReservation << endl
             << "Payment : ";
    bp06:
        setPaidMoney(pID - 1);
        if (checkPaidMoney(pID, dID))
        {
            cout << "The amount of money you entered is less than the reservation cost of Dr. ' " << array[dID - 1].Name
                 << " ' Please enter again !! : ";
            goto bp06;
        }

        change = getPaidMoney(pID - 1) - array[dID - 1].docReservation;
        reserved[dID - 1] = true;
        cout << "Pateint ' " << getName(pID - 1) << " ' Has Successfully made an apointment with Dr. ' " << array[dID - 1].Name << " ' \n"
             << "Bell : [ " << array[dID - 1].docReservation << " ] YR\n"
             << "You Paid : [ " << getPaidMoney(pID - 1) << " ] YR\n"
             << "Change : [ " << change << " ] YR\n";
    }

    bool checkReservation()
    {
        return (getReservationTime(pID - 1) < array[dID - 1].startingTime | getReservationTime(pID - 1) >= array[dID - 1].finishingTime);
    }

    // ########################## Exception Handeling ###############################
    void exceptionHandeling(int &ID, int range)
    {
    bp04:
        try // Error Handeling
        {
            cin >> ID;
            if (ID > range || ID <= 0)
            {
                throw "Error, ";
            }
        }
        catch (const char *ch)
        {
            system("clear");
            cerr << ch << "Invalid Range" << '\n';
            goto bp04;
        } // end of Error Handeling
    }

    // ########################## Is Reserved Function #############################
    bool isReserved(int ID, int time) // to check whether a doctor is free or not
    {
        return (reserved[ID - 1] == true & patientReservationTime[ID - 1] == time);
    }

    // ######################### Check Paid Money #############################
    bool checkPaidMoney(int pID, int dID)
    {
        return getPaidMoney(pID - 1) < array[dID - 1].docReservation;
    }

public:
    // ################## Constructor #######################
    Switch()
    {
        pID = dID = change = 0;
        reserved = new bool[getDoctorsCounter()];
        patientReservationTime = new int[getDoctorsCounter()];
        for (int i = 0; i < getDoctorsCounter(); i++)
        {
            reserved[i] = false;
            patientReservationTime[i] = 0;
        }
    }

    // ################# Main Sweitch ########################
    void mainSwitch()
    {
        int choice;
    bp01:
        do
        {
            MainMenu();
            cin >> choice;
            switch (choice)
            {
            case 0:
                exit(0);

            case 1:
                Doctor::getInfo();
                break;

            case 2:
                pateintSwitch();
                break;

            case 3:
                doctorSwitch();
                break;

            default:
                cerr << "Invalid Range\n";
                goto bp01;
                break;
            }
        } while (choice < 4 & choice >= 0);
    }
};