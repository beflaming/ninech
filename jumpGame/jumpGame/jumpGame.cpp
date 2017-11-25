// jumpGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	bool canJump(vector<int> A) {
		//n.last stone, f[0]=true; f[1],...f[i],...f[n-1]; 1. can jump on; 2. n-1-i<a[i]
		int n = A.size();
		int jmax=0;
		for (int i = 0; i < n; ++i) {
			if (i > jmax) return false;
			if (i + A[i] > jmax) jmax=i+A[i];
		}
		return true;
	}
};
int main()
{
	vector<int> ARR = { 2,3,1,1,4 };
	Solution res;
	bool xrt = res.canJump(ARR);
    return 0;
}

