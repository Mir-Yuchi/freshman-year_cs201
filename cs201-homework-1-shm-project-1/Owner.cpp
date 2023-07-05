//
// Created by Mirazimov Mirkamol ID:220427
//

#include "Owner.hpp"

static set<string> names; // <- static variable

Owner::Owner() {};// <- default constructor
Owner::Owner(string n, int a, int pn, string dn) {// <- constructor with parameters
    setName(n);
    setAge(a);
    setPhoneNumber(pn);
    setDogName(dn);
}

void Owner::setName(string n) {
    if (names.find(n) == names.end()) {// <- if name is not taken
        this->name = n;
        names.insert(n);// <- add name
    } else {
        cout << "Name " << n << " is already taken. Please choose another name." << endl;// <- if name is taken
    }
}
void Owner::setAge(int a) { this->age = a; }
void Owner::setPhoneNumber(int pn) { this->phoneNumber = pn; }
void Owner::setDogName(string dn) { this->dogName = dn; }

string Owner::getName() { return this->name; }
int Owner::getAge() { return this->age; }
int Owner::getPhoneNumber() { return this->phoneNumber; }
string Owner::getDogName() { return this->dogName; }

void Owner::setDetails() {// <- take input from user
    cout << "Enter the owner's name: ";
    cin >> this->name;
    cout << "Enter the owner's age: ";
    cin >> this->age;
    cout << "Enter the owner's Phone Number: ";
    cin >> this->phoneNumber;
    cout << "Enter the owner's dog's name: ";
    cin >> this->dogName;
}

void Owner::printDetails() {// <- getters with output to user
    cout << "Owner's name is: " << this->name << endl;
    cout << "Owner's age is: " << this->age << endl;
    cout << "Owner's phone number is: " << this->phoneNumber << endl;
    cout << "Owner's dog's name is: " << this->dogName << endl;
}