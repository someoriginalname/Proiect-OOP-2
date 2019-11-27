#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <string>
#include <exception>

class Vector
{
int *a;
public:
    Vector(std::string numar);
    Vector();
    Vector(const Vector& ob);
    Vector& operator=(Vector ob);
    ~Vector();
    void afisare(int _nrcif);
    void alocate(int _nrcif);
    int& operator[](int nr);
    void getad();
    int* retad();
};

#endif // VECTOR_H
