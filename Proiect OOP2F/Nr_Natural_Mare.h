#ifndef NR_NATURAL_MARE_H
#define NR_NATURAL_MARE_H
#include "Vector.cpp"

class Nr_Natural_Mare
{
protected:
    int _nrcif;
    Vector V;
public:
    Nr_Natural_Mare(int _nrcif,std::string numar);
    Nr_Natural_Mare();
    Nr_Natural_Mare(std::string numar);
    Nr_Natural_Mare(const Nr_Natural_Mare& ob);
    void afisare();
    friend std::istream &operator>>(std::istream &ceva,Nr_Natural_Mare &nr);
    friend std::ostream &operator<<(std::ostream &ceva,Nr_Natural_Mare &nr);
    Nr_Natural_Mare& operator=(Nr_Natural_Mare nr);
    Nr_Natural_Mare operator+(Nr_Natural_Mare nr);
    int absmaxim(Nr_Natural_Mare b,Nr_Natural_Mare c);
    Nr_Natural_Mare operator-(Nr_Natural_Mare nr);
    Nr_Natural_Mare operator*(Nr_Natural_Mare nr);
    Nr_Natural_Mare operator++();
    Nr_Natural_Mare operator++(int);
    ~Nr_Natural_Mare();
};

#endif // NR_NATURAL_MARE_H
