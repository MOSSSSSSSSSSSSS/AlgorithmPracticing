
#include<bits/stdc++.h>
using namespace std;

const int N = 5010;
int n;
int a[N];
int f[N];
int ans;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for(int i = 1;i<=n;i++)f[i] = 1;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[i] > a[j])
			{
				f[i] = max(f[i], f[j] + 1);
			}
		}
	}
	for (int i = 1; i <= n; i++)ans = max(ans, f[i]);
	cout << ans;

	return 0;
}