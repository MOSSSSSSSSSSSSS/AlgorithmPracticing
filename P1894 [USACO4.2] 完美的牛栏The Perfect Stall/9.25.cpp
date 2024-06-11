

#include<bits/stdc++.h>
using namespace std;

const int N = 210, M = 40010;
int n, m;
int h[N], e[M], ne[M],idx;
int match[N];
bool vis[N];
int ans;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool Find(int x)
{
	for (int i = h[x]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!vis[j])
		{
			vis[j] = true;
			if (!match[j] || Find(match[j]))
			{
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		while (num--)
		{
			int x;
			cin >> x;
			add(i, x);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			vis[j] = false;
		if (Find(i))
			ans++;
	}
	cout << ans;

	return 0;
}