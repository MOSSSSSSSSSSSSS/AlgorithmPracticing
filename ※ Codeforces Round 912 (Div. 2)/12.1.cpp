/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	return 0;
}
*/

// A 以下代码对
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	while (t--)
	{
		int n, k;
		int a[N];
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		if (k >= 2)cout << "YES" << '\n';
		else
		{
			if (is_sorted(a + 1, a + 1 + n))cout << "YES" << 'n';
			else cout << "NO" << '\n';
		}
	}

	return 0;
}*/

// B 以下代码对，不懂看b站教程
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int M[N][N];
int a[N];
int T;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T--)
	{
		int n;
		bool f = false;
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> M[i][j];
		for (int i = 1; i <= n; i++)
		{
			int res = 0x3fffffff;                          //  res必须全是1，不是等于1，1是0000000001
			for (int j = 1; j <= n; j++)
				if(j!=i)
					res &= M[i][j];
			a[i] = res;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i!=j&&M[i][j] != (a[i] | a[j]))
				{
					cout << "NO" << '\n';
					f = true;
					break;
				}
			}
			if (f)break;
		}
		if (!f)
		{
			cout << "YES" << '\n';
			for (int j = 1; j <= n; j++)
				cout << a[j] << ' ';
			cout<<'\n';
		}
	}

	return 0;
}*/
//C
//分析：第一部分*1+第二部分*2+第三部分*3+第四部分*4。。。。。。
//     转化成第一部分+第二部分+第三部分+第四部分+
//           +第二部分+第三部分+第四部分+
//           +第三部分+第四部分+
//           +第四部分
// 需要求出后缀和数组，当后缀是>0的时候就切割
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;
int T;
int a[N];
vector<int> res;
int ans;
int hou[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T--)
	{
		memset(a, 0, sizeof a);
		memset(hou, 0, sizeof hou);
		res.clear();
		ans = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = n; i >= 1; i--)
			hou[i] = hou[i + 1] + a[i];
		for (int i = 1; i <= n; i++)
		{
			ans += a[i];
			if (i + 1 <= n && hou[i + 1] > 0)
				ans += hou[i + 1];
		}
		cout << ans << '\n';
	}

	return 0;
}
