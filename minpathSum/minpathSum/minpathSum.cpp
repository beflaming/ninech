// minpathSum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& exrry) {
		if (exrry[0][0] == NULL) return 0;
		int xr1 = exrry.size();
		int xc1 = exrry[0].size();
//		int f[101][101];  apply space in stack, max limitation on it. 
//      using vector, apply space in heap, no limitation.
		vector<vector<int>> f(1001, vector<int>(1001) );

		if (xr1 <= 0 || xc1 <= 0) return 0;

		f[0][0] = exrry[0][0];
		for (int i = 1; i < xr1; ++i) {
			f[i][0] = f[i - 1][0] + exrry[i][0];
		}
		for (int j = 1; j < xc1; ++j) {
			f[0][j] = f[0][j - 1] + exrry[0][j];
		}
		for (int i = 1; i < xr1; ++i) {
			for (int j = 1; j < xc1; ++j) {
				f[i][j] = min(f[i - 1][j], f[i][j - 1]) + exrry[i][j];
			}
		}

		return f[xr1 - 1][xc1 - 1];
	}
};

int main()
{
	vector<vector<int>> vec = { { 1,1,1,1 },{ 2,2,2,2 },{ 2,1,3,1 },{ 3,3,3,1 } };
	Solution tar;
	int x = vec.size();
	int y = vec[0].size();
	int sxm = tar.minPathSum(vec);
	return 0;
}