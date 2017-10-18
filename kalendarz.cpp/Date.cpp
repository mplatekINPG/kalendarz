#include "Date.h"
#include <iostream>
#include <cmath>

Date::Date(int newYear, int newMonth, int newDay)
{
	year = newYear;
	month = newMonth;
	day = newDay;
}

Date::Date(const Date& data1)
{
	year = data1.getYear();
	month = data1.getMonth();
	day = data1.getDay();
}

Date & Date::operator=(const Date& data1)
{
	year = data1.getYear();
	month = data1.getMonth();
	day = data1.getDay();
	return *this;
}

Date Date::operator+(int nDays) const
{
	int newYear = year, newMonth = month, newDay = day;
	newDay += nDays;
	while(newDay > monthDays[newMonth - 1] || newMonth > 12)
	{
		if (newDay > monthDays[month - 1])
		{
			newMonth++;
			newDay -= monthDays[month - 1];
		}
		if (newMonth > 12)
		{
			newYear++;
			newMonth -= 12;
		}
	}
	return Date(newYear, newMonth, newDay);
}

Date Date::operator-(int nDays) const
{
	int newYear = year, newMonth = month, newDay = day;
	newDay -= nDays;
	while(newDay < 0 || newMonth < 12)
	{
		if (newDay > monthDays[month - 1])
		{
			newMonth++;
			newDay -= monthDays[month - 1];
		}
		if (newMonth > 12)
		{
			newYear++;
			newMonth -= 12;
		}
	}
	return Date(newYear, newMonth, newDay);
}

int Date::operator-(const Date& data1) const
{
	int daysA = 0, daysB = 0;
	daysA += day + year * 365;
	for (int i = 0; i<month; i++)
		daysA += month*monthDays[i];
		
	daysB += data1.getDay() + data1.getYear() * 365;
	for (int i = 0; i<data1.getMonth(); i++)
		daysA += data1.getMonth()*monthDays[i];
		
	return abs(daysA - daysB);
}

std::ostream & operator<<(std::ostream & out, const Date& data1)
{
	out<<data1.getYear()<<".";
	data1.getMonth() > 9 ? out<<data1.getMonth()<<"." : out<<"0"<<data1.getMonth()<<".";
	data1.getDay() > 9 ? out<<data1.getDay() : out<<"0"<<data1.getDay();
	return out;
}
