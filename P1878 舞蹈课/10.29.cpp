

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
struct dogs {
	int num, l, r;
	friend bool operator <(dogs a, dogs b)
	{
		if (a.num == b.num)return a.l > b.l;
		else return a.num > b.num;
	}
};
const int N = 2e5 + 10;
priority_queue<dogs> heap;
int n, a[N];
char sex[N];
bool st[N];
vector<PII> ans;
int wcnm[N];
int nmsl[N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> sex[i];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 2; i <= n; i++)
		wcnm[i] = i - 1;
	for (int i = 1; i < n; i++)
		nmsl[i] = i + 1;
	for (int i = 1; i < n; i++)
	{
		if (sex[i] != sex[i + 1])
		{
			heap.push({ abs(a[i] - a[i + 1]),i ,i+1});
		}
	}
	while (heap.size())
	{
		dogs tt = heap.top();
		heap.pop();
		if (!st[tt.l] && !st[tt.r])
		{
			ans.push_back({tt.l,tt.r});
			st[tt.l] = st[tt.r] = true;
			wcnm[nmsl[tt.r]] = wcnm[tt.l];
			nmsl[wcnm[tt.l]] = nmsl[tt.r];
			int l = wcnm[tt.l], r = nmsl[tt.r];
			if (l&&r &&sex[l]!=sex[r])heap.push({abs(a[l] - a[r]),l,r});
		}
		
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << endl;

	return 0;
}