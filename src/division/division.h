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

    Fraction(const Fraction &f);

    Fraction(Fraction &&f) noexcept;

    Fraction &operator=(const Fraction &other);

    Fraction &operator=(Fraction &&other) noexcept;
};

struct DivisionResult {
    long long division;
    long long remainder;

    DivisionResult() = default;

    DivisionResult(long long d, long long r) : division(d), remainder(r) {}

    DivisionResult(const DivisionResult &d);

    DivisionResult(DivisionResult &&d) noexcept;

    DivisionResult &operator=(const DivisionResult &other);

    DivisionResult &operator=(DivisionResult &&other) noexcept;
};

class Division {
public:
    explicit Division(const Fraction &f);

    explicit Division(Fraction &&f) noexcept;

    ~Division() = default;

    DivisionResult divide();

private:
    Fraction fraction;
};

#endif //CMAKE_DIVISION_H
