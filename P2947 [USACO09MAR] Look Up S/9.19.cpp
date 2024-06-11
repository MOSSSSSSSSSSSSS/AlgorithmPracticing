#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, h[N];
int stk[N], tt;
int ans[N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int i = n; i;i--)
	{
		while (tt && h[stk[tt]] <= h[i])tt--;
		if (tt)ans[i] = stk[tt];
		stk[++tt] = i;
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << endl;

	return 0;
}