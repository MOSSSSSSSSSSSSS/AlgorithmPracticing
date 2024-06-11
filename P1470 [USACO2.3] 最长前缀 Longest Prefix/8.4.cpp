


//string�Ѿ���һ��ֵ���ֶ��룬��������������β�㣬string�ļӷ���Ҳ�Ǽӵ�β��Ϊֹ

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
			if (cnt[k])dp[i+1] = dp[i+1] || dp[i+1 - cnt[k]]; //   ��Ȼs�Ǵ�0��ʼ����dp[i]��ʾǰi������
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
		if (dp[i] == true)                       //   ��Ȼs�Ǵ�0��ʼ����dp[i]��ʾǰi������    ע�������==���˷�ʱ��
		{
			cout << i;
			break;
		}
	}

	return 0;
}