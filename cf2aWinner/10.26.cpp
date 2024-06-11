
#include<bits/stdc++.h>
using namespace std;

typedef pair<string, int> PSI;
map<string, int> mp,m;
int MAX;
int n;
PSI huihe[1010];
string winner;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string str;
		int x;
		cin >> str >> x;
		huihe[i].first = str, huihe[i].second = x;
		mp[str] += x;
	}
	for (auto item : mp)
	{
		MAX = max(MAX,item.second);
	}
	for (int i = 1; i <= n; i++)
	{
		m[huihe[i].first] += huihe[i].second;
		if (m[huihe[i].first] >= MAX && mp[huihe[i].first] == MAX) { winner = huihe[i].first; break; }
	}
	cout << winner;

	return 0;
}