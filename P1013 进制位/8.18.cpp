


//  ������Ƶļӷ���n-1���ǽ��ƣ���Ϊ���ֻ��һ�⣩������ÿһ���ж��ٸ���λ�ģ���һ�е�һ�������Ǽ���������Ҳ�����ף���Ҳû��λ��
//�ж��ǲ���error�����ж���û���ظ���������û�е��ڻ����n-1��������������������Ӻ�Ľ��

#include<bits/stdc++.h>
using namespace std;

typedef pair<char, int> PCI;
const int N = 10;
int n;
string form[N][N];
PCI ans[N];

int transform(string str)
{
	int res = 0;
	for (int i = 0; i < str.size(); i++)
		for (int j = 1; j <= n - 1; j++)
			if (ans[j].first == str[i])
				res = res * (n - 1) + ans[j].second;

	return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> form[i][j];
			if (j == 0)
				ans[i].first = form[i][j][0];
			if (form[i][j].size() == 2)
				ans[i].second++;
		}
	}
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (ans[i].second == ans[j].second||ans[i].second>=n-1)
			{
				cout << "ERROR!";
				return 0;
			}
		}
	}
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 1; j <= n - 1; j++)
		{
			if (ans[i].second + ans[j].second != transform(form[j][i]))
			{
				cout << "ERROR!";
				return 0;
			}
		}
	}
	for (int i = 1; i <= n - 1; i++)
		cout << form[i][0] << '=' << ans[i].second << ' ';
	cout << endl << n - 1;

	return 0;  
}