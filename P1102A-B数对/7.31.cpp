

#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
int n, c;
int a[N];
long long ans;    //   注意 有时候要用 long long

int main()
{
	cin >> n >> c;
	for (int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + 1 + n);
	int l = 1, r = 2;
	while (r <= n && l <= n)
	{
		if (a[r] - a[l] > c)l++;
		else if (a[r] - a[l] < c)r++;
		else if (a[r] - a[l] == c)
		{
			int l2 = l + 1;
			while (a[l2] == a[l] && l2 < n)l2++;
			int r2 = r + 1;
			while (a[r2] == a[r] && r2 <= n)r2++;
			ans += (long long)(r2 - r) * (long long)(l2 - l);   //  在分配给long long之前，乘积的结果仍然是int型，所以要存在long long中
			r = r2;
			l = l2;
		}
	}

	cout << ans;

	return 0;
}

/*#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
int n, c;
int a[N];
long long ans;    //   注意 有时候要用 long long

int main()
{
	cin >> n >> c;
	for (int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + 1 + n);
	int l = 1, r = 2;
	while (r <= n && l <= n)
	{
		if (a[r] - a[l] > c)l++;
		else if (a[r] - a[l] < c)r++;
		else if (a[r] - a[l] == c)
		{
			int l2 = l + 1;
			while (a[l2] == a[l] && l2 < n)l2++;
			ans += (l2 - l);
			r++;
		}
	}

	cout << ans;

	return 0;
*/
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
int n, c, ans;
int a[N];

int main()
{
	cin >> n >> c;
	for (int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + 1 + n);
	int l = 1, r = 2;
	while (r <= n && l <= n)
	{
		if (a[r] - a[l] > c)l++;
		else if (a[r] - a[l] < c)r++;
		else if (a[r] - a[l] == c)
		{
			ans++;
			if (l + 1 <= n && a[l + 1] == a[l] && r + 1 <= n && a[r + 1] == a[r])
			{
				ans++;
				l++;
			}
			else if (l + 1 <= n && a[l + 1] == a[l])l++;
			else if (r + 1 <= n && a[r + 1] == a[r])r++;
			else l++;
		}
	}

	cout << ans;

	return 0;
}
*/