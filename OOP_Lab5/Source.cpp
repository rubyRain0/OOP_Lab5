#include "Time.h"
#include "Date.h"

int main()
{
	Date date1("31.12.2000");
	Date date2(03, 01, 2000);
	Date date3;
	date1++; ++date1;
	date3 = date1;
	std::cout << date1 << date2; // <<
	std::cout << (date1 > date2) << '\n'; // < > != ==

	Time time1(33, 55, 23); // hour:min:sec
	time1++; ++time1;
	Time time2(49, 75, 49);
	Time time3;
	time3 = (time2-time1);
	std::cout << "Time1: " <<time1 << "Time2: " <<time2 << "Time3: " << time3;
	std::cout << (time3 > time1);

}