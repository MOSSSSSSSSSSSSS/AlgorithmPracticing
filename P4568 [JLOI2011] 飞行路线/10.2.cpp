


#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 110010, M = 2500000,INF = 0x3f3f3f3f;
int n, m, k, s, t;
int h[N], e[M], ne[M], w[M], idx;
bool st[N];
int dist[N];

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void dijkstra()
{
	for (int i = 0; i <= n * (k + 1) - 1; i++)
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
		for (int i = h[ver]; ~i; i = ne[i])
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
	cin >> n >> m >> k >> s >> t;
	for (int i = 0; i <= n*(k+1)-1; i++)
		h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
		for (int j = 1; j <= k; j++)
		{
			add(a + j * n, b + j * n, c);
			add(b + j * n, a + j * n, c);
			add(a + (j - 1) * n, b + j * n, 0);
			add(b + (j - 1) * n, a + j * n, 0);
		}
	}
	dijkstra();
	int ans = INF;
	for (int i = 0; i <= k; i++)
		ans = min(dist[t+i*n], ans);
	cout << ans;

	return 0;
}
