
//  ����� ��������  �����㷨

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m, a[N];
vector<int> all;
int root[N], idx;
struct node
{
	int ls, rs, sum;
}tr[N * 36];
struct q
{
	char op;
	int a, b, c;
}ask[N];

int get(int x)
{
	return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
}
void pushup(int u)
{
	tr[u].sum = tr[tr[u].ls].sum + tr[tr[u].rs].sum;
}
void modify(int& u, int l, int r, int p, int x)
{
	if(!u)u = ++idx;
	if (l == r)
	{
		tr[u].sum = x;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid)modify(tr[u].ls, l, mid, p, x);
	else modify(tr[u].rs, mid + 1, r, p, x);
	pushup(u);
}
int query(int u, int l, int r, int ll, int rr)
{
	int res = 0;
	if (ll <= l && r <= rr)return tr[u].sum;
	int mid = l + r >> 1;
	if (ll <= mid)res += query(tr[u].ls, l, mid, ll, rr);
	if (rr >= mid + 1)res += query(tr[u].rs, mid + 1, r, ll, rr);
	return res;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i],all.push_back(a[i]);
	for (int i = 1; i <= m; i++)
	{
		char op;
		cin >> op;
		if (op == 'C')
		{
			ask[i].op = 'C';
			cin >> ask[i].a >> ask[i].b;
			all.push_back(ask[i].b);
		}
		else
		{
			ask[i].op = 'Q';
			cin >> ask[i].a >> ask[i].b>>ask[i].c;
			all.push_back(ask[i].c);
		}
	}
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	for (int i = 1; i <= n; i++)modify(root[get(a[i])], 1, n, i, 1);
	for (int i = 1; i <= m; i++)
	{
		char op = ask[i].op;
		if (op == 'C')
		{
			int c = a[ask[i].a];
			modify(root[get(c)], 1, n, ask[i].a, 0);
			modify(root[get(ask[i].b)], 1, n, ask[i].a, 1);
			a[ask[i].a] = ask[i].b;
		}
		else
		{
			cout << query(root[get(ask[i].c)], 1, n, ask[i].a, ask[i].b) << '\n';
		}
	}

	return 0;
}

int n, m, a[N], b[N * 2]; //b:������ɢ��
struct node {
	int opt, l, r, id;    //id:��ı���
}q[N];               //�������
int root[N], tot, cnt;
int ls[N * 25], rs[N * 25], sum[N * 25];
//tot:������� cnt:��ı���ĸ���
//sum:�������ĸ���
int main() {
	for (int i = 1; i <= m; i++) { //�������
		if (!q[i].opt) { //����ͼ��
			change(root[a[q[i].l]], 1, n, q[i].l, -1);
			a[q[i].l] = lower_bound(b + 1, b + bn + 1, q[i].id) - b;
			change(root[a[q[i].l]], 1, n, q[i].l, 1);
		}
		else { //��ѯĳ�������ĸ���
			int id = lower_bound(b + 1, b + bn + 1, q[i].id) - b;
			printf("%d\n", query(root[id], 1, n, q[i].l, q[i].r));
		}
	}
}
