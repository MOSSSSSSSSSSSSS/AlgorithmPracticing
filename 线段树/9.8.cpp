
//segment tree线段树，segmentation fault段错误
//  线段树是一个平衡二叉树，每个节点记录一段的和。线段树的每个节点都对应一条线段（区间），但并不保证所有的线段（区间）都是线段树的节点，这两者应当区分开。
// 线段树 左边子节点的区间长度比右边子节点的区间长度多一或者相等
//  现将数据输入到一个数组A中，再用build函数，在tree数组中建立线段树。类比：建堆：现将数据输入一个数组这种，再从n/2开始down，这个数组就建成了堆

//  之所以叫懒标记是因为每次只更新到需要的位置，需要哪就更新到哪而不是全部更新

/*
void build(int l,int r,int p)  //  l，r是在原数组中的区间，p是tree数组的下标,一开始传入 1，n，1
{
	if(l==r)
	{
		tree[p] = A[l];
		return;
	}
	int mid = l + r >> 1;
	build(l,mid,2*p);
	build(mid+1,r,2*p+1);
	tree(p) = tree(2*p)+tree(2*p+1);
}
*/

/*void push_down(int p, int len)
{
	mark[2 * p] += mark[p];
	mark[2 * p + 1] += mark[p];
	tree[2 * p] += mark[p] * (len - len / 2);
	tree[2 * p + 1] += mark[p] * len / 2;
	mark[p] = 0;
}

void update(int l,int r,int d,int p,int cl,int cr)
{
	if (cl > r || cr < l)
		return;
	else if (l <= cl && cr <= r)
	{
		tree[p] += d * (cr - cl + 1);
		if (cl < cr)
			mark[p] += d;
	}
	else
	{
		int mid = cl + cr >> 1;
		push_down(p, cr - cl + 1);
		update(l, r, d, 2 * p, cl, mid);
		update(l, r, d, 2 * p + 1, mid + 1, cr);
		tree[p] = tree[2 * p] + tree[2 * p + 1];
	}
}

int query(int l, int r, int p, int cl, int cr)
{
	if (l > cr || cl > r)
		return 0;
	else if (l <= cl && cr <= r)
		return tree[p];
	else
	{
		int mid = cl + cr >> 1;
		push_down(p, cr - cl + 1);
		return query(l, r, 2 * p, cl, mid) + query(l, r, 2 * p + 1, mid + 1, cr);
	}
}*/
/*
// 模板题：
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100010;
LL tree[4*N],mark[4*N], n, m, a[N];

void build(LL l,LL r,LL p)
{
	if (l == r)
	{
		tree[p] = a[l];
		return;
	}
	LL mid = l + r >> 1;
	build(l, mid, 2 * p);
	build(mid + 1, r, 2 * p + 1);
	tree[p] = tree[2 * p] + tree[2 * p + 1];
}

void push_down(LL p, LL len)
{
	mark[2 * p] += mark[p];
	mark[2 * p + 1] += mark[p];
	tree[2 * p] += mark[p] * (len - len / 2);//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	tree[2 * p + 1] += mark[p] * (len / 2);          //   注意 a*b/2和a*（b/2）一个错一个对%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	mark[p] = 0;                                    //  注意清零%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
}

void update(LL l, LL r,LL d, LL p, LL cl, LL cr)
{
	if (l > cr || cl > r)
		return;
	else if (cl >= l && r >= cr)
	{
		tree[p] += d * (cr - cl + 1);
		if (cl < cr)
			mark[p] += d;                           //  如果不是叶子节点就要加懒标记
	}
	else
	{
		LL mid = cl + cr >> 1;
		push_down(p, cr - cl + 1);
		update(l, r, d, 2 * p, cl, mid);
		update(l, r, d, 2 * p + 1, mid + 1, cr);
		tree[p] = tree[2 * p] + tree[2 * p + 1];
	}
}

LL query(LL l, LL r, LL p, LL cl, LL cr)
{
	if (l > cr || cl > r)
		return 0;
	else if (cl >= l && r >= cr)
		return tree[p];
	else
	{
		LL mid = cl + cr >> 1;
		push_down(p, cr - cl + 1);
		return query(l, r, 2 * p, cl, mid) + query(l, r, 2 * p + 1, mid + 1, cr);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1,n,1);
	while (m--)
	{
		int flag;
		cin >> flag;
		if (flag == 1)
		{
			LL x, y, k;
			cin >> x >> y >> k;
			update(x, y, k, 1, 1, n);
		}
		else
		{
			LL x, y;
			cin >> x >> y;
			cout << query(x, y, 1, 1, n) << endl;
		}
	}

	return 0;
}*/

//线段树区间乘和模板
#include<bits/stdc++.h>
#define int long long
#define lc p<<1
#define rc p<<1|1   //肯定是偶数二进制最后是0，或1就把最后一位变成1，相当于加1
using namespace std;

const int N = 1e5+10, mod = 571373;
int n, q,m;
int w[N];
struct node {
	int l, r, sum, mul, add;
}tree[4*N];                              //建 4 倍

void push_up(int p)
{
	tree[p].sum = (tree[lc].sum + tree[rc].sum)%mod;                        //%
}

void build(int p,int l,int r)
{
	tree[p] = { l,r,w[l],1,0 };
	if (l == r)return;
	int mid = l + r >> 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	push_up(p);
}

void cal(int p,int m,int a)
{
	tree[p].sum = (tree[p].sum * m + a*(tree[p].r-tree[p].l+1))%mod;        //%
	tree[p].mul = tree[p].mul * m%mod;                                      //%
	tree[p].add = (tree[p].add * m + a)%mod;                                //% 
}

void push_down(int p)
{
	cal(lc, tree[p].mul, tree[p].add);
	cal(rc, tree[p].mul, tree[p].add);
	tree[p].add = 0;
	tree[p].mul = 1;
}

void change(int p,int l,int r,int m,int a)
{
	if (tree[p].l > r || tree[p].r < l)return;
	if (tree[p].l >= l && tree[p].r <= r)
	{
		cal(p, m, a);
		return;
	}
	//int mid = tree[p].l + tree[p].r >> 1;                        //  当我把change和query都写上mid的时候并且change(lc, l, mid, m, a);change(rc, mid + 1, r, m, a);query也那么写就wa了
	push_down(p);
	change(lc, l, r, m, a);
	change(rc, l, r, m, a);
	push_up(p);
}

int query(int p, int l, int r)
{
	//if (tree[p].l > r || tree[p].r < l)return 0;      和下面的判断if要一个就行
	if (tree[p].l > r || tree[p].r < l)return 0;
	if (tree[p].l >= l && tree[p].r <= r)
		return tree[p].sum;
	//int mid = tree[p].l + tree[p].r >> 1;
	push_down(p);
	int sum = 0;
	/*if (mid >= l)*/sum = (sum + query(lc, l, r)) % mod;                          //%
	/*if (mid<r)*/sum = (sum + query(rc, l, r)) % mod;                             //%
	return sum;
}

signed main()
{
	cin >> n >> q >> m;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	build(1,1,n);
	for (int i = 1; i <= q; i++)
	{
		int flag, x, y;
		cin >> flag >> x >> y;
		if (flag == 1)
		{
			int k;
			cin >> k;
			change(1, x, y, k, 0);
		}
		else if (flag == 2)
		{
			int k;
			cin >> k;
			change(1, x, y, 1, k);
		}
		else
			cout << query(1, x, y) << endl;
	}

	return 0;
}