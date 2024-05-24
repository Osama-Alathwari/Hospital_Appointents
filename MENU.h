#include "Costs^_^.h"

class Menu
{
protected:
    void MainMenu()
    {
        cout << "__________MAIN MENU_________\n";
        cout << " 1- List Doctors' Information\n"
             << " 2- Mnanage Pateints' DataBase\n"
             << " 3- Manage Doctors' DataBase\n"
             << " 0- Exit\n"
             << " Your Choice : ";
    }

    void pateintMenu()
    {
        cout << "__________Pateint MENU_________\n";
        cout << " 1- To Enter Pateint's Info\n"
             << " 2- To Reserve an appointment\n"
             << " 3- List Patient's Information\n"
             << " 0- back\n"
             << " Your Choice : \n";
    }

    friend void doctorMenu();
};
void doctorMenu()
{
    cout << "__________Doctor MENU_________\n"
         << " 1- To add a new Doctor \n"
         << " 0- Back \n"
         << " Your Choice : \n";
}