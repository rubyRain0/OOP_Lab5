#include "Time.h"
#include "Date.h"

int main()
{
	Triad* date1 = new Date("31.12.2000");
	Triad* date2 = new Date(03, 01, 2000);
	Triad* date3 = new Date;
	(*date1)++; ++(*date1);
	date3 = date1;
	std::cout << date1->toString() << date2->toString();
	std::cout << (*date1 > *date2) << '\n'; // < > != ==

	Triad* time1 = new Time(33, 55, 23); // hour:min:sec
	(*time1)++; ++(*time1);
	std::cout << time1->toString();
	Triad* time2 = new Time(49, 75, 49);
	Triad* time3 = new Time;
	Time* ptrT2 = (Time*)time2;
	Time* ptrT1 = (Time*)time1;
	*time3 = *ptrT2 - *ptrT1;
	std::cout << "Time1: " << time1->toString() << "Time2: " << time2->toString() << "Time3: " << time3->toString();
	std::cout << (*time3 > *time1);

}