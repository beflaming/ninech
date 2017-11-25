// bitopt.cpp : Defines the entry point for the console application.
//n = (1024)10 = (00000000000000000000010000000000)2; // 我们这里用32位表述
//m = (21)10 = (00000000000000000000000000010101)2; // 1 + 4 + 16 = 21, 这里同样我们用32位表述
//i = 2, j = 6,

//那么根据题目，我们希望最终得到的结果是`(00000000000000000000010001010100)2` = `(1108)10`

#include "stdafx.h"
#include<iostream>
using namespace std;

class bitOpt {
public:
	int adTlue(int N, int M, int i, int j) {
		//(-1)10, 31-j -->0; i -->0
		int st1 = (-1) << (31 - j);
		int st2 = (-1) << i;
		int st0 = (-1) << (31 - j) >> (31-j+i)<<i;  // ~((((-1)<<(31-j))>>>(31-j+i))<<i))&n)|(m<<i);
		int st3 = st1^st2;
		int finB = st3 & N;
		int fin = (M<<i) | finB;

		return fin;
	}

	/*
	* param a: The first integer
	* param b: The second integer
	* return: The sum of a and b
	*/
	int adAL(int a, int b) {
		while (b != 0) {
			int _a = a^b;
			int _b = (a&b) << 1;
			a = _a;
			b = _b;
		}
		return a;
	}
};

int main()
{
	int a = 1024, b = 21;
	int t = 2, k = 6;
	bitOpt lulu;
	int yyt = lulu.adTlue(a, b, t, k);
    return 0;
}

