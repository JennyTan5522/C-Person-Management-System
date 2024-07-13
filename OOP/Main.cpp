#include <iostream>
#include <vector>
#include <string>
#include<fstream>
using namespace std;

class Person {
public:
    // constructor
    Person(string name, string address) {
        this->name = name;
        this->address = address;
    }
    // getters
    string getName() {
        return name;
    }
    string getAddress() {
        return address;
    }
    // setters
    void setName(string name) {
        this->name = name;
    }
    void setAddress(string address) {
        this->address = address;
    }

    //to enable dynamic binding on the destructor
    ~Person() {
        deletePerson();
    }

    void deletePerson() {
         name = "";
        address = "";
    }

    //Pure virtual functions
    virtual void displayData() = 0;
    virtual void modifyData(string newName, string newAddress) = 0;

private:
    string name;
    string address;
};

//Implement a Friend class which inherits from the Person class and overrides the virtual
//functions in the Person class
class Friend : public Person {
public:
    // constructor
    Friend(string name, string address, string phone) : Person(name, address) {
        this->phone = phone;
    }
    // getters
    string getPhone() {
        return phone;
    }
    // setters
    void setPhone(string phone) {
        this->phone = phone;
    }

    // overridden virtual functions
    void displayData() override {
        cout << "Name: " << getName() << endl;
        cout << "Address: " << getAddress() << endl;
        cout << "Phone: " << phone << endl;
    }
    void modifyData(string newName, string newAddress) override {
        setName(newName);
        setAddress(newAddress);
    }

private:
    string phone;
};

//Implement a BusinessContact class which inherits from the Person class and overrides
//the virtual functions in the Person class.
class Contact : public Person{
public:
    Contact(string name, string address, string company_name) : Person(name, address) {
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

    // overridden virtual functions
    void displayData() override {
        cout << "Name: " << getName() << endl;
        cout << "Address: " << getAddress() << endl;
        cout << "Company Name: " << company_name << endl;
    }
    void modifyData(string newName, string newAddress) override {
        setName(newName);
        setAddress(newAddress);
    }

private:
    string name;
    string address;
    string company_name;
};

vector<Contact> business_contacts;
vector<Friend> friends;

void viewContacts() {
    cout << endl;
    //Friend(string name, string address, string phone) : Person(name, address)
    for (int i = 0; i < friends.size(); i++) {
        cout << i + 1 << ". " << "Name: " << friends[i].getName() << endl;
        cout << "   Phone Number: " << friends[i].getPhone() << endl;
        cout << "   Address: " << friends[i].getAddress() << endl;
        cout << "   Company Name: " << business_contacts[i].getCompanyName() << endl;
    }
    cout << endl;
}
void main() {
   
    while (true) {
        // menu selection for user
        cout << "=============================================\n";
        cout << "  SMALL OOP PERSON MANAGEMENT PROJECT" << endl;
        cout << "=============================================\n";
        cout << "1. Add a person's contact information" << endl;
        cout << "2. View contact information" << endl;
        cout << "3. Delete contact information" << endl;
        cout << "4. Modify contact information   " << endl;
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
            //Friend(string name, string address, string phone) : Person(name, address)
            // Contact(string name, string address, string company_name) 
            string name, phone_number, address,companyName;
            cout << endl;
            cout << "Enter name: ";
            cin.ignore();
            getline(std::cin, name);
            cout << "Enter phone number: ";
            getline(std::cin, phone_number);
            cout << "Enter address: ";
            getline(std::cin, address);
            cout << "Company name: ";
            cin.ignore();
            getline(std::cin, companyName);
            cout << endl;

            Contact newContact = Contact(name, address, companyName);
            Friend newFriend = Friend(name, address, phone_number);
            friends.push_back(newFriend);
            business_contacts.push_back(newContact);
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
                    business_contacts.erase(business_contacts.begin() + (contactIndex - 1));
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
                    business_contacts[contactIndex - 1].setName(name);
                    cout << "Enter new phone number: ";
                    string phone_number;
                    getline(cin, phone_number);
                    friends[contactIndex - 1].setPhone(phone_number);
                  
                    cout << "Enter new address: ";
                    string address;
                    getline(cin, address);
                    friends[contactIndex - 1].setAddress(address);  
                    business_contacts[contactIndex - 1].setAddress(address);

                    cout << "Enter company name: ";
                    string companyName;
                    cin.ignore();
                    getline(cin, companyName);
                    business_contacts[contactIndex - 1].setCompanyName(companyName);

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
                                Friend temp = friends[i];
                                friends[i] = friends[j];
                                friends[j] = temp;
                            }
                        }
                    }
                    for (int i = 0; i < friends.size(); i++) {
                        cout << "\n\nName           :" << friends[i].getName() << endl;
                        cout << "Contact Number :" << friends[i].getPhone() << endl;
                        cout << "Address        :" << friends[i].getAddress() <<endl;
                        cout << "Company Name   :" << business_contacts[i].getCompanyName() << endl;
                    }
                }
                else if (sortChoice == 2) {
                    for (int i = 0; i < friends.size(); i++) {
                        for (int j = i + 1; j < friends.size(); j++) {
                            if (friends[i].getName() < friends[j].getName()) {
                                Friend temp = friends[i];
                                friends[i] = friends[j];
                                friends[j] = temp;
                            }
                        }
                    }
                    for (int i = 0; i < friends.size(); i++) {
                        cout << "\n\nName           :" << friends[i].getName() << endl;
                        cout << "Contact Number :" << friends[i].getPhone() << endl;
                        cout << "Address        :" << friends[i].getAddress() << endl;
                        cout << "Company Name   :" << business_contacts[i].getCompanyName() << endl;
                    }
                }
                else {
                    std::cout << "Invalid choice" << std::endl;
                }
            }
        }
        // Search based on a value
        else if (choice == 6) {
            string searchValue;
            cout << "Enter the value to search for: ";
            cin.ignore();
            getline(cin, searchValue);
            bool found = false;
            for (int i = 0; i < friends.size(); i++) {
                if (friends[i].getName() == searchValue || friends[i].getPhone() == searchValue || friends[i].getAddress() == searchValue) {
                    cout << "Name: " << friends[i].getName() << endl;
                    cout << "Phone Number: " << friends[i].getPhone() << endl;
                    cout << "Address:" << friends[i].getAddress() << endl;
                    cout << "Company Name:" << business_contacts[i].getCompanyName();
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
                outfile << friends[i].getPhone() << " ";
                outfile << friends[i].getAddress() << " ";
                outfile << business_contacts[i].getCompanyName() << endl;
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
            string name, phone_number, address,companyName;
            if (!infile) {
                cout << "File not found" << endl;
                continue;
            }  
            

            int count = 0;
            while (infile >> name >> phone_number >> address>>companyName) {
                Friend new_friend = Friend(name, address,phone_number);
                Contact new_contact = Contact(name, address, companyName);
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

}
