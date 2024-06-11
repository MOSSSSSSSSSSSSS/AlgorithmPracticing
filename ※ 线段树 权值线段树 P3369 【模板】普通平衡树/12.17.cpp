

//  2e5的询问，2e9的范围，权值线段树先离散化(离线数据结构)，即可实现  同样功能
//  splay 在2e5的询问，每个数在2e9以内，还可以支持 插入一个数，删除一个数（若有多个只删除一个），找某个数的排名，求排名是i的数，找某个数的前驱和后继

//  出现死循环，看是不是忘写return了，或者看是不是忘调用build()

#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int n;
PII op[N];
vector<int> alls;
struct node {
	int l, r, sum;
}tr[N<<2];

int getid(int x)
{
	return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}
void pushup(int u)
{
	tr[u].sum = tr[ls].sum + tr[rs].sum;
}
void build(int u,int l,int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r){tr[u].sum = 0;return;}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(u);
}
void modify(int u, int p,int op)
{
	if (tr[u].l == tr[u].r && tr[u].l == p){tr[u].sum += op;return;}
	int mid = tr[u].l + tr[u].r >> 1;
	if (p <= mid)modify(ls, p, op);
	else if (p >= mid + 1)modify(rs, p, op);
	pushup(u);
}
int query(int u, int l,int r)
{
	int res = 0;
	if (l <= tr[u].l && tr[u].r <= r)return tr[u].sum;
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)res+=query(ls, l, r);
	if (r >= mid + 1)res+=query(rs, l, r);
	return res;
}
int ask(int u, int x)
{
	if (tr[u].l == tr[u].r)return tr[u].l;
	else if (x <= tr[ls].sum)return ask(ls, x);
	else return ask(rs, x - tr[ls].sum);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> op[i].first >> op[i].second;
		if (op[i].first != 4)alls.push_back(op[i].second);
	}
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	build(1, 1, N);
	for (int i = 1; i <= n; i++)
	{
		int opt = op[i].first, x = op[i].second;
		if (opt != 4)x = getid(x);
		if (opt == 1)modify(1, x, 1);
		else if (opt == 2)modify(1, x, -1);
		else if (opt == 3)
		{
			/*if (query(1, x, x) != 0)cout << query(1, 1, x) << '\n';          ///  若查询一个没有的数的排名，需要加一
			else cout << query(1, 1, x - 1) + 1 << '\n';*/
			if (x > 1)cout << query(1, 1, x - 1) + 1 << '\n';                  //////////////////////
			else cout << 1 << '\n';                                            //////////////////////
		}
		else if (opt == 4)cout << alls[ask(1, x) - 1] << '\n';
		else if (opt == 5)cout << alls[ask(1, query(1, 1, x - 1)) - 1] << '\n';//////////////////////
		else if (opt == 6)cout << alls[ask(1, query(1, 1, x) + 1) - 1] << '\n';//////////////////////
	}

	return 0;
}