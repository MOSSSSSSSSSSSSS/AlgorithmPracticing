

//   ���и����ı������⣬������01�����ı�ʽ��

//���⻹�ã�ÿһ����Ʒ���ֻ��������������ô�����ڶ��������б�����ʱ�򣬾��߾Ͳ����������ˣ����������

//���ǵ�01�����ľ�����ʲô��

//1.��ѡ��Ȼ��ȥ������һ��

//2.ѡ���������������Ǹ���������ֵ�����Ǹ���ֵ��

//�����ľ�����������ֱ��ǣ�

//1.��ѡ��Ȼ��ȥ������һ��

//2.ѡ��ֻѡ�������

//3.ѡ�������������ѡ����1

//4.ѡ�������������ѡ����2

//5.ѡ�������������ѡ����1�͸���2.

#include<bits/stdc++.h>
using namespace std;

const int N = 32010, M = 70;
typedef pair<int, pair<int, int>> PIII;
int money, num,n;
int dp[M][N];
int no[M],idx;
PIII goods[M][4];

int get(int j)
{
	if (goods[j][2].first < goods[j][3].first)return 2;
	else return 3;
}

int main()
{
	cin >> money >> num;
	for (int i = 1; i <= num; i++)
	{
		int v, p, q;
		cin >> v >> p >> q;
		if (q == 0)
		{
			goods[i][1] = { v,{p,q} };
			no[++idx] = i;
		}
		else
		{
			goods[q][goods[q][0].first + 2] = { v,{p,q} };
			goods[q][0].first++;
		}
	}
	n = idx;  //  ���ٸ�����
	for (int j = no[idx]; idx >= 1; idx--)
	{
		j = no[idx];
		for (int i = 1; i <= money; i++)
		{
			if (goods[j][0].first == 2 && i >= goods[j][1].first+goods[j][2].first+goods[j][3].first)
			{
				dp[n - idx + 1][i] = max(dp[n - idx][i], max(dp[n - idx][i - goods[j][1].first]+goods[j][1].first*goods[j][1].second.first, max(dp[n - idx][i - goods[j][1].first - goods[j][2].first] + goods[j][1].first * goods[j][1].second.first+goods[j][2].first*goods[j][2].second.first, max(dp[n - idx][i - goods[j][1].first - goods[j][3].first] + goods[j][1].first * goods[j][1].second.first + goods[j][3].first * goods[j][3].second.first, dp[n - idx][i - goods[j][1].first - goods[j][2].first - goods[j][3].first]+goods[j][1].first * goods[j][1].second.first + goods[j][2].first * goods[j][2].second.first+ goods[j][3].first * goods[j][3].second.first))));
			}
			else if (goods[j][0].first == 2 && i >= goods[j][1].first + goods[j][2].first && i < goods[j][1].first + goods[j][2].first + goods[j][3].first && i >= goods[j][1].first + goods[j][3].first)
			{
				dp[n - idx + 1][i] = max(dp[n-idx][i], max(dp[n-idx][i - goods[j][1].first] + goods[j][1].first * goods[j][1].second.first, max(dp[n-idx][i - goods[j][1].first - goods[j][2].first] + goods[j][1].first * goods[j][1].second.first + goods[j][2].first * goods[j][2].second.first,dp[n-idx][i - goods[j][1].first - goods[j][3].first] + goods[j][1].first * goods[j][1].second.first + goods[j][3].first * goods[j][3].second.first)));
			}
			else if (goods[j][0].first == 2 && i >= goods[j][1].first + min(goods[j][2].first, goods[j][3].first) && i < goods[j][1].first + max(goods[j][2].first, goods[j][3].first))
			{
				dp[n - idx + 1][i] = max(dp[n-idx][i], max(dp[n-idx][i - goods[j][1].first] + goods[j][1].first * goods[j][1].second.first, dp[n-idx][i - goods[j][1].first - min(goods[j][2].first, goods[j][3].first)]+ goods[j][1].first * goods[j][1].second.first+goods[j][get(j)].first* goods[j][get(j)].second.first));
			}
			else if (goods[j][0].first == 2 && i >= goods[j][1].first && i < goods[j][1].first + min(goods[j][2].first, goods[j][3].first))
			{
				dp[n - idx + 1][i] = max(dp[n-idx][i],dp[n-idx][i - goods[j][1].first] + goods[j][1].first * goods[j][1].second.first);
			}
			else if (goods[j][0].first == 2 && i < goods[j][1].first)
			{
				dp[n - idx + 1][i] = dp[n - idx][i];
			}
			else if (goods[j][0].first == 1 && i >= goods[j][1].first + goods[j][2].first)
			{
				dp[n - idx + 1][i] = max(dp[n - idx][i], max(dp[n-idx][i - goods[j][1].first] + goods[j][1].first * goods[j][1].second.first, dp[n-idx][i - goods[j][1].first - goods[j][2].first]+ goods[j][1].first * goods[j][1].second.first + goods[j][2].first * goods[j][2].second.first));
			}
			else if (goods[j][0].first == 1 && i >= goods[j][1].first && i < goods[j][1].first + goods[j][2].first)
			{
				dp[n - idx + 1][i] = max(dp[n - idx][i], dp[n - idx][i - goods[j][1].first] + goods[j][1].first * goods[j][1].second.first);
			}
			else if (goods[j][0].first == 1 && i < goods[j][1].first)
			{
				dp[n - idx + 1][i] = dp[n - idx][i];
			}
			else if (goods[j][0].first == 0 && i >= goods[j][1].first)
			{
				dp[n - idx + 1][i] = max(dp[n - idx][i], dp[n-idx][i - goods[j][1].first] + goods[j][1].first * goods[j][1].second.first);
			}
			else if (goods[j][0].first == 0 && i < goods[j][1].first)
			{
				dp[n - idx + 1][i] = dp[n-idx][i];
			}
		}
	}
	cout << dp[n][money];

	return 0;
}