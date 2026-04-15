#include "Serializer.hpp"

int main() {
    Data myData = {1, 100, 2000};

    uintptr_t encodedAddress = Serializer::serialize(&myData);

    std::cout << "Data Address (as a number): " << encodedAddress << std::endl;

    Data* decodedPtr = Serializer::deserialize(encodedAddress);
    std::cout << "Returned value: " << decodedPtr->quantity << std::endl;

    return 0;
}