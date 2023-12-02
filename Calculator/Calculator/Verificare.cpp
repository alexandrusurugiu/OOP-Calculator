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

	Verificare();

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
		}

		this->expresie = new char[strlen(expresie) + 1];
		strcpy(this->expresie, expresie);
		
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

	void Prelucrare()
	{
		if (this->expresie != nullptr)
		{
			string expresie = this->expresie;
			vector<std::string> sir;
			Spatii(expresie, sir);

			if (!sir.empty())
			{
				Evaluator e(stod(sir[0]));

				for (int i = 1; i < sir.size(); i += 2)
				{
					double operand2 = stod(sir[i + 1]);
					char semn = sir[i][0];
					e.Prelucrare(e.getResult(), operand2, semn);
				}

				e.printFinalResult();
			}
		}
	}

	friend istream& operator>>(istream& in, Verificare& v);
	friend ostream& operator<<(ostream& out, Verificare& v);
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
