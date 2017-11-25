// paintHouse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

class Solution {
public:
	int paintHouse(vector<vector<int>> &costs) {
		//color: costs[*][color], 0-red,1-blue,2-green;
		int col = costs.size();
		int color = costs[0].size();
		if (col == 0) return 0;  //no house

		vector<vector<int>> f(2,vector<int>(color));
 		int old, now = 0;
 		f[now][0] = f[now][1] = f[now][2] = 0;
  
		for (int i = 1; i <= col; ++i) {
			old = now;
			now = 1 - now;
			for (int j = 0; j < color; ++j) {
				f[now][j] = INT_MAX;  //make sure f[now][j] gets value;
				for (int k = 0; k < color; ++k) {
					if (k != j && f[old][k] + costs[i - 1][j] < f[now][j]) {
						f[now][j] = f[old][k] + costs[i - 1][j];
					}
				}
			}
		}

		int res = f[now][0];
		cout << "res" << res<<endl;
		if (f[now][1] < res) {
			res = f[now][1];
		}
		if (f[now][2] < res) {
			res = f[now][2];
		}

		return res;
	}
};
int main()
{
	vector<vector<int>> houseCost = { {14, 2, 11},{11, 14, 5},{14, 3, 10}};
	Solution keys;
	int xxY = keys.paintHouse(houseCost);
    return 0;
}

