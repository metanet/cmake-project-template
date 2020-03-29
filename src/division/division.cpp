//
// Created by Konstantin Gredeskoul on 5/14/17.
//

#include "division.h"


Fraction::Fraction(const Fraction &f) : numerator(f.numerator), denominator(f.denominator) {
    std::cout << "Fraction copy c'tor" << std::endl;
}

Fraction::Fraction(Fraction &&f) noexcept : numerator(f.numerator), denominator(f.denominator) {
    std::cout << "Fraction move c'tor" << std::endl;
}

Fraction &Fraction::operator=(const Fraction &other) {
    std::cout << "Fraction copy assignment" << std::endl;
    if (this != &other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }

    return *this;
}

Fraction &Fraction::operator=(Fraction &&other) noexcept {
    std::cout << "Fraction move assignment" << std::endl;
    if (this != &other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }

    return *this;
}

DivisionResult::DivisionResult(const DivisionResult &d) : division(d.division), remainder(d.remainder) {
    std::cout << "DivisionResult copy c'tor" << std::endl;
}

DivisionResult::DivisionResult(DivisionResult &&d) noexcept : division(d.division), remainder(d.remainder) {
    std::cout << "DivisionResult move c'tor" << std::endl;
}

DivisionResult &DivisionResult::operator=(const DivisionResult &other) {
    std::cout << "DivisionResult copy assignment" << std::endl;
    if (this != &other) {
        this->division = other.division;
        this->remainder = other.remainder;
    }

    return *this;
}

DivisionResult &DivisionResult::operator=(DivisionResult &&other) noexcept {
    std::cout << "DivisionResult move assignment" << std::endl;
    if (this != &other) {
        this->division = other.division;
        this->remainder = other.remainder;
    }

    return *this;
}


Division::Division(const Fraction &f) : fraction(f) {
    std::cout << "Division copy c'tor" << std::endl;
}

Division::Division(Fraction &&f) noexcept : fraction(std::move(f)) {
    // From Scott Mayers:
    // an rvalue reference as a function parameter is turned back into
    // an lvalue by virtue of the fact that it is now named, and therefore
    // std::move is necessary once again turn it back into an rvalue.

    std::cout << "Division move c'tor" << std::endl;
}

DivisionResult Division::divide() {
    if (fraction.denominator == 0L) {
        throw DivisionByZero();
    }

    DivisionResult result = {
            fraction.numerator / fraction.denominator,
            fraction.numerator % fraction.denominator
    };

  return result;
}
