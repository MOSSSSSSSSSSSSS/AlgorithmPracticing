

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, a[N];
int k;
int b[(1 << 20)];
int ans;

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 19; j >= 0; j--)
		{
			if ((k >> j) & 1)
			{
				if ((a[i] >> j) & 1)
				{
					b[sum + (1 << j)]++;
					b[sum + (1 << (j + 1))]--;
				}
				else
				{
					b[sum]++;
					b[sum + (1 << j)]--;
					sum += (1 << j);
				}
			}
			else
				sum += ((a[i] >> j) & 1) << j;
			if (j == 0)//////////////////////////////////////////////////
			{
				b[sum]++;
				b[sum + 1]--;
			}
		}
	}
	for (int i = 1; i < (1 << 20); i++)
	{
		b[i] = b[i - 1] + b[i];
		ans = max(ans, b[i]);
	}
	cout << ans;

	return 0;
}