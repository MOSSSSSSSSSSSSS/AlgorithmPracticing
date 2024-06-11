


#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 100010,INF = 0x3f3f3f3f;
int n, m,s;
int h[N], e[2 * N],w[2*N], ne[2 * N], idx;
int dist[N];
bool st[N];

void add(int x, int y, int z)
{
	e[idx] = y;
	w[idx] = z;
	ne[idx] = h[x];
	h[x] = idx++;
}

void dijkstra()
{
	for (int i = 1; i <= n; i++)dist[i] = INF;
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
				heap.push({ dist[j],j });
			}
		}
	}
}

int main()
{
	cin >> n >> m>>s;
	for (int i = 1; i <= n; i++)h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}

	dijkstra();

	for (int i = 1; i <= n; i++)cout << dist[i] << ' ';

	return 0;
}