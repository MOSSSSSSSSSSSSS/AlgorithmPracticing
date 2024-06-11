

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e6 + 10,INF = 0x3f3f3f3f;
int n, m;
int u[N], v[N], c[N];
int h[N], e[N], ne[N], w[N], idx;
long long dist[N];           //  w很大，dist开long long
bool st[N];
long long ans; //  w很大，ans开long long

void dijkstra()
{
	for (int i = 1; i <= n; i++)
		st[i] = 0;
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[1] = 0;
	//st[1] = 1;                   不要加！！！！！！！！！！！！！！！11
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0,1 });
	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();
		int ver = t.second, distance = t.first;
		if (st[ver])continue;
		st[ver] = 1;
		for (int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > (long long)w[i] + distance)
			{
				dist[j] = (long long)w[i] + distance;             //   可能会溢出
				heap.push({ dist[j], j });
			}
		}
	}
}

void add(int u, int v, int c)
{
	w[idx] = c;
	e[idx] = v;
	ne[idx] = h[u];
	h[u] = idx++;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> u[i] >> v[i] >> c[i];
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= m; i++)
		add(u[i], v[i], c[i]);
	dijkstra();
	for (int i = 1; i <= n; i++)
		ans += dist[i];
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	idx = 0;
	for (int i = 1; i <= m; i++)
		add(v[i], u[i], c[i]);
	dijkstra();
	for (int i = 1; i <= n; i++)
		ans += dist[i];
	cout << ans;
	return 0;
}
