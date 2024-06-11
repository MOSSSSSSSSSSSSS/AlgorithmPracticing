

//染色做的，图可能是不连通的，每个连通块中找染色较少的颜色数量，最后把各个连通块的数加起来
//   注意不是连通图，而是有多个连通块的不连通的图，所以每个连通块中找染色较少的颜色数量，最后把各个连通块的数加起来



#include<bits/stdc++.h>
using namespace std;

const int N = 10010, M = 200010;
int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool dfs(int x, int c)
{
	color[x] = c;

	for (int i = h[x]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!color[j])
		{
			if (!dfs(j, 3 - c))
				return false;
		}
		else if (color[j] == c)
			return false;
	}
	return true;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	bool flag = true;
	int ans = 0;
	int num_of_1 = 0;
	int num_of_2 = 0;
	int bef1 = 0;
	int bef2 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!color[i])
		{
			if (!dfs(i, 1))
			{
				flag = false;
				break;
			}
			int now1 = 0,now2 = 0;
			for (int i = 1; i <= n; i++)
			{
				if (color[i] == 1)
					now1++;
				else if(color[i]==2)
					now2++;
			}
			num_of_1 = now1 - bef1;
			num_of_2 = now2 - bef2;
			bef1 = now1;
			bef2 = now2;
			ans += min(num_of_1, num_of_2);
		}
	}
	if (!flag)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	cout << ans;

	return 0;
}