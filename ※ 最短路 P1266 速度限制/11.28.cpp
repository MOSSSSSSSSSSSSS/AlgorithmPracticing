

//  首先注意到 数据范围比普通的最短路要异常的  小
//  二维dist数组dist[i][j]表示以速度j到达i的最短时间  ，因为需要到一个点的速度，所以第二维是速度
//  二维vis数组同理

#include<bits/stdc++.h>
using namespace std;

typedef pair<double, pair<int, int>> PII;
const int N = 160, M = 25600, K = 510;
const double INF = 1e9;
int h[N], e[M], ne[M], l[M], v[M], idx;
int n, m, D;
bool vis[N][K];
double dist[N][K];
pair<int, int> path[N][K];        //  路径
double ans = INF;
int ansv;
vector<int> res;

void add(int a, int b, int c, int d)
{
	e[idx] = b;
	v[idx] = c;
	l[idx] = d;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dijkstra()
{
	memset(dist, 0x7f, sizeof dist);
	dist[0][70] = 0;
	priority_queue<PII, vector<PII>, greater<PII> >heap;
	heap.push({ dist[0][70],{0,70} });
	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();
		int ver = t.second.first, old_v = t.second.second;
		double distance = t.first;
		if (vis[ver][old_v])continue;
		vis[ver][old_v] = true;
		for (int i = h[ver]; ~i; i = ne[i])
		{
			int j = e[i];
			if (v[i] == 0)
			{
				if (dist[j][old_v] > distance + (double(l[i])) / old_v)
				{
					dist[j][old_v] = distance + (double(l[i])) / old_v;
					heap.push({ dist[j][old_v],{j,old_v } });
					path[j][old_v] = { ver,old_v };
				}
			}
			else
			{
				if (dist[j][v[i]] > distance + (double(l[i])) / v[i])
				{
					dist[j][v[i]] = distance + (double(l[i])) / v[i];
					heap.push({ dist[j][v[i]],{j,v[i]} });
					path[j][v[i]] = { ver,old_v };
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(h, -1, sizeof h);
	cin >> n >> m >> D;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		add(a, b, c, d);
	}
	dijkstra();
	for (int i = 1; i < K; i++)
		if (dist[D][i] < ans && dist[D][i] != 0)
			ans = dist[D][i], ansv = i;
	for (pair<int, int> i = path[D][ansv]; i.first != 0; i = path[i.first][i.second])
		res.push_back(i.first);
	cout << 0 << ' ';
	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i] << ' ';
	cout << D;

	return 0;
}