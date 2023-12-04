#include "Verificare.h"
#include <cstring>

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

const char* Verificare::getExpresie()
{
    return this->expresie;
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

void Verificare::Spatii(const std::string& expresie, std::string& sir)
{
    int start = 0;
    char operand;

    for (int i = 0; i < expresie.size(); i++)
    {
        if (!isdigit(expresie[i]) && expresie[i] != '.')
        {
            operand = expresie[i];
            sir = sir + expresie.substr(start, i - start) + " ";
            sir = sir + std::string(1, operand) + " ";
            start = i + 1;
        }
    }

    if (start < expresie.size())
    {
        sir = sir + expresie.substr(start) + " ";
    }
    std::cout << sir;
}

void Verificare::Prelucrare()
{
    Evaluator e;
    if (this->expresie != nullptr)
    {
        std::string expresie = this->expresie;

        std::string token;
        int pos = 0;

        if ((pos = expresie.find(' ')) != std::string::npos)
        {
            token = expresie.substr(0, pos);
            expresie.erase(0, pos + 1);

            char semn;
            double operand2;
            while ((pos = expresie.find(' ')) != std::string::npos)
            {
                semn = expresie[0];
                expresie.erase(0, 2);

                pos = expresie.find(' ');
                token = expresie.substr(0, pos);
                expresie.erase(0, pos + 1);

                operand2 = stod(token);
            }
            e.Rezultat();
        }
    }
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
}

Verificare& Verificare::operator++()
{
    nrCifre++;
    return *this;
}
