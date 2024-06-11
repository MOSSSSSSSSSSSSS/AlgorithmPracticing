

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int tr[N][26], cnt[N], idx;
int q[N], ne[N];
int din[N];
int vis[N];
int num[N];
vector<int> same[N];
string str, strr;
int n;

void insert(string str, int ver)
{
	int p = 0;
	for (int i = 0; str[i]; i++)
	{
		int t = str[i] - 'a';
		if (!tr[p][t])tr[p][t] = ++idx;
		p = tr[p][t];
	}
	if (!cnt[p])cnt[p] = ver;
	else same[cnt[p]].push_back(ver);
}
void build()
{
	int hh = 0, tt = -1;
	for (int i = 0; i < 26; i++)
		if (tr[0][i])
			q[++tt] = tr[0][i];
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = 0; i < 26; i++)
		{
			if (!tr[t][i])tr[t][i] = tr[ne[t]][i];
			else
			{
				ne[tr[t][i]] = tr[ne[t]][i];
				din[tr[ne[t]][i]]++;
				q[++tt] = tr[t][i];
			}
		}
	}
}
void toposort()
{
	int hh = 0, tt = -1;
	for (int i = 1; i <= idx; i++)
		if (din[i] == 0)
			q[++tt] = i;
	while (hh <= tt)
	{
		int t = q[hh++];
		vis[ne[t]] += vis[t];
		din[ne[t]]--;
		if (din[ne[t]] == 0)q[++tt] = ne[t];
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		insert(str, i);
		strr += str;
		strr += '#';
	}
	build();
	for (int i = 0, j = 0; strr[i]; i++)
	{
		if (strr[i] == '#') { j = 0; continue; }
		int t = strr[i] - 'a';
		j = tr[j][t];
		vis[j]++;
	}
	toposort();
	for (int i = 1; i <= idx; i++)
		if (cnt[i])
			num[cnt[i]] = vis[i];/////////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < same[i].size(); j++)
			num[same[i][j]] = num[i];
	for (int i = 1; i <= n; i++)
		cout << num[i] << endl;


	return 0;
}