#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;

int n, m,flag = 1,ans;
int r[N],a[N];

void insert(int dj, int sj, int tj)
{
	a[sj] -= dj;
	a[tj + 1] += dj;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &r[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		insert(i, i, r[i]);
	}
	for (int j = 1; j <= m; j++)
	{
		int dj, sj, tj;
		scanf("%d%d%d", &dj, &sj, &tj);
		insert(dj, sj, tj);
		for (int i = 1; i <= n; i++)
		{
			r[i] = r[i - 1] + a[i];
			if (r[i] < 0)
			{
				if (flag != 0)
				{
					flag = 0;
					ans = j + 1;
				}
			}
		}
	}
	if (flag)cout << 0;
	else cout << -1 << endl << ans;

	return 0;
}
