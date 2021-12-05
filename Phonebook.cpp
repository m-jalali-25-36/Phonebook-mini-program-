#include <iostream>
#include <conio.h>

using namespace std;

struct contact
{
    string firstName = "null";
    string lastName = "null";
    string phone = "null";
};

contact listContact[10];

int getIndex(){
    for (int i = 0; i < 10; i++)
    {
        if(listContact[i].firstName == "null" && listContact[i].lastName == "null" && listContact[i].phone == "null"){
            return i;
        }
    }
    return -1;
}

void PrintHeader(){
    cout << "-------------------** Welcome to the phonebook **-------------------" << endl;
    cout << "| 1) View contacts                                                 |" << endl;
    cout << "| 2) Add a contact                                                 |" << endl;
    cout << "| 3) Edit contact                                                  |" << endl;
    cout << "| 4) Delete contact                                                |" << endl;
    cout << "| 0) Exit                                                          |" << endl;
    cout << "| ** To go to the desired page, enter its number and press Enter.  |" << endl;
    cout << "--------------------------------------------------------------------" << endl;
}

void printContacts(){
    cout << "index   First name\t\tLast Name\t\tPhone Number" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i+1 << ")      " << listContact[i].firstName << "\t\t\t";
        cout << listContact[i].lastName << "\t\t\t";
        cout << listContact[i].phone << "\n";
    }
}

void addContact(){
    system("cls");
    contact add;
    int index = getIndex();
    if(index == -1){
        cout << "Your phonebook memory is full." << endl;
        cout << "Press a key...";
        getch();
        return;
    }
    cout << "** Add a contact" << endl;
    cout << "Enter the first name>>";
    cin >> add.firstName;
    cout << "Enter the last name>>";
    cin >> add.lastName;
    cout << "Enter the phone number>>";
    cin >> add.phone;
    listContact[index] = add;
    index++;
    cout << "The contact was saved successfully." << endl;
    cout << "Press a key...";
    getch();
}

void deleteContact(){
    int index;
    system("cls");
    cout << "** Delete contacts" << endl;
    printContacts();
    cout << "Enter the contact number>>";
    cin >> index;
    if (index >= 0 && index < 10 && listContact[index].firstName != "null")
    {
        listContact[index].firstName = "null";
        listContact[index].lastName = "null";
        listContact[index].phone = "null";
        cout << "Contact deleted successfully." << endl;
        cout << "Press a key...";
        getch();
    }
    else{
        cout << "The entered contact number is not valid." << endl;
        cout << "Press a key...";
        getch();
    }
}

void editContact(){
    int index;
    system("cls");
    cout << "** Edit contacts" << endl;
    printContacts();
    cout << "Enter the contact number>>";
    cin >> index;
    if (index >= 0 && index < 10 && listContact[index].firstName != "null")
    {
        string inp;
        system("cls");
        cout << "** Edit contacts" << endl;
        cout << "**" << endl;
        cout << "First Name: " << listContact[index].firstName << endl;
        cout << "Last Name: " << listContact[index].lastName << endl;
        cout << "Phone Number: " << listContact[index].phone << endl;
        cout << "**" << endl;
        cout << "Enter new information." << endl;
        cout << "You can enter -1 to skip each section." << endl;
        cout << "Enter the first name>>";
        cin >> inp;
        if(inp != "-1")
             listContact[index].firstName = inp;
        cout << "Enter the last name>>";
        cin >> inp;
        if(inp != "-1")
             listContact[index].lastName = inp;
        cout << "Enter the phone number>>";
        cin >> inp;
        if(inp != "-1")
             listContact[index].phone = inp;
        cout << "Contact edit successfully." << endl;
        cout << "Press a key...";
        getch();
    }
    else{
        cout << "The entered contact number is not valid." << endl;
        cout << "Press a key...";
        getch();
    }
}

int main(int argc, char const *argv[])
{
    
    int inp;
    while (true)
    {
        system("cls");
        PrintHeader();
        cout << "Enter the command number>>";
        cin >> inp;
        switch (inp)
        {
        case 0:
            return 0;
        case 1:
            system("cls");
            cout << "** View contacts" << endl;
            printContacts();
            cout << "Press a key...";
            getch();
            break;
        case 2:
            addContact();
            break;
        case 3:
            editContact();
            break;
        case 4:
            deleteContact();
            break;
        
        default:
            cout << "The command was not entered correctly.";
            getch();
            break;
        }
    }
    
    return 0;
}
