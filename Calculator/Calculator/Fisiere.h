#pragma once
#include "Evaluator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <stack>


class Fisiere
{
private:
    std::string numeFisier;
    bool binar;
    std::map<std::string, double> variables;

public:
    Fisiere(std::string numeFisier, bool binar);

    std::string getNumeFisier();

    void setNumeFisier(std::string numeFisier);

    bool getBinar();

    void setBinar(bool binar);

    Evaluator e;

    void procesare();

    void salvareRezultat();
};


