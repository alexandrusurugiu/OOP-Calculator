#pragma once
#include "Calculator.h"

class Expresie :public Calculator
{
public:
	std::string expresie(const std::string& expresie) const override;
};
