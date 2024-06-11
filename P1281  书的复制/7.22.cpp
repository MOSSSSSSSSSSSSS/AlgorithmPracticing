

//二分不一定是  单调的一个数列的  情况下可以使用，其他情况，其他具体问题，也可以用二分，这时候需要写   check函数  if(check)  r = mid;else  l = mid + 1(举个例子)
//讲二分时的模板提到过，所以不要不知道check函数干什么的

#include<bits/stdc++.h>
using namespace std;

const int N = 510;

int m, k,l,r = 1e9;
int a[N], L[N], R[N];

bool check(int sum)
{
	int s = 0, cnt = 1;
	R[cnt] = m;
	for (int i = m; i >= 1; i--)
	{
		if (s + a[i] <= sum)s += a[i];
		else
		{
			L[cnt] = i + 1;
			cnt++;
			R[cnt] = i;
			s = a[i];
		}
	}
	L[cnt] = 1;

	if (cnt<=k)return true;
	else return false;
}

int main()
{
	cin >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &a[i]);
		l = max(l, a[i]);
	}

	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}

	check(l);
	for (int i = k; i >= 1; i--)
		cout << L[i] << ' ' << R[i] << endl;
	

	return 0;
}