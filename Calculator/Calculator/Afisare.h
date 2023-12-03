#pragma once
#include <iostream>
#include <string>
#include "Verificare.h"

using namespace std;

class Afisare
{
private:
	bool merge = false;
	static int nrInstanta;
	int instanteCreate = 0;
	const int MAX_INSTANTE = 10;

public:

	Afisare();

	~Afisare()
	{

	}

	bool getMerge()
	{
		return this->merge;
	}

	void setMerge(bool merge)
	{
		this->merge = merge;
	}

	int getInstanteCreate()
	{
		return this->instanteCreate;
	}

	int getNrInstanta() const 
	{
		return nrInstanta;
	}

	Afisare(int nrInstanta)
	{
		if (instanteCreate < MAX_INSTANTE) 
		{
			this->instanteCreate++;
			this->merge = true;
		}
		else 
		{
			cout << "\n" << "Prea multe instante ce ruleaza simultan!";
			this->merge = false;
		}
	}

	int EcranPrincipal()
	{
		Verificare v;
		string input;
		cout << "\n" << "Introdu expresia pe care vrei sa o prelucrezi:";
		cout << "\n" << "Daca vrei sa iesi, tasteaza exit";

		while (this->merge == true)
		{
			cin >> input;
			
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

	friend istream& operator>>(istream& in, Afisare& a);
	friend ostream& operator<<(ostream& out, Afisare& a);

	bool operator>(int copie)
	{
		if (instanteCreate > copie)
			return true;

		return false;
	}

	bool operator<(int copie)
	{
		if (instanteCreate < copie)
			return true;

		return false;
	}
};

	int Afisare::nrInstanta = 0;

	istream& operator>>(istream& in, Afisare& a)
	{
		in >> a.instanteCreate;
		return in;
	}

	ostream& operator<<(ostream& out, Afisare& a)
	{
		out << a.instanteCreate;
		return out;
	}
