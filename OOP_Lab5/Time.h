#pragma once
#include "Triad.h"

class Time : public Triad
{
	void fixTime();
public:
	Time();
	Time(unsigned int h, unsigned int m, unsigned int s);

	Triad& operator++() override;
	Triad& operator++(int) override;
	bool operator>(const Triad& objDate) override;
	bool operator<(const Triad& objDate) override;
	std::string toString() override;

	Time operator+(Time& objTime);
	Time& operator+=(Time& objTime);
	Time operator-(Time& objTime);
	Time& operator-=(Time& objTime);
};

