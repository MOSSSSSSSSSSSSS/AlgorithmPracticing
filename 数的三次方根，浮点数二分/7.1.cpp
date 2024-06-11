#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	double x;
	scanf("%lf", &x);
	double l = -1e4, r = 1e4;//   确定范围l 和 r 
	while (r - l > 1e-8) // 题目要求保留6位小数，就用1e-8（加二）
	{
		double mid = (l + r) / 2;//   每次循环后mid要确定新的值
		if (mid*mid*mid >= x)r = mid;
		else l = mid;
	}
	printf("%lf", l);//  输出l和r都可以，因为这两个数很接近


	return 0;
}