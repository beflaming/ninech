// longIncrArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	int longIncrSub(vector<int> &A) {
		int len=A.size();
		if (len == 0) return 0;

		vector<int> f(len);
		vector<int> pi(len);
		int p = 0;
		int res = 0;

		for (int j = 0; j < len; ++j) {
			//case 1, null array;
			f[j] = 1;
			pi[j] = -1;

			//case 2, enumerate previous element;
			//from left->right, f[i]=f[i-1]+1|j>0 && A[j-1]<A[j];
			for (int i = 0; i < j; ++i) {
				if (A[i] < A[j]) {
					f[j] = max(f[i] + 1, f[j]);
					if (f[j]==f[i]+1) pi[j]=i;
				}
			}
			if (f[j] > res) {
				res = f[j];
				p = j;
			}
		}

		vector<int> seq(len);
		for (int i = res - 1; i >= 0; --i) {
			seq[i] = A[p];
			p = pi[p];
		}
		for (int i = 0; i < res; ++i)
			cout << "value" << seq[i] << endl;

		return res;
	}
};

int main()
{
//	vector<int> kk = { 12,3,2,6,5,8,9,10,14,3,7 };
//	vector<int> kk = { 7,8,9,1,2 };
//	vector<int> kk = { 5,4,2,1,3 };
//	vector<int> kk = {};
	vector<int> kk = { 5,6,7,1,2,3,2,4 };
	Solution yt;
	int ron = yt.longIncrSub(kk); 
    return 0;
}

