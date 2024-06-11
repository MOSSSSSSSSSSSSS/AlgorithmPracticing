

#include<bits/stdc++.h>
using namespace std;

const int N = 2010;
int n, m, k;
struct node {
	int time, x, y;
}nodes[N][N];
queue<node> q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int Max;
node ans;

void bfs()
{
	while (q.size())
	{
		node t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = t.x + dx[i], y = t.y + dy[i];
			if (x >= 1 && x <= n && y >= 1 && y <= m && !nodes[x][y].time)
			{
				nodes[x][y].time = t.time + 1;
				nodes[x][y].x = x;
				nodes[x][y].y = y;
				if (nodes[x][y].time > Max)
				{
					Max = nodes[x][y].time;
					ans = nodes[x][y];
				}
				q.push(nodes[x][y]);
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++)
	{
		int x, y;
		cin >> x >> y;
		nodes[x][y].time = 1;
		nodes[x][y].x = x;
		nodes[x][y].y = y;
		q.push(nodes[x][y] );
	}
	bfs();
	if (ans.x == 0)cout << 1 << ' ' << 1;
	else cout << ans.x << ' ' << ans.y;

	return 0;
}