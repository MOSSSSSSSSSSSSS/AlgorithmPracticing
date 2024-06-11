/*����һ��n���ڵ���и��������Ϊ1��n,1, 
 �ŵ�Ϊ���ڵ���ÿ���ڵ� �м�ֵ���������������Ϊ�����������ĳ�ڵ�ѡ�ˣ������������� 
 ��Ҫѡ�������£�ʹѡ�����Ʒ����ܼ�ֵ�����*/

/*���Ƕ��巺����ƷΪû�й̶��ķ��ã�������ͼ�ֵ����ֵ����ã�������ɺ�����ϵ����Ʒ��������Ʒ������һ��һά���� 
 ������������ f [i] ����Ϊ�����Ϊiʱ������Ʒ������ֵ��*/

//  �����Ǹ�ɭ�֣�������0�����и��ڵ������������һ����

#include<bits/stdc++.h>
using namespace std;

const int N = 310;
int f[N][N][N];
int n, m;
int h[N], e[N], ne[N], idx;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs(int u)
{
	for (int i = h[u]; ~i; i = ne[i])
		dfs(e[i]);
	for (int i = h[u]; ~i; i = ne[i])
		for (int j = m + 1; j >= 1; j--)
			for (int k = 0; k <= j - 1; k++)
				f[u][j] = max(f[u][j], f[u][j - k] + f[e[i]][k]);
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, i),f[i][1] = b;       //  f[i][w[i]] = v[i]
	}
	dfs(0);
	cout << f[0][m + 1];

	return 0;
}