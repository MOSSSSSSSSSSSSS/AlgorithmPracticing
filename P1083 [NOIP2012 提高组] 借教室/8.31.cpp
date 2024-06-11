


#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
int n, m;
int sum[N],a[N];
int l[N], r[N], c[N];          //  必须都记录下来，而不是一个一个while(m--)不记录，再二分

void insert(int l, int r, int c)
{
	a[l] -= c;            //   注意-=，+=顺序，别上面的写+=（根据题意，是减小的）
	a[r + 1] += c;           //   注意%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5
}  //%%%%%%%%%%%%%%%%%%%%%%%%%%%% 获得差分数组时必须上面的是+=，下边的是-=
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%555
bool check(int mid)
{
	for (int i = 1; i <= n; i++)
		a[i] = 0;
	for (int i = 1; i <= n; i++)
		insert(i, i, -sum[i]);           //   理解好这一步是求差分数组，a[]要是从所有都是0开始，所以前一步先把以前有的全部清零
	for (int i = 1; i <= mid; i++)
		insert(l[i], r[i], c[i]);
	for (int i = 1; i <= n; i++)
	{
		a[i] = a[i - 1] + a[i];
		if (a[i] < 0)return 0;
	}
	return 1;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> sum[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> c[i] >> l[i] >> r[i];
	}
	int left = 1, right = m;
	while (left < right)
	{
		int mid = left + right >> 1;    
		if (!check(mid))right = mid;          
		else left = mid + 1;
	}
	if (left < m)
	{
		cout << -1 << endl << left;
	}
	else                              //   注意还有一种情况是不缺教室的情况，模拟一下就知道其实mid = m时是直接退出的，所以不能确定  m 到底缺不缺，需要最后再判断
	{
		if (check(m))cout << 0;
		else cout << -1 << endl << m;
	}

	return 0;
}