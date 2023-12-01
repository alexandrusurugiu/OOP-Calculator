#include <iostream>
#include <string>
#include <vector>
//#include <Evaluator.cpp>

using namespace std;


class Verificare
{
	char* expresie = nullptr;
	int nrCifre = 0;
	
public:

	void getExpresie()
	{
		if (this->expresie != nullptr)
		{
			delete[] this->expresie;
			this->expresie == nullptr;
			
			char* copie = new char[strlen(this->expresie) + 1];
			this->expresie = copie;
		}
	}

	char* setExpresie(char* expresie)
	{
		return this->expresie = expresie;
	}

	void Verifica(char* expresie, int nrCifre)
	{
		for (int i = 0; i < nrCifre; i++)
		{
			this->expresie[i] = expresie[nrCifre];
		}
	}

	void Spatii(const string& expresie, vector<string>& sir) 
	{
		size_t start = 0;
		char operand;

		for (size_t i = 0; i < expresie.size(); i++) 
		{
			if (isdigit(expresie[i] == false) && expresie[i] != '.') 
			{
				operand = expresie[i];
				sir.push_back(expresie.substr(start, i - start));
				sir.push_back(string(1, operand));
				start = i + 1;
			}
		}

		if (start < expresie.size()) {
			sir.push_back(expresie.substr(start));
		}
	}
};