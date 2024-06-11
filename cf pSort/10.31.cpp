
#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int p[N];
int tar[N];
int n;

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		p[i] = i, cin >> tar[i];
	for (int i = 1; i <= n; i++)
	{
		int d;
		cin >> d;
		if (i - d >= 1)
		{
			int fa = find(i), fb = find(i - d);
			if (fa != fb)
			{
				p[fa] = fb;
			}
		}
		if (i + d <= n)
		{
			int fa = find(i), fb = find(i + d);
			if (fa != fb)
			{
				p[fa] = fb;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int fa = find(tar[i]), fb = find(i);
		if (fa != fb)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}