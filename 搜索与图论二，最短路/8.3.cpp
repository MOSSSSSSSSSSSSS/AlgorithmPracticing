
//  有向图无向图都是用    这些算法，没区别
//  常见的最短路问题可以分为两大类：第一类：单源最短路，第二类：多源汇最短路
//   单源最短路：求一个点到其他所有点的最短距离。又可细分两类：第一类：所有边权都是正数。两个算法：朴素Dijkstra（O（n方）n指点数，m指边数）适用于边数多的时候的稠密图（m和n方一个级别）
//              和堆优化Dijkstra（O（mlogn））（适用于不同场景）。
//              dijkstra一般不用来求最长路和有负权的
//				第二类：存在负权边。两种算法：Bellman-Ford算法O（nm），spfa算法（对Bellman-Ford的优化，但也不是所有情况下都可以做，例如限制经过的边数小于等于k）一般情况下O（m），最坏O（nm）
//   多源汇最短路：源点：起点，汇点：终点。有多对，每对让求一个起点到一个终点的最短距离。
//                 Floyd算法 O（n三次方） 可以处理负权边，但不能有负权回路。
//   

//朴素Dijkstra
#include<bits/stdc++.h>
using namespace std;

const int N = 510,INF = 1e9;
int n, m;
int g[N][N];      //稠密图邻接矩阵  表示 a 到 b 的距离，一开始都初始化成 无穷大，对角线都是0。
int dist[N];     //表示起点到某个点的一定最短的距离
bool st[N];     //标记一个点，有没有求出起点到它的最短距离

bool dijkstra()
{
	for (int i = 2; i <= n; i++)
		dist[i] = INF;
	dist[1] = 0;                            //  起点距离初始化成 0 ，其他无穷大

	for (int i = 0; i < n-1; i++)               //  循环迭代n-1次，因为有一个点进来了
	{
		int t = -1;
		for(int j = 1;j<=n;j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		st[t] = true;                           //  从未被标记的点中，找最短的，标记  ，表示已经求得最短路
		
		//if (t == n)break;                     //  已经求出到终点最短距离直接退出，不对，可能求出到n的距离但返回true，dist【n】仍然是极大值

		for (int j = 1; j <= n; j++)                    
			dist[j] = min(dist[j], dist[t] + g[t][j]);              //  更新刚标记的点连通的点中未被标记的点距离，可以只更新未被标记的
	}

	if (dist[n] == INF)return false;          //  如果 还是无穷大，则到不了终点
	else return true;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)g[i][j] = 0;
			else g[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		g[x][y] = min(g[x][y], z);          //  题目说有自环，不用记录，直接距离为0，有重环，记录最短的边，邻接矩阵不能记录重环
	}
	if (dijkstra())
		cout << dist[n];
	else
		cout << -1;

	return 0;
}
//   堆优化用的是  STL的小根堆
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 150010,INF = 0x3f3f3f3f;
int n, m;
int h[N], w[N],e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int x, int y, int z)
{
	e[idx] = y;
	w[idx] = z;
	ne[idx] = h[x];
	h[x] = idx++;
}

bool dijkstra()
{
	for (int i = 2; i <= n; i++)dist[i] = INF;
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
	heap.push({ 0,1 });          //st[1] = 1;                   不要加！！！！！！！！！！！！！！！11
	//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();
		int ver = t.second, distance = t.first;
		if (st[ver])continue;
		st[ver] = true;                             //  标记
		for (int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				heap.push({ dist[j],j });
			}
		}
	}

	if (dist[n] == INF)return false;
	else return true;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}

	if (dijkstra())cout << dist[n];
	else cout << -1;

	return 0;
}

//    贝尔曼福特算法：边的存储很简单，只需要定义一个边的结构体，在定义结构体数组。循环n次，每次循环所有边，更新dist（松弛操作）。做完所有操作后，所有a到b权重w的边都满足dist[b]<=dist[a]+w
//                    （三角不等式）
//    求有负权的最短路时，如果有负权回路（一圈的权重和小于0），最短路不一定存在，因为可以在最短路中一直转，减到负无穷再走到终点。而如果最短路中一直转，出来后到不了终点，最短路就存在，所以不一定
//    贝尔曼福特算法可以求出是否存在负权回路，但时间复杂度高一般用SPFA。循环n次，是找到走不超过n条边，到各点的最短距离，如果第n次有更新，说明走到某个点的最短距离大于等于n，上面点的数量最少
//                     是n+1，说明有重点，有环，而这又是更新过的，所以一定是负权环
#include<bits/stdc++.h>
using namespace std;

