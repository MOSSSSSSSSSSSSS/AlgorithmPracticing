

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 160, M = 5010;
int n, m;
int p[N];
PII edge[M];

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> edge[i].first >> edge[i].second;
		if (edge[i].first > edge[i].second)
			swap(edge[i].first, edge[i].second);
	}
	sort(edge + 1, edge + 1 + m);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			p[j] = j;
		for (int j = 1; j <= m; j++)
		{
			if (j != i)
			{
				int a = find(edge[j].first);
				int b = find(edge[j].second);
				if (a != b)
					p[a] = b;
			}
		}
		bool flag = true;
		int baba = find(1);
		for (int j = 2; j <= n; j++)
		{
			if (find(j) != baba)
			{
				flag = false;
				break;
			}
		}
		if (!flag)cout << edge[i].first << ' ' << edge[i].second << endl;
	}

	return 0;
}
/*
9 11
7 8
8 9
9 7
4 1
7 3
1 2
2 5
5 6
6 2
1 3
3 4
*/