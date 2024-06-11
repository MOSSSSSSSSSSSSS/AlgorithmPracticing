



//   拓扑优化，没有了暴力跳


#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int tr[N][26], cnt[N], idx;
int q[N], ne[N];
int n;
int num[N];
int vis[N];///////////////////////////////////////////////////////////////////////////////
string str[N];
string sstr;
vector<int> a[N];
int din[N];///////////////////////////////////////////////////////////////////

void insert(string str, int u)
{
	int p = 0;
	for (int i = 0; str[i]; i++)
	{
		int t = str[i] - 'a';
		if (!tr[p][t])tr[p][t] = ++idx;
		p = tr[p][t];
	}
	if (!cnt[p])cnt[p] = u;
	else a[cnt[p]].push_back(u);
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
			int j = tr[t][i];
			if (!j)tr[t][i] = tr[ne[t]][i];
			else
			{
				ne[j] = tr[ne[t]][i];
				din[tr[ne[t]][i]]++;
				q[++tt] = j;
			}
		}
	}
}
void toposort()/////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	queue<int> qq;
	for (int i = 1; i <= idx; i++)
		if (!din[i])
			qq.push(i);
	while (qq.size())
	{
		int t = qq.front();
		qq.pop();
		vis[ne[t]] += vis[t];
		din[ne[t]]--;
		if (!din[ne[t]])qq.push(ne[t]);
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> str[i], insert(str[i], i);
	cin >> sstr;
	build();
	for (int i = 0, j = 0; sstr[i]; i++)
	{
		int t = sstr[i] - 'a';
		j = tr[j][t];
		vis[j]++;///////////////////////////////////////////////////////////////////////////////////////////
	}
	toposort();
	for (int i = 1; i <= idx; i++)
		if (cnt[i])
			num[cnt[i]] = vis[i];/////////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < a[i].size(); j++)
			num[a[i][j]] = num[i];
	for (int i = 1; i <= n; i++)
		cout << num[i] << endl;

	return 0;
}