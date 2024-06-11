


#include<bits/stdc++.h>
using namespace std;

const int N = 60;
struct state {
	int x, y;
	int time = -1;
	char direction = 0;
};
queue<state> q;
int n, m;
state s, t;
char Map[N][N];
bool st[N][N][5];

int res(char direction)
{
	if (direction == 'W')
		return 1;
	else if (direction == 'N')
		return 2;
	else if (direction == 'E')
		return 3;
	else if (direction == 'S')
		return 4;
}

int bfs()
{
	s.time = 0;
	q.push(s);
	st[s.x][s.y][res(s.direction)] = true;
	while (q.size())
	{
		state temp = q.front();
		//cout << temp.x << ' ' << temp.y << ' ' << temp.time << ' ' << temp.direction << endl;
		q.pop();
		if (temp.direction == 'E')
		{
			if (temp.y <= m - 2 && Map[temp.x][temp.y + 2] != '1' && Map[temp.x + 1][temp.y + 2] != '1' && !st[temp.x][temp.y + 1][res(temp.direction)])
			{
				q.push({ temp.x ,temp.y + 1,temp.time + 1,temp.direction });
				st[temp.x][temp.y + 1][res(temp.direction)] = true;
				if (temp.x == t.x && temp.y + 1 == t.y)return temp.time + 1;
			}
			if (temp.y <= m - 3 && Map[temp.x][temp.y + 2] != '1' && Map[temp.x+1][temp.y + 2] != '1' && Map[temp.x][temp.y + 3] != '1' && Map[temp.x+1][temp.y + 3] != '1' && !st[temp.x][temp.y + 2][res(temp.direction)])
			{
				q.push({ temp.x ,temp.y + 2,temp.time + 1,temp.direction });
				st[temp.x][temp.y + 2][res(temp.direction)] = true;
				if (temp.x == t.x && temp.y + 2 == t.y)return temp.time + 1;
			}
			if (temp.y <= m - 4 && Map[temp.x][temp.y + 2] != '1' && Map[temp.x+1][temp.y + 2] != '1' && Map[temp.x][temp.y + 3] != '1' && Map[temp.x+1][temp.y + 3] != '1' && Map[temp.x][temp.y + 4] != '1' && Map[temp.x+1][temp.y + 4] != '1' && !st[temp.x][temp.y + 3][res(temp.direction)])
			{
				q.push({ temp.x ,temp.y + 3,temp.time + 1,temp.direction });
				st[temp.x][temp.y + 3][res(temp.direction)] = true;
				if (temp.x == t.x && temp.y + 3 == t.y)return temp.time + 1;
			}
			if(!st[temp.x][temp.y][res('N')])q.push({temp.x ,temp.y,temp.time + 1,'N'}), st[temp.x][temp.y][res('N')] = true;
			if (!st[temp.x][temp.y][res('S')])q.push({ temp.x ,temp.y,temp.time + 1,'S' }), st[temp.x][temp.y][res('S')] = true;
		}
		else if (temp.direction == 'S')
		{
			if (temp.x <= n - 2 && Map[temp.x+2][temp.y] != '1' && Map[temp.x + 2][temp.y+1] != '1' && !st[temp.x+1][temp.y][res(temp.direction)])
			{
				q.push({ temp.x+1 ,temp.y,temp.time + 1,temp.direction });
				st[temp.x+1][temp.y][res(temp.direction)] = true;
				if (temp.x+1 == t.x && temp.y == t.y)return temp.time + 1;
			}
			if (temp.x <= n - 3 && Map[temp.x+2][temp.y] != '1' && Map[temp.x+2][temp.y+1] != '1' && Map[temp.x + 3][temp.y] != '1' && Map[temp.x + 3][temp.y + 1] != '1' && !st[temp.x+2][temp.y][res(temp.direction)])
			{
				q.push({ temp.x +2,temp.y,temp.time + 1,temp.direction });
				st[temp.x+2][temp.y][res(temp.direction)] = true;
				if (temp.x+2 == t.x && temp.y == t.y)return temp.time + 1;
			}
			if (temp.x <= n - 4 && Map[temp.x+2][temp.y] != '1' && Map[temp.x+2][temp.y+1] != '1' && Map[temp.x + 3][temp.y] != '1' && Map[temp.x + 3][temp.y + 1] != '1' && Map[temp.x + 4][temp.y] != '1' && Map[temp.x + 4][temp.y + 1] != '1' && !st[temp.x+3][temp.y][res(temp.direction)])
			{
				q.push({ temp.x+3 ,temp.y,temp.time + 1,temp.direction });
				st[temp.x+3][temp.y][res(temp.direction)] = true;
				if (temp.x+3 == t.x && temp.y == t.y)return temp.time + 1;
			}
			if (!st[temp.x][temp.y][res('E')])q.push({ temp.x ,temp.y,temp.time + 1,'E' }), st[temp.x][temp.y][res('E')] = true;
			if (!st[temp.x][temp.y][res('W')])q.push({ temp.x ,temp.y,temp.time + 1,'W' }), st[temp.x][temp.y][res('W')] = true;
		}
		else if (temp.direction == 'W')
		{
			if (temp.y >= 2 && Map[temp.x][temp.y - 1] != '1' && Map[temp.x+1][temp.y - 1] != '1' && !st[temp.x][temp.y - 1][res(temp.direction)])
			{
				q.push({ temp.x ,temp.y - 1,temp.time + 1,temp.direction });
				st[temp.x][temp.y - 1][res(temp.direction)] = true;
				if (temp.x == t.x && temp.y - 1 == t.y)return temp.time + 1;
			}
			if (temp.y >= 3 && Map[temp.x][temp.y - 1] != '1' && Map[temp.x+1][temp.y - 1] != '1' && Map[temp.x][temp.y - 2] != '1' && Map[temp.x+1][temp.y - 2] != '1' && !st[temp.x][temp.y - 2][res(temp.direction)])
			{
				q.push({ temp.x ,temp.y - 2,temp.time + 1,temp.direction });
				st[temp.x][temp.y - 2][res(temp.direction)] = true;
				if (temp.x == t.x && temp.y - 2 == t.y)return temp.time + 1;
			}
			if (temp.y >= 4 && Map[temp.x][temp.y - 1] != '1' && Map[temp.x+1][temp.y - 1] != '1' && Map[temp.x][temp.y - 2] != '1' && Map[temp.x+1][temp.y - 2] != '1' && Map[temp.x][temp.y - 3] != '1' && Map[temp.x+1][temp.y - 3] != '1' && !st[temp.x][temp.y - 3][res(temp.direction)])
			{
				q.push({ temp.x ,temp.y - 3,temp.time + 1,temp.direction });
				st[temp.x][temp.y - 3][res(temp.direction)] = true;
				if (temp.x == t.x && temp.y - 3 == t.y)return temp.time + 1;
			}
			if (!st[temp.x][temp.y][res('S')])q.push({ temp.x ,temp.y,temp.time + 1,'S' }), st[temp.x][temp.y][res('S')] = true;
			if (!st[temp.x][temp.y][res('N')])q.push({ temp.x ,temp.y,temp.time + 1,'N' }), st[temp.x][temp.y][res('N')] = true;
		}
		else if (temp.direction == 'N')
		{
			if (temp.x >= 2 && Map[temp.x-1][temp.y ] != '1' && Map[temp.x - 1][temp.y+1] != '1' && !st[temp.x-1][temp.y][res(temp.direction)])
			{
				q.push({ temp.x-1 ,temp.y,temp.time + 1,temp.direction });
				st[temp.x-1][temp.y][res(temp.direction)] = true;
				if (temp.x-1 == t.x && temp.y == t.y)return temp.time + 1;
			}
			if (temp.x >= 3 && Map[temp.x-1][temp.y] != '1' && Map[temp.x - 1][temp.y+1] != '1' && Map[temp.x-2][temp.y] != '1' && Map[temp.x - 2][temp.y+1] != '1' && !st[temp.x-2][temp.y][res(temp.direction)])
			{
				q.push({ temp.x -2,temp.y,temp.time + 1,temp.direction });
				st[temp.x-2][temp.y][res(temp.direction)] = true;
				if (temp.x-2 == t.x && temp.y == t.y)return temp.time + 1;
			}
			if (temp.x >= 4 && Map[temp.x-1][temp.y] != '1' && Map[temp.x - 1][temp.y+1] != '1' && Map[temp.x-2][temp.y] != '1' && Map[temp.x - 2][temp.y+1] != '1' && Map[temp.x-3][temp.y] != '1' && Map[temp.x - 3][temp.y+1] != '1' && !st[temp.x-3][temp.y][res(temp.direction)])
			{
				q.push({ temp.x-3 ,temp.y,temp.time + 1,temp.direction });
				st[temp.x-3][temp.y][res(temp.direction)] = true;
				if (temp.x-3 == t.x && temp.y == t.y)return temp.time + 1;
			}
			if (!st[temp.x][temp.y][res('W')])q.push({ temp.x ,temp.y,temp.time + 1,'W' }), st[temp.x][temp.y][res('W')] = true;
			if (!st[temp.x][temp.y][res('E')])q.push({ temp.x ,temp.y,temp.time + 1,'E' }), st[temp.x][temp.y][res('E')] = true;
		}
	}
	return -1;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1;j <= m; j++)
			cin >> Map[i][j];
	cin >> s.x >> s.y >> t.x >> t.y >> s.direction;
	if (Map[s.x][s.y] == '1' || Map[s.x + 1][s.y + 1] == '1' || Map[s.x][s.y + 1] == '1' || Map[s.x + 1][s.y] == '1')
	{
		cout << -1;
		return 0;
	}
	if (Map[t.x][t.y] == '1' || Map[t.x + 1][t.y + 1] == '1' || Map[t.x][t.y + 1] == '1' || Map[t.x + 1][t.y] == '1')
	{
		cout << -1;
		return 0;
	}
	if (s.x >= n || s.x <= 0 || s.y >= m || s.y <= 0)
	{
		cout << -1;
		return 0;
	}
	if (s.x == t.x && s.y == t.y)
	{
		cout << 0;
		return 0;
	}
	cout << bfs();

	return 0;
}