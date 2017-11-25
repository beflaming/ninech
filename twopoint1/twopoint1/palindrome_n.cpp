// twopoint1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class Solution {
public:
	/*
	* @param num: a positive number
	* @return: true if it's a palindrome or false
	*/
	bool isPalindrome(int num) {
		//
		if (num < 0) return false;
		long long rev=0, tmp=num;
		while (tmp) {
			rev = rev * 10 + tmp % 10;
			tmp /= 10;
		}
		return rev==num;
	}
};

int main()
{
	int test = 1234554321;
	Solution solv;
	bool bol = false;
	bol = solv.isPalindrome(test);
	cout << "reverse:" << bol << endl;
    return 0;
}

