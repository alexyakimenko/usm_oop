#pragma once
#include <cmath>

template <typename T>
class Fraction {
public:
    T numeral;
    T nominative;

    Fraction(T numeral, T nominative): numeral(numeral), nominative(nominative) { }

    Fraction<T> sum(Fraction<T>& other) {
        const T resultNumeral = this->numeral * other.nominative + other.numeral * this->nominative;
        const T resultNominative = this->nominative * other.nominative;
        return Fraction<T>(resultNumeral, resultNominative);
    }

    Fraction<T> operator+(Fraction<T>& other) {
        return this->sum(other);
    }

    Fraction<T> subtract(const Fraction<T>& other) {
        const T resultNumeral = this->numeral * other.nominative - other.numeral * this->nominative;
        const T resultNominative = this->nominative * other.nominative;
        return Fraction<T>(resultNumeral, resultNominative);
    }

    Fraction<T> operator-(Fraction<T>& other) {
        return this->subtract(other);
    }

    Fraction<T> multiply(const Fraction<T>& other) {
        const T resultNumeral = this->numeral * other.numeral;
        const T resultNominative = this->nominative * other.nominative;
        return Fraction<T>(resultNumeral, resultNominative);
    }
    
    Fraction<T> operator*(Fraction<T>& other) {
        return this->multiply(other);
    }

    Fraction<T> divide(const Fraction<T>& other) {
        T resultNumeral = this->numeral * other.nominative;
        T resultNominative = this->nominative * other.numeral;
        return Fraction<T>(resultNumeral, resultNominative);
    }
    
    Fraction<T> operator/(Fraction<T>& other) {
        return this->divide(other);
    }

    Fraction<T>& operator++() {
        this->numeral += this->nominative;
        return *this;
    }

    double getDecimal() {
        return double(this->numeral) / double(this->nominative);
    }

    friend std::ostream& operator<<(std::ostream& cout, const Fraction<T>& fraction) {
        cout << fraction.numeral << "/" << fraction.nominative;
        return cout;
    }
    
};