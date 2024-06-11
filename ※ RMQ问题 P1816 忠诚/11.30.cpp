

//  可以用st表解决RMQ问题，也可以把数列建成笛卡尔树，权值符合堆的性质，下标符合二叉查找树的性质，
//  通过LCA求区间最小值，或区间最大值，笛卡尔树在range top k问题中也有广泛应用

//  也可以通过树状数组解决，树状数组维护的不再是区间和，而是区间最值
//  建树状数组的时候通过modify一个一个建就可以,nlogn复杂度

// 但是查询要查询l到r区间内的最大最小值，树状数组只能查询1到n区间的最大最小值，这时：
/*考虑拆开[x,y]这个区间。以下，我们分两种情况讨论
The first case： 当y−lowbit(y)>x时显然，我们可以把[x,y]拆成
[x,y−lowbit(y)] 和[y−lowbit(y)+1,y]。拆成这个样子有什么好处呢？如果再细心一点，可以发现
[y−lowbit(y)+1,y]其实就是tree[y]。 这里可以自己口算一下验证。
这样，我们求最值的区间直接减小了一半。效率其实还不错。
The second case： 当y−lowbit(y)<x
这种情况下，由于y−lowbit(y)会超过左区间范围，这个时候，考虑直接把[x,y]拆为
[x,y−1] 与 a[y]。这样看似只拆了一个出来，但是拆过后[x,y−1]区间可能就满足了第一种情况。 所以效率其实也很不错。
然后，上述过程用递归完成即可。当递归到某一层，x==y，这个时候返回a[x]或者a[y]即可
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10,INF = 1e9;
int n, m;
int a[N];
int tr[N];

int lowbit(int p)
{
	return p & (-p);
}
void modify(int p, int x)
{
	while (p < N)
	{
		tr[p] = min(tr[p], x);
		p += lowbit(p);
	}
}
int query(int l,int r)
{
	if (l < r)
	{
		if (l <= r - lowbit(r))return min(query(l, r - lowbit(r)), tr[r]);
		else return min(a[r], query(l, r - 1));
	}
	return a[l];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(tr, 0x3f, sizeof tr);
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		modify(i, a[i]);
	while (n--)
	{
		int l, r;
		cin >> l >> r;
		cout << query(l, r) << ' ';
	}

	return 0;
}