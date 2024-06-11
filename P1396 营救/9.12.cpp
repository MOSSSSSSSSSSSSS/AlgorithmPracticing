

//��³˹�����Ļ�ֻҪ�����յ���һ�������ˣ�����������뼯�ϵ������ߵı�Ȩֵ���Ͼ�֮ǰ��С��������������š�

//�����Ƕ��ּ�kruskal����һ�ַ���

#include<bits/stdc++.h>
using namespace std;

const int N = 10010, INF = 0x3f3f3f3f;
int n, m, s, t;
int p[N];
int l = INF, r = -INF;
struct edge {
	int u, v, w;
}edges[2*N];

bool cmp(edge a, edge b)
{
	if (a.w < b.w)return true;
	else return false;
}

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

bool check(int mid)
{
	for (int i = 1; i <= n; i++)
		p[i] = i;                    //  ������Ҫע�⣡������������������
	for (int i = 1; i <= m; i++)
	{
		int a = edges[i].u, b = edges[i].v, c = edges[i].w;
		a = find(a), b = find(b);
		if (a != b&&c<=mid)
		{
			p[a] = b;
			if (find(s)==find(t))
				return true;
		}
	}
	return false;
}

int main()
{
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		l = min(l, w);
		r = max(r, w);
		edges[i] = { u,v,w };
	}
	sort(edges + 1, edges + 1 + m, cmp);
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	cout << l;

	return 0;
}