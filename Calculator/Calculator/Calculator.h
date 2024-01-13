#pragma once
#include <iostream>

class Calculator
{
public:
	virtual std::string expresie(const std::string& expreise) const = 0;

	virtual ~Calculator() = default;
};
