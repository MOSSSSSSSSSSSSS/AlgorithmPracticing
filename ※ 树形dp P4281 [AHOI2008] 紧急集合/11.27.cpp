

//  倍增lca ：可以有st数组防止TLE，下面的等于号不要漏写

// 猜结论的题，容易想到lca，两两求lca，共三个，发现一定有至少两个lca相同，一个不同，那么不同的那个是答案
//           三个相同就是初始地点三个重合，直接有答案

//  加了ios::sync.....和cin.tie(nullptr)就不TLE了，否则两个点TLE

#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int h[N], e[N*2], ne[N*2], idx;
int n, m;
int dep[N], fa[N][20];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs(int u, int father)
{
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for (int i = 1; i < 20; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != father)dfs(j, u);
	}
}
int lca(int a, int b)
{
	if (dep[a] < dep[b])
		swap(a, b);
	for (int i = 19; i >= 0; i--)
		if (dep[fa[a][i]] >= dep[b])       //!!!!等于号不要漏写，等于也可以转移!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
			a = fa[a][i];
	if (a == b)return a;
	for (int i = 19; i >= 0; i--)
		if (fa[a][i] != fa[b][i])
			a = fa[a][i], b = fa[b][i];
	return fa[a][0];
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for(int i = 1;i<=n-1;i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs(1, 0);
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b && b == c)
		{
			cout << a << ' ' << 0 << '\n';
			continue;
		}
		int lca1 = lca(a, b), lca2 = lca(a, c), lca3 = lca(b,c);
		//cout << "%%%" << lca1 << ' ' << lca2 << ' ' << lca3 << endl;
		if (lca1 == lca2)
		{
			cout << lca3 << ' ';
			int d1 = dep[b] - dep[lca3] - dep[lca3] + dep[c];
			int lca4 = lca(lca3, a);
			cout << d1 + dep[lca3] + dep[a] - dep[lca4] * 2 << '\n';
		}
		else if (lca1 == lca3)
		{
			cout << lca2 << ' ';
			int d1 =  -dep[lca2] + dep[a] - dep[lca2] + dep[c];
			int lca4 = lca(lca2, b);
			cout << d1 + dep[lca2] + dep[b] - dep[lca4] * 2 << '\n';
		}
		else if (lca2 == lca3)
		{
			cout << lca1 << ' ';
			int d1 = -dep[lca1] + dep[a] - dep[lca1] + dep[b];
			int lca4 = lca(lca1, c);
			cout << d1 + dep[lca1] + dep[c] - dep[lca4] * 2 << '\n';
		}
	}

	return 0;
}