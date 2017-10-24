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
		if (newDay > monthDays[newMonth - 1])
		{
			newMonth++;
			newDay -= monthDays[newMonth - 2];
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
	while(newDay < 1 || newMonth < 1)
	{
		if (newDay < 1)
		{
			newMonth--;
			newDay += monthDays[newMonth - 1];
		}
		if (newMonth < 1)
		{
			newYear--;
			newMonth += 12;
		}
	}
	return Date(newYear, newMonth, newDay);
}

int Date::operator-(const Date& data1) const
{
	int daysA = 0, daysB = 0;
	daysA += day + year * 365;
	for (int i = 0; i<month; i++)
		daysA += monthDays[i];
		
	daysB += data1.getDay() + data1.getYear() * 365;
	for (int i = 0; i<data1.getMonth(); i++)
		daysB += monthDays[i];
		
	return abs(daysA - daysB);
}

Date & Date::operator+=(int nDays)
{
	day += nDays;
	while(newDay > monthDays[newMonth - 1] || newMonth > 12)
	{
		if (newDay > monthDays[newMonth - 1])
		{
			newMonth++;
			newDay -= monthDays[newMonth - 2];
		}
		if (newMonth > 12)
		{
			newYear++;
			newMonth -= 12;
		}
	}
	return *this;
}

Date & Date::operator-=(int nDays)
{
	day -= nDays;
	while(newDay < 1 || newMonth < 1)
	{
		if (newDay < 1)
		{
			newMonth--;
			newDay += monthDays[newMonth - 1];
		}
		if (newMonth < 1)
		{
			newYear--;
			newMonth += 12;
		}
	}
	return *this;
}

bool Date::operator==(const Date & data1)
{
	if ( day != data1.day || month != data1.month || year != data1.year )
		return false;
	return true;
}

bool Date::operator!=(const Date & data1)
{
	if ( day == data1.day && month == data1.month && year == data1.year )
		return false;
	return true;
}



std::ostream & operator<<(std::ostream & out, const Date& data1)
{
	if ( data1.getYear() < 1970 && data1.getMonth() < 1 && data1.getDay() < 1 )
	{
		out<<"data sprzed poczatku epoki";
		return out;
	}
	out<<data1.getYear()<<"-";
	data1.getMonth() > 9 ? out<<data1.getMonth()<<"-" : out<<"0"<<data1.getMonth()<<"-";
	data1.getDay() > 9 ? out<<data1.getDay() : out<<"0"<<data1.getDay();
	return out;
}
