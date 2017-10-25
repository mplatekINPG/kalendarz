/*
 * DateFormatter.cpp
 *
 *  Created on: 25 paź 2017
 *      Author: maciejs
 */

#include "DateFormatter.h"
#include <sstream>
#include <iomanip>

using namespace std;

string ComputerDateFormatter::format(const Date& data1) const
{
	ostringstream out;
	out << data1.getYear() << "-";
	out << setfill('0') << setw(2);
	out << data1.getMonth() << '-';
	out << setfill('0') << setw(2);
	out << data1.getDay();
	return out.str();
}

string GermanDateFormatter::format(const Date& data1) const
{
	ostringstream out;
	out << setfill('0') << setw(2);
	out << data1.getDay() << '.';
	out << setfill('0') << setw(2);
	out << data1.getMonth() << '.';
	out << data1.getYear();


	return out.str();
}
