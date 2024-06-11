

#include<bits/stdc++.h>
using namespace std;

const int N = 510;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
bool st[N][N];
struct node {
	int x, y, dist;
}nodes[N][N];
char Map[N][N];
int n, m, x111, y111, x222, y222;
node q[2*N * N];

void bfs()
{
	int hh = N*N, tt = N*N-1;
	q[++tt] = nodes[x111][y111];
	st[x111][y111] = true;
	while (hh <= tt)
	{
		node t = q[hh++];
		for (int i = 0; i < 4; i++)
		{
			int x = t.x + dx[i], y = t.y + dy[i];
			if (st[x][y])continue;
			if (x<1 || x>n || y<1 || y>m)continue;
			st[x][y] = true;
			if (Map[t.x][t.y] == Map[x][y])nodes[x][y].dist = t.dist,q[--hh] = nodes[x][y];
			else nodes[x][y].dist = t.dist+1,q[++tt] = nodes[x][y];
			if (x == x222 && y == y222)return;
		}
	}
}

int main()
{
	while (true)
	{
		cin >> n >> m;
		if (!n)return 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> Map[i][j];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				nodes[i][j].x = i, nodes[i][j].y = j;
		cin >> x111 >> y111 >> x222 >> y222;
		x111++, y111++, x222++, y222++;
		bfs();
		cout << nodes[x222][y222].dist << endl;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				nodes[i][j].dist = 0;
		memset(st, 0, sizeof st);
	}

	return 0;
}