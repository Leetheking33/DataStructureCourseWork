#include <string>

class Dog {
    private:
        int mBreed;
        int mColor;
        int mAge;
        std::string *mName;
    public:
        Dog() {
            mBreed = 0;
            mColor = 0;
            mAge = 1;
            mName = new std::string("Spot");
        }
        Dog(int age) {
            mBreed = 0;
            mColor = 0;
            mAge = age;
            mName = new std::string("Spot");
        }
        ~Dog() {
            delete mName;
        }
        void setAge(int age) { mAge = age; }
        void bark();
};

int main(int argc, char *argv[]) {
    Dog d;
    Dog d2(10);

    d = d2;

    return 0;
}
