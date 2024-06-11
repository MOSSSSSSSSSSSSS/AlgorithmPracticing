

#include<bits/stdc++.h>
using namespace std;

const int N = 20;
int t;

int main()
{
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int per[N];
		for (int i = 1; i <= n; i++)
			cin >> per[i];
		for (int i = 2; i <= n-1; i++)
			if (per[i] > per[i - 1] && per[i] > per[i + 1])
				swap(per[i],per[i + 1]);
		for (int i = 2; i <= n - 1; i++)
			if (per[i] > per[i - 1] && per[i] > per[i + 1])
				swap(per[i], per[i + 1]);
		for (int i = 2; i <= n - 1; i++)
			if (per[i] > per[i - 1] && per[i] > per[i + 1])
				swap(per[i], per[i + 1]);
		for (int i = 2; i <= n - 1; i++)
			if (per[i] > per[i - 1] && per[i] > per[i + 1])
				swap(per[i], per[i + 1]);
		for (int i = 2; i <= n - 1; i++)
			if (per[i] > per[i - 1] && per[i] > per[i + 1])
				swap(per[i], per[i + 1]);
		for (int i = 2; i <= n - 1; i++)
			if (per[i] > per[i - 1] && per[i] > per[i + 1])
				swap(per[i], per[i + 1]);
		for (int i = 2; i <= n - 1; i++)
			if (per[i] > per[i - 1] && per[i] > per[i + 1])
				swap(per[i], per[i + 1]);
		for (int i = 2; i <= n - 1; i++)
			if (per[i] > per[i - 1] && per[i] > per[i + 1])
				swap(per[i], per[i + 1]);
		for (int i = 2; i <= n - 1; i++)
			if (per[i] > per[i - 1] && per[i] > per[i + 1])
				swap(per[i], per[i + 1]);
		for (int i = 2; i <= n - 1; i++)
			if (per[i] > per[i - 1] && per[i] > per[i + 1])
				swap(per[i], per[i + 1]);
		if (is_sorted(per + 1, per + 1 + n))cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}