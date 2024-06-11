

//  另一条对角线映射成行-列+n


#include<bits/stdc++.h>
using namespace std;

const int N = 13, M = 55;
int n, ans;
bool lie[N], dui1[2 * N], dui2[2 * N];
vector<int> res;
void dfs(int u)
{
	if (u == n + 1)
	{
		ans++;
		if (ans < 4)
		{
			for (auto item : res)cout << item << ' ';
			cout << '\n';
		}
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!lie[i] && !dui1[i + u - 1] && !dui2[u - i + n])
		{
			lie[i] = dui1[i + u - 1] = dui2[u - i + n] = true;
			res.push_back(i);
			dfs(u + 1);
			res.pop_back();
			lie[i] = dui1[i + u - 1] = dui2[u - i + n] = false;
		}
	}
}

int main()
{
	cin >> n;
	dfs(1);
	cout << ans;

	return 0;
}