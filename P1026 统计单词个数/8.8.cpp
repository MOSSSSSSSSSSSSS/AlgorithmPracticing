

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 210,M = 50;
int p, k, s;
int sum[N][N];
int f[N][M];
string word[10];
string str;

bool check(int l, int r)
{
	for (int i = 1; i <= s; i++)
		if (str.substr(l, r - l + 1).find(word[i]) == 0)
			return true;
	return false;
}

signed main()
{
	cin >> p >> k;
	for (int i = 1; i <= p; i++)
	{
		string ss;
		cin >> ss;
		str += ss;
	}
	cin >> s;
	for (int i = 1; i <= s; i++)cin >> word[i];
	for (int i = str.size() - 1; i >= 0; i--)
	{
		for (int j = i; j >= 0; j--)
		{
			sum[j][i] = sum[j + 1][i];
			if (check(j, i))sum[j][i]++;
		}
	}
	for (int i = 1; i <= str.size(); i++)
		for (int j = 1; j <= k&&j<=i; j++)
			for (int m = j-1; m <= i - 1; m++)
				f[i][j] = max(f[i][j], f[m][j - 1] + sum[m][i - 1]);
	cout << f[str.size()][k];

	return 0;
}
