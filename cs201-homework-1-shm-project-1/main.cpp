//Write Your Code Here
#include "Dog.hpp" // <- class Dog is in "Dog.cpp" && "Dog.hpp"
#include "Owner.hpp" // <- class Owner is in "Owner.cpp" && "Owner.hpp"


struct Pair { //struct to store dog name and owner name
    string ownerName;//to store owner name
    string dogName;//to store dog name
};


int main(int argc, const char * argv[]) {

    //----------PART ONE: DO NOT CHANGE CODE!----------

    Dog d("Beethoven","Saint Bernard",100,1,19.5,"Brown");
    d.printDetails();
}
