

#include<bits/stdc++.h>
using namespace std;

const int N = 1010,M = 20010;
int p[N];
int n, m;
struct edge {
	int a, b, w;
}edges[M];

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

bool cmp(edge a,edge b)
{
	if (a.w > b.w)return true;
	else return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= m; i++)
		cin >> edges[i].a >> edges[i].b >> edges[i].w;
	sort(edges + 1, edges + m + 1,cmp);
	int res = 0,cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		a = find(a);
		b = find(b);
		if (a != b)
		{
			p[a] = b;
			res += w;
			cnt++;
		}
	}
	if (cnt != n - 1)cout << -1;
	else cout << res;

	return 0;
}