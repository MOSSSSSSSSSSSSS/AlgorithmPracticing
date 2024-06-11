

#include<bits/stdc++.h>
using namespace std;

const int N = 60, M = 6010;
int n;
vector<int> v[N];
int d[N],cnt1;
int s,t;
int ans[M],cnt2;

void dfs(int u)
{
	for (int i = 0; i < v[u].size(); i++)
	{
		if (!v[u][i])continue;
		int t = v[u][i];
		v[u][i] = 0;
		for (int j = 0; j < v[t].size(); j++)
		{
			if (v[t][j] == u)
			{
				v[t][j] = 0;
				break;
			}
		}
		dfs(t);
		ans[++cnt2] = t;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char a, b;
		int x, y;
		cin >> a >> b;
		if (a >= 'A' && a <= 'Z')
			x = a - 'A' + 1;
		else
			x = a - 'a' + 27;
		if (b >= 'A' && b <= 'Z')
			y = b - 'A' + 1;
		else
			y = b - 'a' + 27;
		v[x].push_back(y), v[y].push_back(x);
		d[x]++, d[y]++;
	}
	for (int i = 1; i <= 52; i++)
	{
		if (d[i] & 1)
		{
			if (!s)s = i;
			else t = i;
			cnt1++;
		}
	}
	if (cnt1 != 0 && cnt1 != 2)
	{
		cout << "No Solution";
		return 0;
	}
	for (int i = 1; i <= 52; i++)
		sort(v[i].begin(), v[i].end());
	if(s)s = (s < t ? s : t);
	else
	{
		for (int i = 1; i <= 52; i++)
		{
			if (v[i].size())
			{
				s = i;
				break;
			}
		}
	}
	dfs(s);
	if (cnt2 != n)
	{
		cout << "No Solution";
		return 0;
	}
	if (s >= 1 && s <= 26)
		s = s + 'A' - 1;
	else
		s = s + 'a' - 27;
	cout << (char)(s);
	for (int i = cnt2; i >= 1; i--)
	{
		if (ans[i] >= 1 && ans[i] <= 26)
			ans[i] = ans[i] + 'A' - 1;
		else
			ans[i] = ans[i] + 'a' - 27;
		cout << (char)(ans[i]);
	}

	return 0;
}