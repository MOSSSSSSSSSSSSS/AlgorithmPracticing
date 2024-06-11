/*
#include<bits/stdc++.h>
using namespace std;

const int N = 2e4 + 10, M = 2e5 + 10;
int h[N], e[M], ne[M], idx;
int n, m;
int dfn[N], low[N], timestamp;
int root;
priority_queue<int,vector<int>, greater<int>> cut;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void tarjan(int u)
{
	int cnt = 0;
	/*if (u == root && h[u] == -1)
	{
		cut.push(u);
		return;
	}  //单独一个点不是割点，是点双
	dfn[u] = low[u] = ++timestamp;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
			if (low[j] >= dfn[u])
				cnt++;
		}
		else low[u] = min(dfn[j], low[u]);
	}
	if (u != root && cnt)cut.push(u);
	else if (u == root && cnt > 1)cut.push(u);
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == b)continue;
		add(a, b), add(b, a);
	}
	for (root = 1; root <= n; root++)
		if (!dfn[root])
			tarjan(root);
	cout << cut.size() << '\n';
	while (cut.size())
	{
		cout << cut.top() <<' ';
		cut.pop();
	}

	return 0;
}

*/
/*
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int, int>> PII;
const int N = 5e3 + 10, M = 3e5 + 10;
int n, m, l, base;
int h[N], e[M], ne[M], w[M], col[M], idx;
int dist[N][70];
bool st[N][70];
priority_queue<PII, vector<PII>, greater<PII> >q;
int ans = 1e8;

void add(int a, int b, int c, int d)
{
	e[idx] = b;
	w[idx] = d;
	col[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	for (int i = 1; i <= l; i++)
		dist[1][i] = 0, q.push({ dist[1][i],{1, i}});
	while (q.size())
	{
		PII t = q.top();
		q.pop();
		int ver = t.second.first, distance = t.first, c = t.second.second;
		if (st[ver][c])continue;
		st[ver][c] = true;
		for (int i = h[ver]; ~i; i = ne[i])
		{
			int j = e[i];
			if (col[i] == c)
			{
				if (dist[j][c] > distance + w[i])
				{
					dist[j][c] = distance + w[i];
					q.push({ dist[j][c],{j,c} });
				}
			}
			else
			{
				if (dist[j][c] > distance + w[i] * base)
				{
					dist[j][c] = distance + w[i] * base;
					q.push({ dist[j][c],{j,col[i]}});
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(h, -1, sizeof h);
	cin >> n >> m >> l >> base;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		add(a, b, c, d);
	}
	dijkstra();
	for (int i = 1; i <= l; i++)
		ans = min(ans, dist[n][i]);
	cout << ans;

	return 0;
}*/
/*

#include<bits/stdc++.h>
using namespace std;

const int N = 110, INF = 1e9;
int a[N][N], F, V;
int ans = -INF;
int pos[N];
int anss[N];
int b[N][N];

void dfs(int hang, int lie, int sum)
{
	if (hang == F + 1)
	{
		if (sum > ans)
		{
			ans = sum;
			memcpy(anss, pos, sizeof pos);
		}
		return;
	}
	for (int i = lie;i<=V;i++)
	{
		sum += a[hang][i];
		if (sum <= b[hang][i])
		{
			sum -= a[hang][i];
			continue;
		}
		else b[hang][i] = sum;
		pos[hang] = i;
		dfs(hang + 1, i + 1, sum);
		sum -= a[hang][i];
		pos[hang] = 0;
	}
}

int main()
{
	cin >> F >> V;
	for (int i = 1; i <= F; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			cin >> a[i][j];
			b[i][j] = -INF;
		}
	}
	dfs(1, 1, 0);
	cout << ans << '\n';
	for (int i = 1; i <= F; i++)
		cout << anss[i] << ' ';

	return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int x1, yyy1, x2, yyy2;
int n, m;
bool mg[N][N];
int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { 1, 0, 0, -1 };
int dist[N][N][4];
int tim[N][N][4];      //////////////////////////////////////     必须把方向也作为一个状态，并且都要有这个方向的状态

void bfs(int time)
{
	memset(dist, -1, sizeof dist);
	queue<pair<pair<int, int>, pair<int, int>>> q;
	for (int i = 0; i < 4; i++)
	{
		int x = x1 + dx[i], y = yyy1 + dy[i];
		if (mg[x][y])q.push({ {x,y},{i,1} }), dist[x][y][i] = 1, tim[x][y][i] = 1;
	}
	while (q.size())
	{
		int x = q.front().first.first, y = q.front().first.second;
		int idx = q.front().second.first, t = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx > n || ny > m || nx < 1 || ny < 1) continue;
			if (nx == x1 && ny == yyy1)continue;
			if (mg[nx][ny] == 1)
			{
				if (idx == i)
				{
					if(dist[nx][ny][i] == -1 || dist[nx][ny][i] != -1 && tim[nx][ny][i] < t + 1)q.push({{nx, ny}, {idx, t + 1}});
					dist[nx][ny][i] = dist[x][y][i] + 1;
					tim[nx][ny][i] = t + 1;
					if (nx == x2 && ny == yyy2)return;
				}
				else if(t >= time)
				{
					if (dist[nx][ny][i] == -1 || dist[nx][ny][i] != -1 && tim[nx][ny][i] < 1)q.push({ {nx, ny}, {i, 1} });
					dist[nx][ny][i] = dist[x][y][idx] + 1;
					tim[nx][ny][i] = 1;
					if (nx == x2 && ny == yyy2)return;
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m >> x1 >> yyy1 >> x2 >> yyy2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> mg[i][j];
	for (int i = 1; i <= 10; i++)
	{
		bool flag = false;
		bfs(i);
		for(int j = 0;j<4;j++)
			if(dist[x2][yyy2][j] != -1)
			{
				flag = true;
				cout << i << ' ' << dist[x2][yyy2][j] << '\n';
				break;
			}
		if (flag)continue;
		else return 0;
	}

	return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int n;
int a[N][N];
bool st[N][N];
int ans1, ans2;
int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[8] = { -1, 0, 1, 1, -1, -1, 0, 1 };

int bfs(int x, int y)
{
	st[x][y] = true;
	int res = -1;
	queue<pair<int, int>> q;
	q.push({ x, y });
	while (q.size())
	{
		int xx = q.front().first, yy = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = xx + dx[i], ny = yy + dy[i];
			if (nx<1 || nx>n || ny<1 || ny>n)continue;
			if (st[nx][ny])
			{
				if (a[nx][ny] > a[xx][yy] && res != 0)
				{
					if (res == 1)res = 0;
					else if (res == -1)res = 2;
				}
				else  if (a[nx][ny] < a[xx][yy] && res != 0)
				{
					if (res == 2)res = 0;
					else if (res == -1)res = 1;
				}
			}
			else
			{
				if (a[nx][ny] == a[xx][yy])
				{
					q.push({ nx, ny });
					st[nx][ny] = true;
				}
				else if (a[nx][ny] > a[xx][yy] && res != 0)
				{
					if (res == 1)res = 0;
					else if (res == -1)res = 2;
				}
				else  if (a[nx][ny] < a[xx][yy] && res != 0)
				{
					if (res == 2)res = 0;
					else if (res == -1)res = 1;
				}
			}
		}
	}
	return res;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!st[i][j])
			{
				int res = bfs(i, j);
				if (res == 1)ans1++;
				else if(res == 2)ans2++;
				else if (res == -1)
				{
					cout << 1 << ' ' << 1;
					return 0;
				}
			}
	cout << ans1 << ' ' << ans2;

	return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 50010, M = 200010;
int n, m, k;
int h[N], e[M], ne[M],w[M], idx;
bool ok[N];
int x, y;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dijkstra1()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push({ dist[1],1 });
	while (q.size())
	{
		PII t = q.top();
		q.pop();
		int ver = t.second, distance = t.first;
		if (st[ver])continue;
		st[ver] = true;
		for (int i = h[ver]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				q.push({ dist[j],j });
			}
		}
	}
}
void dijkstra2()
{
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push({ dist[1],1 });
	while (q.size())
	{
		PII t = q.top();
		q.pop();
		int ver = t.second, distance = t.first;
		if (st[ver])continue;
		st[ver] = true;
		for (int i = h[ver]; ~i; i = ne[i])
		{
			int j = e[i];
			if (ok[j])continue;
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				q.push({ dist[j],j });
			}
		}
	}
}
void dijkstra3()
{
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	dist[x] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push({ dist[x],x });
	while (q.size())
	{
		PII t = q.top();
		q.pop();
		int ver = t.second, distance = t.first;
		if (st[ver])continue;
		st[ver] = true;
		for (int i = h[ver]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				q.push({ dist[j],j });
			}
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++)
	{
		int x;
		cin >> x;
		ok[x] = true;
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	cin >> x >> y;
	dijkstra1();
	int ans1 = dist[x], ans2 = dist[y];
	dijkstra3();
	int ans7 = dist[y] + min(ans1, ans2);
	dijkstra2();
	int ans3 = dist[x], ans4 = dist[y];
	int ans5 = max(ans1, ans4);
	int	ans6 = max(ans2, ans3);
	cout << min(min(ans5, ans6), ans7);

	return 0;
}*/
/*
   //  区间修改需要懒标记，就是当前区间已经修改，下面区间没有修改的记号，并记录下面区间需要如何修改
#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
#define int long long
const int N = 1e5 + 20;
int n, h;
int x0, yyy0, temp;
int ch[N][2];
int f[N][2];
vector<int> alls;
int st;
struct node {
	int l, r, v;
	int tag;
}tr[8*N];
struct wood {
	int h, l, r;
}woods[N];

bool cmp(wood a, wood b)
{
	return a.h < b.h;
}
int find(int x)
{
	return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)return;
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
}
void pushdown(int u)
{
	if (tr[u].tag != 0)
	{
		tr[ls].v = tr[ls].tag = tr[u].tag;
		tr[rs].v = tr[rs].tag = tr[u].tag;
		tr[u].tag = 0;                             //  清零
	}
}
void modify(int u, int l, int r, int x)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		tr[u].v = x;
		tr[u].tag = x;
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(ls, l, r, x);
	if (r >= mid + 1)modify(rs, l, r, x);
}
int query(int u, int x)
{
	if (tr[u].l == tr[u].r)return tr[u].v;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (x <= mid)return query(ls, x);
	else return query(rs, x);
}

signed main()
{
	memset(f, 0x3f, sizeof f);
	cin >> n >> h >> x0 >> yyy0;
	for (int i = 1; i <= n; i++)
	{
		int h, l, r;
		cin >> h >> l >> r;
		woods[i].h = h, woods[i].l = l, woods[i].r = r, alls.push_back(woods[i].l), alls.push_back(woods[i].r);
	}
	alls.push_back(x0);
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	sort(alls.begin(), alls.end());
	sort(woods + 1, woods + n + 1, cmp);
	build(1, 1, 2*N);
	temp = find(x0);
	for (int i = 1; i <= n; i++)
	{
		int l = find(woods[i].l), r = find(woods[i].r), h = woods[i].h;
		if (h > yyy0)break;
		ch[i][0] = query(1, l);
		ch[i][1] = query(1, r); 
		modify(1, l, r, i);
		st = query(1, temp);
	}
	for (int i = 1; i <= st; i++)
	{
		if (ch[i][0] && woods[i].h - woods[ch[i][0]].h <= h)f[i][0] = min(f[ch[i][0]][0] + woods[i].h - woods[ch[i][0]].h + woods[i].l - woods[ch[i][0]].l, f[ch[i][0]][1] + woods[i].h - woods[ch[i][0]].h + woods[ch[i][0]].r - woods[i].l);
		else if (ch[i][0] == 0 && woods[i].h <= h)f[i][0] = woods[i].h;
		if (ch[i][1] && woods[i].h - woods[ch[i][1]].h <= h)f[i][1] = min(f[ch[i][1]][0] + woods[i].h - woods[ch[i][1]].h + woods[i].r - woods[ch[i][1]].l, f[ch[i][1]][1] + woods[i].h - woods[ch[i][1]].h + woods[ch[i][1]].r - woods[i].r);
		else if (ch[i][1] == 0 && woods[i].h <= h)f[i][1] = woods[i].h;
	}
	cout << min(f[st][0] + x0 - woods[st].l, f[st][1] + woods[st].r - x0) + yyy0 - woods[st].h;

	/*for (int i = 1; i <= n; i++)
	{
		cout << "###" << find(woods[i].l) << ' ' << find(woods[i].r) << '\n';
	}
	for (int i = 1; i <= n; i++)
	{
		cout << "$$$" << ch[i][0] << ' ' << ch[i][1];

	}

	return 0;
}*/

