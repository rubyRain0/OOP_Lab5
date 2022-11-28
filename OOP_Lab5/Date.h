#pragma once
#include "Triad.h"

class Date : public Triad
{
public:
	Date();
	Date(unsigned int d, unsigned int m, unsigned int y);
	Date(std::string date);
	Date(const Date& date);

	void setDate(unsigned int day, unsigned int month, unsigned int year);

	int maxday() const;

	Date& operator++() override;
	Date* operator++(int) override;
	bool operator>(const Triad& objDate) override;
	bool operator<(const Triad& objDate) override;

	Date& operator+=(int days);
	Date& operator-=(int days);

	friend std::ostream& operator<<(std::ostream& out, const Date& objDate);

	static int dayDifference(const Date& dateObj1, const Date& dateObj2);
	static bool isValidDate(unsigned int day, unsigned int month, unsigned int year);
	static bool isLeapYear(unsigned int year);
	static int compareDates(const Date& date1, const Date& date2);
	static int dayInMonth(unsigned int x, unsigned int year = 1);
	static Date currentTime();
	~Date();
};


