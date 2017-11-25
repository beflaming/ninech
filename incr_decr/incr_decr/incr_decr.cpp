// incr_decr.cpp : Defines the entry point for the console application.
// only worked for uncontinuous sequence. 

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	/*
	* @param A: An array of Integer
	* @return: an integer
	*/
	int longestIncreasingContinuousSubsequence(vector<int>& A) {
		// Write your code here
		int len = A.size();
		if (len == 0) return 0;

		vector<int> f(len);
		vector<int> t(len);
		vector<int> pi(len);
		vector<int> pt(len);
		int res = 0, des = 0;
		int p, q, xx;

		for (int i = 0; i<len; ++i) {
			f[i] = 1;
			t[i] = 1;
			pi[i] = -1;
			pt[i] = -1;

			for (int j = 0; j<i; ++j) {
				if (A[j]<A[i]) {
					f[i] = max(f[j] + 1, f[i]);
					if(f[i]==f[j]+1) pi[i] = j;
				}
			}

			for (int k = 0; k<i; ++k) {
				if (A[k]>A[i]) {
					t[i] = max(t[k] + 1, t[i]);
					if(t[i]==t[k]+1) pt[i] = k;
				}
			}

			if (f[i] > res) {
				res = f[i];
				p = i;
			}
			if (t[i] > des) {
				des = t[i];
				q = i;
			}
		}
		xx = max(res, des);
		vector<int> seq(xx);
		for (int i = xx - 1; i >= 0; --i) {
			if (res == xx) {
				seq[i] = A[p];
				p = pi[p];
			}
			else if (des == xx) {
				seq[i] = A[q];
				q = pt[q];
			}
		}
		for (int j = 0; j < xx; ++j) {
			cout << seq[j] << endl;
		}
		return xx;
	}
};

int main()
{
	vector<int> kk = { 99,55,7,29,80,33,19,23,6,35,40,27,44,74,5,17,52,36,67,32,37,42,18,77,66,62,97,79,60,94,30,2,85,22,26,91,3,16,8,0,48,93,39,31,63,13,71,58,69,50,21,70,61,43,12,88,47,45,72,76 };
	Solution keyp;
	int nunn = keyp.longestIncreasingContinuousSubsequence(kk);
    return 0;
}

