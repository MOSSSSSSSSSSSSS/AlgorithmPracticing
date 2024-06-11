


//  Ë«Ö¸Õë



#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m;
string str;
string sstr[N];
map<string, int> mp;
int ans1;
int cnt;
int l = 1, r = 0;
int check[1010];
bool vis[1010];
int ans2 = 1e8;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		mp[str] = i;
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> sstr[i];
		if (mp[sstr[i]]&&!vis[mp[sstr[i]]])
		{
			ans1++;
			vis[mp[sstr[i]]] = true;
		}
	}
	cout << ans1 << endl;
	if (!ans1)
	{
		cout << 0;
		return 0;
	}
	while (r<=m&&l<=m)
	{
		while (cnt < ans1&&r<=m)
		{
			r++;
			if (mp[sstr[r]] && !check[mp[sstr[r]]])cnt++;
			if(mp[sstr[r]])check[mp[sstr[r]]]++;
		}
		if (cnt == ans1)ans2 = min(ans2, r - l + 1);
		while (cnt >= ans1&&l<=m)
		{
			l++;
			if (mp[sstr[l - 1]])
			{
				check[mp[sstr[l - 1]]]--;
				if(!check[mp[sstr[l - 1]]])cnt--;
			}
			if (cnt == ans1)ans2 = min(ans2, r - l + 1);
		}
		if (cnt == ans1)ans2 = min(ans2, r - l + 1);
	}
	cout << ans2;

	return 0;
}