#include <iostream>
#include "contacts.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "utils.h"
#include <limits>
using namespace std;

int main() {

    // file availability checking and creating new file
    ifstream inputfile;
    inputfile.open("ContactList.txt");
    
    // creating new file
    if (!inputfile) {
        ofstream contactsFile;
        contactsFile.open("ContactList.txt");
        cout << "ContactList.txt did not exist. New file created.\n";
        contactsFile.close();
    }
    
    // Vector for All the contacts
    vector<Contact> contacts;
    
    // inserting all data from file to the vector
    string line;
    while (getline(inputfile,line)) {
        stringstream readline(line);
        if(line.empty()) continue;
        string name;
        string phone;
        string email;
        getline(readline, name, ',');
        getline(readline, phone, ',');
        getline(readline, email);
        if (!email.empty()) {
            contacts.push_back(Contact(name,phone,email));
        } else {
            contacts.push_back(Contact(name,phone));
        }
    }
    inputfile.close();
    int count = 1;
    cout << "Select Option:\n1. Add Contact\n2. View All\n3. Search\n4. Edit\n5. Delete\n6. Save & Exit\n";

    while (true) // Main menu loop
    {
        bool isexit = false;
        int operation;
        if (count>1)
        {
            cout << "MAIN MENU:\n";
        } else {
            count = 2;
        }
        // cin.clear();
        cout << "Enter your choice: ";
        cin >> operation;

        cin.ignore();
        string key;
        size_t pos;
        switch (operation)
        {
        case 1:
            add(contacts);
            break;
        case 2:
            viewAll(contacts);
            break;
        case 3:
            cout<< "Phone no. is format sensitive, use the same format as saved:\nEnter The Name or Phone: ";
            getline(cin, key);
            pos = search(contacts, key);
            if (pos != -1) {
                contacts[pos].print();
            } else {
                cout << "Contact NOT founded\n";
            }
            break;
        case 4:
            cout<< "Phone no. is format sensitive, use the same format as saved:\nEnter The Name or Phone: ";
            getline(cin, key);
            pos = search(contacts, key);
            edit(contacts,pos);
            break;
        case 5:
            cout<< "Phone no. is format sensitive, use the same format as saved:\nEnter The Name or Phone: ";
            getline(cin, key);
            pos = search(contacts, key);
            del(contacts, pos);
            break;
        case 6:
            exitProgram(contacts);
            isexit = true;
            break;
        default:
            cout << "Please Enter the Respective Number!\n";

            if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;
        }
        if (isexit) break;
    }
    
    return 0;
}