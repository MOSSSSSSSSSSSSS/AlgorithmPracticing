
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int T;
int C[N],tr[N];
int ans[N];

int lb(int p)
{
	return p & (-p);
}
void add(int p, int x)
{
	while (p < N)
	{
		tr[p] += x;
		p += lb(p);
	}
}
int query(int p)
{
	int res = 0;
	while (p)
	{
		res += tr[p];
		p -= lb(p);
	}
	return res;
}
int main()
{
	cin >> T;
	while (T--)
	{
		long long n,sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> C[i],sum+=C[i];
		sum /= n;
		for (int i = 1; i <= n; i++)
			tr[i] = C[i] - C[i-lb(i)];
		for (int i = n; i >= 1; i--)
		{
			int temp = sum;
			if (query(i) == i)
			{
				ans[i] = 1;
				sum--;
			}
			else ans[i] = 0;
			add(i - temp + 1, -1),add(i + 1,1);
		}
		for (int i = 1; i <= n; i++)
			cout << ans[i] << ' ';
		cout << endl;
	}

	return 0;
}