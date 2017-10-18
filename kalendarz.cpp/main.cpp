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
	
	cout << data1 << endl;
	cout << data1+30 << endl;
	cout << data1-60 <<endl;

	return 0;
}


