#ifndef NR_INTREG_MARE_H
#define NR_INTREG_MARE_H
#include "Nr_Natural_Mare.cpp"

class Nr_Intreg_Mare:public Nr_Natural_Mare
{
char semn;
public:
    Nr_Intreg_Mare(char semn,int _nrcif,std::string numar);
    Nr_Intreg_Mare(int _nrcif,std::string numar);
    Nr_Intreg_Mare();
    Nr_Intreg_Mare(std::string numar);
    Nr_Intreg_Mare(const Nr_Intreg_Mare& ob);
    void afisare();
    friend std::istream &operator>>(std::istream &ceva,Nr_Intreg_Mare &nr);
    friend std::ostream &operator<<(std::ostream &ceva,Nr_Intreg_Mare &nr);
    void afisares();
    Nr_Intreg_Mare& operator=(Nr_Intreg_Mare nr);
    Nr_Intreg_Mare operator*(Nr_Intreg_Mare nr);
    Nr_Intreg_Mare operator+(Nr_Intreg_Mare nr);
    int absmaxim(Nr_Intreg_Mare b,Nr_Intreg_Mare c);
    Nr_Intreg_Mare operator-(Nr_Intreg_Mare nr);
    Nr_Intreg_Mare operator++();
    Nr_Intreg_Mare operator++(int);
    ~Nr_Intreg_Mare();
};

#endif // NR_INTREG_MARE_H
