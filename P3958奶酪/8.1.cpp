

#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
struct center {
	long long x;
	long long y;
	long long z;
};
int t;
int n, h, r;
center centers[N];
bool check[N];

double dist(center a, center b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

bool dfs(int u)
{
	check[u] = true;
	if (centers[u].z + r >= h) return true;

	for (int i = 1; i <= n; i++)
	{
		if (dist(centers[u], centers[i]) <= 2 * r && !check[i])
		{
			if (dfs(i))return true;
			//  check[i] = false      这句话不能加，去了的地方如果退回来就一定到不了了不能再去了。不能恢复原现场，因为如果现在能去，原来一定能去.
		}
	}

	return false;
}

int main()
{
	cin >> t;
	while (t--)
	{
		bool flag = false;
		cin >> n >> h >> r;
		for (int i = 1; i <= n; i++)
			cin >> centers[i].x >> centers[i].y >> centers[i].z;
		for (int i = 1; i <= n; i++)
		{
			if (centers[i].z - r <= 0)
			{
				if (dfs(i))     // 搜下标，方便标记已经搜过
				{
					flag = true;
					break;
				}
			}
		}
		if (flag)cout << "Yes" << endl;
		else cout << "No" << endl;
		for (int i = 1; i <= n; i++)check[i] = false;                 //   有好几组数据，每组都要判断yes或no，第一组yes了之后是直接返回true没有让check里的改变，为了不影响后面组，做完一组后，把check都赋值false
	}



	return 0;
}