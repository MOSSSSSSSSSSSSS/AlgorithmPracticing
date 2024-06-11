

#include<bits/stdc++.h>
using namespace std;

const int N = 30;
int n,m;
int g[N][N];
bool vis[N];

void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				g[i][j] |= (g[i][k] && g[k][j]);
}

bool que_ding()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j && !g[i][j] && !g[j][i])
				return false;
	return true;
}

bool mao_dun()
{
	for (int i = 1; i <= n; i++)
		if (g[i][i] == 1)
			return true;
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		char str[4];
		cin >> str;
		int a = str[0] - 'A'+1, b = str[2] - 'A'+1;
		g[a][b] = 1;
		floyd();
		if (mao_dun())
		{
			cout << "Inconsistency found after ";
			cout << i << ' ';
			cout << "relations.";
			return 0;
		}
		if (que_ding())
		{
			cout << "Sorted sequence determined after ";
			cout << i << ' ';
			cout << "relations: ";
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (!vis[j])
					{
						bool flag = true;
						for (int k = 1; k <= n; k++)
						{
							if (k != j && !vis[k] && !g[j][k])
							{
								flag = false;
								break;
							}
						}
						if (flag == true)
						{
							vis[j] = true;
							cout << char(j + 'A'-1);
							break;
						}
					}
				}
			}
			cout << '.';
			return 0;
		}
		else if (i == m)
			cout << "Sorted sequence cannot be determined.";
	}

	return 0;
}