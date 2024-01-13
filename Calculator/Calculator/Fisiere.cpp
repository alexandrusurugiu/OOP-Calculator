#include "Fisiere.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <stack>

    

    Fisiere::Fisiere(std::string numeFisier, bool binar) 
    {
        this->numeFisier = numeFisier;
        this->binar = binar;
    }

    std::string Fisiere::getNumeFisier()
    {
        return numeFisier;
    }

    void Fisiere::setNumeFisier(std::string numeFisier)
    {
        this->numeFisier = numeFisier;
    }

    bool Fisiere::getBinar()
    {
        return binar;
    }

    void Fisiere::setBinar(bool binar)
    {
        this->binar = binar;
    }
