// rev1.cpp : Defines the entry point for the console application.
// palindrome  characters
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

class Solution {
	/* @param: a string which consists of lowercase and uppercase letters, 
	 * @return: the length of the longest palindromes that can be built. 
	*/
public:
	int longestPalindrome(string s) {
		int charStatArray[52];
		int oneTimeOddCount = 0;
		int evenCount = 0;
		
		//zero the HashMap/clearing the memory of Array
		memset(charStatArray, 0, sizeof(charStatArray));

		//keep the times of appearance of each character in the array
		//for(i=0;i<sizeof(array);i++) HASHMAPrecords the number of appearance;
		for (char ch : s) {
			if (ch >= 97) {/* ASCII 'a'=97, 'A'=65*/
				charStatArray[ch + 26 - 'a']++;
			}
			else {
				charStatArray[ch - 'A']++;
			}
		}

		//answer if the count of characters that has even number of appearance 
		//for characters that has odd number of appearance, appearance-1=even number 
		//finally put unused characters in the middle of palindrome
		for (int cnt : charStatArray) {
			if (cnt != 0) {
				if (cnt % 2 == 0) {
					evenCount += cnt;
				}
				else {
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
		return oneTimeOddCount ? 1+evenCount : evenCount;
	}
};



int main()
{
	string st = "abccccdd";
	Solution res;
	int num = res.longestPalindrome(st);
	cout << "string" << num << endl;
    return 0;
}

