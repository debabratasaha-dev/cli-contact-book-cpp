#include <algorithm>
#include <limits>
#include <iostream>
#include "contacts.h"
#include <string>
#include <vector>
#include <fstream>
#include "utils.h"
#include <sstream>
#include "Validator.h"
using namespace std;

void viewAll(vector<Contact>& contacts) {
    sort(contacts.begin(),contacts.end());
    for (Contact contact : contacts)
    {
        contact.print();
    }
}

string toUpperCase(string str) { // string Uppercase conversion
    for (auto &charecter : str)
    {
        charecter = toupper(charecter);
    }
    return str;
}

string provideValiPhone(string& phone) {
    while (true)
    {        
        if (!validateContactDetail(phone)) {
        cout << "Your entered Number is not a valid Phone no.\nEnter a valid no.: ";
        getline(cin, phone);
        } else break;
    }
    
    return phone;
}
string provideValiEmail(string& email) {
    while (true)
    {        
        if (!validateContactDetail(email)) {
        cout << "Your entered Email is invalid \nEnter a valid Email: ";
        getline(cin, email);
        } else break;
    }
    
    return email;
}

void add(vector<Contact>& contacts){ // adding new contact
    string line;
    string name;
    string phone;
    string email;

    cout << "Please saperate the inputs with ','; e.g. Name, Phone-Number, Email-ID (optional)\nEnter Contact Details: ";
    while (true) {
        getline(cin, line);
        stringstream readline(line);
        getline(readline, name, ',');
        getline(readline, phone, ',');
        getline(readline, email);
        if (name.empty() || name.find_first_not_of(' ') == std::string::npos) {
            cout << "Name can't be empty.\nPlease Reenter Name: ";
            continue;
        } else if (phone.empty() || phone.find_first_not_of(' ') == std::string::npos) {
            cout << "Phone No. can't be empty.\nPlease Reenter Name: ";
            continue;
        }

        break;
    }
    phone = provideValiPhone(phone);
    name = trimLeadingSpaces(name);
    phone = trimLeadingSpaces(phone);
    if (!email.empty()) {
        email = provideValiEmail(email);
        email = trimLeadingSpaces(email);
        contacts.push_back(Contact(name,phone,email));
    } else {
        contacts.push_back(Contact(name,phone));
    }
}

size_t search(vector<Contact> contacts, string key) {
    for (auto &ch : contacts)
    {
        ch.name = toUpperCase(ch.name);
    }
    key = toUpperCase(key);
    for (int i = 0; i <  contacts.size(); i++)
    {
        if (contacts[i].name == key || contacts[i].phone == key)
        {
            return i;
        }
    }
    return -1;
}

void edit(vector<Contact>& contacts, int pos) {
    if (pos == (size_t)-1) { // NOt found case
        cout << "Contact details NOT found\n";
        return;
    }
    cout << "Contact details founded\n";

    int edit_element;
    cout << "Please select edit element:\n1. Name\n2. Phone\n3. Email\n";
    cout << "Enter your choice: ";

    cin >> edit_element;

    while (true) { // taking selection and edit that details
        string newValue;
        bool isComplete = false;
        switch (edit_element)
        {
        case 1:
            cout << "Enter New Name: ";
            while(true) {
                cin.ignore();
                getline(cin, newValue);
                if (newValue.empty()) {
                    cout << "Please enter the name: ";
                } else break;
            }
            contacts[pos].name = newValue;
            isComplete = true;
            break;
            
        case 2:
            cout << "Enter New Phone: ";
            while(true) {
                cin.ignore();
                getline(cin, newValue);
                if (newValue.empty() || newValue.find_first_not_of(' ') == std::string::npos) {
                    cout << "Please enter the Phone: ";
                } else break;
            }
            newValue = provideValiPhone(newValue);
            contacts[pos].phone = newValue;
            isComplete = true;
            break;

        case 3:
            cout << "Enter New Email: ";
            while(true) {
                cin.ignore();
                getline(cin, newValue);
                if (newValue.empty() || newValue.find_first_not_of(' ') == std::string::npos) {
                    cout << "Please enter the Email: ";
                } else break;
            }
            newValue = provideValiEmail(newValue);
            contacts[pos].email = newValue;
            isComplete = true;
            break;

        default:
            cout << "invalid selection\n";
            break;
        }
        if (isComplete) break;

        if (edit_element > 3 || edit_element < 1)
        {
            if (cin.fail()) { // clear error state
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter your choice again: ";
            cin >> edit_element;
        }

        if (cin.fail()) { // clear error state
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
    }
}

void del(vector<Contact>& contacts, int pos) {
    if (pos == (size_t)-1) { // NOt found case
        cout << "Contact details NOT found\n";
        return;
    }
    contacts.erase(contacts.begin() + pos);
    cout << "Contact Succesfully Deleted\n";
}

void exitProgram(vector<Contact>& contacts) {
    ofstream contactsFile;
    contactsFile.open("ContactList.txt");
    sort(contacts.begin(),contacts.end());
    
    for (auto contact : contacts) // overwriting ContactList.txt
    {
        contactsFile << contact.name;
        contactsFile << ',';
        contactsFile << contact.phone;
        contactsFile << ',';
        contactsFile << contact.email;
        contactsFile << '\n';
    }
    contactsFile.close();
    
}