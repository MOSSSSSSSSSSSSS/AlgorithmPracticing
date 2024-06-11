

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int n, k;
int st, ed, dist[N], vis[N],mx;
int mid,path[N],cnt;  // bfs过程中记录每个点前面是谁
int dep[N], mxdep[N],mxdist[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
int bfs(int u)
{
	memset(dist, 0, sizeof dist);
	memset(vis, 0, sizeof vis);
	queue<int> q;
	q.push(u), dist[u] = 0, vis[u] = true;
	int node = 0;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (!vis[j])
			{
				if(u==st)path[j] = t;
				vis[j] = true;
				dist[j] = dist[t] + 1;
				if (dist[j] >= mx)
				{
					mx = dist[j];
					node = j;
				}
				q.push(j);
			}
		}
	}
	return node;
}
void dfs(int u, int father)
{
	dep[u] = dep[father] + 1;
	mxdep[u] = dep[u];
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != father)
		{
			dfs(j, u);
			mxdep[u] = max(mxdep[u], mxdep[j]);
		}
	}
}
bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> k;
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	st = bfs(1);
	ed = bfs(st);
	mid = ed;
	cnt = 1;
	for (int i = path[ed]; i != st; i = path[i])
	{
		if (cnt == mx / 2)
		{
			mid = i;
			break;
		}
		cnt++;
	}
	dfs(mid,0);
	for (int i = 1; i <= n; i++)
		mxdist[i] = mxdep[i] - dep[i];
	sort(mxdist + 1, mxdist + 1 + n, cmp);
	cout << mxdist[k + 1] + 1;

	return 0;
}