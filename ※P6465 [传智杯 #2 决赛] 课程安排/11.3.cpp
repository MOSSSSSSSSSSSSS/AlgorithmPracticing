

#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int T;
long long num[N];
long long cnt[N];
unsigned long long ans;

int main()
{
	cin >> T;
	while (T--)
	{
		int n, len;
		cin >> n >> len;
		for (int i = 1; i <= n; i++)
			cin >> num[i];
		int j = 1;
		for (int i = 1; i <= n;)
		{
			while (j<n&&num[j] != num[j + 1])
			{
				if (j - i + 1 >= len)cnt[num[j]]++;
				j++;
			}
			if (j - i + 1 >= len)cnt[num[j]]++;
			while (i <= j)
			{
				ans += j - i + 2 - len - cnt[num[i]];
				cnt[num[i + len - 1]]--;
				i++;
			}
			j = i;
			memset(cnt, 0, sizeof cnt);
		}
		cout << ans << endl;
		ans = 0;
	}

	return 0;
}