

//  ������Ҫע��ĵ�
//1.һ���㱻ѡ�о���check[x][y] = 1����һ�����ܲ��ܱ�ѡ���ǿ�һ������Χ��û��checkΪ1�ģ����û�п��Ա�ѡ
//  �����ǣ�һ���㱻ѡ�о�����Χ���еĵ㶼check[x][y] = 1��һ����ѡ�к���ɾ�����ᵼ����Χ���еĵ�check�ֱ�Ϊ0����������Χ�ĵ����Χ�ĵ������1������Χ�ĵ��ǲ��ܱ�Ϊ0�ģ��������ַ�������ִ���
//2.dfs�е�����ѭ��Ҫ��Ŀǰ�ҵĵ����ĵ����ң����ÿ�ζ�ȫ��һ��ᳬʱ��ͬһ���𰸻���ü���
//���� ͬһ���𰸿��ܴ�ǰ��������һ�飬�ִӵڶ����ҵ�һ���ҵ������ҵ��ĸ���һ�飬�ִӺ���ǰ��һ�顣


#include<bits/stdc++.h>
using namespace std;

const int N = 15;
int t, n, m;
int num[N][N],ans;
bool check[N][N];
int dx[9] = { 1,1,0,-1,-1,-1,0,1 ,0 };
int dy[9] = { 0,-1,-1,-1,0,1,1,1 ,0 };

bool judge(int x, int y)
{
	for (int i = 0; i < 9; i++)
		if (x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= m&& check[x + dx[i]][y + dy[i]])
			return false;
	return true;
}

void dfs(int x,int y,int add)
{
	add += num[x][y];
	check[x][y] = 1;

	for (int i = x; i <= n; i++)
	{
		int j;
		if (i == x)
			j = y + 2;
		else
			j = 1;
		for (; j <= m; j++)
		{
			if (judge(i,j))
			{
				dfs(i,j,add);
				check[i][j] = 0;
			}
		}
	}

	ans = max(ans, add);
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> num[i][j];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				dfs(i, j, 0);
				check[i][j] = 0;
			}
		}
		cout << ans << endl;
		ans = 0;
	}

	return 0;
}