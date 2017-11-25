// decodeWay.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

class Solution {
public:
	int numDecoding(string& strcode) {
		int ltr = strcode.length();
		if (ltr == 0) return 0; //NULL string;
		vector<int> f(ltr+1);
		//f[i]=f[i-1]|s[i-1]+f[i-2]|s[i-1]s[i-2];  letter N-1 and letter N-2/N-1
		f[0] = 1;  //NULL string should be counted 1;
/*
		for (int i = 0; i < ltr; ++i) {
			f[i + 1] = 0;
			if (strcode[i] != '0') {
				f[i + 1] += f[i];
			}
			if (i >= 1 && (strcode[i - 1] - '0') * 10 + strcode[i] - '0' <= 26 && strcode[i - 1] != '0') {
				f[i + 1] += f[i - 1];
			}
		}
*/
		for (int i = 1; i <= ltr; ++i) {
			f[i] = 0;
			if (strcode[i - 1] >= '1' && strcode[i - 1] <= '9') {
				f[i] += f[i - 1];
			}
			if (i > 1) {
				int j = 10 * (strcode[i - 2] - '0') + (strcode[i - 1] - '0');
				if (strcode[i-2]!=0 && j >= 10 && j <= 26) {
					f[i] += f[i - 2];
				}
			}

		}
		return f[ltr];

	}
};

int main()
{
	string tu ="42212312";
	Solution key;
	int tt = key.numDecoding(tu);
    return 0;
}

