
#include<bits/stdc++.h>
using namespace std;

const int N = 10010,INF = 0x3f3f3f3f;
int fruit[N],s[N], n;
int dp[N][N];    //  �ϲ����ĵ�����Ҫ����С���� dp[i][j] = dp[i][k]+dp[k+1][j]  +  �ϲ��������(  i<=k<=j-1  )

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		fruit[i] = num;
		s[i] = s[i - 1] + fruit[i];
		dp[i][i] = 0;    //    �Ѿ���һ���ˣ���0������num
	}

	for (int i = n; i >= 1; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int k = i; k <= j - 1; k++)
			{
				if(k==i)dp[i][j] = INF;
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]-s[i-1]+s[j]);
			}
		}
	}

	cout << dp[1][n];

	return 0;
}
//   �ϲ�ʯ��ֻ��300������ݣ����������10000�����ݣ����������%%%%%%%����������ʯ�Ӻϲ�����DP������Ϊʯ�Ӻϲ�ֻ�ܺϲ����ڵ����ѣ����Ӻϲ����Ժϲ���������ѣ���̰��
//   ����DP�ǳ��Գ�������������������̫�࣬��ҪһЩ����
//   ���ɣ����ϵ��ó���С�����������ϳ�һ�����Ž�ȥ��ֱ���ϳ�Ϊһ�ѣ���ʱ���ǻ�����С����
//   ���Կ����ã�С����
#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, heap[N], Size, res;

void down(int u)
{
	int t = u;
	if (2 * u <= Size && heap[2 * u] < heap[t])t = 2 * u;
	if (2 * u + 1 <= Size && heap[2 * u + 1] < heap[t])t = 2 * u + 1;
	if (t != u)
	{
		swap(heap[t], heap[u]);
		down(t);
	}
}

void up(int u)
{
	while (u / 2 && heap[u / 2] > heap[u])
	{
		swap(heap[u / 2], heap[u]);
		u /= 2;
	}
}

int main()
{
	cin >> n;
	Size = n;
	for (int i = 1; i <= n; i++)cin >> heap[i];
	for (int i = n / 2; i >= 1; i--)down(i);

	while (Size != 1)
	{
		int ans = 0;
		ans += heap[1];
		//swap(heap[1], heap[Size]);     Ҳ��
		heap[1] = heap[Size];
		Size--;
		down(1);
		ans += heap[1];
		//swap(heap[1], heap[Size]);
		heap[1] = heap[Size];
		Size--;
		down(1);
		heap[++Size] = ans;
		up(Size);            //   up��down���� �±� ����д��ans
		res += ans;           //  ע��res��ans��ʲô��
	}

	cout << res;

	return 0;
}