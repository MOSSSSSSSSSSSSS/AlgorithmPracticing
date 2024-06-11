

#include<bits/stdc++.h>
using namespace std;

const int N = 510,INF = 0x3f3f3f3f;
int n, m;
int jump[N];
struct node {
	int x, y;
}nodes[2*N];
double g[2 * N][2 * N];
double dist[2 * N];
bool st[2 * N];

double prim()
{
	double MAX = 0;
	for (int i = 1; i <= m; i++)
		dist[i] = INF;
	for (int i = 0; i < m; i++)           //  注意一定从0 开始，因为下面有  if（i&&。。。）
	{
		int t = -1;
		for (int j = 1; j <= m; j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		if (i && dist[t] == INF)return INF;
		if(i)MAX = max(MAX, dist[t]);           //  if(i)才给MAX赋值，0的时候不用是进来一个点
		st[t] = 1;
		for (int j = 1; j <= m; j++)
			dist[j] = min(dist[j], g[t][j]);
	}
	return MAX;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> jump[i];
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x>>y;
		nodes[i] = { x,y };
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == j)
				g[i][j] = 0;
			else
				g[i][j] = sqrt((nodes[i].x - nodes[j].x) * (nodes[i].x - nodes[j].x) + (nodes[i].y - nodes[j].y) * (nodes[i].y - nodes[j].y));
		}
	}
	int ans = 0;
	double t = prim();
	for(int i = 1;i<=n;i++)
		if (jump[i]>=t)ans++;
	cout << ans;

	return 0;
}
