/*
 * main.cpp
 *
 *  Created on: 18 paź 2017
 *      Author: siniewic
 */

#include <iostream>
#include "Date.h"
#include "DateFormatter.h"

using namespace std;

int main()
{
	Date data1(2000, 9, 4);
	Date data2(2001, 9, 13);
	
	cout << data1 << ", " << data2 << endl;
	cout << data1+366 << endl;
	Date data3(data1);
	data3 += 366;
	cout << "+= " << data3 << endl; 
	cout << data1-44 <<endl;
	Date data4(data1);
	data4 -= 44;
	cout << "-= " << data4 << endl;
	cout << data2 - data1 << endl;
	data4 = data4 - 100000;
	cout << data4 <<endl;
	ComputerDateFormatter f1;
	cout << f1.format(data1) << endl;
	GermanDateFormatter f2;
	cout << f2.format(data1);

	return 0;
}


