

#include<iostream>
using namespace std;

int t,n,m;
string a, b;

int main()
{
	cin >> t;
	while (t--)
	{
		int cnt = 0;
		cin >> n >> m >> a >> b;
		while (a.find(b) == string::npos && a.size() <= n * m + 10)
		{
			cnt++;
			a += a;
		}
		if (a.find(b) != string::npos)cout << cnt << endl;
		else cout << -1 << endl;
	}

	return 0;
}