

#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int n, q;
int d[N][N],temp[N][N];
int mind[N][N];

void zhi(int mid)
{
	int k = mid / n;     //  0到n-1治理k
	int m = mid % n - 1; //  0到d治理1
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (i <= m && j <= m)
				{
					if (temp[i][j] - (2 * k + 2) < mind[i][j])
						temp[i][j] = mind[i][j];
					else
						temp[i][j] -= (2 * k + 2);
				}
				else if (i > m && j > m)
				{
					if (temp[i][j] - (2 * k) < mind[i][j])
						temp[i][j] = mind[i][j];
					else
						temp[i][j] -= (2 * k);
				}
				else
				{
					if (temp[i][j] - (2 * k + 1) < mind[i][j])
						temp[i][j] = mind[i][j];
					else
						temp[i][j] -= (2 * k + 1);
				}
			}
		}
	}
}

bool check(int mid)
{
	zhi(mid);
	long long tot = 0;
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				temp[i][j] = min(temp[i][j], temp[i][k] + temp[k][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)tot += temp[i][j];
	if (tot <= q)return true;
	else return false;
}

int main()
{
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> d[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mind[i][j];
	int l = 0, r = 100000 * n;
	while (l < r)
	{
		int mid = l + r >> 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				temp[i][j] = d[i][j];
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	if (l != 100000 * n)cout << l;
	else cout << -1;

	return 0;
}