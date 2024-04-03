#include <iostream>
#include "Integer.h"

using namespace std;

int main() {
    Integer first = 120;
    Integer second = 50;

    cout << (first - second).get() << endl;
    cout << (second + 50).get() << endl;
    cout << (++first).get() << endl;
    cout << (--first).get() << endl;
}