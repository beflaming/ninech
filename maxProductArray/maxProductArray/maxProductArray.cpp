// maxProductArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>        //vector<int>, int x[]={}, vector.assign()
#include<algorithm>     //min, max
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		vector<int> f, g;
		f.push_back(nums[0]);
		g.push_back(nums[0]);

		for (int i = 1; i < nums.size();++i) {
			f.push_back(max(max(nums[i] * f[i-1], nums[i] * g[i-1]), nums[i]));
			g.push_back(min(min(nums[i] * f[i-1], nums[i] * g[i-1]), nums[i]));
		}
		int m = f[0];
		for (int i = 0; i < f.size(); ++i)   m = max(m, f[i]);
		return m;
	}
};

int main()
{
	int myint[] = { 1, 7, 4,3, -5,4,2,-1,2 };
	vector<int> gg;
	gg.assign (myint, myint+9);
	Solution res;
	int kk = res.maxProduct(gg);
    return 0;
}

