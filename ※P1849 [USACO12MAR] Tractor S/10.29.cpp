

//  优先队列bfs


#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
struct node {
	int num, x, y;
	friend bool operator <(node a, node b)
	{
		return a.num > b.num;
	}
}nodes[N][N];
bool st[N][N];
int n, xx, yy;

void bfs()
{
	priority_queue<node> heap;
	nodes[xx][yy].x = xx, nodes[xx][yy].y = yy;
	heap.push(nodes[xx][yy]);
	st[xx][yy] = true;
	while (heap.size())
	{
		node tt = heap.top();
		heap.pop();
		if (tt.y + 1 <= N && tt.x >= 0 && tt.y + 1 >= 0 && tt.x <= N && !st[tt.x][tt.y + 1])
		{
			st[tt.x][tt.y + 1] = true;
			nodes[tt.x][tt.y + 1].num += tt.num;
			nodes[tt.x][tt.y + 1].x = tt.x, nodes[tt.x][tt.y + 1].y = tt.y + 1;
			heap.push(nodes[tt.x][tt.y + 1]);
			if (tt.x == 0 && tt.y + 1 == 0)return;
		}
		if (tt.x - 1 >= 0 && tt.y >= 0 && tt.y <= N && tt.x - 1 <= N && !st[tt.x - 1][tt.y])
		{
			st[tt.x - 1][tt.y] = true;
			nodes[tt.x - 1][tt.y].num += tt.num;
			nodes[tt.x - 1][tt.y].x = tt.x - 1, nodes[tt.x - 1][tt.y].y = tt.y;
			heap.push(nodes[tt.x - 1][tt.y]);
			if (tt.x - 1 == 0 && tt.y == 0)return;
		}
		if (tt.x + 1 <= N && tt.x + 1 >= 0 && tt.y >= 0 && tt.y <= N && !st[tt.x + 1][tt.y])
		{
			st[tt.x + 1][tt.y] = true;
			nodes[tt.x + 1][tt.y].num += tt.num;
			nodes[tt.x + 1][tt.y].x = tt.x + 1, nodes[tt.x + 1][tt.y].y = tt.y;
			heap.push(nodes[tt.x + 1][tt.y]);
			if (tt.x + 1 == 0 && tt.y == 0)return;
		}
		if (tt.y - 1 >= 0 && tt.y - 1 <= N && tt.x >= 0 && tt.x <= N && !st[tt.x][tt.y - 1])
		{
			st[tt.x][tt.y - 1] = true;
			nodes[tt.x][tt.y - 1].num += tt.num;
			nodes[tt.x][tt.y - 1].x = tt.x, nodes[tt.x][tt.y - 1].y = tt.y - 1;
			heap.push(nodes[tt.x][tt.y - 1]);
			if (tt.x == 0 && tt.y - 1 == 0)return;
		}


	}
}

int main()
{
	cin >> n >> xx >> yy;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		nodes[x][y].num = 1;
	}
	bfs();
	cout << nodes[0][0].num;

	return 0;
}