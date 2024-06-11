

// 按照题意，一个点的直接前驱是 x - f[i] i是第几个月出生的

#include<bits/stdc++.h>
using namespace std;

const int N = 60;
int m;
long long fib[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> m;
	fib[1] = 1, fib[2] = 1;
	for (int i = 3; i < N; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	while (m--)
	{
		long long a, b;
		cin >> a >> b;
		while (a != b)
		{
			if (a > b)
			{
				for (int i = N-1; i >= 1; i--)
				{
					if (a > fib[i])
					{
						a -= fib[i];
						break;
					}
				}
			}
			else
			{
				for (int i = N - 1; i >= 1; i--)
				{
					if (b > fib[i])
					{
						b -= fib[i];
						break;
					}
				}
			}
		}
		cout << a << '\n';
	}

	return 0;
}