
#include<bits/stdc++.h>
using namespace std;

const int N = 100010, M = 200010;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int n, m;
int tot,huan;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void tarjan(int u,int from,bool &flag)
{
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!dfn[j])
		{
			tarjan(j, i,flag);
			low[u] = min(low[u], low[j]);
		}
		else if (i != (from ^ 1))
			low[u] = min(low[u], dfn[j]);
	}
	if (dfn[u] == low[u])
	{
		int y;
		int sz = 0;
		do {
			y = stk[top--];
			sz++;
		} while (y != u);
		if (sz > 2)flag = true;
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y), add(y, x);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
		{
			tot++;
			bool flag = false;
			tarjan(i, -1,flag);
			if (flag)huan++;
		}
	}
	cout << tot - huan;

	return 0;
}