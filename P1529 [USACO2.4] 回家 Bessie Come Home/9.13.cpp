

#include<bits/stdc++.h>
using namespace std;

const int N = 60,INF = 0x3f3f3f3f;
int P,ans = INF,ans1;
int g[N][N];
int dist[N];
bool vis[N];

void dijkstra()
{
	for (int i = 1; i < N; i++)
		dist[i] = INF;
	dist[52] = 0;
	for (int i = 0; i < 51; i++)
	{
		int t = -1;
		for (int j = 1; j <= 52; j++)
			if (!vis[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		vis[t] = 1;
		//if (t >= 'A' || t <= 'Z')return;   不要加，我是想算出一个大写字母表示的牧场
		//认为先算出来的离的最近，就是答案，就直接结束，但运行结果不对
		for (int j = 1; j <= 52; j++)
			dist[j] = min(dist[j], dist[t] + g[t][j]);
	}
}

int main()
{
	cin >> P;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (i == j)g[i][j] = 0;
			else g[i][j] = INF;
		}
	}
	for (int i = 1; i <= P; i++)
	{
		char a, b;
		int w,x,y;
		cin >> a >> b >> w;
		if (a >= 'a' && a <= 'z')
			x = a - 'a' + 1;
		else
			x = a - 'A' + 27;
		if (b >= 'a' && b <= 'z')
			y = b - 'a' + 1;
		else
			y = b - 'A' + 27;
		g[x][y] = min(w, g[x][y]);
		g[y][x] = g[x][y];
	}
	dijkstra();
	for (int i = 27; i <= 51; i++)
	{
		if (dist[i] < ans)
		{
			ans = dist[i];
			ans1 = i;
		}
	}
	ans1 = ans1 - 27 + 'A';
	cout << (char)ans1 << ' ' << ans;

	return 0;
}