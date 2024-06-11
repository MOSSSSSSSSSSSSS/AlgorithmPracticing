
//  有向无环图 ， 注意一种特殊情况，有两个入度为0的点，一个出度为0的点一条链
//  如果先搜其中一个入度为0的点，结果加1，再搜另一个入度为0的点，由于有vis数组，搜不过去了
//  结果还是1，错误。因此不能有vis数组，但这样造成重复搜索，会TLE，因此再记忆化搜索

#include<bits/stdc++.h>
using namespace std;

const int N = 5010, M = 500010,P = 80112002;
int h[N], e[M], ne[M], idx;
int n, m;
int din[N], dout[N];
set<int> chudu;
vector<int> rudu;
int num[N];
int ans;

void dfs(int u)
{
	int cnt = 0;
	if (chudu.count(u))
	{
		cnt = (cnt + 1)%P;
		num[u] = cnt;
		return;
	}
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if(num[j]==0)dfs(j);
		num[u] = (num[j] + num[u])%P;
	}
}

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		din[b]++;
		dout[a]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (din[i] == 0)rudu.push_back(i);
		if (dout[i] == 0)chudu.insert(i);
	}
	for (auto node : rudu)
		dfs(node);
	for (auto node : rudu)
		ans = (ans + num[node]) % P;
	cout << ans;

	return 0;
}