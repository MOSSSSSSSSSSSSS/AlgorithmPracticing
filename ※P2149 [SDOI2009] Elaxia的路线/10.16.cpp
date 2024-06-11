


 //  两点对的最短路径的最长重合


#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 1510, M = 600010;
int h[N], e[M], ne[M], w[M], idx;
bool check1[M], check2[M];
int dist1[N], dist2[N], dist3[N], dist4[N];
bool st[N];
int n, m;
int x1, y111, x2, y222;
int f[N],g[N],din[N];
int q[N];
int ans;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dijkstra(int s,int dist[])
{
	for (int i = 1; i <= n; i++)
		dist[i] = 0x3f3f3f3f;
	memset(st, 0, sizeof st);
	dist[s] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ dist[s],s });
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
void toposort()
{
	int hh = 0, tt = -1;
	for (int i = 1; i <= n; i++)
		if (!din[i])
			q[++tt] = i;
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; ~i; i = ne[i])
		{
			if (check1[i])
			{
				int j = e[i];
				din[j]--;
				if (!din[j])q[++tt] = j;
				if (check2[i])f[j] = f[t] + w[i];
				else if (check2[i ^ 1])g[j] = g[t] + w[i];
			}
		}
	}
}

int main()
{
	cin >> n >> m >> x1 >> y111 >> x2 >> y222;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	dijkstra(x1,dist1);
	dijkstra(y111,dist2);
	dijkstra(x2,dist3);
	dijkstra(y222,dist4);
	for (int i = 0; i < idx; i++)
	{
		int s = e[i ^ 1], t = e[i];
		if (dist1[s] + w[i] + dist2[t] == dist1[y111])
		{
			check1[i] = true;
			din[t]++;
		}
	}
	for (int i = 0; i < idx; i++)
	{
		int s = e[i ^ 1], t = e[i];
		if (dist3[s] + w[i] + dist4[t] == dist3[y222])
			check2[i] = true;
	}
	toposort();
	for (int i = 1; i <= n; i++)
		ans = max(ans, max(f[i], g[i]));
	cout << ans;

	return 0;
}