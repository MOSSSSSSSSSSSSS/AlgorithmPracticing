

#include<bits/stdc++.h>
using namespace std;

const int N = 110,INF = 2e9;
int n, m;
char Map[N][N];
bool vis[N][N][4];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };  //  0ср1об2вС3ио
struct node {
	int x, y, sum, d;
	friend bool operator<(node a, node b)
	{
		return a.sum > b.sum;
	}
};
int s_x, s_y, e_x, e_y;
int ans = INF;

int bfs(int d)
{
	bool flag = false;
	int wcnm = INF;
	priority_queue<node> heap;
	vis[s_x][s_y][d] = true;
	if (s_x + dx[d] >= 1 && s_x + dx[d] <= n && s_y + dy[d] >= 1 && s_y + dy[d] <= m && Map[s_x + dx[d]][s_y + dy[d]] != '*')
		heap.push({ s_x + dx[d],s_y + dy[d],0,d });
	else
		return INF;
	vis[s_x + dx[d]][s_y + dy[d]][d] = true;
	while (heap.size())
	{
		node tt = heap.top();
		heap.pop();
		//if (d == 3)cout << tt.x << ' ' << tt.y << ' ' << tt.sum << ' ' << tt.d << endl;
		if (flag && tt.sum > wcnm)return wcnm + 1;//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		for (int i = 0; i <= 3; i++)
		{
			int x = tt.x + dx[i], y = tt.y + dy[i];
			if ( x >= 1 && x <= n && y >= 1 && y <= m)
			{
				if (x == e_x && y == e_y&& abs(i - tt.d) != 2)
				{
					if (i == tt.d)return tt.sum;
					else {
						flag = true;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
						wcnm = tt.sum;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					}
				}
				if (Map[x][y] == '*')continue;
				if (abs(i - tt.d) == 2)continue;
				if (i == tt.d && !vis[x][y][i])
				{
					vis[x][y][i] = true;
					heap.push({ x,y,tt.sum,i });
				}
				else
				{
					if (!vis[x][y][i])
					{
						vis[x][y][i] = true;
						heap.push({ x,y,tt.sum + 1,i });
					}
				}
			}
		}
	}
	return INF;
}

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 'C')
			{
				if(!s_x)s_x = i, s_y = j;
				else e_x = i, e_y = j;
			}
		}
	}
	for (int i = 0; i <= 3; i++)
	{
		ans = min(ans,bfs(i));
		memset(vis, 0, sizeof vis);
	}
	cout << ans;

	return 0;
}
