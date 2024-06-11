

#include<bits/stdc++.h>
using namespace std;

const int N = 20;
int t;
bool check[N];
int w[N];

bool dfs(int n,int i)
{
	if (i == n + 1)
	{
		int res1 = 0, res2 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (check[i] == 0)
				res1 ^= w[i];
			else
				res2 ^= w[i];
		}
		if (res1 == res2)return true;
		else return false;
	}

	for (int j = 0; j <= 1; j++)
	{
		check[i] = j;
		if (dfs(n, i + 1))
		{
			int i = 2;
			for (; i <= n; i++)
				if (check[i] != check[1])
					return true;
		}
	}

	return false;
}

int main()
{
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> w[i];
		if (dfs(n,1))
		{
			cout << "Yes" << endl;
			for (int i = 1; i <= n; i++)
				cout << check[i];
			cout << endl;
		}
		else
			cout << "No" << endl;
	}

	return 0;
}