

#include<bits/stdc++.h>
using namespace std;

const int N = 110,M = 10010;
int p[N];
struct edge {
	int a, b, w;
}edges[M];
int n, k;
int ans;
int tot;

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
int kruskal()
{
	int cnt = 0,res = 0;
	for (int i = 1; i <= k; i++)
	{
		int a = find(edges[i].a), b = find(edges[i].b), w = edges[i].w;
		if (a != b)
		{
			cnt++;
			res += w;
			p[a] = b;
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= k; i++)
		cin >> edges[i].a >> edges[i].b >> edges[i].w,tot+=edges[i].w;
	sort(edges + 1, edges + 1 + k, cmp);
	cout << tot - kruskal();

	return 0;
}