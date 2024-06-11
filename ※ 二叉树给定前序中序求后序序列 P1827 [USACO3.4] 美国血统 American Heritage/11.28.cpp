

#include<bits/stdc++.h>
using namespace std;

string a, b;
int l;

void dfs(int l1, int l2, int l3, int l4)
{
	if (l1 > l2 || l3 > l4)return;
	for(int i = l1;i<=l2;i++)
	{
		if (a[i] == b[l3])
		{
			dfs(l1, i - 1, l3 + 1, i - l1 + l3);
			dfs(i + 1, l2, i - l1 + l3 + 1, l4);
			cout << a[i];
			break;
		}
	}
}

int main()
{
	cin >> a >> b;
	l = a.size() - 1;
	dfs(0, l, 0, l);

	return 0;
}