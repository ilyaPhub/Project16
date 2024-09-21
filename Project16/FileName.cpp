#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;   // Numerator
    int denominator; // Denominator

public:
    Fraction() : numerator(0), denominator(1) {}


    Fraction(int n, int d) {
        numerator = n;
        if (d != 0) {
            denominator = d;
        }
        else {
            cout << "Denominator cannot be zero. Set to 1." << endl;
            denominator = 1;
        }
    }


    void input() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
        if (denominator == 0) {
            cout << "Denominator cannot be zero. Set to 1." << endl;
            denominator = 1;
        }
    }


    void display() const {
        cout << numerator << "/" << denominator << endl;
    }


    void simplify() {
        int gcd = findGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }


    Fraction operator+(const Fraction& other) const {
        int n = numerator * other.denominator + other.numerator * denominator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    }


    Fraction operator-(const Fraction& other) const {
        int n = numerator * other.denominator - other.numerator * denominator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    }


    Fraction operator*(const Fraction& other) const {
        int n = numerator * other.numerator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    }


    Fraction operator/(const Fraction& other) const {
        int n = numerator * other.denominator;
        int d = denominator * other.numerator;
        return Fraction(n, d);
    }

private:

    int findGCD(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    Fraction f1, f2, result;

    cout << "Enter the first fraction:" << endl;
    f1.input();
    cout << "Enter the second fraction:" << endl;
    f2.input();


    result = f1 + f2;
    cout << "Addition: ";
    result.simplify();
    result.display();

    result = f1 - f2;
    cout << "Subtraction: ";
    result.simplify();
    result.display();

    result = f1 * f2;
    cout << "Multiplication: ";
    result.simplify();
    result.display();

    result = f1 / f2;
    cout << "Division: ";
    result.simplify();
    result.display();

    return 0;
}
