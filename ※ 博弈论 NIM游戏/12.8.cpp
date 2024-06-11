

//  若先手必胜，则应该在哪拿多少？
//  其实就是考察关于异或的运算

#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
int k;
int a[N];

int main()
{
	cin >> k;
	int res = 0;
	for (int i = 1; i <= k; i++)
	{
		cin >> a[i];
		res ^= a[i];
	}
	if (res == 0)cout << "lose" << endl;
	else
	{
		for (int i = 1; i <= k; i++)
		{
			if (a[i] > (a[i] ^ res))
			{
				cout << a[i] - (a[i] ^ res) << ' ' << i << endl;
				a[i] = (a[i] ^ res);
				break;
			}
		}
		for (int i = 1; i <= k; i++)
		{
			cout << a[i] << ' ';
		}
		cout << endl;
	}

	return 0;
}