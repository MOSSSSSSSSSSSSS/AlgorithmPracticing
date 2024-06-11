

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
char s[N];
int t,n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	while (t--)
	{
		cin >> n;
		int cnt = 0;
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			cin >> s[i];
		for (int i = 1; i <= n; i++)
		{
			if (s[i] == 'A')cnt++;
			else ans += cnt;
		}
		if (ans >= n - 1 && s[n] == 'B')cout << n - 1 << '\n';
		else if (ans >= n - 2 && s[n] == 'A')cout << n - 2 << '\n';
		else cout << ans<<'\n';
	}

	return 0;
}