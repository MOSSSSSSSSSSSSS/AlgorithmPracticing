

#include<bits/stdc++.h>
using namespace std;

const int N = 5010;
int n, m, q;
int p[N];

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)p[i] = i;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		if (find(x) != find(y))p[find(x)] = y;
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		if (find(x) == find(y))cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}
//   典型并查集模板
#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, m;
int p[N];

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)p[i] = i;
	while (m--)
	{
		int z, x, y;
		cin >> z >> x >> y;
		if (z == 1)
		{
			if (find(x) != find(y))
				p[find(x)] = y;
		}
		else
		{
			if (find(x) == find(y))cout << "Y" << endl;
			else cout << "N" << endl;
		}
	}

	return 0;
}