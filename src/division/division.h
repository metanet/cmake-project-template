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
};

struct DivisionResult {
    long long division;
    long long remainder;
};

class Division {
public:
    explicit Division(const Fraction& f) : fraction(f) {}

    ~Division() = default;;
    DivisionResult divide();

private:
    Fraction fraction;
};

#endif //CMAKE_DIVISION_H
