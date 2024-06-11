

#include<bits/stdc++.h>
using namespace std;

const int N = 300010, M = 1010;
int m, s, t,Max;

int check(int t,int m)
{
	int ans = 0,t0 = t;
	while (t > 0)
	{
		if (m >= 10)
		{
			t--;
			ans += 60;
			m -= 10;
		}
		else if (m >= 6 && t >= 2)
		{
			t -= 2;
			m -= 6;
			ans += 60;
		}
		else if (m >= 2 && t >= 3)
		{
			t -= 3;
			ans += 60;
			m -= 2;
		}
		else if (m <= 1 && t >= 7)
		{
			t -= 7;
			ans += 120;
		}
		else
		{
			ans += (t * 17);
			t = 0;
		}
	}

	if (ans >= s)return ans;
	else
	{
		Max = ans;
		return 0;
	}
}

int main()
{
	cin >> m >> s >> t;
	int i = t;
	for (; i > 0; i--)
		if (!check(i, m))
			break;

	if (i == t)cout << "No" << endl << Max;
	else cout << "Yes" << endl << i + 1;

	return 0;
}