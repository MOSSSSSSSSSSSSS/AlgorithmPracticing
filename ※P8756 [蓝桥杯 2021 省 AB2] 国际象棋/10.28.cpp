
// ״ѹdp

#include<bits/stdc++.h>
using namespace std;

const int N = 110, M = 25, K = 1 << 6, P = 1000000007;
int n, m, num;
int f[N][M][K][K];
int ans;
int cnt[K];

int count(int a)
{
	/*int cnt = 0;
	while (a)
	{
		a -= (a & (-a));
		cnt++;
	}*/
	int sum = 0;
	while (a) sum += a & 1, a >>= 1;
	return sum;
}

int main()
{
	cin >> n >> m >> num;
	for (int i = 0; i < 1 << n; i++)
		cnt[i] = count(i);
	for (int i = 0; i < 1 << n; i++)
		for (int j = 0; j < 1 << n; j++)
			if (!((i << 2 | i >> 2) & j) && cnt[i] + cnt[j] <= num)
				f[2][cnt[i] + cnt[j]][j][i] = 1;
	for (int i = 3; i <= m; i++)
	{
		for (int j = 0; j <= num; j++)
		{
			for (int k = 0; k < 1 << n; k++)//i
			{
				for (int l = 0; l < 1 << n; l++)//i-1
				{
					for (int p = 0; p < 1 << n; p++)//i-2
					{
						if (!((p << 2 | p >> 2) & l) && !((p << 1 | p >> 1) & k) && !((l << 2 | l >> 2) & k) && cnt[k] + cnt[p]+cnt[l] <= j)
						{
							f[i][j][k][l] = (f[i][j][k][l] + f[i - 1][j - cnt[k]][l][p]) % P;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 1 << n; i++)
		for(int j = 0;j<1<<n;j++)
			if (cnt[i] + cnt[j] <= num && !((j << 2 | j >> 2) & i))
				ans = (ans + f[m][num][i][j]) % P;
	cout << ans;

	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 110, M = 25, K = 1 << 6,P = 1000000007;
int n, m, num;
int f[N][M][K];
int ans;

int count(int a)
{
	int cnt = 0;
	while (a)
	{
		a -= (a & (-a));
		cnt++;
	}
	return cnt;
}

int main()
{
	cin >> n >> m >> num;
	for (int i = 0; i < (1 << n); i++)
		if(count(i)<=num)
			f[1][count(i)][i] = 1;
	for (int i = 2; i <= m; i++)
	{
		for (int j = 0; j <= num; j++)
		{
			for (unsigned int k = 0; k < (1 << n); k++)
			{
				if (count(k) <= j)
				{
					for (unsigned int l = 0; l < (1 << n); l++)
					{
						if (!((l << 2 | l >> 2) & k) && count(l) + count(k) <= j)
						{
							if (i > 2)
							{
								for (unsigned int o = 0; o < (1 << n); o++)
								{
									if (!((o << 1 | o >> 1) & k) && count(l) + count(k) + count(o) <= j && (!((o << 2 | o >> 2) & l)))
									{
										f[i][j][k] = (f[i][j][k] + min(f[i - 1][j - count(k)][l], f[i - 2][j - count(k) - count(l)][o])) % P;
									}
								}
							}
							else
							{
								f[2][j][k] = (f[2][j][k] + f[1][count(l)][l]) % P;
							}
						}
					}
				}

			}
		}
	}
	for (int i = 0; i < 1 << n; i++)
		if(count(i)<=num)
			ans = (ans + f[m][num][i]) % P;
	cout << ans;

	return 0;
}*/