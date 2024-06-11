

// 后序

#include<bits/stdc++.h>
using namespace std;

const int N = 1040;

////////////////////  int h[N], e[N], ne[N], idx;  二叉树左儿子<<1,右儿子<<1|1,这样存图

char flag[N];
int n;
int len = 1;
char s[N];

/*void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}*/
char get(int l, int r)
{
	int cnt0 = 0, cnt1 = 0;
	for (int i = l; i <= r; i++)
	{
		if (s[i] == '1')cnt1++;
		else cnt0++;
	}
	if (cnt0 > 0 && cnt1 > 0)return 'F';
	else if (cnt0 > 0 && cnt1 == 0)return 'B';
	else return 'I';
}
void build(int u, int l, int r)
{
	flag[u] = get(l, r);
	if (l == r)return;
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}
void dfs(int u)
{
	if ((u << 1) > n)
	{
		cout << flag[u];
		return;
	}
	if ((u << 1) <= n)
	{
		dfs(u << 1);
	}
	if ((u << 1 | 1) <= n)
	{
		dfs(u << 1 | 1);
	}
	cout << flag[u];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		len *= 2;
	n = len;
	cin >> s + 1;
	build(1, 1, n);
	n = n * 2 - 1;
	dfs(1);

	return 0;
}