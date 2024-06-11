

//  ��̬�����߶��������ռ�̫��ֱ�ӿ���ô��Ŀռ�����ʱ��ʹ�ö�̬�����߶���
//  ����Ҫ�����е��߶����ϵĵ㶼��������ͨ�����㣬�õ�Ҫ���ĵ�ĸ���������Ӧ�����ĵ�
//  ������2*n��2*n+1��ʾ������Ҷ��ӣ�������ls��rs��¼���Ҷ��ӱ�ţ�ע���� �����ҵ�ʱ�� �ж���û�ж��ӣ�����ǲ���Ҫ����

//  �ǵ�����һ�¿ռ� ��m��������ÿ��������࿪���µ� 2*logn���ڵ㣬
//  �ռ���  2 * 3e5 * log(1e9) * 6 * 4 = 432M > 250M
//  ����  2*logn  �Ǵﲻ���ģ���һ��ÿ�ζ���60��2*log1e9��������ȡ��30��Ҳ���� N = 1e7��������N = 4*1e9   ������Ҳ�� MLE
//  ����ⲻ�ܰ� l��r��Ҳ����ÿ���ڵ�ά�����ĸ������¼�����������˷ѿռ䣬Ӧ����Ϊ  �����Ĳ���  ����֮������ac
#include<bits/stdc++.h>
using namespace std;

const int N = 1.4e7;
struct edge {
	int ls, rs, sum, tag = -1;//sum���������ٷǹ����գ���Ϊһ��ʼsum��0
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
		if (!tr[u].ls)  // ��̬����
		{
			tr[u].ls = ++idx;
		}
		if (!tr[u].rs)  // ��̬����
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
	cout.tie(nullptr);//////////////////////////////  cf�ϵ��� ��TLE
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
	int l, r, ls, rs, sum, tag = -1;//sum���������ٷǹ����գ���Ϊһ��ʼsum��0
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
		if (!tr[u].ls)  // ��̬����
		{
			tr[u].ls = ++idx;
			tr[tr[u].ls].l = tr[u].l;
			tr[tr[u].ls].r = tr[u].l + tr[u].r >> 1;
		}
		if (!tr[u].rs)  // ��̬����
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
	cout.tie(nullptr);//////////////////////////////  cf�ϵ��� ��TLE
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