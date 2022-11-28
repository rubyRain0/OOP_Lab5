#pragma once
#include "Triad.h"

class Time : public Triad
{
	void fixTime();
public:
	Time();
	Time(unsigned int h, unsigned int m, unsigned int s);

	Time& operator++() override;
	Time* operator++(int) override;
	bool operator>(const Triad& objDate) override;
	bool operator<(const Triad& objDate) override;

	Time operator+(Time& objTime);
	Time& operator+=(Time& objTime);
	Time operator-(Time& objTime);
	Time& operator-=(Time& objTime);

	friend std::ostream& operator<<(std::ostream& out, Time& objTime);

};

