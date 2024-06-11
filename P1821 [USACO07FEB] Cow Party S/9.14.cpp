

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 1010, M = 100010,INF = 0x3f3f3f3f;
int n, m, x,a[M],b[M],c[M];
int h[N], e[M], ne[M], w[M], idx;
int dist[N],dist2[N];
bool vis[N];
int ans = -INF;

void dijkstra()
{
	for (int i = 1; i <= n; i++)
		dist[i] = INF, vis[i] = 0;
	dist[x] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0,x });
	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();
		int ver = t.second, distance = t.first;
		if (vis[ver])continue;
		vis[ver] = 1;
		for (int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				heap.push({ dist[j],j });
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
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		add(a[i],b[i],c[i]);
	}
	dijkstra();
	for (int i = 1; i <= n; i++)
		dist2[i] = dist[i];
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	idx = 0;
	for (int i = 1; i <= m; i++)
		add(b[i], a[i], c[i]);
	dijkstra();
	for (int i = 1; i <= n; i++)
		ans = max(ans, dist2[i] + dist[i]);
	cout << ans;

	return 0;
}