#include <iostream>
#include <stdexcept>

#include "Integer.h"

Integer::Integer(): value(0) {}

Integer::Integer(int value) {
    if(value > 128 || value < -128) {
        throw std::invalid_argument("value range (-128, 128)");
    }
    this->value = value;
}

int Integer::get() {
    return this->value;
}

void Integer::display() {
    std::cout << this->value << std::endl;
}

Integer Integer::operator =(int value) {
    return Integer(value);
}

Integer& Integer::operator ++() {
    this->value++;
    return *this;
}

Integer Integer::operator ++(int crap) {
    return Integer(this->value++);
}

Integer& operator --(Integer& some) {
    some.value--;
    return some;
}

Integer operator --(Integer& some, int crap) {
    return Integer(some.value--);
}

Integer Integer::operator +(Integer& term) {
    return Integer(this->value + term.value);
}

Integer Integer::operator +(int term) {
    return Integer(this->value + term);
}

Integer operator -(Integer& minuend, Integer& subtrahend) {
    return Integer(minuend.value - subtrahend.value);
}

Integer Integer::operator -(int subtrahend) {
    return Integer(this->value - subtrahend);
}