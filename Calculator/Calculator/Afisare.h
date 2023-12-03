#pragma once
#include <iostream>
#include <string>
#include "Verificare.h"

class Afisare
{
private:
    bool merge = false;
    static int nrInstanta;
    int instanteCreate = 0;
    const int MAX_INSTANTE = 10;

public:
    Afisare();
    ~Afisare();

    bool getMerge();
    void setMerge(bool merge);

    int getInstanteCreate();
    int getNrInstanta() const;

    Afisare(int nrInstanta);

    int EcranPrincipal();

    friend std::istream& operator>>(std::istream& in, Afisare& a);
    friend std::ostream& operator<<(std::ostream& out, Afisare& a);

    bool operator>(int copie);
    bool operator<(int copie);
};

std::istream& operator>>(std::istream& in, Afisare& a);
std::ostream& operator<<(std::ostream& out, Afisare& a);
