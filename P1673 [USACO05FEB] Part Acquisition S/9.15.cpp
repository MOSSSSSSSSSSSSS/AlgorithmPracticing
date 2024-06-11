

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 1010, M = 50010,INF = 0x3f3f3f3f;
int n, k;  //  n±ßkµã
int h[N], e[M], ne[M], idx;
int dist[N];
bool vis[N];

void dijkstra()
{
	for (int i = 1; i <= k; i++)
		dist[i] = INF;
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0,1 });
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
			if (dist[j] > distance + 1)
			{
				dist[j] = distance + 1;
				heap.push({ dist[j],j });
			}
		}
	}
}

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		h[i] = -1;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	dijkstra();
	if (dist[k] == INF)cout << -1;
	else cout << dist[k] + 1 << endl;

	return 0;
}