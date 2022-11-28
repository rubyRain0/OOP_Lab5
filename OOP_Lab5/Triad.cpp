#include "Triad.h"

Triad::Triad(std::string _triadType) 
{ 
	triadType = _triadType; 
};

Triad& Triad::operator=(const Triad& objTriad)
{
	if (this != &objTriad)
	{
		a = objTriad.a; b = objTriad.b; c = objTriad.c;
		return *this;
	}
}

bool Triad::operator==(const Triad& objTriad)
{
	if (a == objTriad.a && b == objTriad.b && c == objTriad.c)
		return true;
	return false;
}

bool Triad::operator!=(const Triad& objTriad)
{
	if (a == objTriad.a && b == objTriad.b && c == objTriad.c)
		return false;
	return true;
}

void Triad::setA(unsigned int _a)
{
	a = _a;
}

void Triad::setB(unsigned int _b)
{
	b = _b;
}

void Triad::setC(unsigned int _c)
{
	c = _c;
}

unsigned int Triad::getA() const
{
	return a;
}

unsigned int Triad::getB() const
{
	return b;
}

unsigned int Triad::getC() const
{
	return c;
}