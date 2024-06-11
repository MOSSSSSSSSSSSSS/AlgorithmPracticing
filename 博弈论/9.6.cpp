
// nim游戏属于公平组合游戏(ICG)
// nim取石子游戏结论：a1^a2^a3.....^an = 0，先手必败，！=0，先手必胜


#include<bits/stdc++.h>
using namespace std;

int T;

int main()
{
	cin >> T;
	while (T--)
	{
		int n,res = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			res ^= x;
		}
		if (res == 0)cout << "No" << endl;
		else cout << "Yes" << endl;
	}

	return 0;
}