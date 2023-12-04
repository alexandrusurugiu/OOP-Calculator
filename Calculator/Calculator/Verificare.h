#pragma once
#include <iostream>
#include <string>
#include "Evaluator.h"

class Verificare
{
private:
    char* expresie = nullptr;
    int nrCifre = 0;

public:
    Verificare(std::string ceva);
    Verificare();
    Verificare(const Verificare& copie);
    ~Verificare();

    char* getExpresie();
    void setExpresie(const char* expresie);

    void EliminaSpatii(const std::string& expresie, std::string& sir);
    void Prelucrare();

    friend std::istream& operator>>(std::istream& in, Verificare& v);
    friend std::ostream& operator<<(std::ostream& out, Verificare& v);

    Verificare operator=(const Verificare& copie);
    Verificare& operator++();
    Verificare& operator++(int);
    char operator[](int index);
};
