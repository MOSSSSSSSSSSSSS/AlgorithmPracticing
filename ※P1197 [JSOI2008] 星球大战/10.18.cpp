

// 倒着使用并查集

#include<bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10, M = 4e5 + 10;
int h[N], e[M], ne[M], idx;
int p[N];
bool brk[N];
vector<int> brkk;
int n, m, k;
int cnt;
int ans[N];
int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		int x;
		cin >> x;
		brkk.push_back(x);
		brk[x] = true;
	}
	cnt = n - k;
	for (int i = 0; i < idx; i += 2)
	{
		if (!brk[e[i]] && !brk[e[i ^ 1]])
		{
			int x = find(e[i]), y = find(e[i ^ 1]);
			if (x != y)p[x] = y,cnt--;
		}
	}
	ans[k] = cnt;
	for (int i = k - 1; i >= 0; i--)
	{
		cnt++;
		brk[brkk[i]] = false;
		for (int j = h[brkk[i]]; ~j; j = ne[j])
		{
			int k = e[j];
			if (!brk[k])
			{
				int x = find(k), y = find(brkk[i]);
				if (x != y)p[x] = y,cnt--;
			}
		}
		ans[i] = cnt;
	}
	for (int i = 0; i <= k; i++)
		cout << ans[i] << endl;

	return 0;
}