/*
#include<bits/stdc++.h>
using namespace std;

typedef pair<double, int> PII;
const int N = 410, M = 2 * N * N, INF = 1e9;
int n;
int h[N], e[M], ne[M], idx;
double w[M];
double dist[N];
bool st[N];
struct city {
	int railway;
	pair<int, int> node[4];
}citys[110];
void get4(city &c)            ///////////////////////////////////   如何求第四个点，矩形
{
	int x1 = c.node[0].first, y1 = c.node[0].second;
	int x2 = c.node[1].first, y2 = c.node[1].second;
	int x3 = c.node[2].first, y3 = c.node[2].second;
	int ab = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	int ac = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
	int bc = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
	if (ab == ac + bc)c.node[3].first = x1 + x2 - x3, c.node[3].second = y1 + y2 - y3;
	else if(ac == ab + bc)c.node[3].first = x1 + x3 - x2, c.node[3].second = y1 + y3 - y2;
	else if(bc == ab + ac)c.node[3].first = x3 + x2 - x1, c.node[3].second = y3 + y2 - y1;
}
double juli(int x1,int y1,int x2,int y2) { return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));}
void add(int a, int b, double c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
double dijkstra(int start,int ed)
{
	memset(dist, 0x7f, sizeof dist); ////////////////////////////////////////    double赋极大值一定是0x7f

	memset(st, 0, sizeof st);
	dist[start] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push({ dist[start],start });
	while (q.size())
	{
		PII t = q.top();
		q.pop();
		int ver = t.second;
		double distance = t.first;
		if (st[ver])continue;
		st[ver] = true;
		for (int i = h[ver]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				q.push({ dist[j],j });
			}
		}
	}
	return dist[ed];
}

int main()
{
	cin >> n;
	while (n--)
	{
		memset(h, -1, sizeof h);
		idx = 0;
		int S, t, A, B;
		double ans = INF;
		cin >> S >> t >> A >> B;
		for (int i = 1; i <= S; i++)
		{
			for (int j = 0; j < 3; j++)
				cin >> citys[i].node[j].first >> citys[i].node[j].second;
			cin >> citys[i].railway;
			get4(citys[i]);
		}
		for (int i = 1; i <= S * 4; i++)
		{
			for (int j = 1; j <= S * 4; j++)
			{
				if (i != j)
				{
					if (((i - 1) / 4) == ((j - 1) / 4))
					{
						int k = (i - 1) / 4 + 1;
						int a = (i - 1) % 4, b = (j - 1) % 4;
						double distance = juli(citys[k].node[a].first,citys[k].node[a].second,citys[k].node[b].first,citys[k].node[b].second);
						add(i, j, distance * citys[k].railway);
						//cout << "@@@" << distance * citys[k].railway << '\n';
					}
					else
					{
						int k1 = (i - 1) / 4 + 1;
						int k2 = (j - 1) / 4 + 1;
						int a = (i - 1) % 4, b = (j - 1) % 4;
						double distance = juli(citys[k1].node[a].first, citys[k1].node[a].second, citys[k2].node[b].first, citys[k2].node[b].second);
						add(i, j, distance * t);
						//cout << "@@@" << distance * t << '\n';
					}
				}
			}
		}
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 1; j <= 4; j++)
			{
				/*int d = dijkstra((A - 1) * 4 + i, (B - 1) * 4 + j);
				cout << d << "@@@" << '\n';
				ans = min(ans, dijkstra((A - 1) * 4 + i,(B - 1) * 4 + j));
			}
		}
		printf("%.1lf", ans);
	}

	return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;

int n, sum;
int arr[20];
int yh[20][20];

int res(int arr[])
{
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += yh[n - 1][i] * arr[i];
	return ans;
}
void getyh()
{
	yh[1][1] = 1, yh[1][2] = 1;
	for(int i = 2;i<=15;i++)
		for (int j = 1; j <= i + 1; j++)
		{
			if (j == 1)yh[i][j] = 1;
			else if (j == i + 1)yh[i][j] = 1;
			else yh[i][j] = yh[i - 1][j - 1] + yh[i - 1][j];
		}
}

int main()
{
	getyh();
	cin >> n >> sum;
	for (int i = 1; i <= n; i++)
		arr[i] = i;
	do {
		if (res(arr) == sum)
		{
			for (int i = 1; i <= n; i++)
				cout << arr[i] << ' ';
			return 0;
		}
	} while (next_permutation(arr + 1, arr + 1 + n));

	return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 210;
int n, A, B;
int K[N];
int ans[N];
queue<int> q;
bool st[N];

int main()
{
	cin >> n >> A >> B;
	for (int i = 1; i <= n; i++)
		cin >> K[i];
	q.push(A);
	ans[A] = 0;
	st[A] = true;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		if (t - K[t] >= 1 && !st[t-K[t]])
		{
			st[t - K[t]] = true;
			ans[t - K[t]] = ans[t] + 1;
			q.push(t - K[t]);
			if (t - K[t] == B)break;
		}
		if (t + K[t] <= n && !st[t+K[t]])
		{
			st[t + K[t]] = true;
			ans[t + K[t]] = ans[t] + 1;
			q.push(t + K[t]);
			if (t + K[t] == B)break;
		}
	}
	if (st[B])cout << ans[B];
	else cout << -1;

	return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 1010, dx[4] = { 0, 1, -1, 0 }, dy[4] = {1, 0, 0, -1};
int n, m;
char mg[N][N];
int sum[N * N];
int ltk[N][N], idx;

void bfs(int x, int y)
{
	ltk[x][y] = idx;
	queue<pair<int, int>> q;
	q.push({ x, y });
	sum[idx]++;
	while (q.size())
	{
		int ox = q.front().first, oy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = ox + dx[i], ny = oy + dy[i];
			if (nx >= 1 && ny >= 1 && nx <= n && ny <= n&&!ltk[nx][ny])
			{
				if (mg[nx][ny] == '0'&& mg[ox][oy] == '1'|| mg[nx][ny] == '1' && mg[ox][oy] == '0')
				{
					ltk[nx][ny] = idx;
					q.push({ nx, ny });
					sum[idx]++;
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> mg[i][j];
	for(int i = 1;i<=n;i++)
		for (int j = 1; j <= n; j++)
		{
			if (!ltk[i][j])
			{
				idx++;
				bfs(i, j);
			}
		}
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		cout << sum[ltk[a][b]] << '\n';
	}

	return 0;
}
*/
/*
//  带权树的重心
#include<bits/stdc++.h>
using namespace std;

const int N = 110, M = 2*N, INF= 1e9;
int h[N], e[M], ne[M], idx;
int n;
int f[N], sz[N], num[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs(int u, int fa)
{
	sz[u] = num[u];
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != fa)
		{
			dfs(j, u);
			sz[u] += sz[j];
			f[u] += f[j];
			f[u] += sz[j];
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		num[i] = a;
		if (b)add(i, b), add(b, i);
		if (c)add(i, c), add(c, i);
	}
	dfs(1, 0);
	int ans = f[1];
	memset(f, 0, sizeof f);
	f[1] = ans;
	queue<int> q;
	q.push(1);
	while (q.size())
	{
		int t = q.front();
		q.pop();
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (!f[j])
			{
				f[j] = f[t] + sz[1] - 2 * sz[j];
				ans = min(ans, f[j]);
				q.push(j);
			}
		}
	}
	cout << ans;

	return 0;
}*/
/*
// （必须手写）单调队列
#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
int n, m;
int a[N];
int q[N], hh, tt = -1;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	cout << 0 << '\n';
	for (int i = 1; i < n; i++)
	{
		while (hh <= tt && a[i] <= a[q[tt]])tt--;
		q[++tt] = i;
		if (hh <= tt && i - m + 1 > q[hh])hh++;
		cout << a[q[hh]] << '\n';
	}

	return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;

int l, r;
int ans;

int main()
{
	cin >> l >> r;
	int len = r - l + 1;
	if (len % 2 == 0)ans += len / 2;
	else
	{
		if (l % 2 == 0)ans += (len - 1) / 2;
		else ans += (len + 1) / 2;
	}
	ans += (r / 4 - (l - 1) / 4);
	cout << ans;
	
	return 0;
}
*/

