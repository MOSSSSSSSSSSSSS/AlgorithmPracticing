#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	double x;
	scanf("%lf", &x);
	double l = -1e4, r = 1e4;//   ȷ����Χl �� r 
	while (r - l > 1e-8) // ��ĿҪ����6λС��������1e-8���Ӷ���
	{
		double mid = (l + r) / 2;//   ÿ��ѭ����midҪȷ���µ�ֵ
		if (mid*mid*mid >= x)r = mid;
		else l = mid;
	}
	printf("%lf", l);//  ���l��r�����ԣ���Ϊ���������ܽӽ�


	return 0;
}