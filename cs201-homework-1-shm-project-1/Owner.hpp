//
// Created by Mirazimov Mirkamol ID:220427
//

#ifndef CS201_HOMEWORK_1_SHM_PROJECT_1_OWNER_HPP
#define CS201_HOMEWORK_1_SHM_PROJECT_1_OWNER_HPP

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Owner {
    private:
        string name, dogName;
        int age, phoneNumber;

    public:
        Owner();
        Owner(string, int, int, string);

        void setName(string);// set name for owner
        void setAge(int);// set age for owner
        void setPhoneNumber(int);// set phone number for owner
        void setDogName(string);// set dog name for owner

        string getName();
        int getAge();// get age for owner
        int getPhoneNumber();// get phone number for owner
        string getDogName();// get dog name for owner

        void setDetails();// set details for owner
        void printDetails();// print details for owner
};

#endif // CS201_HOMEWORK_1_SHM_PROJECT_1_OWNER_HPP