// 区间dp
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 5010;
string num;
int ans;
bool dp[N][N];

int main()
{
	cin >> num;
	int length = num.size();
	for (int len = 2; len <= length; len++)
	{
		for (int l = 0; l + len - 1 <= length - 1; l++)
		{
			if (num[l] > num[l + len - 1])dp[l][l + len - 1] = 1, ans++;
			else if (num[l] < num[l + len - 1])dp[l][l + len - 1] = 0;
			else if (dp[l + 1][l + len - 2])dp[l][l + len - 1] = 1, ans++;
		}
	}
	cout << ans;

	return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
const int N = 1e5 + 10, INF = 1e9;
int n;
int a[N];
int cnt;
struct node {
	int l, r, g;
}tr[4*N];

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}
void pushup(int u)
{
	tr[u].g = gcd(tr[ls].g, tr[rs].g);
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		tr[u].g = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(u);
}
int query(int u, int l, int r)
{
	if (l <= tr[u].l && tr[u].r <= r)return tr[u].g;
	int mid = tr[u].l + tr[u].r >> 1;
	int res = 0;
	if (l <= mid)res = gcd(res, query(ls, l, r));
	if (r >= mid + 1)res = gcd(res, query(rs, l, r));
	return res;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 1)cnt++;
	}
	if (cnt)
	{
		cout << n - cnt;
		return 0;
	}
	build(1, 1, n);
	int l = 1, r = 2;
	cnt = INF;
	while (l<=r&&r<=n)
	{
		if (query(1, l, r) == 1)
		{
			cnt = min(cnt, r - l);
			l++;
		}
		else
		{
			r++;
		}
	}
	if (cnt == INF)cout << -1;
	else cout << cnt + n - 1;

	return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int n, t, a[N];
