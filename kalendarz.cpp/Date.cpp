#include "Date.h"
#include <iostream>
#include <cmath>

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
	while(data1.day > data1.monthDays[data1.month - 1] || data1.month > 12)
	{
		if (data1.day > data1.monthDays[month - 1])
		{
			data1.month++;
			data1.day -= data1.monthDays[month - 1];
		}
		if (data1.month > 12)
		{
			data1.year++;
			data1.month -= 12;	
		}
	}
	return data1;
}


int Date::operator-(const Date& data1)
{
	int daysA = 0, daysB = 0;
	daysA += this.day + this.year * 365;
	for (int i = 0; i<this.month; i++)
		daysA += this.month*this.monthDays[i];
		
	daysB += data1.day + data1.year * 365;
	for (int i = 0; i<data1.month; i++)
		daysA += data1.month*data1.monthDays[i];
		
	return abs(daysA - daysB);
}

std::ostream & operator<<(std::ostream & out, const Date data1)
{
	out<<data1.year<<".";
	data1.month > 9 ? out<<data1.month<<"." : out<<"0"<<data1.month<<".";
	data1.day > 9 ? out<<data1.day : out<<"0"<<data1.day;
	return out;
}
