#include <iostream>
#include <string>
using namespace std;

class Animal abstract {
public:
    virtual void SetName(string name) {}
    virtual string GetName() = 0;
    virtual Animal* clone() const = 0;
};

class Sheep : public Animal {
private:
    string name;
    Sheep(const Sheep& donor) {
        this->name = donor.name;
    }
public:
    Sheep() {}

    void SetName(string name) override {
        this->name = name;
    }

    string GetName() override {
        return name;
    }

    Sheep* clone() const {
        return new Sheep(*this);
    }
};

int main() {
    Sheep* sheepDonor = new Sheep();
    sheepDonor->SetName("Dolly");

    Sheep* sheepClone = sheepDonor->clone();

    cout << "sheepDonor: " << sheepDonor->GetName() << "\n";
    cout << "sheepClone: " << sheepClone->GetName() << "\n";
}