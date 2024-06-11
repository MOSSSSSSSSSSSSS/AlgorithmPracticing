

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 10010, M = 500010,INF = 0x3f3f3f3f;
int n, m, s;
int h[N], w[M], e[M], ne[M], idx;
int dist[N];
bool st[N];

void dijkstra()
{
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[s] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0,s });
	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();
		int ver = t.second, distance = t.first;
		if (st[ver])continue;
		st[ver] = true;
		for (int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				heap.push({ dist[j], j });
			}
		}
	}
}

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int main()
{
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
	}
	dijkstra();
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == INF)cout << 2147483647 <<' ';
		else cout << dist[i] <<' ';
	}

	return 0;
}