
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];
int s[N];
int num0[21];
int num1[21];
long long ans;

signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] ^ a[i];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if ((s[i] >> j) & 1)
				num1[j]++;
			else
				num0[j]++;
		}
	}
	for (int i = 0; i <= 20; i++)
		ans += (num1[i] * num0[i] * (1 << i));
	cout << ans;

	return 0;
}