

//����Ҫ����ľ���ƿ��MST��������Ȩ��С�����������и�����һ����С�������ض���һ����Сƿ������������������ֱ����һ����С����������


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