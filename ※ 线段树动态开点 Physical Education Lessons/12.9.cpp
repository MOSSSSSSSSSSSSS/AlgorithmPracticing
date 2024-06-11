

//  动态开点线段树：当空间太大，直接开那么大的空间会出错时，使用动态开点线段树
//  不需要把所有的线段树上的点都开出来，通过计算，得到要开的点的个数，开相应个数的点
//  不再用2*n，2*n+1表示左儿子右儿子，而是用ls，rs记录左右儿子编号，注意是 向下找的时候 判断有没有儿子，检查是不是要开点

//  记得再算一下空间 ，m个操作，每个操作最多开辟新的 2*logn个节点，
//  空间是  2 * 3e5 * log(1e9) * 6 * 4 = 432M > 250M
//  但是  2*logn  是达不到的，不一定每次都是60（2*log1e9），可以取到30，也就是 N = 1e7，而不是N = 4*1e9   但这样也会 MLE
//  这道题不能把 l，r，也就是每个节点维护的哪个区间记录下来，否则浪费空间，应该作为  函数的参数  ，改之后，轻松ac
#include<bits/stdc++.h>
using namespace std;

const int N = 1.4e7;
struct edge {
	int ls, rs, sum, tag = -1;//sum这个区间多少非工作日，因为一开始sum是0
}tr[N];
int idx = 1; ////////////////////////////////////////////////////
int n, q;

void pushup(int u)
{
	tr[u].sum = tr[tr[u].ls].sum + tr[tr[u].rs].sum;
}
void pushdown(int u,int l,int r)
{
	if (tr[u].tag != -1)
	{
		if (!tr[u].ls)  // 动态开点
		{
			tr[u].ls = ++idx;
		}
		if (!tr[u].rs)  // 动态开点
		{
			tr[u].rs = ++idx;
		}
		tr[tr[u].ls].tag = tr[tr[u].rs].tag = tr[u].tag;
		int mid = l + r >> 1;
		tr[tr[u].ls].sum = tr[u].tag * (mid - l + 1);
		tr[tr[u].rs].sum = tr[u].tag * (r - mid);
		tr[u].tag = -1;
	}
}
void modify(int u, int ll,int rr,int l, int r, int k)
{
	if (l <= ll && rr <= r)
	{
		tr[u].tag = k;
		tr[u].sum = k * (rr - ll + 1);
		return;
	}
	pushdown(u,ll,rr);
	int mid = ll + rr >> 1;
	if (l <= mid)
	{
		if (!tr[u].ls)
		{
			tr[u].ls = ++idx;
		}
		modify(tr[u].ls, ll,mid,l, r, k);
	}
	if (r >= mid + 1)
	{
		if (!tr[u].rs)
		{
			tr[u].rs = ++idx;
		}
		modify(tr[u].rs,mid+1,rr, l, r, k);
	}
	pushup(u);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);//////////////////////////////  cf上的题 防TLE
	cin >> n >> q;
	for (int i = 1; i <= q; i++)
	{
		int l, r, k;
		cin >> l >> r >> k;
		if (k == 1)modify(1,1,n ,l, r, 1);/////////////////////////////////////////////////////////
		else modify(1,1,n ,l, r, 0);/////////////////////////////////////////////////////////
		cout << n - tr[1].sum << '\n';
	}

	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e7;
struct edge {
	int l, r, ls, rs, sum, tag = -1;//sum这个区间多少非工作日，因为一开始sum是0
}tr[N];
int idx = 1; ////////////////////////////////////////////////////
int n, q;

void pushup(int u)
{
	tr[u].sum = tr[tr[u].ls].sum + tr[tr[u].rs].sum;
}
void pushdown(int u)
{
	if (tr[u].tag != -1)
	{
		if (!tr[u].ls)  // 动态开点
		{
			tr[u].ls = ++idx;
			tr[tr[u].ls].l = tr[u].l;
			tr[tr[u].ls].r = tr[u].l + tr[u].r >> 1;
		}
		if (!tr[u].rs)  // 动态开点
		{
			tr[u].rs = ++idx;
			tr[tr[u].rs].l = (tr[u].l + tr[u].r >> 1) + 1;
			tr[tr[u].rs].r = tr[u].r;
		}
		tr[tr[u].ls].tag = tr[tr[u].rs].tag = tr[u].tag;
		tr[tr[u].ls].sum = tr[u].tag * (tr[tr[u].ls].r - tr[tr[u].ls].l + 1);
		tr[tr[u].rs].sum = tr[u].tag * (tr[tr[u].rs].r - tr[tr[u].rs].l + 1);
		tr[u].tag = -1;
	}
}
void modify(int u, int l, int r, int k)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		tr[u].tag = k;
		tr[u].sum = k * (tr[u].r - tr[u].l + 1);
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)
	{
		if (!tr[u].ls)
		{
			tr[u].ls = ++idx;
			tr[tr[u].ls].l = tr[u].l;
			tr[tr[u].ls].r = mid;
		}
		modify(tr[u].ls, l, r, k);
	}
	if (r >= mid + 1)
	{
		if (!tr[u].rs)
		{
			tr[u].rs = ++idx;
			tr[tr[u].rs].l = mid + 1;
			tr[tr[u].rs].r = tr[u].r;
		}
		modify(tr[u].rs, l, r, k);
	}
	pushup(u);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);//////////////////////////////  cf上的题 防TLE
	cin >> n >> q;
	tr[1].l = 1, tr[1].r = n;///////////////////////////////////////////////////////////
	for (int i = 1; i <= q; i++)
	{
		int l, r, k;
		cin >> l >> r >> k;
		if (k == 1)
			modify(1, l, r, 1);/////////////////////////////////////////////////////////
		else
			modify(1, l, r, 0);/////////////////////////////////////////////////////////
		cout << n - tr[1].sum << '\n';
	}

	return 0;
}*/