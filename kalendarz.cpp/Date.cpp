#include "Date.h"
#include <iostream>

Date::Date(int newYear=1970, int newMonth=1, int newDay=1) 
{
	year = newYear;
	month = newMonth;
	day = newDay;
}

Date::Date(const Date& data1)
{
	year = data1.year;
	month = data1.month;
	day = data1.day;
}

Date & Date::operator=(const Date& data1)
{
	this.year = data1.year;
	this.month = data1.month;
	this.day = data1.day;
	return *this;
}

Date Date::operator+(int nDays)
{
	Date data1(year,month,day);
	data1.day += nDays;
	if (data1.day > data1.monthDays[month])
	{
		data1.month++;
		if (data1.month > 12)
			data1.year++;
	}
	return data1;
}

