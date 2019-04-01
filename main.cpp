#include <iostream>
#include "matrix.h"
#include <stdlib.h>
using namespace std;

int main()
{
	float arr[][2] = { {1,2},{3,4},{5,6} };
	float arr1[][2] = { {1,2},{3,4},{5,6} };
	float arr2[][2] = { {1,2},{3,4},{5,6} };
	int rows = sizeof(arr) / sizeof(arr[0]);
	int cols = sizeof(arr[0]) / sizeof(arr[0][0]);
	float p[100];


	avgRows((float*)arr, rows, cols, p);
	cout << "每行均值为：" << endl;
	print(p, rows);
	cout << endl;


	avgCols((float*)arr, rows, cols, p);
	cout << "每列均值为：" << endl;
	print(p, cols);
	cout << endl;


	int x;
	cout << "请输入想删去的行数" << endl;
	cin >> x;

	removeRows((float*)arr1, rows, cols, x);
	cout << "删去第" << x << "行后的数组：" << endl;
	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr1[i][j] << " " ;
		}
		cout << endl;
	}
	
	int y;
	cout << "请输入想删去的列数" << endl;
	cin >> y;

	removeCols((float*)arr2, rows, cols, y);
	cout << "删去第" << y << "列后的数组：" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols-1; j++)
		{
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}

	
	float p1[100];
	cout << "请输入一个" << cols << "维向量：" << endl;
	for (int i = 0; i < cols; i++) {
		cin >> p1[i];
	}
	multiply((float*)arr, p1, rows, cols, p);
	cout << "相乘结果是：" << endl;
	print(p,cols);

	getchar();
	getchar();

	return 0;
}