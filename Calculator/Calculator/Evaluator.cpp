#include <iostream>
using namespace std;

class Evaluator
{
	bool erori = false;
	double rezultat = 0.00;

public:

	bool getErori()
	{
		return this->erori;
	}

	void setErori(bool eroare)
	{
		this->erori = eroare;
	}

	double Operatii(double operand1, double operand2, char semn)
	{
		try
		{
			switch (semn)
			{
				case '+':
					rezultat = operand1 + operand2;
					break;

				case '-':
					rezultat = operand1 - operand2;
					break;

				case '*':
					rezultat = operand1 * operand2;
					break;

				case '/':
					if (operand2 == 0)
						throw exception("Eroare: incerci sa imparti un numar la 0!");
					else
						rezultat = operand1 / operand2;
					break;

				default:
					cout << "\n" << "Semnul introdus este necunoscut (inca)!";
					this->erori = true;
					break;
			}
		}

		catch (exception e)
		{
			cout << "\n" << e.what();
		}
	}

	double getRezultat()
	{
		return this->rezultat;
	}

	void setRezultat(double rez)
	{
		this->rezultat = rez;
	}

	void Rezultat()
	{
		cout << "\n" << "Rezultatul ecuatieii este: " << this->rezultat;
	}

	friend istream& operator>>(istream& console, Evaluator& e);
	friend ostream& operator<<(istream& console, Evaluator& e);
};

	
