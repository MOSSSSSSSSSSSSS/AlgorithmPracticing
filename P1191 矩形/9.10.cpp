

/*ö�ٵ��Ǿ��ε����½ǣ�ö��ÿһ�����飬�����������Ϊ���½ǵľ��ζ��ٸ�����������*/

#include<bits/stdc++.h>
using namespace std;

const int N = 160,INF = 0x3f3f3f3f;
int n;
char a[N][N];
int ans;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] == 'W')
			{
				int add = 0,hmx = INF;
				for (int k = 0;j+k<=n; k++)
				{
					for (int h = 0;i-h>=1&&h<hmx; h++)
					{
						if (a[i - h][j + k] == 'W')
						{
							add++;
						}
						else
						{
							hmx = min(h, hmx);
							break;
						}
					}
				}
				ans += add;
			}
		}
	}
	cout << ans;
	
	return 0; 
}