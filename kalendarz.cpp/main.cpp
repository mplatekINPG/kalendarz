/*
 * main.cpp
 *
 *  Created on: 18 paź 2017
 *      Author: siniewic
 */

#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	Date data1(2000, 9, 14);
	Date data2(2001, 9, 13);
	
	cout << data1 << ", " << data2 << endl;
	cout << data1+366 << endl;
	cout << data1-44 <<endl;
	cout << data2 - data1 << endl;

	return 0;
}


