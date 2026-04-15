#define SERIALIZER_HPP
#ifdef SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    int id;
    int quantity;
    int weight;
};


class Serializer
{
private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();
public:
    static uintptr_t serialize(Data* p_data);
    static Data* deserialize(uintptr_t p_uni);
};

#endif