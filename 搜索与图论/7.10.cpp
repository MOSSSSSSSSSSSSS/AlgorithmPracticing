


//深度优先搜索DFS，宽度优先搜索BFS，树与图的存储，树与图的深度优先遍历，树与图的宽度优先遍历，拓扑排序
//DFS是用stack实现，BFS用queue实现，DFS空间复杂度O（n），BFS空间复杂度O(2的n次方)
//DFS不具有最短路特点，BFS具有最短路特点，BFS找到一个点是由最短路找到的，从近到远找
//DFS：回溯：恢复之前现场。剪枝，最优性剪枝：判断当前情况一定不如最优解，就提前结束当前情况看下一种。可行性剪枝：这种情况一定违反题意，就提前结束当前情况看下一种。


//7.29
//排列数字
#include<bits/stdc++.h>
using namespace std;

const int N = 10;

int n,path[N];
bool st[N];

void dfs(int u)
{
	if (u == n + 1)
	{
		for (int i = 1; i <= n; i++)cout << path[i] << ' ';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!st[i])
		{
			path[u] = i;
			st[i] = true;
			dfs(u + 1);
			path[u] = 0;
			st[i] = false;
		}
	}

}

int main()
{
	cin >> n;
	dfs(1);

	return 0;
}
//n 皇后问题    这个复杂度 n*n！
#include<bits/stdc++.h>
using namespace std;

const int N = 20;
int n,col[N],dg[N],udg[N];
char path[N / 2][N / 2];

void dfs(int u)
{
	if (u == n + 1)       //      递归要有 结束条件
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				cout << path[i][j];
			cout << endl;
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!col[i] && !dg[u + i - 1] && !udg[u - i + n])
		{
			path[u][i] = 'Q';
			col[i] = dg[u + i - 1] = udg[u - i + n] = true;
			dfs(u + 1);
			col[i] = dg[u + i - 1] = udg[u - i + n] = false;
			path[u][i] = '.';
		}
	}

}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			path[i][j] = '.';

	dfs(1);

	return 0;
}
//      所有边权重都是1的时候，才能用BFS求最短路
//      走迷宫
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 110;
int n, m, g[N][N], d[N][N];   //g存迷宫，d是每个点到起点距离
PII q[N * N], Prev[N][N]; //想要把路径输出，只需要 记录一个点，它前面的点是谁
int hh, tt = -1;

int bfs(int n, int m)
{
	q[++tt] = { 1,1 };                  //把第一个点放进去
	d[1][1] = 0;                        //把第一个点放进去
	int dx[4] = { 0,-1,0,1 };
	int dy[4] = { 1,0,-1,0 };         //  可以走到周围四个方向上，不用一个一个枚举，可以这样写
	while (hh <= tt)
	{
		PII t = q[hh++]; //%%%%%%%%%%%%%%%%%%
		for (int i = 0; i < 4; i++)
		{
			int x = t.first + dx[i];
			int y = t.second + dy[i];
			if (x >= 1 && x <= n && y >= 1 && y <= m && g[x][y] != 1 && d[x][y] == -1)
			{//如果新的点在迷宫内，且不是墙壁，且没有到达过
				d[x][y] = d[t.first][t.second] + 1;
				q[++tt] = { x,y };
				Prev[x][y] = t;
			}
		}
	}
	for (int x = n, y = m; x != 1 || y != 1; )
	{
		PII t = Prev[x][y];
		cout << t.first << ',' << t.second << '   ';
		x = t.first, y = t.second;
	}

	return d[n][m];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> g[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			d[i][j] = -1;

	cout << bfs(n, m);

	return 0;
}
// 树是一种特殊的图，树是无环连通图.%%%%%%%%%%%%%%%%%%%% n个节点的树最多有n-1个边 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// 
//  图分成有向图和无向图， a -->b 有向图边是有方向的，a--b无向图，建的时候就建a -->b，b -->a，无向图是特殊的有向图
//   有向图  存储  第一种：邻接矩阵，g[a][b] 指a 到 b这条边，有权重就是权重，无权重就是bool值表示  之间有没有边，邻接矩阵不能存储 重边，只能保留 一个边
//   空间复杂度 大 n方，适合存储稠密图，稀疏图不适合
//    第二种是：邻接表，n个点，开n个单链表，单链表（idx从下标0开始存储）存储 这个点 可以到的点

//树与图的遍历，深度优先遍历，宽度优先遍历，每个点都遍历一遍，用bool st数组表示有没有被遍历过

//树的重心：深度优先遍历，因为深度优先遍历遍历某个节点，是走到底，在这个过程中可以求出以这个节点为根节点的子树的大小
#include<bits/stdc++.h>
using namespace std;

const int N = 100010, M = N * 2;     //  n个节点，最多n-1无向边，开2*N大小存储边
int h[N], e[M], ne[M], idx;        // 虽然有n个单链表，但是e，ne，idx只用这样
bool st[N];                        //深度优先遍历 ，bool记录有没有被遍历过
int n, ans = N;                      //注意ans是所有最大值的最小，ans = min（），ans一开始赋值为N

void add(int a, int b)         //  建立a到b的边
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx++;
}

int dfs(int x)
{
 	st[x] = true;           //标记为已经被找过
 	int sum = 1, res = 0;
	for (int i = h[x]; i != -1; i = ne[i])      //  深度优先搜索
	{
		if (!st[e[i]])
		{
			int s = dfs(e[i]);
			res = max(res, s);
			sum += s;
		}
	}

	res = max(res, n - sum);
	ans = min(ans, res);

	return sum;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)h[i] = -1;
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);    //  两次，因为是  无 向边
	}
	dfs(1);      //从所有节点中，任选一个开始搜就行
	cout << ans;
}

//  宽度优先遍历 ， 宽度优先搜索+邻接表
//图中点的层次
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;    
int q[N], hh, tt = -1, d[N];  

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void bfs()
{
	q[++tt] = 1;
	d[1] = 0;
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1)
			{
				q[++tt] = j;
				d[j] = d[t] + 1;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		d[i] = h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}

	bfs();

	cout << d[n];

	return 0;
}

//   图的宽度优先搜索，应用：求拓扑序
//   图的拓扑序列针对有向图来说的，无向图没有，拓扑序列A满足，对于图中的x到y的边来说序列A中x在y前面
// 也就是说在拓扑序列中如果把边画出来，所有的边都是往后指的
//   有向 无环 的图一定有拓扑序列，所以有向无环图，称为拓扑图（有环一定没拓扑序列）
//    有向图中，每个点都有两个度，入读表示有多少边通向自己，出度表示有多少边自己发出通向别人
//
//   如何求拓扑序列：先把图中所有入读为0的放队列中，不断取队头，看他的所有出度，每个出度指向对应点
//看到的对应点相应入读--，看完后再把入读为0的放队列里，一直这样放下去

#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];//  表示 每个点的入度

void add(int a,int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
	d[b]++;
}

bool topsort()
{
	int hh = 0, tt = -1;
	for (int i = 1; i <= n; i++)
		if (!d[i])
			q[++tt] = i;
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			d[j]--;
			if (!d[j])q[++tt] = j;
		}
	}

	return tt == n - 1;    //  看有没有全部的数都插入，tt是一直在加加的，如果全插入tt == n-1就存在拓扑序
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}

	if (topsort())
		for (int i = 0; i < n; i++)
			cout << q[i] << ' ';      //  当排出队头元素时只是hh++，但是从0开始还是有数的。
	else
		cout << -1;

	return 0;
}