const int N = 10010, INF = 0x3f3f3f3f, M = 510;
int n, m, k;
int dist[M], backup[M];  //  backup用于备份防止串联
struct edge {
	int a;
	int b;
	int w;
}edges[N];

int bellman_ford()
{
	for (int i = 1; i <= n; i++)dist[i] = INF;
	dist[1] = 0;

	for (int i = 1; i <= k; i++)                       //   题中说不超过  k  条 ，所以循环  k  次
	{
		for (int j = 1; j <= n; j++)backup[j] = dist[j];
		for (int j = 1; j <= m; j++)
		{
			int st = edges[j].a, ed = edges[j].b, we = edges[j].w;
			dist[ed] = min(dist[ed], backup[st] + we);
		}
	}

	if (dist[n] > INF / 2)return 0;           //  不能到的地方原来是最大值，但也有可能在计算的过程中，这个最大值减去了一些负的权值，由题意k = 500，最多经过500条边，每条边10000，
	//                                             所以最多减 5000000，所以不是dist[n] == INF，而是dist[n] > INF / 2表示到达不了
	else return dist[n];
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		edges[i] = { x,y,z };
	}

	int t = bellman_ford();
	if (t)cout << t;
	else cout << "impossible";

	return 0;
}


//    如果用SPFA，图中就不能有负环
#include<bits/stdc++.h>
using namespace std;

const int N = 100010,INF = 0x3f3f3f3f;
int n, m;
int head[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];  //  记录谁在队列里，防止重复

void insert(int x,int y,int z)
{
	e[idx] = y;
	w[idx] = z;
	ne[idx] = head[x];
	head[x] = idx++;
}

int spfa()
{
	for (int i = 1; i <= n; i++)dist[i] = INF;
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	st[1] = true;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;          //  弹出了，不在队列里了
		for (int i = head[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])   //如果应该更新
			{
				dist[j] = dist[t] + w[i];
				if (!st[j])                //  如果没在队列，在就不用管
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	if (dist[n] == INF)return 0;
	else return dist[n];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)head[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		insert(x, y, z);
	}

	int t = spfa();
	if (t)cout << t;
	else cout << "impossible";

	return 0;
}

//   spfa判断是否有负环，需要再多一个cnt数组，记录第i个的最短路的边数
#include<bits/stdc++.h>
using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;
int n, m;
int head[N], e[N], ne[N], w[N], idx;
int dist[N],cnt[N];
bool st[N];  //  记录谁在队列里，防止重复

void insert(int x, int y, int z)
{
	e[idx] = y;
	w[idx] = z;
	ne[idx] = head[x];
	head[x] = idx++;
}

bool spfa()
{
	for (int i = 1; i <= n; i++)dist[i] = INF;       //  判断负环dist可以不初始化，但是洛谷那个模板题需要更新
	dist[1] = 0;
	queue<int> q;
	//q.push(1);       //  题中说要求负环是否存在，但负环不一定从1号点出发就能到，可能从别的点出发才能到，所以一开始要把所有的点都放在队列里
	for (int i = 1; i <= n; i++)q.push(i), st[i] = true;;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;          //  弹出了，不在队列里了
		for (int i = head[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])   //如果应该更新
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n)return true;
				if (!st[j])                //  如果没在队列，在就不用管
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)head[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		insert(x, y, z);
	}

	int t = spfa();
	if (t)cout << "Yes";
	else cout << "No";

	return 0;
}
//floyd算法d[][]一开始用邻接矩阵存储所有边，没有边就无限大，有多重边就保留最短的，有自环因为没有负环所以一定是正的，就不用保留自环
//看是有向图还是无向图，无向图就存两次
//判断是不是无解，是看是否大于INF/2
#include<bits/stdc++.h>
using namespace std;

const int N = 110, INF = 0x3f3f3f3f;
int d[N][N];
int n, m;

void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		d[x][y] = min(d[x][y], z);
		d[y][x] = d[x][y];
	}
	floyd();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << d[i][j] << ' ';
		cout << endl;
	}

	return 0;
}
//最小生成树：
//最小生成树问题对应的图一般是无向图，普利姆（prim）算法（稠密图用朴素版n方，稀疏图用堆优化mlogn，但一般用不到），kruskal算法一般固定mlogm，稀疏图一般用kruskal
//二分图：
//判断是不是二分图：染色法（DFS）O（m+n）
//匈牙利算法求二分图最大匹配O（mn）实际上远小于这个时间

