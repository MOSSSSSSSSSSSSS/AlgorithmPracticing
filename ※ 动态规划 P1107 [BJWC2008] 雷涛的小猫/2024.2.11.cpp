
#include<bits/stdc++.h>
using namespace std;

const int N = 5010;
int tree[N][N];
int f[N][N];
int ljp[N];
int n, h, delta;
int ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> h >> delta;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		for (int j = 1; j <= num; j++)
		{
			int x;
			cin >> x;
			tree[i][x]++;
		}
	}
	for (int i = h; i >= 0; i--)
	{
		for (int j = 1; j <= n; j++)
		{
			int mx = 0;
			mx = max(mx, ljp[i + delta] );
			mx = max(mx, f[j][i + 1]);
			f[j][i] = mx + tree[j][i];
			ljp[i] = max(ljp[i], f[j][i]);
		}
	}
	for (int i = 1; i <= n; i++)
		if (ans < f[i][0])
			ans = f[i][0];
	cout << ans;

	return 0;
}