int l = 1, r = N;

bool check(int mid)
{
	int sum = 0, idx = mid + 1;
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 1; i <= mid && i <= n; i++)q.push(a[i]);
	while (q.size())
	{
		int t = q.top();
		int cnt = 0;
		while (q.size()&&q.top() == t)
		{
			q.pop();
			cnt++;
		}
		sum = t;
		for (; idx <= n && cnt; idx++)
		{
			q.push(a[idx] + t);
			cnt--;
		}
	}
	if (sum <= t)return true;
	else return false;
}

int main()
{
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	cout << l;

	return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, k;
char a[N];
vector<int> b;
int l, r;

bool check(int mid)
{
	int sum = 0;
	for (auto x : b)
	{
		sum += (x +1)/ (mid + 1) - 1;
	}
	if (sum <= k)return true;
	else return false;
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	char now = a[1];
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == now)
		{
			cnt++;
		}
		else
		{
			b.push_back(cnt);
			cnt = 1;
			now = a[i];
		}
	}
	b.push_back(cnt);
	l = 1, r = n;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	cout << l;

	return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 200, M = 20000;
int n, m;
int h[N], e[M], ne[M], idx;
double w[M];
pair<int, int> pos[N];
int path[N], backup[N];
double dist[N];
bool st[N];
double ans = 1e8;

