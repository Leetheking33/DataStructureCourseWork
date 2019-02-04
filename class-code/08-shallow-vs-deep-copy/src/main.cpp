#include <iostream>
#include <string.h>
#include "second.hpp"

class Car {
    public:
        Car() {
            mDoors = 3;
            mRocketsAmt = 2;
            mName = NULL;
        }
        Car(Car *car) {
            mDoors = (*car).mDoors;
            mRocketsAmt = car->mRocketsAmt;
            //mName = car->mName; //WRONG: SHALLOW COPY
            // Do a deep copy
            setName(car->mName);
        }
        void setName(const char *name) {
            //Shallow Copy:
            //mName = name;

            //Deep Copy:
            mName = new char[strlen(name)];
            for (size_t i = 0; i <= strlen(name); i++) {
                mName[i] = name[i];
            }
        }
        char* getName() {
            return mName;
        }
        ~Car() {
            std::cout << mName <<  ": I'm in delete!\n";
            delete [] mName;
        }
    private:
        int mDoors;
        int mRocketsAmt;
        char *mName;
};

int main(int argc, char *argv[]) {
    int ary1[] = {1, 2, 3, 10, 19, 32};

    int *shallow_copy = ary1;

    int *deep_copy = new int[6];
    for (int i = 0; i < 6; i++) {
        deep_copy[i] = ary1[i];
    }

    /*
    Car *car = new Car();
    car->setName("miles");
    delete car;
    */
    Car car2;
    car2.setName("batmobile");

    std::cout << "car2.getName() = " << car2.getName() << "\n";

    Car dodge(&car2);

    /*
    std::cout << "dodge.getName() = " << dodge.getName() << "\n";
    */
}
