#pragma once
#include <iostream>

class Evaluator
{
private:
    bool erori = false;
    double rezultat = 0.00;

public:
    Evaluator();
    Evaluator(const Evaluator& copie);
    ~Evaluator();


    bool getErori();
    void setErori(bool eroare);

    double Operatii(double operand1, double operand2, char semn);

    double getRezultat();
    void setRezultat(double rez);

    void Rezultat();

    friend std::istream& operator>>(std::istream& in, Evaluator& e);
    friend std::ostream& operator<<(std::ostream& out, const Evaluator& e);
    friend Evaluator operator+(Evaluator e1, Evaluator e2);
    friend Evaluator operator-(Evaluator e1, const Evaluator e2);
};