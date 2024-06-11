

#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
int n,m;
int son[N][26],cnt[N],idx;
string name;

void insert(string name)
{
	int p = 0;
	for (int i = 0; i < name.size(); i++)
	{
		int u = name[i] - 'a';
		if (!son[p][u])son[p][u] = ++idx;
		p = son[p][u];
	}
	cnt[p]++; 
}

int query(string name)
{
	int p = 0;
	for (int i = 0; i < name.size(); i++)
	{
		int u = name[i] - 'a';
		if (!son[p][u])return 0;               
		p = son[p][u];
	}
	if (cnt[p])cnt[p]++;         //   ������û���ؿ�������������֣�Ҳ�����ǲ�ѯ���ַ�����ĳ�����ֵ�ǰ׺������Ҫ
	//�ж�һ���Ƿ�����������β������

	return cnt[p];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		insert(name);
	}
	cin >> m;
	while (m--)
	{
		cin >> name;
		int res = query(name);
		if (res == 2) cout << "OK" << endl;
		else if (res > 2) cout << "REPEAT" << endl;
		else cout << "WRONG" << endl;
	}

	return 0;
}