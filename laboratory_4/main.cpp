#include <iostream>

#include "Fraction.h"

using namespace std;

int main() {
    Fraction<float> fract(5.3, 6);
    Fraction<float> fract2(5.3, 6);
    cout << (fract + fract2) << endl;
    cout << (fract - fract2) << endl;
    cout << (fract * fract2) << endl;
    cout << (fract / fract2) << endl;
    cout << ++(fract + fract2) << endl;
}

