//  单向的传递性不要用并查集维护


#include<bits/stdc++.h>
using namespace std;

const int N = 210,M = 40010;
int h[N], e[M], ne[M], idx;
int n,ans;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], cnt;
int din[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u, in_stk[u] = true;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (dfn[j] == 0)
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if (in_stk[j])
			low[u] = min(low[u], dfn[j]);
	}
	if (low[u] == dfn[u])
	{
		cnt++;
		int y;
		do {
			y = stk[top--];
			in_stk[y] = false;
			id[y] = cnt;
		} while (y != u);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		while (true)
		{
			int x;
			cin >> x;
			if (x == 0)break;
			add(i, x);
		}
	}
	for (int i = 1; i <= n; i++)
		if (dfn[i] == 0)
			tarjan(i);
	for (int i = 1; i <= n; i++)
	{
		for (int j = h[i]; ~j; j = ne[j])
		{
			int k = e[j];
			if (id[i] != id[k])
				din[id[k]]++;
		}
	}
	for (int i = 1; i <= cnt; i++)
		if (din[i] == 0)
			ans++;
	cout << ans;

	return 0;
}
//  单向的传递性不要用并查集维护
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 210;
int p[N];
int n,ans;

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= n; i++)
	{
		while (true)
		{
			int x;
			cin >> x;
			if (x == 0)break;
			int fa = find(i), fb = find(x);
			if (fa != fb)p[fa] = fb;
		}
	}
	for (int i = 1; i <= n; i++)
		if (p[i] == i)
			ans++;
	cout << ans;

	return 0;
}*/