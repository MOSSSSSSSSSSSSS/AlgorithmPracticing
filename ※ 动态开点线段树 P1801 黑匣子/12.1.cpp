


//  2e5的询问，每个数在2e9以内，插入一个数或者求排名是i的数，可以用对顶堆（对顶堆还可以用于解决其他“第i小”的变形问题：比如求前n个元素的中位数等。）
// 
//  权值线段树和线段树，唯一的本质的区别就是他们维护的东西不一样，权值线段树维护的是桶，如序列 1 1 1 2 2 3 3 4 5 叶节点是1的个数，2的个数，这两个叶节点的父节点是1和2的总个数
//  因此权值线段树可以查询全局第k大，最小差等线段树无法维护的东西。      ////  权值线段树也能处理负数。此时mid应取(l+r-1)/2; ？？？？？？？
// 这里要注意！我们只能对给定数列解决整个数列的第k大/小，并不能解决数列的子区间的第k大/小。（剧透一下，解决数列子区间的第k大 / 小需要主席树（可持久化线段树）
// 权值线段树 的空间是由值域决定的，若每个数在2e9以内，需要 保序的 离散化，这是一种劣势，就变成了离线的数据结构。在开辟 4倍大小的空间
// 
// 另外 ， 若n太大达到不能直接开数组的级别，可以考虑动态开点的方式节省空间
// 
//  splay 在2e5的询问，每个数在2e9以内，还可以支持 插入一个数，删除一个数（若有多个只删除一个），找某个数的排名，求排名是i的数，找某个数的前驱和后继


​
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m;
int a[N],b[N];
vector<int> alls;
struct node {
	int l, r, sum;  //  维护的是l到r这个值域的数，总共出现多少次
}tr[4*N];
int last = 1;

int get(int x)
{
	return lower_bound(alls.begin(), alls.end(),x) - alls.begin()+1;  // 值域从一开始
}
void pushup(int u)
{
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		tr[u].sum = 0;
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void modify(int u, int x)
{
	if (tr[u].l == tr[u].r && tr[u].l == x)
	{
		tr[u].sum++;
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (x <= mid)modify(u << 1, x);
	else modify(u << 1 | 1, x);
	pushup(u);
}
int query(int u,int i)
{
	if (tr[u].l == tr[u].r)
	{
		return tr[u].l;
	}
	if (tr[u << 1].sum >= i)
	{
		return query(u << 1, i);
	}
	else
	{
		i -= tr[u << 1].sum;
		return query(u << 1 | 1, i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
		alls.push_back(a[i]);
	}
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	build(1, 1, m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = last; j <= b[i]; j++)
		{
			modify(1, get(a[j]));
		}
		last = b[i] + 1;
		cout << alls[query(1,i)-1] << '\n';
	}

	return 0;
}