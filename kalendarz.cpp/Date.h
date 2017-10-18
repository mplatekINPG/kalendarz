#ifndef DATE_H_
#define DATE_H_
#include <iostream>

class Date
{
	private:
		int year;
		int month;
		int day;
		const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	public:
		Date(int newYear = 1970, int newMonth = 1, int newDay = 1);
		Date(const Date& data1);

		Date& operator=(const Date& data1);
		Date operator+(int nDays) const;
		Date operator-(int nDays) const;

		Date& operator+=(int nDays);
		Date& operator-=(int nDays);

		int operator-(const Date& data1) const;

		bool operator==(const Date& data1) const;
		bool operator!=(const Date& data1) const;

		friend Date operator+(int nDays, const Date& data1);
		friend std::ostream& operator<<(std::ostream& out, const Date& data1);

		int getYear() const {return year;};
		int getMonth() const {return month;};
		int getDay() const {return day;};
};

#endif /* DATE_H_ */
