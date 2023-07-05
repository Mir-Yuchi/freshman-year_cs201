//
// Created by Mirazimov Mirkamol ID:220427
//

#include "Dog.hpp"

static set<string> names; // <- static variable

Dog::Dog() {};// <- default constructor

Dog::Dog(string n, string b, int e, int a, float s, string c) {  // <- constructor with parameters
    setName(n);// <- setters
    setBreed(b);// <- setters
    setEnergy(e);// <- setters
    setAge(a);// <- setters
    setSize(s);// <- setters
    setColor(c);// <- setters
}

void Dog::setName(string n) { // <- setters
    if (names.find(n) == names.end()) {// <- check if name is already taken
        this->name = n;
        names.insert(n);// <- insert name to set
    } else {
        cout << "Name " << n << " is already taken. Please choose another name." << endl;// <- output error message
    }
}

void Dog::setBreed(string b) { this->breed = b; }

void Dog::setEnergy(int e) {
    if (e > 100) {// <- check if energy more than max
        this->energy = 100;// <- set energy to max
    } else if (e < 0) {
        this->energy = 0;// <- set energy to min if less than min
    } else {
        this->energy = e;
    }
}

void Dog::setAge(int a) { this->age = a; } // <- setters

void Dog::setSize(float s) { this->size = s; }// <- setters

void Dog::setColor(string c) { this->color = c; }// <- setters

string Dog::getName() { return this->name; }// <- getters

string Dog::getBreed() { return this->breed; }// <- getters

string Dog::getColor() { return this->color; }// <- getters

int Dog::getEnergy() { return this->energy; }// <- getters

int Dog::getAge() { return this->age; }// <- getters

float Dog::getSize() { return this->size; }// <- getters

void Dog::setDetails() {// <- setters with input from user
    cout << "Enter the Dog's name: ";
    cin >> this->name;
    cout << "Enter the Dog's breed: ";
    cin >> this->breed;
    cout << "Enter the Dog's energy: ";
    cin >> this->energy;
    cout << "Enter the Dog's age: ";
    cin >> this->age;
    cout << "Enter the Dog's size: ";
    cin >> this->size;
    cout << "Enter the Dog's color: ";
    cin >> this->color;
}

void Dog::printDetails() {// <- getters with output to user
    cout << "The Dog's name is: " << getName() << endl;
    cout << "The Dog's breed is: " << getBreed() << endl;
    getline(cin, this->color);
    cout << "The Dog's Energy is: " << getEnergy() << "%\n";
    cout << "The Dog's Age is: " << getAge() << endl;
    cout << "The Dog's Size is: " << getSize() << "kg\n";
    cout << "The Dog's Color is: " << getColor() << endl;
}

void Dog::walk(int minutes) {// <- methods
    if (this->energy <= 0)// <- check if energy equals or less then 0
        cout << "Dog " << getName() << " needs some sleep!\n";
    this->energy -= minutes * 2;// <- decrease energy
    cout << "The energy of the dog " << getName() << " is: " << getEnergy() << "%\n";// <- output energy
}

void Dog::sleep(int minutes) {// <- methods
    if (this->energy != 100) {// <- check if energy is not max
        this->energy += minutes * 3;// <- increase energy
    } else if (this->energy > 100) {// <- check if energy more than max
        this->energy = 100;// <- set energy to max
    }
    cout << "The energy of the dog " << getName() << " is: " << getEnergy() << "%\n";// <- output energy
}

void Dog::bark() {// <- methods
    cout << getName() << " said \"Bowwow!\"" << endl;// <- output bark
}

void Dog::eat() {// <- methods
    this->size += 0.5;// <- increase size
    cout << "The size of the dog " << getName() << " is: " << getSize() << "kg\n";// <- output size
}