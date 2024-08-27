#include <iostream>
using namespace std;
class student 
{
    private:
        int roll;
    public:
        student(int r = 0) : roll(r) {};
        void setr(int r) 
        {
             roll = r; 
        }
        void getr()
        { 
            cout << "Roll: " << roll << endl; 
        }
};
class test : virtual public student 
{
    private:
        int marks;
    public:
        test(int r = 0, int m = 0) : student(r), marks(m) {};
        void setm(int m)
        { 
            marks = m; 
        }
        void getm()
        { 
            cout << "Marks: " << marks << endl; 
        }
};

class sports : virtual public student 
{
    private:
        int score;
    public:
        sports(int r = 0, int s = 0) : student(r), score(s) {};
        void sets(int s) 
        { 
            score = s; 
        }
        void getS()
        {
            cout << "Score: " << score << endl; 
        }
};

class result : public test, public sports {
private:
    int total;
public:
    result(int r = 0, int m = 0, int s = 0) : student(r), test(r, m), sports(r, s) 
    {
        total = m + r;
    }
    void display() 
    {
        getS();
        getm();
        getr();
        cout << "Total: " << total << endl;
    }
};

int main() 
{
    int roll, marks, score;
    cout << "Enter Roll: ";
    cin >> roll;
    cout << "Enter Marks: ";
    cin >> marks;
    cout << "Enter Score: ";
    cin >> score;
    result r(roll, marks, score);
    r.display();
    return 0;
}