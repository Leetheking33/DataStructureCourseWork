#include <iostream>
#include "array.hpp"

template <class T>
T add(T a, T b) {
    return a + b;
}

class House {
    public:
        House() {
            mRooms = 0;
        }
        void operator++(int) {
            mRooms++;
        }
        void operator++() {
            mRooms++;
        }
        void operator+(House &house) {
            mRooms += 100;
        }
        int getRooms() {
            return mRooms;
        }
        const House& operator=(const House &house) {
            this->mRooms = house.mRooms;
            return *this;
        }
    private:
        int mRooms;
};

int main(int argc, char *argv[]) {
    std::cout << "add(1, 2) = " << add(1, 2) << "\n";
    std::cout << "add(1.2, 2.4) = " << add(1.2, 2.4) << "\n";

    House house;
    std::cout << "house.getRooms() = " << house.getRooms() << "\n";
    house++;
    std::cout << "house.getRooms() = " << house.getRooms() << "\n";
    house + house;
    std::cout << "house.getRooms() = " << house.getRooms() << "\n";

    House shack;
    shack++;
    house = shack;
    std::cout << "house.getRooms() = " << house.getRooms() << "\n";

    Array<int> iarray(10);
}
