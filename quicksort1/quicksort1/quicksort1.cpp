// quicksort1.cpp : Defines the entry point for the console application.
/* quick sort the 
*/
//

#include "stdafx.h"
#include<iostream>
#include<vector>

class Solution {
public:
	int partitionArray(vector<int> &nums, int k){
		int i = 0, j = nums.size() - 1;
		while (i <= j) {
			while (i <= j && num[i] < k) i++;
			while (i <= j && num[j] >= k) j++;
			if (i <= j) {
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
				i++;
				j--;
			}
		}
		return i;
	}
};

int main()
{
    return 0;
}

