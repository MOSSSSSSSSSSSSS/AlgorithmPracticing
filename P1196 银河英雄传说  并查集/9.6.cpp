


//带权并查集：多两个数组：集合大小数组和每个点到头节点距离数组

#include<bits/stdc++.h>
using namespace std;

const int N = 30010;
int T;
int p[N],dis[N],num[N];

int find(int x)
{
	int k = p[x];
	if (x != p[x])p[x] = find(p[x]);
	dis[x] += dis[k];
	num[x] = num[k];
	return p[x];
}

int main()
{
	cin >> T;
	for (int i = 1; i <= 30000; i++)
	{
		p[i] = i;
		dis[i] = 0;
		num[i] = 1;
	}
	while (T--)
	{
		char flag;
		int x, y;
		cin >> flag >> x >> y;
		if (flag == 'M')
		{
			int dx = find(x);   //  因为下面多次用到dx，dy，就不用多从调用find函数了
			int dy = find(y);   //  因为下面多次用到dx，dy，就不用多从调用find函数了
			p[dx] = dy;
			dis[dx] += num[dy];
			num[dx] += num[dy];
			num[dy] = num[dx];
		}
		else
		{
			if (find(x) != find(y))
				cout << -1 << endl;
			else
				cout << abs(dis[x] - dis[y]) - 1 << endl;
		}
	}

	return 0;
}