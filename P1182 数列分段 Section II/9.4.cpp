

#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m;
int num[N],l,r,sum[N];

bool check(int mid)
{
	int cnt = 0,add = 0;
	for (int i = 1; i <= n; i++ )//   题目中说的是每个区间都小于等于，不要用大于了以后才cnt++，（像第一个题解一样），逻辑不通
	{
		add += num[i];
		if (add <= mid)
			;
		else
		{
			if (add - num[i] <= mid)
			{
				add = num[i];
				cnt++;
			}
		}
	}
	cnt++;
	if (cnt <= m)return true;
	else return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
		l = max(l, num[i]);
		r += num[i];
	}
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l;

	return 0;
}