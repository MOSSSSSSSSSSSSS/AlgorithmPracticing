/*#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	return 0;
}*/
//A 以下代码对
/*
#include<bits/stdc++.h>
using namespace std;

int t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	while (t--)
	{
		int n;
		string str;
		bool f = false;
		cin >> n;
		cin >> str;
		for(int i = 0;i<str.size();i++)
			if (str[i] == '0')
			{
				cout << "YES" << '\n';
				f = true;
				break;
			}
		if (f)continue;
		cout << "NO" << '\n';
	}

	return 0;
}*/
//B 以下代码对
/*
#include<bits/stdc++.h>
using namespace std;

#define int long long
int tc;

bool check(int mid,int x,int y,int n,int P)
{
	int sc = 0;
	sc += mid * x;
	sc += min((n + 6) / 7, 2 * mid) * y;
	return sc >= P;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> tc;
	while (tc--)
	{
		int n, P, x, y;
		cin >> n >> P >> x >> y;
		int l = 0, r = n;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (check(mid, x, y, n, P))r = mid;
			else l = mid + 1;
		}
		cout << n - l << '\n';
	}

	return 0;
}*/
//C
//F  以下代码错
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx;
int n;
int a[N];
int sum[N];
int q;
int dep[N], fa[N][20];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs1(int u, int father)
{
	sum[u] = a[u] ^sum[father];
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != father)
		{
			dfs1(j,u);
		}
	}
}
void dfs2(int u, int father)
{
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for (int i = 1; i < 20; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != father)dfs1(j, u);
	}
}
int lca(int a, int b)
{
	if (dep[a] < dep[b])swap(a, b);
	for (int i = 19; i >= 0; i--)
		if (dep[fa[a][i]] >= dep[b])
			a = fa[a][i];
	if (a == b)return a;
	for (int i = 19; i >= 0; i--)
		if (fa[a][i] != fa[b][i])
			a = fa[a][i], b = fa[b][i];
	return fa[a][0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		add(u, v), add(v, u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	cin >> q;
	while (q--)
	{
		int x, y, k;
		cin >> x >> y >> k;
		int z = lca(x, y);

	}

	return 0;
}*/