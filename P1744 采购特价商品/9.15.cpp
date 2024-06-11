
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//  ��Ҫ���Ե�pair<int, int>������ĵ�һ����ָ�ľ��룬
//�������о�����double,���� pair<double, int>
//!!!!!%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#include<bits/stdc++.h>
using namespace std;

typedef pair<double, int> PII;
const int N = 110,M = 2010,INF = 0x3f3f3f3f;
int n, m, s, t;
int h[N], e[M], ne[M], idx;
double dist[N],w[M];
bool vis[N];
struct node {
	int x, y;
}nodes[N];

void add(int a, int b, double c)
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
		int ver = t.second;
		double distance = t.first;
		if (vis[ver]) continue;
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

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= n; i++)
		cin >> nodes[i].x >> nodes[i].y;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		double w;
		w = sqrt((nodes[a].x - nodes[b].x) * (nodes[a].x - nodes[b].x) + (nodes[a].y - nodes[b].y) * (nodes[a].y - nodes[b].y));
		add(a, b, w), add(b, a, w);
	}
	cin >> s >> t;
	dijkstra();
	printf("%.2lf", dist[t]);

	return 0;
}