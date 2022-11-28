#include "Date.h"
Date::Date() : Triad("Date")
{
	this->a = 1;
	this->b = 1;
	this->c = 1970;
}

Date::Date(unsigned int d = 0, unsigned int m = 0, unsigned int y = 0) : Triad("Date")
{
	setDate(d, m, y);
}
Date::Date(std::string date) : Triad("Date")
{
	std::vector<std::string> result;
	std::stringstream ss(date);
	std::string item;
	char delim = '.';

	while (std::getline(ss, item, delim)) {
		result.push_back(item);
	}
	setDate(stoi(result[0]), stoi(result[1]), stoi(result[2]));
}

Date::Date(const Date& date) : Triad("Date")
{
	setDate(date.a, date.b, date.c);
}

int Date::compareDates(const Date& date1, const Date& date2)
{
	int result = 1;
	if (date1.c < date2.c ||
		date1.c == date2.c && date1.b < date2.b ||
		date1.c == date2.c && date1.b == date2.b && date1.a < date2.a)
		result = -1;
	else
		if (date1.c == date2.c && date1.b == date2.b && date1.a == date2.a)
			result = 0;
	return result;
}

bool Date::isLeapYear(unsigned int year) {
	return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

int Date::dayInMonth(unsigned int x, unsigned int year)
{
	if (x == 2 && isLeapYear(year))
		return 29;
	else
		return 28 + (x + (x / 8)) % 2 + 2 % x + 2 * (1 / x);
}

Date::~Date()
{
}

bool Date::isValidDate(unsigned int day, unsigned int month, unsigned int year) {
	if ((day < 1 || day>31) ||
		(month < 1 || month>12))
		return false;
	return true;
}

Date& Date::operator+=(int days)
{
	if (this->a + days > maxday())
	{
		this->a = this->a + days - maxday();
		if (++b > 12)
		{
			b = 1;
			c++;
		}
	}
	else this->a += days;
	return *this;
}

Date& Date::operator-=(int days)
{
	int day = this->a;
	if ((day - days) < 1) {
		if (--b == 0) {
			b = 12;
			c--;
		}
		this->a = maxday() - (days - this->a);
	}
	else this->a -= days;
	return *this;
}

int Date::dayDifference(const Date& dateObj1, const Date& dateObj2)
{
	int daysCount = 0;
	if (compareDates(dateObj1, dateObj2) == 1) //dateObj1>dateObj2
	{
		Date copyObj2 = dateObj2;
		while (compareDates(dateObj1, copyObj2) != 0)
		{
			copyObj2 += 1;
			++daysCount;
		}
	}
	else if (compareDates(dateObj1, dateObj2) == -1) // dateObj1<dateObj2
	{
		Date copyObj1 = dateObj1;
		while (compareDates(copyObj1, dateObj2) != 0)
		{
			copyObj1 += 1;
			++daysCount;
		}
	}
	return daysCount;
}

void Date::setDate(unsigned int day, unsigned int month, unsigned int year)
{
	if (isValidDate(day, month, year)) {
		a = day;
		b = month;
		c = year;
	}
	else {
		throw std::string("Not valid date");
	}
}

int Date::maxday() const
{
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear(this->c))
		days[1] = 29;
	return days[this->b - 1];
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date* Date::operator++(int)
{
	Date* result = this;
	++(*this);
	return result;
}

bool Date::operator>(const Triad& objDate)
{
	bool result = 1;
	if (c < objDate.getC() ||
		c == objDate.getC() && b < objDate.getB() ||
		c == objDate.getC() && b == objDate.getB() && a < objDate.getA() ||
		a == objDate.getA() && b == objDate.getB() && c == objDate.getC())
		result = 0;
	return result;
}

bool Date::operator<(const Triad& objDate)
{
	bool result = 1;
	if (*this > objDate || *this == objDate)
		result = 0;
	return result;
}

Date Date::currentTime()
{
	#pragma warning(disable : 4996)
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	Date currentDate(timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
	return currentDate;
}

std::ostream& operator<<(std::ostream& out, const Date& objDate)
{
	out << objDate.a << '/'
		<< objDate.b << '/'
		<< objDate.c << std::endl;
	return out;
}
