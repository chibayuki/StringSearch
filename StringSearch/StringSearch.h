/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Copyright © 2021 chibayuki@foxmail.com

StringSearch.StringSearch
Version 21.3.27.0000

This file is part of StringSearch
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#pragma once

#include <string>

using namespace std;

// Boyer-Moore 算法
int BM(const string& str, const string& subStr, int startIndex = 0)
{
	size_t s1 = str.size(), s2 = subStr.size();

	if (s2 == 0)
	{
		return startIndex;
	}

	if (s1 < s2)
	{
		return -1;
	}

	if (startIndex > s1 - s2)
	{
		return -1;
	}

	int right = startIndex + s2 - 1;
	int i1 = right, i2 = s2 - 1;

	while (right < s1)
	{
		if (str[i1] == subStr[i2])
		{
			if (i2 == 0)
			{
				return i1;
			}
			else
			{
				i1--;
				i2--;
			}
		}
		else
		{
			char last = str[i1];
			int iLast = s2 - 1;

			while (iLast >= 0)
			{
				if (last == subStr[iLast])
				{
					break;
				}
				else
				{
					iLast--;
				}
			}

			if (iLast >= i2)
			{
				right++;
			}
			else if (iLast < 0)
			{
				right += i2 + 1;
			}
			else
			{
				right += i2 - iLast;
			}

			i1 = right;
			i2 = s2 - 1;
		}
	}

	return -1;
}

// Knuth-Morria-Pratt 算法
int KMP(const string& str, const string& subStr, int startIndex = 0)
{
	size_t s1 = str.size(), s2 = subStr.size();

	if (s2 == 0)
	{
		return startIndex;
	}

	if (s1 < s2)
	{
		return -1;
	}

	if (startIndex > s1 - s2)
	{
		return -1;
	}

	int* ff = new int[s2];
	ff[0] = 0;

	for (int i = 1, j = 0; i < s2; i++)
	{
		if (subStr[i] == subStr[j])
		{
			ff[i] = ff[i - 1] + 1;
			j++;
		}
		else
		{
			j = 0;

			if (subStr[i] == subStr[j])
			{
				ff[i] = 1;
				j++;
			}
			else
			{
				ff[i] = 0;
			}
		}
	}

	int i1 = startIndex, i2 = 0;

	while (i1 < s1)
	{
		if (str[i1] == subStr[i2])
		{
			if (i2 == s2 - 1)
			{
				delete[] ff;
				return i1 - s2 + 1;
			}
			else
			{
				i1++;
				i2++;
			}
		}
		else
		{
			if (i2 > 0)
			{
				i2 = ff[i2 - 1];
			}
			else
			{
				i1++;
			}
		}
	}

	delete[] ff;
	return -1;
}