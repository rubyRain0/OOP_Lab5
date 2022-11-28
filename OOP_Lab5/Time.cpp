#pragma once
#include "Time.h"
Time::Time() : Triad("Time") 
{
	a = b = c = 0;
}

Time::Time(unsigned int h, unsigned int m, unsigned int s) : Triad("Time") 
{
	a = h; b = m; c = s;
	fixTime();
}

Time& Time::operator++()
{
	Time _1sec(0, 0, 1);
	(*this) += _1sec;
	return *this;
}

Time* Time::operator++(int)
{
	Time _1sec(0, 0, 1);
	Time* result = this;
	(*this) += _1sec;
	return result;
}

Time Time::operator+(Time& objTime) 
{
	Time temp;
	temp.a = a + objTime.a; 
	temp.b = b + objTime.b;
	temp.c = c + objTime.c;
	temp.fixTime();

	return temp;
}

Time& Time::operator+=(Time& objTime)
{
	a += objTime.a;
	b += objTime.b;
	c += objTime.c;
	fixTime();
	return *this;
}

Time& Time::operator-=(Time& objTime)
{
	int difA = a - objTime.a;
	int difB = b - objTime.b;
	int difC = c - objTime.c;
	if (difA < 0)
		a = 24 - abs(difA);
	else
		a = difA;
	if (difB < 0)
		b = 60 - abs(difB);
	else
		b = difB;
	if (difC < 0)
		c = 60 - abs(difC);
	else
		c = difC;
	fixTime();
	return *this;
}

Time Time::operator-(Time& objTime)
{
	Time temp;
	int difA = a - objTime.a;
	int difB = b - objTime.b;
	int difC = c - objTime.c;
	if (difA < 0)
		temp.a = 24 - abs(difA);
	else
		temp.a = difA;
	if (difB < 0)
		temp.b = 60 - abs(difB);
	else
		temp.b = difB;
	if (difC < 0)
		temp.c = 60 - abs(difC);
	else
		temp.c = difC;
	temp.fixTime();
	return temp;
}

bool Time::operator>(const Triad& objTime) 
{
	bool result = 0;
	double thisTimeSeconds = a * 360 + b * 60 + c;
	double objTimeSeconds = objTime.getA() * 360 + objTime.getB() * 60 + objTime.getC();
	if (thisTimeSeconds > objTimeSeconds) 
		result = 1;
	return result;
}

bool Time::operator<(const Triad& objTime) 
{
	bool result = 1;
	if (*this > objTime || *this == objTime)
		result = 0;
	return result;
}

void Time::fixTime() 
{
	if (c >= 60) 
	{ 
		while (c >= 60) c -= 60;
		b++; 
	}
	else if (c < 0) 
	{
		while (c < 0) c += 60;
		b--; 
	}
	if (b >= 60) 
	{ 
		while (b >= 60) b -= 60;
		a++; 
	}
	else if (b < 0) 
	{
		b = 60 + b; 
		c--; 
	}
	if (a >= 24) 
	{ 
		while (a >= 24) a -= 24;
	}
}

std::ostream& operator<<(std::ostream& out, Time& objTime) 
{
	out << objTime.a << ":" << objTime.b << ":" << objTime.c << std::endl;
	return out;
}
