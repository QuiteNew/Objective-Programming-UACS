#include <stdexcept>

class NegativeDiscriminantException : public std::domain_error {
public:
    NegativeDiscriminantException()
    : std::domain_error("Negative discriminant") {}

    NegativeDiscriminantException(char* errmsg)
    : std::domain_error(errmsg) {
        std::cerr << "Negative discriminant" << std::endl;
    }
};


