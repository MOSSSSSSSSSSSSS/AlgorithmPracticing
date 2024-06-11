
//    修路的并查集，在一条线上说明这几个村通了，可互相到达

#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int p[N];

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int main()
{
	while (1)
	{
		int n, m;
		cin >> n;
		if (n == 0)break;
		cin >> m;
		for (int i = 1; i <= n; i++)
			p[i] = i;
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			cin >> x >> y;
			if (find(x) != find(y))
				p[find(x)] = y;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (p[i] == i)
				ans++;
		cout << ans - 1 << endl;
	}

	return 0;
}