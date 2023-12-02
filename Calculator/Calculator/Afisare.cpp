#include <iostream>
#include <string>

using namespace std;

class Afisare
{
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
		if (instanteCreate < MAX_INSTANTE) {
			this->instanteCreate++;
			this->merge = true;
		}
		else 
		{
			cout << "\n" << "Prea multe instante ce ruleaza simultan!";
			this->merge = false;
		}
	}


};

	int Afisare::nrInstanta = 0;

