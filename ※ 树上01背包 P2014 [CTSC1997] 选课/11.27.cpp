/*给定一棵n个节点的有根树，编号为1到n,1, 
 号点为根节点且每个节点 有价值，体积。背包容量为，在满足如果某节点选了，则其所有祖先 
 都要选的限制下，使选择的物品组合总价值和最大。*/

/*我们定义泛化物品为没有固定的费用（体积）和价值，价值与费用（体积）成函数关系的物品。泛化物品可以用一个一维数组 
 来描述，其中 f [i] 意义为在体积为i时泛化物品的最大价值。*/

//  这题是个森林，可以用0把所有根节点连起来，变成一棵树

#include<bits/stdc++.h>
using namespace std;

const int N = 310;
int f[N][N][N];
int n, m;
int h[N], e[N], ne[N], idx;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs(int u)
{
	for (int i = h[u]; ~i; i = ne[i])
		dfs(e[i]);
	for (int i = h[u]; ~i; i = ne[i])
		for (int j = m + 1; j >= 1; j--)
			for (int k = 0; k <= j - 1; k++)
				f[u][j] = max(f[u][j], f[u][j - k] + f[e[i]][k]);
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, i),f[i][1] = b;       //  f[i][w[i]] = v[i]
	}
	dfs(0);
	cout << f[0][m + 1];

	return 0;
}