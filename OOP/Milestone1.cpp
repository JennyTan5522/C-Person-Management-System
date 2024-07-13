/*
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Contact {
public:
    Contact(string name, string phone_number, string address) {
        this->name = name;
        this->phone_number = phone_number;
        this->address = address;
    }
    string getName() {
        return name;
    }
    string getPhoneNumber() {
        return phone_number;
    }
    string getAddress() {
        return address;
    }

    void setName(string name) {
        this->name = name;
    }
    void setPhoneNumber(string phone_number) {
        this->phone_number = phone_number;
    }
    void setAddress(string address) {
        this->address = address;
    }

private:
    string name;
    string phone_number;
    string address;
};

vector<Contact> friends;


void viewContacts() {
    cout << endl;

    for (int i = 0; i < friends.size(); i++) {
        cout << i + 1 << ". " << "Name: " << friends[i].getName() << endl;
        cout << "   Phone Number: " << friends[i].getPhoneNumber() << endl;
        cout << "   Address: " << friends[i].getAddress() << endl;
    }
    cout << endl;
}



int main() {
    while (true) {
        cout << "=============================================\n";
        cout << "            MILESTONE 1" << endl;
        cout << "=============================================\n";
        cout << "1. Add a friend's contact information" << endl;
        cout << "2. View all friend's contact information" << endl;
        cout << "3. Delete a friend's contact information" << endl;
        cout << "4. Modify a friend's contact information   " << endl;
        cout << "5. Sort contacts" << endl;
        cout << "6. Search for a contact based on a value" << endl;
        cout << "7. Save the contacts into a txt file:" << endl;
        cout << "8. Load contacts from txt file" << endl;
        cout << "9: Exit" << endl;
        cout << endl;
        cout << "Enter a choice: ";

        int choice;
        cin >> choice;

        //Insertion of a new object
        if (choice == 1) {
            string name, phone_number, address;
            cout << endl;
            cout << "Enter name: ";
            cin.ignore();
            getline(std::cin, name);
            cout << "Enter phone number: ";
            getline(std::cin, phone_number);
            cout << "Enter address: ";
            getline(std::cin, address);
            cout << endl;
            Contact new_friend = Contact(name, phone_number, address);
            friends.push_back(new_friend);
        }

        //View contact
        else if (choice == 2) {
            viewContacts();
        }

        //Deletion of an object
        else if (choice == 3) {
            if (friends.empty()) {
                cout << "No contacts to delete" << endl;
            }
            else {
                viewContacts();
                int contactIndex;
                cout << "Enter the number of contact you want to delete: ";
                cin >> contactIndex;
                if (contactIndex > 0 && contactIndex <= friends.size()) {
                    friends.erase(friends.begin() + (contactIndex - 1));
                    cout << "Contact deleted" << endl;
                }
                else {
                    cout << "Invalid index" << endl;
                }
            }
        }

        //Modify
        else if (choice == 4) {
            if (friends.empty()) {
                cout << "No contacts to modify" << endl;
            }
            else {
                viewContacts();
                int contactIndex;
                cout << "Enter the number of contact you want to modify: ";
                cin >> contactIndex;
                if (contactIndex > 0 && contactIndex <= friends.size()) {
                    cout << "Enter new name: ";
                    string name;
                    cin.ignore();
                    getline(cin, name);
                    friends[contactIndex - 1].setName(name);
                    cout << "Enter new phone number: ";
                    string phone_number;
                    getline(cin, phone_number);
                    friends[contactIndex - 1].setPhoneNumber(phone_number);
                    cout << "Enter new address: ";
                    string address;
                    getline(cin, address);
                    friends[contactIndex - 1].setAddress(address);
                    cout << "Contact " << contactIndex << "has been ammended" << endl;
                    cout << endl;
                }
            }
        }

        //Sorting
        else if (choice == 5) {
            if (friends.empty()) {
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
                    for (int i = 0; i < friends.size(); i++) {
                        for (int j = i + 1; j < friends.size(); j++) {
                            if (friends[i].getName() > friends[j].getName()) {
                                Contact temp = friends[i];
                                friends[i] = friends[j];
                                friends[j] = temp;
                            }
                        }
                    }
                    for (int i = 0; i < friends.size(); i++) {
                        cout << "\n\nName           :" << friends[i].getName() << endl;
                        cout << "Contact Number :" << friends[i].getPhoneNumber() << endl;
                        cout << "Address        :" << friends[i].getAddress();
                    }
                }
                else if (sortChoice == 2) {
                    for (int i = 0; i < friends.size(); i++) {
                        for (int j = i + 1; j < friends.size(); j++) {
                            if (friends[i].getName() < friends[j].getName()) {
                                Contact temp = friends[i];
                                friends[i] = friends[j];
                                friends[j] = temp;
                            }
                        }
                    }
                    for (int i = 0; i < friends.size(); i++) {
                        cout << "\n\nName           :" << friends[i].getName() << endl;
                        cout << "Contact Number :" << friends[i].getPhoneNumber() << endl;
                        cout << "Address        :" << friends[i].getAddress();
                    }
                }
                else {
                    std::cout << "Invalid choice" << std::endl;
                }
            }
        }

        else if (choice == 6) {
            string searchValue;
            cout << "Enter the value to search for: ";
            cin.ignore();
            getline(cin, searchValue);
            bool found = false;
            for (int i = 0; i < friends.size(); i++) {
                if (friends[i].getName() == searchValue || friends[i].getPhoneNumber() == searchValue || friends[i].getAddress() == searchValue) {
                    cout << "Name: " << friends[i].getName() << endl;
                    cout << "Phone Number: " << friends[i].getPhoneNumber() << endl;
                    cout << "Address:" << friends[i].getAddress() << endl;
                    cout << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "No contact found with the given value" << endl;
            }
        }
        //Saving to file
        else if (choice == 7) {
            string fileName;
            cout << "Enter the file name: ";
            cin >> fileName;
            string fullFileName = fileName + ".txt";
            ofstream outfile(fullFileName.c_str());
            for (int i = 0; i < friends.size(); i++) {
                outfile << i + 1 << ": ";
                outfile << friends[i].getName() << " ";
                outfile << friends[i].getPhoneNumber() << " ";
                outfile << friends[i].getAddress() << endl;
            }
            outfile.close();
            cout << "Contacts saved to " << fileName << ".txt" << endl;
            cout << endl;
        }

        else if (choice == 8) {
            string fileName;
            cout << "Enter the file name: ";
            cin >> fileName;
            string fileFullName = fileName + ".txt";
            ifstream infile;
            infile.open(fileFullName.c_str());
            string name, phone_number, email;
            if (!infile) {
                cout << "File not found" << endl;
                continue;
            }

            int count = 0;
            while (infile >> name >> phone_number >> email) {
                Contact new_friend = Contact(name, phone_number, email);
                friends.push_back(new_friend);
                count++;
            }
            cout << count << " contacts loaded from " << fileName << ".txt" << endl;
            cout << endl;
            infile.close();


        }

        else if (choice == 9) {
            break;
        }

        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
*/