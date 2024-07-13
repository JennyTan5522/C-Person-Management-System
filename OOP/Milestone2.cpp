/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;
class Contact {
public:
    Contact(string name, string address, string company_name) {
        this->name = name;
        this->address = address;
        this->company_name = company_name;
    }
    string getName() {
        return name;
    }
    string getAddress() {
        return address;
    }
    string getCompanyName() {
        return company_name;
    }
    void setName(string name) {
        this->name = name;
    }
    void setAddress(string address) {
        this->address = address;
    }
    void setCompanyName(string company_name) {
        this->company_name = company_name;
    }
private:
    string name;
    string address;
    string company_name;
};

vector<Contact> business_contacts;

void viewContacts() {
    for (int i = 0; i < business_contacts.size(); i++) {
        cout << i + 1 << ". " << business_contacts[i].getName() << endl;
        cout << "   " << business_contacts[i].getAddress() << endl;
        cout << "   " << business_contacts[i].getCompanyName() << endl;
    }
}

void searchContacts(std::string value) {
    for (int i = 0; i < business_contacts.size(); i++) {
        if (business_contacts[i].getName() == value || business_contacts[i].getAddress() == value || business_contacts[i].getCompanyName() == value) {
            std::cout << i + 1 << ". " << business_contacts[i].getName() << std::endl;
            std::cout << "   " << business_contacts[i].getAddress() << std::endl;
            std::cout << "   " << business_contacts[i].getCompanyName() << std::endl;
        }
    }
}


int main() {
    while (true) {
        int choice;
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Delete Contact" << endl;
        cout << "4. Modify Contact" << endl;
        cout << "5. Save Contacts" << endl;
        cout << "6. Load Contacts" << endl;
        cout << "7. Search Contacts" << endl;
        cout << "8. Sort Contacts" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter a choice: ";
        cin >> choice;
        if (choice == 1) {
            string name, address, company_name;
            cout << endl;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter address: ";
            getline(cin, address);
            cout << "Enter company name: ";
            getline(cin, company_name);
            cout << endl;
            Contact new_business_contact = Contact(name, address, company_name);
            business_contacts.push_back(new_business_contact);
        }
        else if (choice == 2) {
            viewContacts();
        }
        else if (choice == 3) {
            int index;
            cout << "Enter index of contact to delete: ";
            cin >> index;
            business_contacts.erase(business_contacts.begin() + index - 1);
        }
        else if (choice == 4) {
            int index;
            cout << "Enter index of contact to modify: ";
            cin >> index;
            Contact& contact = business_contacts[index - 1];
            cout << "1. Modify name" << endl;
            cout << "2. Modify address" << endl;
            cout << "3. Modify company name" << endl;
            int sub_choice;
            cout << "Enter a choice: ";
            cin >> sub_choice;
            string new_value;
            cin.ignore();
            if (sub_choice == 1) {
                cout << "Enter new name: ";
                getline(cin, new_value);
                contact.setName(new_value);
            }
            else if (sub_choice == 2) {
                cout << "Enter new address: ";
                getline(cin, new_value);
                contact.setAddress(new_value);
            }
            else if (sub_choice == 3) {
                cout << "Enter new company name: ";
                getline(cin, new_value);
                contact.setCompanyName(new_value);
            }
            else {
                cout << "Invalid choice" << endl;
            }
        }

        else if (choice == 5) {
            string fileName;
            cout << "Enter the file name: ";
            cin >> fileName;
            string fullFileName;
            ofstream outfile(fullFileName.c_str());
            for (int i = 0; i < business_contacts.size(); i++) {
                outfile << business_contacts[i].getName() << endl;
                outfile << business_contacts[i].getAddress() << endl;
                outfile << business_contacts[i].getCompanyName() << endl;
            }
            outfile.close();
            cout << "Contacts saved to " << fileName << ".txt" << endl;
        }

        else if (choice == 6) {
            string fileName;
            cout << "Enter the file name: ";
            cin >> fileName;
            string fullFileName = fileName + ".txt";
            ifstream infile(fullFileName.c_str());
            string name, address, company_name;
            while (infile >> name >> address >> company_name) {
                Contact new_business_contact = Contact(name, address, company_name);
                business_contacts.push_back(new_business_contact);
            }
            infile.close();
            cout << "Contacts loaded from " << fileName << ".txt" << endl;
        }
        else if (choice == 7) {
            string value;
            cout << "Enter the value to search for: ";
            cin.ignore();
            getline(cin, value);
            searchContacts(value);
        }
        else if (choice == 8) {
            if (business_contacts.empty()) {
                cout << "No contacts to sort" << endl;
            }
            else {
                int sortChoice;
                cout << "1. Sort by name (ascending)" << endl;
                cout << "2. Sort by name (descending)" << endl;
                cout << "Enter a choice: ";
                cout << endl;
                cin >> sortChoice;
                if (sortChoice == 1) {
                    for (int i = 0; i < business_contacts.size(); i++) {
                        for (int j = i + 1; j < business_contacts.size(); j++) {
                            if (business_contacts[i].getName() > business_contacts[j].getName()) {
                                Contact temp = business_contacts[i];
                                business_contacts[i] = business_contacts[j];
                                business_contacts[j] = temp;
                            }
                        }
                    }
                }
                else if (sortChoice == 2) {
                    for (int i = 0; i < business_contacts.size(); i++) {
                        for (int j = i + 1; j < business_contacts.size(); j++) {
                            if (business_contacts[i].getName() < business_contacts[j].getName()) {
                                Contact temp = business_contacts[i];
                                business_contacts[i] = business_contacts[j];
                                business_contacts[j] = temp;
                            }
                        }
                    }
                }
                else {
                    std::cout << "Invalid choice" << std::endl;
                }
            }
        }
        else if (choice == 9) {
            break;
        }
        else {
            std::cout << "Invalid choice" << std::endl;
        }
    }
    return 0;
}
*/