//prim算法迭代n次，因为要放n个点进集合（生成树），和朴素dijkstra相似。
#include<bits/stdc++.h>
using namespace std;

const int N = 5010,INF = 0x3f3f3f3f;
int g[N][N];
int dist[N];
bool st[N];
int n, m;

int prim()
{
	int res= 0;//  生成树中所有边长之和
	for (int i = 1; i <= n; i++)
		dist[i] = INF;                 //  dist初始化
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		if (i && dist[t] == INF) return INF;
		if (i)res += dist[t];
		st[t] = 1;
		for (int j = 1; j <= n; j++)
			dist[j] = min(dist[j], g[t][j]);
	}
	return res;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)g[i][j] = 0;
			else g[i][j] = INF;
		}
	}                              //  g初始化
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		g[x][y] = min(g[x][y], z);
		g[y][x] = g[x][y];
	}
	int t = prim();
	if (t == INF)cout << "orz" << endl;
	else cout << t << endl;

	return 0;
}
//kruskal算法
//将所有边根据权从小到大排序，枚举每一条边a到b权重c，如果当前ab不连通，将ab加入集合中

//   需要p数组（并查集），需要  edge结构体数组 ，需要排序

#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int p[N];
int n, m;
struct edge{
	int a, b, w;
}edges[2*N];

bool cmp(edge a, edge b)
{
	if (a.w < b.w)return true;
	else return false;
}

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges[i] = { a,b,w };  //  无向边也存一个
	}
	sort(edges + 1, edges + m + 1, cmp);
	for (int i = 1; i <= n; i++)p[i] = i;
	int res = 0, cnt = 0;//  分别记录边一共多长，有多少个边
	for (int i = 1; i <= m; i++)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		a = find(a);
		b = find(b);
		if (a != b)
		{
			p[a] = b;
			res += w;
			cnt++;               //   判断是否是n-1个，能不能建成
		}
	}
	if (cnt < n - 1)cout << "impossible" << endl;
	else cout << res << endl;

	return 0;
}
//  染色法判断一个图是不是二分图：
//  一个图是二分图 图中不含奇数环，不含奇数环一定是二分图
//  如果染色法染色过程中出现矛盾，说明有奇数环，不是二分图，如果没有矛盾，说明没奇数环，是二分图。
//  循环遍历所有点，如果一个点没有被染色，就dfs把这个点所在连通块中的点都染色

//  最小生成树里都是无向图，但这里无向图和有向图都有，无向图存储时如果稀疏图拿链表存储，记得开两倍大小
#include<bits/stdc++.h>
using namespace std;

const int N = 100010, M = 200010;
int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool dfs(int x, int c)
{
	color[x] = c;

	for (int i = h[x]; i != -1; i = ne[i])
	{
		int j = e[i];//5%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%注意int j = e[i]，再用j去做
		if (!color[j])
		{
			if (!dfs(j, 3 - c))
			{
				return false;
			}
		}                         //  注意这种情况如果不加大括号，会认为else if和第二个if配对
		else if (color[j] == c)
			return false;
	}
	return true;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		add(u, v), add(v, u);
	}
	bool flag = true;                  //  是否矛盾
	for (int i = 1; i <= n; i++)
	{
		if (!color[i])
		{
			if (!dfs(i, 1))
			{
				flag = false;
				break;
			}
		}
	}
	if (flag)cout << "Yes" << endl;         
	else cout << "No" << endl;

	return 0;
}
//匈牙利算法:
//O（mn），但往往远小于这个复杂度
// 二分图最大匹配，最多能有多少条边，任意两条边都不连同一个点
// 遍历所有男生，待字闺中，据为己有，名花有主，求他放手
//    存边的时候  只用存  左边指向右边的边，因为要遍历左边点所有出边，用邻接表更方便

//   **  数组越界什么错误都有可能发生，可能segmentation fault也可能TLE等等
//左半部包含 n1个点（编号 1∼n1），右半部包含 n2个点（编号 1∼n2）
#include<bits/stdc++.h>
using namespace std;

const int N = 510, M = 100010;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool Find(int x)
{
	for (int i = h[x]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			st[j] = 1;
			if (!match[j] || Find(match[j]))
			{
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	cin >> n1 >> n2 >> m;
	for (int i = 1; i <= n1; i++)
		h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	int ans = 0;
	for (int i = 1; i <= n1; i++)
	{
		for (int j = 1; j <= n2; j++)
			st[j] = 0;
		if (Find(i))
			ans++;
	}
	cout << ans;

	return 0;
}

// 拓扑排序：-
