


//string已经有一个值，又读入，再输出，是输出到尾零，string的加法，也是加到尾零为止

#include<bits/stdc++.h>
using namespace std;

const int N = 2010,M = 200010;
string str,s;
int son[N][26], cnt[N], idx,ne[N];
bool dp[M];

void insert(string str)
{
	int p = 0;
	for (int i = 0; i < str.size(); i++)
	{
		int u = str[i] - 'A';
		if (!son[p][u])son[p][u] = ++idx;
		p = son[p][u];
	}
	cnt[p] = str.size();
}

void build()
{
	queue<int> q;
	for (int i = 0; i < 26; i++)
		if (son[0][i])
			q.push(son[0][i]);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (int i = 0; i < 26; i++)
		{
			int v = son[t][i];
			if (v)ne[v] = son[ne[t]][i],q.push(v);
			else son[t][i] = son[ne[t]][i];
		}
	}
}

void query(string s)
{
	for (int i = 0, j = 0; i < s.size(); i++)
	{
		j = son[j][s[i] - 'A'];
		for (int k = j; k && !dp[i+1]; k = ne[k])
			if (cnt[k])dp[i+1] = dp[i+1] || dp[i+1 - cnt[k]]; //   虽然s是从0开始，但dp[i]表示前i个可以
	}
}

int main()
{
	while (cin >> str, str[0] != '.')
		insert(str);
	build();
	while (cin >> str)                // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		s += str;
	dp[0] = 1;

	query(s);
	
	for (int i = s.size(); i >= 0; i--)
	{
		if (dp[i] == true)                       //   虽然s是从0开始，但dp[i]表示前i个可以    注意等于是==，浪费时间
		{
			cout << i;
			break;
		}
	}

	return 0;
}