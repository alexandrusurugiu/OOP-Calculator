#include "Verificare.h"
#include <cstring>

Verificare::Verificare(std::string ceva)
{
    this->expresie = new char[ceva.size() + 1];
    strcpy_s(this->expresie, ceva.size() + 1, ceva.c_str());
}

Verificare::Verificare()
{

}

Verificare::Verificare(const Verificare& copie)
{
    if (copie.expresie != nullptr)
    {
        this->expresie = new char[strlen(copie.expresie) + 1];
        strcpy_s(this->expresie, strlen(copie.expresie) + 1, copie.expresie);
    }
}

Verificare::~Verificare()
{
    delete[] this->expresie;
}

char* Verificare::getExpresie()
{
    if (this->expresie != nullptr)
    {
        char* copie = new char[strlen(expresie) + 1];
        strcpy_s(copie, strlen(expresie) + 1, this->expresie);
        return copie;
    }
    else
        return nullptr;
}

void Verificare::setExpresie(const char* expresie)
{
    if (expresie != nullptr)
    {
        delete[] this->expresie;

        this->expresie = new char[strlen(expresie) + 1];
        strcpy_s(this->expresie, strlen(expresie) + 1, expresie);
    }
    else
    {
        this->expresie = nullptr;

    }
}

void Verificare::EliminaSpatii(const std::string& expresie, std::string& sir)
{
    for (char caracter : expresie)
    {
        if (!isspace(caracter))
        {
            sir += caracter;
        }
    }
}


void Verificare::Prelucrare()
{
    std::string sir = this->expresie;
    std::string* componente = new std::string[sir.size()];

    int indexComponent = 0;

    std::string curent;

    for (int i = 0; i < sir.size(); i++)
    {
        if (isdigit(sir[i]) || sir[i] == '.')
        {
            curent += sir[i];
        }
        else
        {
            if (!curent.empty())
            {
                componente[indexComponent++] = curent;
                curent.clear(); 
            }

            componente[indexComponent++] = std::string(1, sir[i]);
        }
    }

    if (!curent.empty())
    {
        componente[indexComponent++] = curent;
    }

    Evaluator e;
    e.setRezultat(std::stod(componente[0]));

    for (int i = 1; i < indexComponent - 1; i++)
    {
        e.Operatii(e.getRezultat(), std::stod(componente[i + 1]), componente[i][0]);
    }

    delete[] componente;

    e.Rezultat();
}


std::istream& operator>>(std::istream& in, Verificare& v)
{
    in >> v.expresie;
    return in;
}

std::ostream& operator<<(std::ostream& out, Verificare& v)
{
    out << v.expresie;
    return out;
}

Verificare Verificare::operator=(const Verificare& copie)
{
    if (&copie == this)
        return *this;
    
    if (copie.expresie != nullptr)
    {
        delete[] this->expresie;

        strcpy_s(this->expresie, strlen(copie.expresie) + 1, copie.expresie);
    }
    else
    {
        delete[] this->expresie;
        this->expresie = nullptr;
    }
    return *this;
}

Verificare& Verificare::operator++()
{
    nrCifre++;
    return *this;
}

Verificare& Verificare::operator++(int)
{
    Verificare copie = *this;
    nrCifre++;
    return copie;
}

char Verificare::operator[](int index)
{
    if (index >= 0 && index < strlen(this->expresie))
    {
        return this->expresie[index];
    }
    else return -1;
}
