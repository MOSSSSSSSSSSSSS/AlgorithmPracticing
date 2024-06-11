

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 2510, M = 12410,INF = 0x3f3f3f3f;
int n, m, s,t;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool vis[N];

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

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
		if (vis[ver])continue;
		vis[ver] = 1;
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

int main()
{
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	dijkstra();
	cout << dist[t];

	return 0;
}