
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10,M = 1e7+10;
int n;
unsigned long long ans;
queue<int> q1, q2;
int cnt[N],a[M];

inline void read(int& x) {
	int f = 1; x = 0; char s = getchar();
	while (s < '0' || s>'9') { if (s == '-')f = -1; s = getchar(); }
	while (s >= '0' && s <= '9') { x = x * 10 + s - '0'; s = getchar(); }
	x *= f;
}
int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		read(x);
		cnt[x]++;
	}
	for (int i = 1; i < N; i++)
		for (int j = 1; j <= cnt[i]; j++)
			q1.push(i);
	while (true)
	{
		int cnm = 0;
		int res = 0;
		if (q1.size())res = q1.front();
		if (q2.size()&&(res > q2.front()||res==0))
		{
			res = q2.front();
			q2.pop();
		}
		else
			q1.pop();
		ans += res;
		cnm += res;
		res = 0;
		if (q1.size())res = q1.front();
		if (q2.size() && (res > q2.front() || res == 0))
		{
			res = q2.front();
			q2.pop();
		}
		else
			q1.pop();
		ans += res;
		cnm += res;
		q2.push(cnm);
		if (q1.size() == 0 && q2.size() == 1)break;
	}
	cout << ans;

	return 0;
}