

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
			//  check[i] = false      ��仰���ܼӣ�ȥ�˵ĵط�����˻�����һ���������˲�����ȥ�ˡ����ָܻ�ԭ�ֳ�����Ϊ���������ȥ��ԭ��һ����ȥ.
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
				if (dfs(i))     // ���±꣬�������Ѿ��ѹ�
				{
					flag = true;
					break;
				}
			}
		}
		if (flag)cout << "Yes" << endl;
		else cout << "No" << endl;
		for (int i = 1; i <= n; i++)check[i] = false;                 //   �кü������ݣ�ÿ�鶼Ҫ�ж�yes��no����һ��yes��֮����ֱ�ӷ���trueû����check��ĸı䣬Ϊ�˲�Ӱ������飬����һ��󣬰�check����ֵfalse
	}



	return 0;
}