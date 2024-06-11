
//整数二分有两个模板，第一个是分为两个部分（注意是整数，两个部分有明显的区分），要求的是右部分的最左边界，第二种是分为两个部分（注意是整数，两个部分有明显的区分），要求的是左部分的最右边界
//做题时先写出判断函数，
// if (q[mid] >= x)j = mid;把区间分为大于等于和小于两个部分，最后i = j = 右边部分的左边界。
// 也就是找到一个条件，如果符合这个条件后将 l = mid，则mid = l + r + 1 >> 1，不符合这个条件将 r = mid - 1；（这种情况下不加一的话，当l = r - 1，时出现死循环）
//如果符合这个条件后将r = mid ，则mid = l + r >> 1，不符合这个条件(else）将 l = mid + 1；

//二分法的模板一定有答案，但对于不同的题，例如下面的题是一个升序数组，会出现查找的数k，数组中没有的情况，如果查找k的起始下标，二分查找出来的数本应该是第一个k的下标，但没有k所以找到了第一个大于k的数的下标
//这时题目无解，但是模板永远都有解
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

const int N = 100010;
int q[N], n, m;


int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)scanf("%d", &q[i]);

	while (m--)//  一共查找m个数
	{
		int i = 0, j = n - 1,x,mid;
		scanf("%d", &x);
		while (i < j)
		{
			mid = i + j >> 1;
			if (q[mid] >= x)j = mid;//是大于  等于  注意等于
			else i = mid + 1;
		}
		if (q[i] != x)printf("-1 -1");
		else
		{
			printf("%d ", i);
			i = 0, j = n - 1;
			while (i < j)
			{
				mid = i + j + 1 >> 1;
				if (q[mid] <= x)i = mid;
				else j = mid - 1;
			}
			printf("%d\n", i);
		}
	}

	return 0;
}