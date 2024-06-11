
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
bool a[N];
int n, m;
struct node {
	int l, r, sumof0, sumof1;
	bool tag;
}tr[4 * N];
string str;

void pushup(int u)
{
	tr[u].sumof1 = tr[u << 1].sumof1 + tr[u << 1 | 1].sumof1;
	tr[u].sumof0 = tr[u << 1].sumof0 + tr[u << 1 | 1].sumof0;
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		if (a[l] == 1)tr[u].sumof0 = 0, tr[u].sumof1 = 1;
		else tr[u].sumof1 = 0, tr[u].sumof0 = 1;
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void pushdown(int u)
{
	if (tr[u].tag)
	{
		tr[u << 1].tag ^= 1;
		swap(tr[u << 1].sumof0, tr[u << 1].sumof1);
		tr[u << 1 | 1].tag ^= 1;
		swap(tr[u << 1 | 1].sumof0, tr[u << 1 | 1].sumof1);
		tr[u].tag = 0;
	}
}
void modify(int u, int l, int r)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		tr[u].tag ^= 1;
		swap(tr[u].sumof0, tr[u].sumof1);
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(u << 1, l, r);
	if (r >= mid + 1)modify(u << 1 | 1, l, r);
	pushup(u);
}
int query(int u, int l, int r)
{
	int ans = 0;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].sumof1;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)ans += query(u << 1, l, r);
	if (r >= mid + 1)ans += query(u << 1 | 1, l, r);
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> str;
	for (int i = 0; str[i]; i++)
		a[i + 1] = str[i] - '0';
	build(1, 1, n);
	while (m--)
	{
		int op, l, r;
		cin >> op >> l >> r;
		if (op == 0)
			modify(1, l, r);
		else
			cout << query(1, l, r) << endl;
	}

	return 0;
}