#include "Afisare.h"
#include <iostream>
#include <string>

int Afisare::nrInstanta = 0;

Afisare::Afisare()
{
    this->merge = true;
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

void Afisare::EcranPrincipal()
{
    Verificare v;
    std::string input;
    std::string sir;
    std::cout << "Introdu expresia pe care vrei sa o prelucrezi:";
    std::cout << "\n" << "Daca vrei sa iesi, tasteaza exit";
    std::cout << "\n";

    while (this->merge == true)
    {
        getline(std::cin, input);

        if (input == "exit" || input == "")
        {
            this->merge = false;
            break;
        }
        else
        {
            v.EliminaSpatii(input, sir);
            v.setExpresie(sir.c_str());
            v.Prelucrare();
            std::cout << "\n" << "Introdu alta expresie: ";
        }
        std::cout << "\n";
        
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

bool Afisare::operator!()
{
    return this->instanteCreate != 0;
}
