// longestPalindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		int charStatArray[52];
		int oneTimeOddCount = 0;
		int evenCount = 0;

		//zero clearing the memory of array
		memset(charStatArray, 0, sizeof(charStatArray));

		//keep the times of appearance of each character in the array
		// for(i=0; i<sizeof(s); i++)   HASHMAP records the number of appearance.
		for (char ch : s) {
			if (ch >= 97) {  //ascii 97=a; 65=A;
				charStatArray[26 + ch - 'a']++;
			}
			else {
				charStatArray[ch - 'A']++;
			}
		}

		//the answer is the count of characters that has even number of appearance. 
		//for characters that hs odd number of appearance. 
		//their appearance minus 1 will make their appearance even. 
		//finally we put unused character in the middle of the palindrome.

		for (int cnt : charStatArray) {
			if (cnt != 0) {
				if (cnt % 2 == 0) {
					evenCount += cnt;
				} else {
					if (cnt == 1) {
						oneTimeOddCount++;
					}
					else {
						evenCount += cnt - 1;
						oneTimeOddCount++;
					}
				}
			}
		}
		return oneTimeOddCount > 0 ? 1 + evenCount : evenCount;
	}
};

int main()
{
	string st = "whhihdrw";
	Solution res;
	int num = res.longestPalindrome(st);
	cout << "string" << num << endl;
    return 0;
}

