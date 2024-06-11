

//         tarjan+自己写的dfs   会超时，不应该用dfs

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10, M = 2e6 + 10;
int h[N], e[M], ne[M], idx;
int A[N], B[N];
int dfn[N], low[N], timestamp;
int n, m, K, L;
vector<PII> ans;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void tarjan(int u, int from)
{
	dfn[u] = low[u] = ++timestamp;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!dfn[j])
		{
			tarjan(j, i);
			low[u] = min(low[u], low[j]);
			if (low[j] > dfn[u])
				if (!A[j] || !B[j] || A[j] == K || B[j] == L)//////////////////////////////////////////////////////////////////////
					ans.push_back({ j,u });///////////////////////////////////////////////////////////////////////////////////////////
			A[u] += A[j], B[u] += B[j];////////////////////////////////////////////////////////////////////////////////////////////
		}
		else if (i != (from ^ 1)) low[u] = min(low[u], dfn[j]);
	}
}
int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m >> K >> L;
	for (int i = 1; i <= K; i++)
	{
		int x;
		cin >> x;
		A[x] = 1;
	}
	for (int i = 1; i <= L; i++)
	{
		int x;
		cin >> x;
		B[x] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	tarjan(1, -1);
	
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second<< endl;

	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

typedef pair<bool,pair<bool, bool>> PBB;
const int N = 1e5 + 10, M = 2e6 + 10;
int h[N], e[M], ne[M], idx;
bool A[N], B[N];
int dfn[N], low[N], timestamp;
bool is_bridge[M];
PBB vis[N];
int n, m, K, L;
vector<int> ans;
bool st[N];
int check[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void tarjan(int u, int from)
{
	dfn[u] = low[u] = ++timestamp;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!dfn[j])
		{
			tarjan(j, i);
			low[u] = min(low[u], low[j]);
			if (low[j] > dfn[u])is_bridge[i] = is_bridge[i ^ 1] = true;
		}
		else if (i != (from ^ 1)) low[u] = min(low[u], dfn[j]);
	}
}
void dfs(int u, int root)
{
	st[u] = true;
	if (A[u])vis[root].second.first = true;
	if (B[u])vis[root].second.second = true;
	if (!check[u] && vis[u].second.first && vis[u].second.second)vis[root].second.first = true, vis[root].second.second = true;
	if (vis[root].second.first && vis[root].second.second)return;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (st[j])continue;
		dfs(j, root);
		if (vis[root].second.first && vis[root].second.second)return;
	}
}
int main()                                                                                          
{
	memset(h, -1, sizeof h);
	cin >> n >> m >> K >> L;
	for (int i = 1; i <= K; i++)
	{
		int x;
		cin >> x;
		A[x] = true;
	}
	for (int i = 1; i <= L; i++)
	{
		int x;
		cin >> x;
		B[x] = true;
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	tarjan(1, -1);
	for (int i = 0; i < idx; i++)
		if (is_bridge[i])
			check[e[i]]++;
	for (int i = 1; i <= n; i++)
	{
		if (check[i] > 1)
			check[i] = 1;
		else
			check[i] = 0;
	}
	for (int i = 0; i < idx; i+=2)
	{
		if (is_bridge[i])
		{
			memset(st, 0, sizeof st);
			if (!vis[e[i]].first)
			{
				st[e[i ^ 1]] = true;
				dfs(e[i], e[i]);
				if(!check[e[i]])vis[e[i]].first = true;
			}
			if (vis[e[i]].second.first && vis[e[i]].second.second)
			{
				if (check[e[i]])
					vis[e[i]].second.first = vis[e[i]].second.second = false;
			}
			else if (!vis[e[i]].second.first || !vis[e[i]].second.second)
			{
				ans.push_back(i);
				if (check[e[i]])
					vis[e[i]].second.first = vis[e[i]].second.second = false;
				continue;
			}
			memset(st, 0, sizeof st);
			if (!vis[e[i ^ 1]].first)
			{
				st[e[i]] = true;
				dfs(e[i ^ 1], e[i ^ 1]);
				if (!check[e[i^1]])vis[e[i^1]].first = true;
			}
			if (vis[e[i ^ 1]].second.first && vis[e[i ^ 1]].second.second)
			{
				if (check[e[i ^ 1]])
					vis[e[i ^ 1]].second.first = vis[e[i ^ 1]].second.second = false;
			}
			else if (!vis[e[i ^ 1]].second.first || !vis[e[i ^ 1]].second.second)
			{
				if (check[e[i^1]])
					vis[e[i^1]].second.first = vis[e[i^1]].second.second = false;
				ans.push_back(i);
			}
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << e[ans[i]] << ' ' << e[ans[i] ^ 1] <<endl;

	return 0;
}*/
/*9 10 3 4
2 4 5
4 9 8 3
1 2
4 1
2 3
4 2
1 5
5 6
6 7
6 8
7 9
8 7*/
/*


#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 2e6 + 10;
int h[N], e[M], ne[M], idx;
bool A[N], B[N];
int dfn[N], low[N], timestamp;
bool is_bridge[M];
int n, m, K, L;
vector<int> ans;
bool f1, f2;
bool st[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void tarjan(int u, int from)
{
	dfn[u] = low[u] = ++timestamp;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!dfn[j])
		{
			tarjan(j, i);
			low[u] = min(low[u], low[j]);
			if (low[j] > dfn[u])is_bridge[i] = is_bridge[i ^ 1] = true;
		}
		else if (i != (from ^ 1)) low[u] = min(low[u], dfn[j]);
	}
}
void dfs(int u)
{
	st[u] = true;
	if (A[u])f1 = true;
	if (B[u])f2 = true;
	if (f1 && f2)return;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (st[j])continue;
		dfs(j);
		if (f1 && f2)return;
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m >> K >> L;
	for (int i = 1; i <= K; i++)
	{
		int x;
		cin >> x;
		A[x] = true;
	}
	for (int i = 1; i <= L; i++)
	{
		int x;
		cin >> x;
		B[x] = true;
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	tarjan(1, -1);
	for (int i = 0; i < idx; i+=2)
	{
		if (is_bridge[i])
		{
			f1 = f2 = false;
			memset(st, 0, sizeof st);
			st[e[i ^ 1]] = true;
			dfs(e[i]);
			if (!f1 ||!f2)
			{
				ans.push_back(i);
				continue;
			}
			f1 = f2 = false;
			memset(st, 0, sizeof st);
			st[e[i]] = true;
			dfs(e[i^1]);
			if (!f1 || !f2) ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << e[ans[i]] << ' ' << e[ans[i] ^ 1] <<endl;

	return 0;
}
/*9 10 3 4
2 4 5
4 9 8 3
1 2
4 1
2 3
4 2
1 5
5 6
6 7
6 8
7 9
8 7*/
