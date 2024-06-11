

//事先知道每个题的锦囊，所以可以按照最优策略分配，即if (!match[j] || dfs(match[j]))，
//但是答错题后立即淘汰，即匹配失败break

#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int h[N], e[2 * N], ne[2 * N], idx;
int n, m;
int st[N],timestamp;
int match[N];
int match2[N];
int ans;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
bool dfs(int u)
{
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (st[j] != timestamp)
		{
			st[j] = timestamp;
			if (!match[j] || dfs(match[j]))
			{
				match[j] = u;
				match2[u] = j;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == b)
		{
			a++;
			add(i, a);
		}
		else
		{
			a++, b++;
			add(i, a), add(i, b);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		timestamp = i;
		if (dfs(i))ans++;
		else break;
	}
	cout << ans << '\n';
	for (int i = 1; i <= m; i++)
		if (match2[i])
			cout << match2[i] - 1 << '\n';

	return 0;
} 