
//    ǰ׺�����飬����������ĳ������  �ĺ� ��

#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
string str;
int a[N],sum[N],ans;

int main()
{
	cin >> str;
	for (int i = 1; str[i-1]; i++)
	{
		if (str[i-1] == 'G')          //  str��0��ʼ���룬Ҫ���±�0��ʼ��������  i - 1
			a[i] = 1;
		else
			a[i] = -1;
	}
	for (int i = 1; i <= str.size(); i++)
		sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= str.size(); i++)
	{
		for (int j = i + 1; j <= str.size(); j++)
		{
			if (sum[j] - sum[i - 1] == 0)
				ans = max(ans, j - i + 1);
		}
	}
	cout << ans;

	return 0;
}
