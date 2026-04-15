#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) {
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other) {
    (void)other;
    return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* p_data)
{
    return reinterpret_cast<uintptr_t>(p_data);
}

Data* Serializer::deserialize(uintptr_t p_uni)
{
    return reinterpret_cast<Data *>(p_uni);
}