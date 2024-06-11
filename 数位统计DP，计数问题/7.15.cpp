
//  数位DP：分情况讨论

//  求A到B  区间（0<A,B<100000000）注意AB之间大小关系没有，  某个数出现的次数  ，前缀和思想，求 1到A-1 中此数的次数  ，再求1到B中次数出现的次数 ，相减，就是  区间 的答案。
//  写一个函数count（n，x）求1到n中x出现的次数
//  函数实现：分别求出x在每一位上出现的次数，加起来就是x出现的次数，
//  例如求x在第四位出现的次数，abc d efg，就是找abc x efg 这样的一共多少个数 ，首先枚举前三位 从 000 到abc-1，d = x，后三位可以从000到999
//  再看前三位是abc的情况，如果d<x，0种，如果d = x，efg可以从 000到efg，efg+1种，如果d>X 共1000种
//  有特殊情况：包括求 在首位 次数时，没有枚举前几位的可能，前几位没数，和 求 0 出现的次数时，前几位要从001开始而不是000

// **********************************************************************************************
#include<bits/stdc++.h>
using namespace std;

int a, b;

int get(vector<int> num, int l, int r)
{
	int res = 0;
	for (int i = r; i >= l; i--)
		res = res * 10 + num[i];        //求abc  a*100+b*10+c

	return res;
}

int power10(int n)
{
	int res = 1;
	for (int i = 0; i < n; i++)
		res *= 10;

	return res;
}

int count(int n, int x)
{
	if (!n)return 0;

	int res = 0;
	vector<int> num;
	while (n)                      //怎样把一个数分开存数组里
	{
		num.push_back(n % 10);
		n /= 10;
	}
	n = num.size() - 1; 
	for (int i = n; i >= 0; i--) 
	{
		if (i != n)
		{
			if (x)
				res += get(num, i + 1, n) * power10(i);
			else
				res += (get(num, i + 1, n) - 1) * power10(i);
		}
		if (x == num[i])res += get(num, 0, i - 1) + 1;
		else if (i == n && x < num[i] && x || i != n && x < num[i])res += power10(i);
	}

	return res;
}

int main()
{
	while (cin >> a >> b, a || b)
	{
		if (a > b)swap(a, b);

		for (int i = 0; i <= 9; i++)
			cout << count(b, i) - count(a - 1, i) << ' ';
		cout << endl;
	}

	return 0;
}