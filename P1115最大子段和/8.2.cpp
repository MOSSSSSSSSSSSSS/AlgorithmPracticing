


//   ���ⲻ������DP������Dp����ö�����������̫��
//    ͨ��ά��һ�����У������кͼ���һ�¸����ĺʹ�����һ�������Ͱ�������Ž�����С�ھ�ֱ��
//     ����һ������Ϊ�����У�����Ҳ�ǣ�ÿ�ζ���ans = max(ans,��ǰ)


#include<bits/stdc++.h>
using namespace std;

const int N = 200010,INF = 1e9;
int n, a[N],sum;
int ans = -INF;
vector<int> now;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];

	now.push_back(a[1]);
	sum = a[1];
	ans = a[1];
	for (int i = 2; i <= n; i++)
	{
		if (sum + a[i] <= a[i])
		{
			now.clear();
			now.push_back(a[i]);
			sum = a[i];
		}
		else
		{
			now.push_back(a[i]);
			sum += a[i];
		}
		ans = max(ans, sum);
	}

	cout << ans;

	return 0;
}