#include <division.h>
#include <string>

static const char *const HEADER = "\nDivider © 2018 Monkey Claps Inc.\n\n";
static const char *const USAGE = "Usage:\n\tdivider <numerator> <denominator>\n\nDescription:\n\tComputes the result of a fractional division,\n\tand reports both the result and the remainder.\n";

int main(int argc, const char *argv[]) {
    std::cout << HEADER;

    // ensure the correct number of parameters are used.
    if (argc < 3) {
        std::cout << USAGE;
        return 1;
    }

    long long int numerator = strtoll(argv[1], nullptr, 10);
    long long int denominator = strtoll(argv[2], nullptr, 10);
    Division d{Fraction{numerator, denominator}};
    try {
        DivisionResult r = d.divide();

        std::cout << "Division : " << numerator << " / " << denominator << " = " << r.division << "\n";
        std::cout << "Remainder: " << numerator << " % " << denominator << " = " << r.remainder << "\n";
    } catch (DivisionByZero &) {
        std::cout << "Can not divide by zero, Homer. Sober up!\n";
    }
    return 0;
}
