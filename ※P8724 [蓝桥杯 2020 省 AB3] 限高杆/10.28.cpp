

//  ·Ö²ãÍ¼×î¶ÌÂ·

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 30010, M = 1e6 + 10,INF = 1e8;
int h[N],w[M], e[M], ne[M], idx;
int n, m;
int dist[N];
bool st[N];
int ans = INF;

void add(int a, int b,int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dijkstra()
{
	memset(dist,0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0,1 });
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
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (!d)
		{
			add(a, b, c), add(b, a, c);
			add(a + n, b + n, c), add(b + n, a + n, c);
			add(a + 2 * n, b + 2 * n, c), add(b + 2 * n, a + 2 * n, c);
		}
		else
		{
			add(a, b + n, c), add(b, a + n, c);
			add(a + n, b + 2 * n, c), add(b +  n, a + 2*n, c);
		}
	}
	dijkstra();
	ans = min(dist[2 * n], dist[3 * n]);
	cout << dist[n] - ans;

	return 0;
}