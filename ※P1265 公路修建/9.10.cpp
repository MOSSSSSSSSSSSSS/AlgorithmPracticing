
// 关键是建图，为什么是最小生成树

//   5010*5010的g二维数组会MLE，所以这个数组不建，需要距离的时候用点坐标去求，注意距离范围，计算时的平方会超int，转为LL

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 5010,INF = 0x3f3f3f3f;
int n;
double dist[N];
bool st[N];
struct node {
	int x, y;
}nodes[N];

double get_g(int i, int j)
{
	return sqrt((LL)(nodes[i].x - nodes[j].x) * (nodes[i].x - nodes[j].x) + (LL)(nodes[i].y - nodes[j].y) * (nodes[i].y - nodes[j].y));
}

double prim()
{
	double res = 0;
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		if (i && dist[t] == INF)return INF;
		if (i)res += dist[t];
		st[t] = 1;
		for (int j = 1; j <= n; j++)
			dist[j] = min(dist[j], get_g(t,j));
	}
	return res;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		nodes[i] = { x,y };
	}
	printf("%.2lf", prim());

	return 0;
}