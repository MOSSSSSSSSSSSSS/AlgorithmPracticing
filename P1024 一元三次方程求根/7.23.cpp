

//  题目中说 每两个根的差的绝对值>=1，在一个长为1的区间里，如果两个端点的函数值乘积小于0，则可以用二分求出之间的根,所以可以枚举所有长度为1的区间
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

double a, b, c, d;

double f(double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}

int main()
{
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

	for (int i = -100; i <= 99; i++)
	{
		double l = i, r = i + 1;
		if (!f(l))printf("%.2lf ", l);
		else
		{
			if (f(l) * f(r) < 0)
			{
				while (r - l >= 0.001)
				{
					double mid = (l + r)/2;   //  位运算除以二好像不能给浮点数用
					if (f(mid) * f(r) <= 0)l = mid;
					else r = mid;
				}
				printf("%.2lf ", l);
			}
		}
	}

	return 0;
}
