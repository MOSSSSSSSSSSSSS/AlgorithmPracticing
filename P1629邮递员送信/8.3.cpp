





//   ע�����⣬�ʵ�Ա���ʾֵ�ĳ�أ��ִ�ĳ�ػ���ʾ֣�������ԭ·����Ϊ����·���ǵ����
//   ��ԭͼ��ͬʱ��һ��    ��ͼ   ����ԭ���е�·�����෴������һ��dijkstra()������������ʾֵ����·





#include<bits/stdc++.h>
using namespace std;

const int N = 1010,INF = 0x3f3f3f3f;
int n, m;
int g[N*2][N*2];
int dist[N*2];
bool st[N*2];

void dijkstra(int k)
{
	for (int i = 1+k; i <= n+k; i++)dist[i] = INF;
	dist[1+k] = 0;
	for (int i = 0; i < n; i++)
	{
		int t = -1;                //  t��¼��С��
		for (int j = 1+k; j <= n+k; j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		st[t] = true;
		for (int j = 1+k; j <= n+k; j++)
			dist[j] = min(dist[j], dist[t] + g[t][j]);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= 2*n; i++)
	{
		for (int j = 1; j <= 2*n; j++)
		{
			if (i == j)g[i][j] = 0;
			else g[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		g[x][y] = min(g[x][y],z);                             //  ��Ŀû˵�������ر�
		g[y+n][x+n] = min(g[y + n][x + n],z);
	}

	dijkstra(0);
	dijkstra(n);
	long long ans = 0;
	for (int i = 1; i <= 2*n; i++)ans += dist[i];
	cout << ans;

	return 0;
}