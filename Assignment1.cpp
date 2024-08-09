#include <iostream>
using namespace std;

class student {
private:
    char name[20];
    int roll_no;
    int age;

public:
    void getdata() {
        cout << "Enter details of student:\n";
        cout << "Name: ";
        cin >> name;
        cout << "Roll No: ";
        cin >> roll_no;
        cout << "Age: ";
        cin >> age; 
    }

    void showdata() {
        cout << "The student details:\n";
        cout << "Name: " << name << "\n";
        cout << "Roll No: " << roll_no << "\n";
        cout << "Age: " << age << "\n"; 
    }
};

int main() {
    student obj;
    obj.getdata();
    obj.showdata();
    return 0;
}

