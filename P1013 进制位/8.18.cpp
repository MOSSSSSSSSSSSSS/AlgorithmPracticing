


//  这个进制的加法表，n-1就是进制（因为最多只有一解），并且每一行有多少个二位的，这一行第一个数就是几（举例子也能明白），也没三位数
//判断是不是error，就判断有没有重复的数，有没有等于或大于n-1的数，满不满足表格中相加后的结果

#include<bits/stdc++.h>
using namespace std;

typedef pair<char, int> PCI;
const int N = 10;
int n;
string form[N][N];
PCI ans[N];

int transform(string str)
{
	int res = 0;
	for (int i = 0; i < str.size(); i++)
		for (int j = 1; j <= n - 1; j++)
			if (ans[j].first == str[i])
				res = res * (n - 1) + ans[j].second;

	return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> form[i][j];
			if (j == 0)
				ans[i].first = form[i][j][0];
			if (form[i][j].size() == 2)
				ans[i].second++;
		}
	}
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (ans[i].second == ans[j].second||ans[i].second>=n-1)
			{
				cout << "ERROR!";
				return 0;
			}
		}
	}
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 1; j <= n - 1; j++)
		{
			if (ans[i].second + ans[j].second != transform(form[j][i]))
			{
				cout << "ERROR!";
				return 0;
			}
		}
	}
	for (int i = 1; i <= n - 1; i++)
		cout << form[i][0] << '=' << ans[i].second << ' ';
	cout << endl << n - 1;

	return 0;  
}