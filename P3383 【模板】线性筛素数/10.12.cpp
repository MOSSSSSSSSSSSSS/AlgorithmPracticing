

#include<bits/stdc++.h>
using namespace std;

const int N = 1e8 + 10;
int n, q,k;
int primes[N], cnt;
bool st[N];

void get_primes()
{
	for (int i = 2; i <= n; i++)
	{
		if (!st[i])primes[++cnt] = i;
		for (int j = 1; primes[j] <= n / i; j++)
		{
			st[primes[j] * i] = true;
			if (i % primes[j]==0)break;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(0);
	cin >> n >> q;
	get_primes();
	while (q--)
	{
		cin >> k;
		cout << primes[k] << endl;
	}

	return 0;
}