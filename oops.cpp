#include <iostream>

using namespace std;

class Teacher
{
public:
    void display()
    {
        cout << "Teacher display" << endl;
    }
};

class Student : public Teacher
{
public:
    void display()
    {
        cout << "Student display" << endl;
    }
};

int main()
{
    Teacher *t;
    Student s;
    t = &s;
    t->display();
}
