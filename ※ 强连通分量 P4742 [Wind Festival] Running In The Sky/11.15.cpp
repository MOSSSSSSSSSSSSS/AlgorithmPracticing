

// 正解是拓扑排序，其实只要记录下入度为0的点，从入度为零的点开始dfs，并且已经dfs过的记录下来（只遍历一次，复杂度为线性，可以过），不用再dfs就可
// 缩点完之后，是有向无环图，可能多个点连一个点，可能一个点连多个点

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, M = 5e5 + 10;
int h[N], e[M], ne[M], idx;
int light[N];
int sum[N];
int MAX[N];
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt;
int n, m;
int din[N];
vector<int> edge[N];
int ans1,ans2;
int m_tot[N], m_zuida[N];

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
		scc_cnt++;
		int y;
		do {
			y = stk[top--];
			in_stk[y] = false;
			id[y] = scc_cnt;
			sum[scc_cnt] += light[y];
			MAX[scc_cnt] = max(MAX[scc_cnt], light[y]);
		} while (y != u);
	}
}
pair<int,int> dfs(int u)
{
	m_tot[u] = 0, m_zuida[u] = 0;
	for (auto item : edge[u])
	{
		pair<int, int> res;
		if (m_tot[item] == 0)res = dfs(item);
		else res.first = m_tot[item], res.second = m_zuida[item];
		if (m_tot[u] < res.first)
		{
			m_tot[u] = res.first;
			m_zuida[u] = res.second;
		}
		else if (m_tot[u] == res.first)
		{
			if (m_zuida[u] < res.second)
			{
				m_zuida[u] = res.second;
			}
		}
	}
	m_tot[u] += sum[u], m_zuida[u] = max(m_zuida[u], MAX[u]);
	return { m_tot[u],m_zuida[u]};
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> light[i];
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	for (int i = 1; i <= n; i++)
	{
		if (dfn[i] == 0)
		{
			tarjan(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = h[i]; ~j; j = ne[j])
		{
			int k = e[j];
			if (id[i] != id[k])
			{
				edge[id[i]].push_back(id[k]);
				din[id[k]]++;
			}
		}
	}
	for (int i = 1; i <= scc_cnt; i++)
	{
		if (din[i] == 0)
		{
			pair<int, int> res = dfs(i);
			if (ans1 < res.first)
			{
				ans1 = res.first;
				ans2 = res.second;
			}
			else if (ans1 == res.first)
			{
				if (ans2 < res.second)
				{
					ans2 = res.second;
				}
			}
		}
	}
	cout << ans1 << ' ' << ans2;

	return 0;
}