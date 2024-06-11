

//  扩展域并查集，反集

#include<bits/stdc++.h>
using namespace std;

const int N = 2010;
int p[N];
int n, m;
int ans;

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= 2 * n; i++)
		p[i] = i;
	while (m--)
	{
		char op;
		int a, b;
		cin >> op >> a >> b;
		if (op == 'E')
		{
			int fa = find(n + a), fb = find(n + b), fc = find(a), fd = find(b);
			if (fa != fd)p[fa] = fd;
			if (fb != fc)p[fb] = fc;
		}
		else
		{
			int fa = find(a), fb = find(b);
			if (fa != fb)p[fa] = fb;
		}
	}
	for (int i = 1; i <= n; i++)
		if (p[i] == i)
			ans++;
	cout << ans;

	return 0;
}

