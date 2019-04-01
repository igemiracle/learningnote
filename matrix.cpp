#include <iostream>
#include "matrix.h"
#include <stdlib.h>
using namespace std;

void avgRows(float *a, int rows, int cols, float p[])
{	
	for (int i = 0; i < rows; i++)
	{
		p[i] = 0;
		for (int j = 0; j < cols; j++)
		{
			p[i] = p[i] + a[ i * cols + j];
		}
	}
	for (int i = 0; i < rows; i++) {
		p[i] = p[i] / cols;
	}
	
}

void avgCols(float *a, int rows, int cols, float p[])
{
	for (int i = 0; i < cols; i++)//列数
	{
		p[i] = 0;
		for (int j = 0; j < rows; j++)//行数
		{
			p[i] = p[i] + a[j*cols + i];//a[j][i]
		}
	}

	for (int i = 0; i < cols; i++)
	{
		p[i] = p[i] / rows;
	}
}

void removeRows(float *a, int rows, int cols, int value)
{
	value = value - 1;
	if (value > rows)
		return ;
	for (int i = 0; i < rows; i++)
	{
		if (i < value)
		{
			for (int j = 0; j < cols; j++)
				a[i*cols + j] = a[i*cols + j];
		}
		else if(i > value){
			for (int j = 0; j < cols; j++)
				a[(i-1)*cols + j] = a[i*cols + j];
		}
	}
}

void removeCols(float *a, int rows, int cols, int value)
{
	value = value - 1;
	if (value > cols)
		return;
	for (int i = 0; i < cols; i++)
	{
		if (i < value)
		{
			for (int j = 0; j < rows; j++)
			{
				a[j*cols + i] = a[j*cols + i];
			}
		}
		else if (i > value)
		{
			for (int j = 0; j < rows; j++)
			{
				a[j*cols + (i-1)] = a[j*cols + i];
			}
		}
	}
}

void multiply(float *a, float p1[], int rows, int cols, float p[])
{
	for (int i = 0; i < rows; i++)
	{
		p[i] = 0;
		for(int j=0;j<1;j++)
			for (int k = 0; k < cols; k++)
			{
				p[i] = p[i] + a[i*cols + k] * p1[i];
			}
	}
}

void print(float *a,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " " ;
	}
}