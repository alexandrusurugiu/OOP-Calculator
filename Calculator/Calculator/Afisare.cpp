#include "Afisare.h"
#include <iostream>

int Afisare::nrInstanta = 0;

Afisare::Afisare()
{
}

Afisare::~Afisare()
{
}

bool Afisare::getMerge()
{
    return this->merge;
}

void Afisare::setMerge(bool merge)
{
    this->merge = merge;
}

int Afisare::getInstanteCreate()
{
    return this->instanteCreate;
}

int Afisare::getNrInstanta() const
{
    return nrInstanta;
}

Afisare::Afisare(int nrInstanta)
{
    if (instanteCreate < MAX_INSTANTE)
    {
        this->instanteCreate++;
        this->merge = true;
    }
    else
    {
        std::cout << "\n" << "Prea multe instante ce ruleaza simultan!";
        this->merge = false;
    }
}

int Afisare::EcranPrincipal()
{
    Verificare v;
    std::string input;
    std::cout << "\n" << "Introdu expresia pe care vrei sa o prelucrezi:";
    std::cout << "\n" << "Daca vrei sa iesi, tasteaza exit";

    while (this->merge == true)
    {
        std::cin >> input;

        if (input == "exit")
        {
            this->merge == false;
            return 0;
        }

        else
        {
            v.setExpresie(input.c_str());
            v.Prelucrare();
        }
    }
}

std::istream& operator>>(std::istream& in, Afisare& a)
{
    in >> a.instanteCreate;
    return in;
}

std::ostream& operator<<(std::ostream& out, Afisare& a)
{
    out << a.instanteCreate;
    return out;
}

bool Afisare::operator>(int copie)
{
    if (instanteCreate > copie)
        return true;

    return false;
}

bool Afisare::operator<(int copie)
{
    if (instanteCreate < copie)
        return true;

    return false;
}
