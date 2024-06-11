

//  求数组中一个数右边离他最远比他小的数，没有输出-1

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int n;
struct node {
	int v, order;
}a[N];
int b[N];
int tr[N];
vector<int> wcnm;
int p;

int lb(int x)
{
	return x & (-x);
}
void pushup(int p,int x)
{
	while (p < N)
	{
		tr[p] = max(tr[p], x);
		p += lb(p);
	}
}
int query(int p)
{
	p--;
	int res = 0;
	while (p)
	{
		res = max(res, tr[p]);
		p -= lb(p);
	}
	return res;
}

bool cmp(node a, node b)
{
	return a.v < b.v;
}

signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].v, a[i].order = i;
	a[0].v = a[1].v + 1;
	sort(a + 1, a + 1 + n,cmp);
	//for (int i = 1; i <= n; i++)
		//b[a[i].order] = i;                       //  这样离散化不对，相同的值变得不同了
	for (int i = 1; i <= n; ++i) b[a[i].order] = a[i].v == a[i - 1].v ? p : ++p;
	for (int i = n; i >= 1; i--)
	{
		int ans = query(b[i]);
		if (ans == 0)wcnm.push_back(-1);
		else wcnm.push_back(ans - i - 1);
		pushup(b[i], i);
	}
	for (int i = wcnm.size() - 1; i >= 0; i--)
		cout << wcnm[i] << ' ';

	return 0;
}

/*
#include <bits/stdc++.h>
#define maxn 100010
#define _ 0
using namespace std;
struct data{
	int x, id;
}b[maxn];
int n, a[maxn], ans[maxn], tree[maxn], p;

inline int read(){
	int s = 0, w = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') w = -1;
	for (; isdigit(c); c = getchar()) s = (s << 1) + (s << 3) + (c ^ 48);
	return s * w;
}

bool cmp(data x, data y){ return x.x < y.x; }
void update(int x, int y){ for (; x <= p; x += x & -x) tree[x] = max(tree[x], y); }
int query(int x){ int sum = 0; for (; x; x -= x & -x) sum = max(sum, tree[x]); return sum; }

int main(){
	n = read();
	for (int i = 1; i <= n; ++i) b[i] = (data){read(), i};
	sort(b + 1, b + 1 + n, cmp);
	b[0].x = b[1].x + 1;
	
	for (int i = n; i; --i){
		ans[i] = max(-1, query(a[i] - 1) - i - 1);
		update(a[i], i);
	}
	for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
	return 0 ^ _ ^ 0;
}
*/