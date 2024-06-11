

#include<bits/stdc++.h>
using namespace std;

const int N = 500010, M = 4000010;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int id[N], edcc_cnt;
int Size[N];
vector<int> a[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void tarjan(int u, int from)
{
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!dfn[j])
		{
			tarjan(j, i);
			low[u] = min(low[u], low[j]);
		}
		else if (i != (from ^ 1))
			low[u] = min(low[u], dfn[j]);
	}
	if (dfn[u] == low[u])
	{
		int y;
		edcc_cnt++;
		do {
			y = stk[top--];
			id[y] = edcc_cnt;
			a[edcc_cnt].push_back(y);
			Size[edcc_cnt]++;
		} while (y != u);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	for(int i = 1;i<=n;i++)
		if(!dfn[i])
			tarjan(i, -1);
	cout << edcc_cnt << endl;
	for (int i = 1; i <= edcc_cnt; i++)
	{
		cout << Size[i] << ' ';
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}

	return 0;
}