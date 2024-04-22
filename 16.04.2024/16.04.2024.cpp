#include <iostream>

using namespace std;

class Animal {
public:
    virtual void speak() = 0;
    virtual void scratch(bool HomeworkDone) {};
    virtual void purr() {};
};

class Frog : public Animal {
public:
    void speak() override {
        cout << "Quaaaaaaaaa." << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof Woof Woof." << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Meow Meow Meow." << endl;
    }

    void scratch(bool HomeworkDone) override {
        if (HomeworkDone) {
            cout << "Owner is safe." << endl;
        }
        else {
            cout << "Owner is scratched." << endl;
        }
    }

    void purr() override {
        cout << "Purr Purr Purr." << endl;
    }
};

int main() {
    Animal* animals[3];
    animals[0] = new Frog();
    animals[1] = new Dog();
    animals[2] = new Cat();

    for (int i = 0; i < 3; i++) {
        animals[i]->speak();
        Cat* cat = dynamic_cast<Cat*>(animals[i]);
        if (cat != nullptr) {
            cat->scratch(false);
            cat->purr();
        }
    }

    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }
}