

#include<bits/stdc++.h>
using namespace std;

const int N = 110, M = 10010;
int n;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt;
int Size[N];
int din[N],dout[N];

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
	for(int i=h[u];~i;i=ne[i])
	{
		int j = e[i];
		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if (in_stk[j])
			low[u] = min(low[u], dfn[j]);
	}
	if (dfn[u] == low[u])
	{
		int y;
		scc_cnt++;
		do {
			y = stk[top--];
			id[y] = scc_cnt;
			in_stk[y] = false;
			Size[scc_cnt]++;
		} while (y != u);
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		h[i] = -1;
		while (1)
		{
			int x;
			cin >> x;
			if (!x)break;
			add(i, x);
		}
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	for (int i = 1; i <= n; i++)
	{
		for (int j = h[i]; ~j; j = ne[j])
		{
			int k = e[j];
			if (id[i] != id[k])
			{
				din[id[k]]++;
				dout[id[i]]++;
			}
		}
	}
	int ans1 = 0,ans2=0;
	for (int i = 1; i <= scc_cnt; i++)
	{
		if (!din[i])
			ans1++;
		if (!dout[i])
			ans2++;
	}
	cout << ans1 << endl;
	if (scc_cnt != 1)cout << max(ans1, ans2);
	else cout << 0;

	return 0;
}