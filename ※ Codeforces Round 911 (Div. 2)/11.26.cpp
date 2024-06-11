/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	return 0;
}
*/

// A
/*
#include<bits/stdc++.h>
using namespace std;

int t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	while (t--)
	{
		int n,cnt = 0;
		bool flag = false;
		string s;
		cin >> n;
		cin >> s;
		for (int i = 0; i < s.size() - 2; i++)
		{
			if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.')
			{
				flag = true;
				cout << 2 << endl;
				break;
			}
		}
		if (flag)continue;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == '.')
				cnt++;
		cout << cnt << endl;
	}

	return 0;
}
*/

//B
/*
#include<bits/stdc++.h>
using namespace std;

int t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	while (t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (b == c)cout << 1 << ' ';
		else
		{
			int x = abs(b - c);
			if (x % 2 == 0)
			{
				int y = x / 2;
				if (a >= y)cout << 1 << ' ';
				else cout << 0 << ' ';
			}
			else
			{
				cout << 0 << ' ';
			}
		}
		if (a == c)cout << 1 << ' ';
		else
		{
			int x = abs(a - c);
			if (x % 2 == 0)
			{
				int y = x / 2;
				if (b >= y)cout << 1 << ' ';
				else cout << 0 << ' ';
			}
			else
			{
				cout << 0 << ' ';
			}
		}
		if (a == b)cout << 1 << ' ';
		else
		{
			int x = abs(a - b);
			if (x % 2 == 0)
			{
				int y = x / 2;
				if (c >= y)cout << 1 << ' ';
				else cout << 0 << ' ';
			}
			else
			{
				cout << 0 << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
*/

//C

#include<bits/stdc++.h>
using namespace std;

const int N = 8e4 + 10;
int t;
int a[N];

int gcd(int a, int b)
{
	return (b ? gcd(b, a % b) : a);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	while (t--)
	{
		int n;
		int ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + 1 + n);
		for (int i = 1; i < n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				ans += (gcd(a[i], a[j])*(n-j));
			}
		}
		cout << ans << '\n';
	}

	return 0;
}