

//本题要求求的就是瓶颈MST，即最大边权最小的生成树。有个定理：一棵最小生成树必定是一棵最小瓶颈生成树。所以我们直接做一遍最小生成树即可


#include<bits/stdc++.h>
using namespace std;

const int N = 8010;
int n, m;
struct edge {
	int a, b, c;
}edges[N];
int p[N];
int ans,cnt;

bool cmp(edge a, edge b)
{
	return a.c < b.c;
}
int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[i].a = a, edges[i].b = b, edges[i].c = c;
	}
	sort(edges + 1, edges + 1 + m, cmp);
	for (int i = 1; i <= m; i++)
	{
		int x = edges[i].a, y = edges[i].b, w = edges[i].c;
		int fx = find(x), fy = find(y);
		if (fx != fy)
		{
			p[fx] = fy;
			ans = max(w,ans);
			cnt++;
			if (cnt == n - 1)break;
		}
	}
	cout << n-1<<' ' << ans;

	return 0;
}