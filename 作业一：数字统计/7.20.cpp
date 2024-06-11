#include<bits/stdc++.h>
using namespace std;

int a, b;

int get(vector<int> num, int l, int r)
{
	int res = 0;
	for (int i = r; i >= l; i--)
		res = res * 10 + num[i];

	return res;
}

int power10(int n)
{
	int res = 1;
	for (int i = 0; i < n; i++)
		res *= 10;

	return res;
}

int count(int n)//求1到n中2出现的次数
{
	if (!n)return 0;

	vector<int> num;
	while (n)
	{
		num.push_back(n % 10);
		n /= 10;
	}
	int res = 0;
	for (int i = num.size() - 1; i >= 0; i--)
	{
		if (i == num.size() - 1)
		{
			if (2 == num[i])res += get(num, 0, i - 1) + 1;
			else if (2 < num[i])res += power10(i);
		}
		else
		{
			res += get(num, i + 1, num.size() - 1)* power10(i);
			if (2 == num[i])res += get(num, 0, i - 1) + 1;
			else if (2 < num[i])res += power10(i);
		}
	}

	return res;
}

int main()
{
	cin >> a >> b;
	cout << count(b) - count(a - 1);

	return 0;
}