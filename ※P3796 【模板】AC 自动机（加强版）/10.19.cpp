

#include<bits/stdc++.h>
using namespace std;

const int N = 150 * 70 + 10;
int tr[N][26], cnt[N], idx;
int num[N];
int ne[N],q[N];
int n;
string str[160];
string sstr;
int ans;

void insert(string str,int u)
{
	int p = 0;
	for (int i = 0; str[i]; i++)
	{
		int t = str[i] - 'a';
		if (!tr[p][t])tr[p][t] = ++idx;
		p = tr[p][t];
	}
	cnt[p] = u;
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
				q[++tt] = j;
			}
		}
	}
}

int main()
{
	while (true)
	{
		cin >> n;
		if (!n)return 0;
		ans = idx = 0;
		memset(tr, 0, sizeof tr);
		memset(cnt, 0, sizeof cnt);
		memset(num, 0, sizeof num);
		memset(ne, 0, sizeof ne);
		for (int i = 1; i <= n; i++)
			cin >> str[i], insert(str[i], i);
		cin >> sstr;
		build();
		for (int i = 0, j = 0; sstr[i]; i++)
		{
			int t = sstr[i] - 'a';
			j = tr[j][t];
			int p = j;
			while (p)
			{
				if(cnt[p])num[cnt[p]]++, ans = max(ans, num[cnt[p]]);
				p = ne[p];
			}
		}
		cout << ans << endl;
		for (int i = 1; i <= n; i++)
			if (num[i] == ans)
				cout << str[i] << endl;
	}
	return 0;
}