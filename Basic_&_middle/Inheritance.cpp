#include <iostream>
using namespace std;

class Chef {
    public:
        void makeChicken() {
            cout << "The chef makes chicken" << endl;
        }
        void makeSalad() {
            cout << "The chef makes salad" << endl;
        }
        void makeSpecialDish() {
            cout << "The chef makes bbq ribs" << endl;
        }
};

class ItalianChef : public Chef { // Inheritance: ItalianChef is a subclass of Chef
    public:
        void makePasta() {
            cout << "The chef makes pasta" << endl;
        }
        void makeSpecialDish() { // Method Overriding: ItalianChef provides its own implementation of makeSpecialDish()
            cout << "The chef makes chicken parm" << endl;
        }
};

class MexicanChef : public Chef { // Inheritance: MexicanChef is a subclass of Chef
    public:
        void makeTacos() {
            cout << "The chef makes tacos" << endl;
        }
        void makeSpecialDish() { // Method Overriding: MexicanChef provides its own implementation of makeSpecialDish()
            cout << "The chef makes burritos" << endl;
        }
};

int main() {
    Chef chef;
    cout << "Chef's dishes -->  " << endl;
    chef.makeChicken();
    chef.makeSalad();
    chef.makeSpecialDish();

    cout << endl;

    ItalianChef italianChef;
    cout << "Italian chef's dishes:" << endl;
    italianChef.makeChicken(); // Inherited method
    italianChef.makeSalad(); // Inherited method
    italianChef.makePasta(); // ItalianChef's own method
    italianChef.makeSpecialDish(); // Overridden method

    cout << endl;

    MexicanChef mexicanChef;
    cout << "Mexican chef's dishes:" << endl;
    mexicanChef.makeChicken(); // Inherited method
    mexicanChef.makeSalad(); // Inherited method
    mexicanChef.makeTacos(); // MexicanChef's own method
    mexicanChef.makeSpecialDish(); // Overridden method

    return 0;
}