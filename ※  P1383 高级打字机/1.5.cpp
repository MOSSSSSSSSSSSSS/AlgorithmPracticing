#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int root[N], idx, cnt;
int n;
struct node
{
	int ls, rs, sum;
	char ch;
}tr[N*20];

void modify(int& u, int v, int l, int r, char c)
{
	u = ++idx;
	tr[u].ls = tr[v].ls, tr[u].rs = tr[v].rs, tr[u].sum = tr[v].sum + 1;
	if (l == r)
	{
		tr[u].ch = c;
		return;
	}
	int mid = l + r >> 1;
	if (tr[tr[u].ls].sum < mid - l + 1)modify(tr[u].ls, tr[v].ls, l, mid, c);
	else modify(tr[u].rs, tr[v].rs, mid + 1, r, c);
}
char query(int u, int l, int r, int k)
{
	if (l == r)return tr[u].ch;
	int mid = l + r >> 1;
	if (k <= tr[tr[u].ls].sum)return query(tr[u].ls, l, mid, k);
	else return query(tr[u].rs, mid + 1, r, k - tr[tr[u].ls].sum);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char op;
		cin >> op;
		if (op == 'T')
		{
			char x;
			cin >> x;
			cnt++;
			modify(root[cnt], root[cnt - 1], 1, N, x);
		}
		else if (op == 'U')
		{
			int x;
			cin >> x;
			cnt++;
			root[cnt] = root[cnt - x - 1];
		}
		else
		{
			int x;
			cin >> x;
			cout << query(root[cnt], 1, N, x) << '\n';
		}
	}

	return 0;
}