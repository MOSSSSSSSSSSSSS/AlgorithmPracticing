

#include<bits/stdc++.h>
using namespace std;

const int N = 40010;
vector<int> prims;
bool vis[N];
int n;
int phi[N];
int ans = 1;

int main()
{
	cin >> n;
	phi[1] = 1;
	for (int i = 2; i <= n - 1; i++)
	{
		if (!vis[i])
		{
			phi[i] = i - 1;
			prims.push_back(i);
		}
		ans += phi[i];
		for (int j = 0; prims[j] <= n / i; j++)
		{
			vis[prims[j] * i] = true;
			if (i % prims[j] == 0)
			{
				phi[i * prims[j]] = prims[j] * phi[i];
				break;
			}
			else
				phi[i * prims[j]] = (prims[j] - 1)* phi[i];
		}
	}
	ans = ans * 2 + 1;
	cout << ans;

	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 1e8+10;
vector<int> prims;
int n,q;
bool vis[N];

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> q;
	for (int i = 2; i <= n; i++)
	{
		if (!vis[i])prims.push_back(i);
		for (int j = 0;prims[j]<=n/i;j++)
		{
			vis[prims[j] * i] = true;
			if (i % prims[j] == 0)break;
		}
	}
	while (q--)
	{
		int idx;
		cin >> idx;
		cout << prims[idx - 1] << '\n';
	}

	return 0;
}


*/