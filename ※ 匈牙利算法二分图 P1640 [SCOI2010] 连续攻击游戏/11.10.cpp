
//  复杂度 n*m，但一般远小于
//  时间戳优化，不用每次清零st数组
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10,M = 10010;
int n;
int match[N];
int st[N];
int h[M], e[2 * N], ne[2 * N], idx;
int timestamp;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool Find(int x)
{
	for (int i = h[x]; ~i; i = ne[i])
	{
		int j = e[i];
		if (st[j] != timestamp)
		{
			st[j] = timestamp;
			if (!match[j] || Find(match[j]))
			{
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, i), add(b ,i);
	}
	for (int i = 1; i <= 10000; i++)
	{
		timestamp = i;
		if (!Find(i))
		{
			cout << i - 1;
			return 0;
		}
	}
	cout << 10000;

	return 0;
}