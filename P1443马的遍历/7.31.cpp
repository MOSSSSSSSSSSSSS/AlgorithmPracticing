

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 410;
int n,m,x,y;
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
PII q[N * N];                            //   BFS队列，开N*N的
int hh, tt = -1;
int dist[N][N];                         //   BFS不能走重复的，否则不是最短路，用一个bool，但这里还要记录步数，直接用dist记录步数替代bool

int bfs(int xt, int yt)
{
	dist[x][y] = 0;
	q[++tt] = { x,y };              //     BFS第一步，先进行一系列初始化
	while (hh <= tt)                    //    接下来就是循环，当里面有
	{
		PII t = q[hh++];                 //  循环第一步，先取队头元素，再删掉队头
		for (int i = 0; i < 8; i++)
		{
			if (t.first + dx[i] >= 1 && t.first + dx[i] <= n && t.second+ dy[i] >= 1 && t.second + dy[i] <= m && dist[t.first + dx[i]][t.second + dy[i]] == -1)
			{
				q[++tt] = { t.first + dx[i] ,t.second + dy[i] };
				dist[t.first + dx[i]][t.second + dy[i]] = dist[t.first][t.second] + 1;      //  到了这个点了，把步数也改了，等于上一个位置的加1
			}
		}
	}

	return dist[xt][yt];
}

int main()
{
	cin >> n >> m >> x >> y;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dist[i][j] = -1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << bfs(i, j) << "    ";
		cout << endl;
	}

	return 0;
}