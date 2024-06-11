

#include<iostream>
using namespace std;

const int N = 30;
int a[N],t;

int main()
{
	cin >> t;
	while (t--)
	{
		bool flag = false;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i < n; i++)
		{
			if (i == 1 || i == 2 || i == 4 || i == 8 || i == 16)continue;
			if (a[i] > a[i + 1])
			{
				flag = true;
				cout << "NO" << endl;
				break;
			}
		}
		if (!flag)cout << "YES" << endl;
	}

	return 0;
}