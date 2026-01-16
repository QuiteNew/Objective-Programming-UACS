#include <stdexcept>

class DenominatorZeroException : public std::logic_error {
public:
    DenominatorZeroException()
    : std::logic_error("Denominator can not have a value of zero (0)") {}

    DenominatorZeroException(char* errmsg)
    : std::logic_error(errmsg) {
//        std::cout << "Denominator can not have a value of zero (0) - error message " << std::endl;
    }
};

