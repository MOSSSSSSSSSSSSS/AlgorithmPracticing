

#include<bits/stdc++.h>
using namespace std;

const int N = 510,M = 2e5;
int p[N];
int s, tot; 
struct node {
	int x,y;
}nodes[N];
struct edge {
	int a, b;
	double w;
}edges[M];
int idx = 1;

bool cmp(edge a, edge b)
{
	if (a.w < b.w)return true;
	else return false;
}

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

bool check(double mid)
{
	for (int i = 1; i <= tot; i++)
		p[i] = i;                 //  注意初始化，每次都要
	int cnt = 0;
	for (int i = 1; i <= idx - 1; i++)
	{
		int a = edges[i].a, b = edges[i].b;
		double w = edges[i].w;
		a = find(a);
		b = find(b);
		if (a != b&&w<=mid)
		{
			p[a] = b;
			cnt++;
		}
		if (cnt >= tot - s)return true;
	}
	return false;
}
int main()
{
	cin >> s >> tot;
	for (int i = 1; i <= tot; i++)
	{
		int x, y;
		cin >> x >> y;
		nodes[i] = { x,y };
	}
	for (int i = 1; i <= tot; i++)
	{
		for (int j = i + 1; j <= tot; j++)
		{
			int x1 = nodes[i].x, y1 = nodes[i].y, x2 = nodes[j].x, y2 = nodes[j].y;
			double w = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
			edges[idx++] = { i,j,w };
		}
	}
	sort(edges + 1, edges + idx, cmp);          //   别忘了排序对边从小到大排序
	double l = 0, r = 2e4;
	while (r - l > 1e-5)
	{
		double mid = (l + r) / 2.0;
		if (check(mid)) r = mid;
		else l = mid;
	}
	printf("%.2lf", l);

	return 0;
}