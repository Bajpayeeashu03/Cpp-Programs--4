#include <iostream>
using namespace std;
class Shape 
{
    public:
     virtual double area() = 0;
     virtual double perimeter() = 0;
};
class Square : public Shape 
{
    private:
     double side;
    public:
        Square(double s) : side(s) {};
        double area()
        { 
            return side * side; 
        }
        double perimeter()
        { 
            return 4 * side; 
        }
};
class Rectangle : public Shape 
{
    private:
        double length, breadth;
    public:
        Rectangle(double l, double b) : length(l), breadth(b) {};
        double area()
        { 
            return length * breadth;
        }
        double perimeter() 
        { 
            return 2 * (length + breadth); 
        }
};
int main() {
    int choice;
    double side, length, breadth;
    cout << "Enter 1 for Square or 2 for Rectangle "<<endl;
    cin >> choice;
    Shape* ptr;
    if (choice == 1) 
    {
        cout << "Enter side of Square: ";
        cin >> side;
        ptr = new Square(side);
    } 
    else if (choice == 2) 
    {
        cout << "Enter length and breadth of Rectangle: ";
        cin >> length >> breadth;
        ptr = new Rectangle(length, breadth);
    } 
    else 
    {
        cout << "Invalid choice!" << endl;
        return 1;
    }
    cout << "Area: " << ptr->area() << endl;
    cout << "Perimeter: " << ptr->perimeter() << endl;
    delete ptr;
    return 0;
}