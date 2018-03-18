#include "stdafx.h"
#include <iostream>
using namespace std;
#include <vector>
#include<string>
#include <algorithm>
#include<ctime>
#include<windows.h>
class Solution6 {
public:
	string convert(string s, int numRows) {
		int size = static_cast<int>(s.size());
		if (numRows <= 1 || numRows >= size) {
			return s;
		}
		vector <string> rowString(numRows);
		int rowNum = 1;
		int flag = 1;
		for (int i = 0; i < size; ++i) {
			rowString[rowNum - 1] += s[i];
			if (rowNum == numRows) {
				flag = -1;
			}
			if (rowNum == 1) {
				flag = 1;
			}
			rowNum += flag;
		}

		string result;
		for (int i = 0; i < numRows; ++i) {
			result += rowString[i];
		}
		return result;
	}
};

class Solution8 {
public:// 123124
	int myAtoi(string str)
	{
		if (str == "")
			return 0;
		int result = 0;
		int i = 0, flag = 0, minus = 0, max = 0;
		for (i = 0;i < str.length();i++)
		{
			if (str[i] == ' ')
			{
				if (flag == 1)
					return result;
				continue;
			}
			if (str[i] == '+' && str[i + 1] == '-')
				return 0;
			if (str[i] == '-' && str[i + 1] == '+')
				return 0;
			int temp = str[i] - '0';
			if (temp <= 9 && temp >= 0)
			{
				flag = 1;
				cout << result << endl;
				if (result != 0 && (INT_MAX - temp) / result<10)
				{
					max = 1;
				}
				result = 10 * result + temp;
			}
			else if (str[i] == '+')
			{
				if (flag == 1)
					break;
				flag = 1;
				continue;
			}
			else if (str[i] == '-')
			{
				if (flag == 1)
					break;
				flag = 1;
				minus = 1;
			}
			else
				break;
		}
		cout << max << endl;
		if (max == 1)
		{
			if (minus == 1)
				return INT_MIN;
			return INT_MAX;
		}
		if (minus == 1)
			return -result;
		return result;
	}
};

class Solution9 {
public:
	bool isPalindrome(int x)
	{
		if (x < 0)
			return false;
		if (x >= 0 && x < 10)
			return true;
		if (reverse(x) == x)
			return true;
		return false;
	}
	int reverse(int x) {
		long long res = 0;
		while (x>0)
		{
			res = res * 10 + x % 10;
			x = x / 10;
		}
		if (res<INT_MIN || res>INT_MAX)
		{
			res = 0;
		}
		return res;
	}
};

class Solution10 {  //»ØËÝ·¨
public:
	static const int FRONT = -1;
	bool isMatch(string s, string p) {
		return myMatch(s, s.length() - 1, p, p.length() - 1);
	}
	bool myMatch(string s, int i, string p, int j)
	{
		cout << i << "	" << j << endl;
		if (j == FRONT)
			if (i == FRONT)
				return true;
			else
				return false;

		if (p[j] == '*')
		{
			if (i > FRONT && (p[j - 1] == '.' || p[j - 1] == s[i]))
				if (myMatch(s, i - 1, p, j))
					return true;
			return myMatch(s, i, p, j - 2);
		}

		if (p[j] == '.' || p[j] == s[i])
			return myMatch(s, i - 1, p, j - 1);

		return false;
	}

	bool isMatch2(string s, string p) // DP·¨
	{

	}
};

class Solution11 {
public:
	int maxArea(vector<int>& height) {

	}
};

int main()
{
	system("pause");
	return 0;
}

