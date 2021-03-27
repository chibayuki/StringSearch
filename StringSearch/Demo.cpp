/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Copyright © 2021 chibayuki@foxmail.com

StringSearch.Demo
Version 21.3.27.0000

This file is part of StringSearch
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>

#include "StringSearch.h"

using namespace std;

int main()
{
	string str = "ABCABABCAB", subStr = "ABABC";

	cout << str.find(subStr) << endl; // Output: 3
	cout << BM(str, subStr) << endl; // Output: 3
	cout << KMP(str, subStr) << endl; // Output: 3

	system("pause");
}