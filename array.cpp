#include"array.h"
#include<stdio.h>

int *setArr(int arr[],int x,int len)//全部元素设为同一值 
{
	printf("重新设置元素全部为%d后的数组\n",x);
	for(int i=0;i<len;i++){
		arr[i] = x;
		printf("%d ",arr[i]);
	}
	return arr;
}

int mergeArr(int arr1[],int arr2[],int len1,int len2)//合并两个数组，结果存入第三个数组
{
	printf("合并数组，结果存入arr3：\n");
	int *newArr = new int[len1 + len2];
	int k = 0;
	for(int i=0;i<len1;i++)
	{
		newArr[k++] = arr1[i];
	}
	for(int i=0;i<len2;i++)
	{
		newArr[k++] = arr2[i];
	}
	
	for(int i=0;i<(len1+len2);i++)
	{
		printf("arr3[%d] = %d\n",i,newArr[i]);
	}
	
	return 0;
}

int searchArr(int arr[],int value,int len) //查找某个数在数组中的位置
{
	int index;
	for(int i=0;i<len;i++)
	{
		if(arr[i] == value){
			index = i;
			printf("%d在数组中的位置是arr[%d]\n",value,i);
			break;
		}
		else
			index = -1;
	}
	if(index == -1)
		printf("该数不在数组中\n");
	return index;
}

int *deleteArr(int arr[],int y,int len) //从数组中删除某个数，有几个删几个
{
	int j = 0;
	printf("删除%d后的arr:{",y);
	for(int i=0;i<len;i++)
	{
		
		if(arr[i] != y)
		{
			arr[j] = arr[i];
			j++;
			printf("%d ",arr[i]);
		}
	
	}
		printf("}\n");
	return arr;
} 




