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

	void Operatii(double operand1, double operand2, char semn)
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
		cout << "\n" << "Rezultatul ecuatiei este: " << this->rezultat;
	}

	friend istream& operator>>(istream& in, Evaluator& e);
	friend ostream& operator<<(ostream& out, Evaluator& e);
	friend Evaluator operator+(Evaluator e1, Evaluator e2);
	friend Evaluator operator-(Evaluator e1, Evaluator e2);
};

Evaluator operator+(Evaluator e1, Evaluator e2)
{
	e1.rezultat = e1.rezultat + e2.rezultat;
	return e1;
}

Evaluator operator-(Evaluator e1, Evaluator e2)
{
	e1.rezultat = e1.rezultat - e2.rezultat;
}

istream& operator>>(istream& in, Evaluator& e) 
{
	in >> e.rezultat;
	return in;
}

ostream& operator<<(ostream& out, Evaluator& e)
{
	out << e.rezultat;
	return out;
}







	
