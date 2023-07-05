//
// Created by Mirazimov Mirkamol ID:220427
//

#ifndef CS201_HOMEWORK_1_SHM_PROJECT_1_DOG_HPP
#define CS201_HOMEWORK_1_SHM_PROJECT_1_DOG_HPP

#include <iostream>
#include <string>
#include <set>
using namespace std;
//Prototypes of class Dog
class Dog {
    private:
        string name, breed, color;
        int age, energy;
        float size;

    public:
        Dog();// <- default constructor
        Dog(string, string, int, int, float, string);// <- constructor with parameters

        void setName(string);// <- setters
        void setBreed(string);// <- setters
        void setEnergy(int);// <- setters
        void setAge(int);// <- setters
        void setSize(float);// <- setters
        void setColor(string);// <- setters

        string getName();// <- getters
        string getBreed();// <- getters
        int getEnergy();// <- getters
        int getAge();// <- getters
        float getSize();// <- getters
        string getColor();// <- getters

        void setDetails();// <- setters with input from user
        void printDetails();// <- getters with output to user
        void walk(int);// <- methods
        void sleep(int);// <- methods
        void bark();// <- methods
        void eat();// <- methods
};

#endif // CS201_HOMEWORK_1_SHM_PROJECT_1_DOG_HPP
