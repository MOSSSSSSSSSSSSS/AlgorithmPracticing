

#include<bits/stdc++.h>
using namespace std;

const int N = 160,INF = 1e9;
int n;
struct pos {
	int x, y;
}node[N];
bool exist[N][N];
int p[N];
double dist[N][N];
double real_dist[N][N];
double far[N];//某个点与在连通块中的其他点最小距离最大值
double d[N];//每个连通块直径
double ans = INF;

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}
void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				real_dist[i][j] = min(real_dist[i][j],real_dist[i][k] + real_dist[k][j]);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= n; i++)
		cin >> node[i].x >> node[i].y;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; str[j]; j++)
		{
			if (str[j] == '1')
			{
				exist[i][j + 1] = true;
				int f1 = find(i), f2 = find(j+1);
				if (f1 != f2)p[f1] = f2;
			}
			else
			{
				exist[i][j + 1] = false;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = sqrt((node[i].x - node[j].x) * (node[i].x - node[j].x) + (node[i].y - node[j].y) * (node[i].y - node[j].y));
	for(int i= 1;i<=n;i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)real_dist[i][j] = 0;///////////////////////////////////////////////////  若同一个点，i到i距离0
			else
			{
				if (exist[i][j])real_dist[i][j] = dist[i][j];
				else real_dist[i][j] = INF;
			}
		}
	}
	floyd();
	for (int i = 1; i <= n; i++)
	{
		int f1 = find(i);
		for (int j = 1; j <= n; j++)
		{
			int f2 = find(j);
			if (f1 == f2)
			{
				far[i] = max(far[i], real_dist[i][j]);
				d[f1] = max(d[f1], far[i]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int f1 = find(i), f2 = find(j);
			if (f1 != f2)
			{
				double d3 = dist[i][j] + far[i] + far[j];
				d3 = max(d3, d[f1]);
				d3 = max(d3, d[f2]);
				ans = min(ans, d3);
			}
		}
	}
	printf("%.6lf", ans);

	return 0;
}