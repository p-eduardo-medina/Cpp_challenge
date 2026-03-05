#include <iostream>
using namespace std;

class Student {
    public:
        string name;
        int age;
        string major;
        float gpa;
        Student(string aName, int aAge, string aMajor, float aGpa) {
            this->name = aName;
            this->age = aAge;
            this->major = aMajor;
            this->gpa = aGpa;
        }
        void introduce() {
            cout << "Hi, my name is " << name << ", I am " << age << " years old and I am majoring in " << major << "." << endl;
        }
        bool hasHonors(){
            if(gpa > 3.5){
                return true;
            } else {
                return false;
            }
        }
};

int main() {
    Student student1("Alice", 20, "Computer Science", 3.8);
    student1.introduce();
    if(student1.hasHonors()) {
        cout << student1.name << " has honors!" << endl;
    }
    else {
        cout << student1.name << " does not have honors." << endl;
    }

    Student student2("Bob", 22, "Mathematics", 3.2);
    student2.introduce();
    if(student2.hasHonors()) {
        cout << student2.name << " has honors!" << endl;
    }
    else {
        cout << student2.name << " does not have honors." << endl;
    }

    return 0;
}