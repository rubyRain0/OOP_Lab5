#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>

class Triad
{
protected:
	unsigned int a;
	unsigned int b;
	unsigned int c;
	std::string triadType;
public:
	Triad(std::string _triadType);

	virtual Triad& operator++() = 0;
	virtual Triad& operator++(int) = 0;
	virtual bool operator>(const Triad& objTriad) = 0;
	virtual bool operator<(const Triad& objTriad) = 0;
	virtual std::string toString() = 0;


	bool operator==(const Triad& objTriad);
	bool operator!=(const Triad& objTriad);
	Triad& operator=(const Triad& objTriad);
	
	void setA(unsigned int _a);
	void setB(unsigned int _b);
	void setC(unsigned int _c);

	unsigned int getA() const;
	unsigned int getB() const;
	unsigned int getC() const;
};

