// uniquePath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	//param@ input: 0<m<100;
	//param@ input: 0<n<100;
	//param@ output: integer;
	int uniquePath(int m, int n) {
		vector<vector<int>> f(m,vector<int>(n));
		
		if (m == 0 && n == 0) return 0;
		
		f[0][0] = 0;
		for(int i=0;i<m;++i){
			for (int j = 0; j <n; ++j) {
				if (i == 0 || j == 0) {
					f[i][j] = 1;
					continue;
				}
				f[i][j] = f[i - 1][j] + f[i][j - 1];
			}
		};
		return f[m-1][n-1];
	}
};

int main()
{
	int m=4, n=5;
	//int[][] arr1={ { 1,5,3,7,2 },{ 3,2,3,5,1 },{ 4,2,6,8,1 } };
	vector<vector<int>> fx(m, vector<int>(n));
//	vector<vector<int>> arr1 = { { 1,5,3,7,2 },{ 3,2,3,5,1 },{ 4,2,6,8,1 },{ 1,5,3,7,2 } };
//	fx.assign(arr1.begin(), arr1.end());
	Solution res;
	int num = res.uniquePath(m,n);
	return 0;
}

