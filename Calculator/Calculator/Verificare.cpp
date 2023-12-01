#include <iostream>
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


};