void add(int a, int b, double d)
{
	e[idx] = b;
	w[idx] = d;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dijkstra(int a, int b)
{
	memset(st, 0, sizeof st);
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>> > q;
	memset(dist, 0x7f, sizeof dist);
	dist[1] = 0;
	q.push({ dist[1], 1 });
	while (q.size())
	{
		pair<double, int> t = q.top();
		q.pop();
		int ver = t.second; double distance = t.first;
		if (st[ver])continue;
		st[ver] = true;
		for (int i = h[ver]; ~i; i = ne[i])
		{
			int j = e[i];
			if (ver == a && j == b || ver == b && j == a)continue;
			if (dist[j] > distance + w[i])
			{
				path[j] = ver;
				dist[j] = distance + w[i];
				q.push({ dist[j], j });
			}
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> pos[i].first >> pos[i].second;
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		double d = sqrt((pos[a].first - pos[b].first) * (pos[a].first - pos[b].first) + (pos[a].second - pos[b].second) * (pos[a].second - pos[b].second));
		add(a, b, d), add(b, a, d);
	}
	dijkstra(-1, -1);
	memcpy(backup, path, sizeof path);
	for (int i = n; i != 1; i = backup[i])
	{
		dijkstra(i, path[i]);
		ans = min(ans, dist[n]);
	}
	cout << ans;

	return 0;
}*/
/*
#include<iostream>
using namespace std;

const int N = 110;
int f[N][N];

int main()
{
	int m, n; // m行n列
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0)
				f[i][j] = 1;
			else
				f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	}
	cout << f[m - 1][n - 1];

	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int maxSum(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size();
	int n = nums2.size();
	long long best1 = 0, best2 = 0;
	int i = 0, j = 0;
	while (i < m || j < n) {
		if (i < m && j < n) {
			if (nums1[i] < nums2[j]) {
				best1 += nums1[i];
				++i;
			}
			else if (nums1[i] > nums2[j]) {
				best2 += nums2[j];
				++j;
			}
			else {
				long long best = max(best1, best2) + nums1[i];
				best1 = best2 = best;
				++i;
				++j;
			}
		}
		else if (i < m) {
			best1 += nums1[i];
			++i;
		}
		else if (j < n) {
			best2 += nums2[j];
			++j;
		}
	}
	return max(best1, best2) % mod;
}


int main()
{
	vector<int> nums1;
	vector<int> nums2;
	int n1, n2;
	cin >> n1 >> n2;
	for (int i = 1; i <= n1; i++)
	{
		int x;
		cin >> x;
		nums1.push_back(x);
	}
	for (int i = 1; i <= n2; i++)
	{
		int x;
		cin >> x;
		nums2.push_back(x);
	}
	cout << maxSum(nums1, nums2);

	return 0;
}