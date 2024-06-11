

#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int m, n;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[N][N];
bool vis[N][N];
struct node {
	int x, y, num, ver;
	friend bool operator <(node a, node b)
	{
		return a.num > b.num;
	}
};
priority_queue<node> q;

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		board[x][y] = c + 1;
	}
	q.push({ 1,1,0,0});
	vis[1][1] = true;
	while (q.size())
	{
		node t = q.top();
		q.pop();
		int x = t.x, y = t.y, num = t.num, ver = t.ver;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx <= 0 || nx >= m + 1 || ny <= 0 || ny >= m + 1)continue;
			if (vis[nx][ny])continue;
			if (board[x][y] == 0 && board[nx][ny] == 0)continue;
			else if (board[x][y] == 0 && board[nx][ny] == 1)
			{
				if (ver == 1)
				{
					q.push({ nx,ny,num,0 });
					if (nx == m && ny == m)
					{
						cout << num;
						return 0;
					}
				}
				else
				{
					q.push({ nx,ny,num+1,0 });
					if (nx == m && ny == m)
					{
						cout << num+1;
						return 0;
					}
				}
			}
			else if (board[x][y] == 0 && board[nx][ny] == 2)
			{
				if (ver == 1)
				{
					q.push({ nx,ny,num+1,0 });
					if (nx == m && ny == m)
					{
						cout << num+1;
						return 0;
					}
				}
				else
				{
					q.push({ nx,ny,num,0 });
					if (nx == m && ny == m)
					{
						cout << num;
						return 0;
					}
				}
			}
			else if (board[x][y] == 1 && board[nx][ny] == 0)
			{
				q.push({ nx,ny,num + 2,1 });
				q.push({ nx,ny,num + 3,2 });//////////////////////////////////////
				if (nx == m && ny == m)
				{
					cout << num + 2;
					return 0;
				}
			}
			else if (board[x][y] == 1 && board[nx][ny] == 1)
			{
				q.push({ nx,ny,num,0 });
				if (nx == m && ny == m)
				{
					cout << num;
					return 0;
				}
			}
			else if(board[x][y] == 1 && board[nx][ny] == 2)
			{
				q.push({ nx,ny,num+1,0 });
				if (nx == m && ny == m)
				{
					cout << num+1;
					return 0;
				}
			}
			else if (board[x][y] == 2 && board[nx][ny] == 0)
			{
				q.push({ nx,ny,num + 3,1 });////////////////////////////////////
				q.push({ nx,ny,num + 2,2 });
				if (nx == m && ny == m)
				{
					cout << num + 2;///////////////////////////////////////////
					return 0;
				}
			}
			else if (board[x][y] == 2 && board[nx][ny] == 1)
			{
				q.push({ nx,ny,num + 1,0 });
				if (nx == m && ny == m)
				{
					cout << num + 1;
					return 0;
				}
			}
			else if (board[x][y] == 2 && board[nx][ny] == 2)
			{
				q.push({ nx,ny,num,0 });
				if (nx == m && ny == m)
				{
					cout << num;
					return 0;
				}
			}
			vis[nx][ny] = true;
		}
	}
	if (m == 1)cout << 0;
	else cout << -1;

	return 0;
}







