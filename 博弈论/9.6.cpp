
// nim��Ϸ���ڹ�ƽ�����Ϸ(ICG)
// nimȡʯ����Ϸ���ۣ�a1^a2^a3.....^an = 0�����ֱذܣ���=0�����ֱ�ʤ


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