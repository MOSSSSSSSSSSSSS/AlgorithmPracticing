#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;
map<string, int> mp;
int n;
int a[N];
int tr[N];
int ans;

int lb(int x)
{
	return x & (-x);
}
void pushup(int p)
{
	while (p < N)
	{
		tr[p] += 1;
		p += lb(p);
	}
}
int sum(int p)
{
	int res = 0;
	while (p)
	{
		res += tr[p];
		p -= lb(p);
	}
	return res;
}

signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string name;
		cin >> name;
		mp[name] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		string name;
		cin >> name;
		a[i] = mp[name];
	}
	for (int i = n; i >= 1; i--)
	{
		ans += sum(a[i] - 1);
		pushup(a[i]);
	}
	cout << ans;

	return 0;
}