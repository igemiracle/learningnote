#include<iostream>
#include"array.cpp"
using namespace std;

int main()
{
	int arr[] = {1,2,3,4,5,5};
	int arr1[] = {5,4,3,2,1};
	int arr2[] = {1,2,3};
	int x = 3,y = 5,value = 5;
	
	int len = sizeof(arr)/sizeof(arr[0]);
	int len1 = sizeof(arr1)/sizeof(arr1[0]);
	int len2 = sizeof(arr2)/sizeof(arr2[0]);
	
	mergeArr(arr1,arr2,len1,len2);
	searchArr(arr,value,len);
	deleteArr(arr,y,len);
	setArr(arr,x,len);
	
	return 0;
}

