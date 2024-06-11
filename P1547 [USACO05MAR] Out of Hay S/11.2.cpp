

#include<bits/stdc++.h>
using namespace std;

const int N = 2010, M = 1e4 + 10;
int n, m;
int p[N];
int MAX;
struct edge{
	int a, b, w;
}edges[M];

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
int kruskal()
{
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		int fa = find(a), fb = find(b);
		if (fa != fb)
		{
			MAX = max(MAX, w);
			cnt++;
			p[fa] = fb;
			if (cnt == n - 1)return MAX;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[i].a = a, edges[i].b = b, edges[i].w = c;
	}
	sort(edges + 1, edges + 1 + m, cmp);
	cout<<kruskal();

	return 0;
}