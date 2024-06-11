

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 10;
int T;
int h[N], e[N], ne[N], idx;
int ans[N];
int dfn[N],timestamp,siz[N];
int tr[N];
vector<pair<int, int>> q;

int lowbit(int x)
{
	return x & (-x);
}
void addadd(int p, int x)
{
	while (p < N)
	{
		tr[p] += x;
		p += lowbit(p);
	}
}
int sum(int p)
{
	int res = 0;
	while (p)
	{
		res += tr[p];
		p -= lowbit(p);
	}
	return res;
}
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs(int u)
{
	dfn[u] = ++timestamp;
	siz[u] = 1;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		dfs(j);
		siz[u] += siz[j];
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--)
	{
		memset(h, -1, sizeof h);
		int n,sz = 1;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int op;
			cin >> op;
			if (op == 1)
			{
				int v;
				cin >> v;
				q.push_back({ 0,v });
				add(v, sz + 1);
				sz++;
			}
			else
			{
				int v, x;
				cin >> v >> x;
				q.push_back({ v,x });
			}
		}
		dfs(1);
		int temp = sz;
		for (int i = q.size() - 1; i >= 0; i--)
		{
			int a = q[i].first, b = q[i].second;
			if (a)
			{
				addadd(dfn[a], b);
				addadd(dfn[a] + siz[a], -b);
			}
			else
			{
				ans[temp] = sum(dfn[temp]);
				temp--;
			}
		}
		ans[1] = sum(dfn[1]);
		for (int i = 1; i <= sz; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		for (int i = 1; i <= n+10; i++)
		{
			ans[i] = tr[i] = 0;
		}
		q.clear();
		idx = timestamp = 0;
	}


	return 0;
}