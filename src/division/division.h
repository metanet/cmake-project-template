//
// Created by Konstantin Gredeskoul on 5/14/17.
//

#ifndef CMAKE_DIVISION_H
#define CMAKE_DIVISION_H

static const char *const DIVISION_BY_ZERO_MESSAGE = "Division by zero is illegal";

#include <iostream>
#include <stdexcept>

using namespace std;

class DivisionByZero : public exception {
public:
  const char *what() const noexcept override {
    return DIVISION_BY_ZERO_MESSAGE;
  }
};

struct Fraction {
    long long numerator;
    long long denominator;

    Fraction() = default;

    Fraction(long long n, long long d) : numerator(n), denominator(d) {}

    Fraction(const Fraction &f) : numerator(f.numerator), denominator(f.denominator) {
        std::cout << "Fraction copy c'tor" << std::endl;
    }

    Fraction(Fraction &&f) : numerator(f.numerator), denominator(f.denominator) {
        std::cout << "Fraction move c'tor" << std::endl;
    }

    Fraction &operator=(const Fraction &other) {
        std::cout << "Fraction copy assignment" << std::endl;
        if (this != &other) {
            this->numerator = other.numerator;
            this->denominator = other.denominator;
        }

        return *this;
    }

    Fraction &operator=(Fraction &&other) {
        std::cout << "Fraction move assignment" << std::endl;
        if (this != &other) {
            this->numerator = other.numerator;
            this->denominator = other.denominator;
        }

        return *this;
    }


};

struct DivisionResult {
    long long division;
    long long remainder;

    DivisionResult() = default;

    DivisionResult(long long d, long long r) : division(d), remainder(r) {}

    DivisionResult(const DivisionResult &d) : division(d.division), remainder(d.remainder) {
        std::cout << "DivisionResult copy c'tor" << std::endl;
    }

    DivisionResult(DivisionResult &&d) : division(d.division), remainder(d.remainder) {
        std::cout << "DivisionResult move c'tor" << std::endl;
    }

    DivisionResult &operator=(const DivisionResult &other) {
        std::cout << "DivisionResult copy assignment" << std::endl;
        if (this != &other) {
            this->division = other.division;
            this->remainder = other.remainder;
        }

        return *this;
    }

    DivisionResult &operator=(DivisionResult &&other) {
        std::cout << "DivisionResult move assignment" << std::endl;
        if (this != &other) {
            this->division = other.division;
            this->remainder = other.remainder;
        }

        return *this;
    }
};

class Division {
public:
    explicit Division(const Fraction &f) : fraction(f) {
        std::cout << "Division copy c'tor" << std::endl;
    }

    explicit Division(Fraction &&f) : fraction(std::move(f)) {
        // From Scott Mayers:
        // an rvalue reference as a function parameter is turned back into
        // an lvalue by virtue of the fact that it is now named, and therefore
        // std::move is necessary once again turn it back into an rvalue.

        std::cout << "Division move c'tor" << std::endl;
    }

    ~Division() = default;

    DivisionResult divide();

private:
    Fraction fraction;
};

#endif //CMAKE_DIVISION_H
