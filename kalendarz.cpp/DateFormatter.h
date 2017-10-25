/*
 * DateFormatter.h
 *
 *  Created on: 25 paź 2017
 *      Author: maciejs
 */

#ifndef DATEFORMATTER_H_
#define DATEFORMATTER_H_

#include <iostream>
#include "Date.h"

class DateFormatter
{
	public:
		virtual std::string format(const Date& d) const = 0;
};

class ComputerDateFormatter : public DateFormatter
{
	public:
		std::string format(const Date& data1) const;
};

class GermanDateFormatter : public DateFormatter
{
	public:
		std::string format(const Date& d) const;
};

#endif /* DATEFORMATTER_H_ */
