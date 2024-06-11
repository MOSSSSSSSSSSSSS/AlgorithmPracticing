

//     求迷宫  到终点一共多少  条路 可走，深搜
//     求迷宫，权重都为1，到终点最短路，宽搜

//     只说了起点上一定没障碍，终点没说，所以判断终点，如果有障碍，不用看一定输出0

#include<bits/stdc++.h>
using namespace std;

const int N = 15;
int n, m, t;//长 宽 障碍数
int x0, y00, x1, y11;// 起点终点
int Map[N][N];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
long long ans;
bool check[N][N];

void dfs(int x0,int y00)
{
	check[x0][y00] = true;
	if (x0 == x1 && y00 == y11)
	{
		ans++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (x0 + dx[i] >= 1 && x0 + dx[i] <= n && y00 + dy[i] >= 1 && y00 + dy[i] <= m && Map[x0 + dx[i]][y00 + dy[i]] != 1&&!check[x0 + dx[i]][y00 + dy[i]])
		{
			dfs(x0 + dx[i], y00 + dy[i]);
			check[x0 + dx[i]][y00 + dy[i]] = false;
		}
	}
}

int main()
{
	cin >> n >> m >> t >> x0 >> y00 >> x1 >> y11;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			Map[i][j] = 0;
	for (int i = 1; i <= t; i++)
	{
		int x, y;
		cin >> x >> y;
		Map[x][y] = 1;
	}

	if (Map[x1][y11] == 1)
	{
		cout << 0;
		return 0;
	}

	dfs(x0,y00);

	cout << ans;

	return 0;
}