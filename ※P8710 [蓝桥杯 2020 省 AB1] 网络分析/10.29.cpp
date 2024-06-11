

#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int p[N];
int dist[N];
int value[N];
int n, m;

int find(int x)
{
	if (p[x] != x)
	{
		int temp = p[x];
		p[x] = find(p[x]);
		dist[x] += dist[temp];
	}
	return p[x];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int flag, a, b;
		cin >> flag >> a >> b;
		if (flag == 1)
		{
			int fa = find(a), fb = find(b);
			if (fa!=fb)
			{
				p[fa] = fb;
				dist[fa] = value[fa] - value[fb];
			}
		}
		else
		{
			value[find(a)] += b;
		}
	}
	for (int i = 1; i <= n; i++)cout << value[find(i)] + dist[i] << ' ';

	return 0;
}