#pragma once
#include <iostream>
#include <string>
#include "Evaluator.h"

using namespace std;


class Verificare
{
private:
	char* expresie = nullptr;
	int nrCifre = 0;
	
public:

	Verificare();

	Verificare(const Verificare& copie)
	{
		if (copie.expresie != nullptr)
		{
			this->expresie = new char[strlen(copie.expresie) + 1];
			strcpy_s(this->expresie, strlen(copie.expresie) + 1, copie.expresie);
		}
	}

	~Verificare()
	{
		delete[] this->expresie;
	}

	const char* getExpresie() 
	{
		return this->expresie;
	}

	void setExpresie(const char* expresie) 
	{
		if (expresie != nullptr)
		{
			delete[] expresie;

			this->expresie = new char[strlen(expresie) + 1];
			strcpy_s(this->expresie, strlen(expresie) + 1, expresie);
		}
		else
		{
			expresie = nullptr;
		}
	}

	void Spatii (const string& expresie, string& sir)
	{
		int start = 0;
		char operand;

		for (int i = 0; i < expresie.size(); i++)
		{
			if (!isdigit(expresie[i]) && expresie[i] != '.')
			{
				operand = expresie[i];
				sir = sir + expresie.substr(start, i - start) + " ";
				sir = sir + string(1, operand) + " ";
				start = i + 1;
			}
		}

		if (start < expresie.size())
		{
			sir = sir + expresie.substr(start) + " ";
		}
		cout << sir;
	}

	void Prelucrare()
	{
		if (this->expresie != nullptr)
		{
			string expresie = this->expresie;

			string token;
			int pos = 0;

			if ((pos = expresie.find(' ')) != string::npos)
			{
				token = expresie.substr(0, pos);
				expresie.erase(0, pos + 1);

				//Evaluator e(stod(token));

				char semn;
				double operand2;
				while ((pos = expresie.find(' ')) != string::npos)
				{
					semn = expresie[0];
					expresie.erase(0, 2);

					pos = expresie.find(' ');
					token = expresie.substr(0, pos);
					expresie.erase(0, pos + 1);

					operand2 = stod(token);
				}
				//e.printFinalResult();
			}
		}
	}

	friend istream& operator>>(istream& in, Verificare& v);
	friend ostream& operator<<(ostream& out, Verificare& v);

	Verificare operator=(const Verificare& copie)
	{
		if (&copie == this)
			return *this;
	}

	Verificare& operator++()
	{
		nrCifre++;
		return *this;
	}
};

istream& operator>>(istream& in, Verificare& v)
{
	in >> v.expresie;
	return in;
}

ostream& operator<<(ostream& out, Verificare& v)
{
	out << v.expresie;
	return out;
}
