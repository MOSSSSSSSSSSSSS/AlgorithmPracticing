






//    太难调试了，两个邻接表，最后是因为add2中用了idx而不是idx2




#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 510, M = 2e5 + 10, INF = 1e16, N2 = 1010;
typedef pair<int, int> PII;
int n, m, S, T;
int h[N], e[M], ne[M], w[M], idx;
int h2[N2], e2[M], ne2[M], w2[M], idx2;
int d[N2], cur[N2], q[N2];
int tuntu[N];
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void add2(int a, int b, int c)
{
	w2[idx2] = c;
	e2[idx2] = b;
	ne2[idx2] = h2[a];
	h2[a] = idx2++;
}
void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0,1 });
	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();
		int ver = t.second, distacne = t.first;
		if (st[ver])continue;
		st[ver] = true;
		for (int i = h[ver]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > distacne + w[i])
			{
				dist[j] = distacne + w[i];
				heap.push({ dist[j],j });
			}
		}
	}
}
int find(int u, int limit)
{
	if (u == T)return limit;
	int flow = 0;
	for (int i = cur[u]; ~i && flow < limit; i = ne2[i])
	{
		cur[u] = i;
		int j = e2[i];
		if (d[j] == d[u] + 1 && w2[i])
		{
			int t = find(j, min(w2[i], limit - flow));
			if (!t)d[j] = -1;
			w2[i] -= t, w2[i ^ 1] += t, flow += t;
		}
	}
	return flow;
}
bool bfs()
{
	int hh = 0, tt = -1;
	memset(d, -1, sizeof d);
	q[++tt] = S, d[S] = 0, cur[S] = h2[S];
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h2[t]; ~i; i = ne2[i])
		{
			//cout <<"$$" << i << endl;
			int j = e2[i];
			if (d[j] == -1 && w2[i])
			{
				d[j] = d[t] + 1;
				cur[j] = h2[j];
				q[++tt] = j;
				if (j == T)return true;
			}
		}
	}
	return false;
}
int dinic()
{
	int ans = 0, flow;
	while (bfs())while (flow = find(S, INF))ans += flow;
	return ans;
}

signed main()
{
	cin >> n >> m;
	S = 1, T = n;
	memset(h, -1, sizeof h);
	memset(h2, -1, sizeof h2);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	for (int i = 1; i <= n; i++)
		cin >> tuntu[i];
	dijkstra();
	for (int i = 2; i < n; i++)
		add2(i, i + n, tuntu[i]), add2(i + n, i, 0);
	for (int i = 0; i < idx; i++)
	{
		if (dist[e[i]] == dist[e[i ^ 1]] + w[i])
		{
			if (e[i ^ 1] != S)add2(e[i ^ 1] + n, e[i], INF), add2(e[i], e[i ^ 1] + n, 0);
			else add2(S, e[i], INF), add2(e[i], S, 0);
		}
	}
	//cout << "%%%" << ne2[12];
	cout << dinic();

	return 0;
}