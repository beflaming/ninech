// bigO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <typeinfo>
#include <ctime>

using namespace std;

/*
class addItemArray(int newItem) {
public:
	theArray[itemsInArray++] = newItem;
};
*/

class TestClass {
private:
	int theArray[1000];
	int* B;
	static long startTime;
	static long endTime;	
};

/*O(N^2) 
  bubbleSort(int *array){
     for(int i=sizeof(array)-1;i>1;i--){
       for(int j=0;j<i;j++){
	      if(array[j]>array[j+1]){
          swap(array[j], array[j+1]);
		  }
       }
     }
   }
*/

/*O(log N) 
  binarySearchSort(int *array){
     int lowIndex=0;
	 int highIndex=sizeof(array)-1;
	 int timeThrough = 0;
	 while(lowIndex<=highIndex){
	   int middleIndex = (highIndex+lowIndex)/2;
	   if(array[middleIndex]<value){
	      lowIndex = middleIndex+1;
	   }
	   else if(array[middleIndex]>value){
	      highIndex = middleIndex-1;
	   }
	   else{
	      cout<<"found the value:" << middleIndex << endl;
		  lowIndex=highIndex+1;
	   }
	   timeThrough++;
	 }
   }
*/

/* O(nlogn)  quickSort, the worst situation, maybe O(n^2) */
   void quickSort(int[] arr, int left, int right){
      if(right-left<=0) return NULL;
      
	  int i = left, j = right;
	  int tmp;
	  int pivot = arr[(left+right)/2];
	  
	  /*partition*/
	  while (i <= j) {
		  while (arr[i] < pivot)
			  i++;
		  while (pivot < arr[j])
			  j--;
		  if (i <= j) {
			  tmp = arr[i];
			  arr[i] = arr[j];
			  arr[j] = tmp;
			  i++;
			  j--;
		  }
	  };

	  /*recursion*/
	  if (left < j)
		  quickSort(arr, left, j);
	  if (i < right)
		  quickSort(arr, i, right);
   }


/*
TestClass::TestClass() {
//	cout << "Type A: " << typeid(A).name() << endl;
	cout << "Type B: " << typeid(B).name() << endl;
}
*/

int main(int argc, char** argv) {
	TestClass A;
	/* srand((unsigned)time(0)) get a new seed causing it to produce a different or "random" output.
	* otherwise, the rand() produces the same output
	*/
	srand((unsigned)time(0)); /*time(NULL)); activate the generator*/
	double numd = ((double)rand() / (RAND_MAX));
	int max=9, min=5;
	int numi = (rand() % (max - min)) + min;
	cout << numi << endl;
	cout << numd << endl;

	return 0;
}


