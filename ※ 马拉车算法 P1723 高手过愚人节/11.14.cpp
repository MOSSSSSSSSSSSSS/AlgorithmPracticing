

#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
int n;
char str[N];
char strr[2 * N];
int d[N];

int get_d(int len)
{
	int ans = 0;
	d[1] = 1;
	for (int i = 2, l, r = 1; i <= len; i++)
	{
		if (i <= r)d[i] = min(d[r - i + l], r - i + 1);
		while (strr[i + d[i]] == strr[i - d[i]])d[i]++;
		ans = max(ans, d[i] - 1);
		if (i + d[i] - 1 > r)l = i - d[i] + 1, r = i + d[i] - 1;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (n--)
	{
		memset(d, 0, sizeof d);
		cin >> str + 1;
		int len = strlen(str + 1),idx = 0;
		strr[0] = '$', strr[++idx] = '#';
		for (int i = 1; i <= len; i++)
			strr[++idx] = str[i], strr[++idx] = '#';
		len = idx;
		cout << get_d(len) << endl;
	}

	return 0;
}