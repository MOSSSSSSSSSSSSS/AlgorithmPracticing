

//  ��Ŀ��˵ ÿ�������Ĳ�ľ���ֵ>=1����һ����Ϊ1���������������˵�ĺ���ֵ�˻�С��0��������ö������֮��ĸ�,���Կ���ö�����г���Ϊ1������
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
					double mid = (l + r)/2;   //  λ������Զ������ܸ���������
					if (f(mid) * f(r) <= 0)l = mid;
					else r = mid;
				}
				printf("%.2lf ", l);
			}
		}
	}

	return 0;
}
