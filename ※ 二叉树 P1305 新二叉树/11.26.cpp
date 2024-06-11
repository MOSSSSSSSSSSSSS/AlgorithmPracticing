

//  完全二叉树，才能左节点编号u<<1,右节点编号u<<1|1,这是普通二叉树，会很浪费空间


#include<bits/stdc++.h>
using namespace std;

const int N = 400;
int n;
char flag[N];
map<char, int> mp;
string str;
int tot;
pair<int, int> ch[N];

void dfs(int u)
{
	cout << flag[u];
	if (ch[u].first <= tot && flag[ch[u].first] != '*')dfs(ch[u].first);
	if (ch[u].second <= tot && flag[ch[u].second] != '*')dfs(ch[u].second);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		if (mp[str[0]] == 0)
		{
			mp[str[0]] = ++tot;
			flag[mp[str[0]]] = str[0];
		}
		mp[str[1]] = ++tot;
		ch[mp[str[0]]].first = mp[str[1]];
		flag[mp[str[1]]] = str[1];
		mp[str[2]] = ++tot;
		ch[mp[str[0]]].second = mp[str[2]];
		flag[mp[str[2]]] = str[2];
	}
	dfs(1);

	return 0;
}

/*
10
ag*
geh
efc
h*d
c**
dij
f**
j*b
i**
b**

*/