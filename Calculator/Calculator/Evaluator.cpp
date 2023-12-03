#include "Evaluator.h"
#include <iostream>

bool Evaluator::getErori()
{
    return this->erori;
}

void Evaluator::setErori(bool eroare)
{
    this->erori = eroare;
}

double Evaluator::Operatii(double operand1, double operand2, char semn)
{
    try
    {
        if (semn == '+')
        {
            rezultat = operand1 + operand2;
            return rezultat;
        }

        if (semn == '-')
        {
            rezultat = operand1 - operand2;
            return rezultat;
        }

        if (semn == '*')
        {
            rezultat = operand1 * operand2;
            return rezultat;
        }

        if (semn == '/')
        {
            if (operand2 == 0)
                throw std::exception("Eroare: incerci sa imparti un numar la 0!");
            else
            {
                rezultat = operand1 / operand2;
                return rezultat;
            }
        }

        else
            std::cout << "Semnul pe care incerci sa il introduci este indisponibil inca!";
    }

    catch (const std::exception& e)
    {
        std::cout << "\n" << e.what();
    }
}

double Evaluator::getRezultat()
{
    return this->rezultat;
}

void Evaluator::setRezultat(double rez)
{
    this->rezultat = rez;
}

void Evaluator::Rezultat()
{
    std::cout << "\n" << "Rezultatul ecuatiei este: " << this->rezultat;
}

std::istream& operator>>(std::istream& in, Evaluator& e)
{
    in >> e.rezultat;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Evaluator& e)
{
    out << e.rezultat;
    return out;
}

Evaluator operator+(Evaluator e1, Evaluator e2)
{
    e1.rezultat = e1.rezultat + e2.rezultat;
    return e1;
}

Evaluator operator-(Evaluator e1, const Evaluator e2)
{
    e1.rezultat = e1.rezultat - e2.rezultat;
    return e1;
}
