

//              ע�⣺ʲô��sizeof������ʲô��size��������Ҫ��string���ַ������õ���  .size()����ĳ��������ռ�ֽڴ�С����  sizeof(int)
//                    ����û���壬�˷�ʱ��
//                    ��Ҫע��    string �� size��������С������β�㣬�����ַ�������


#include<bits/stdc++.h>
using namespace std;

const int N = 30;
int n;
char head;
string words[N];
int times[N];
int ans,res;

void dfs(int u)
{
	times[u]++;
	for (int i = 1; i <= n; i++)
	{
		int num = 0;
		for (int j = 1; j < min(words[u].size(), words[i].size()); j++)
		{
			if (words[u].substr(words[u].size() - j, j) == words[i].substr(0, j))                //   ��substr  ��  �Ӵ�  Ҫע���������һ����ĸ����һ������Ҫ�˳�ѭ��������ǰ������һ����
			{
				num = j;
				break;
			}
		}//    Ϊʲôbreak��Ҳ�������һ�����ͳ����˶��������ⲻͬ������ abbb, bbbcde ����������Ӧ��ֻ�ϲ�һ�� b���� abbbbbcde������ 3 �� b ���ϲ����� ����������num��ֵ��ֱ��break
		if (num >= 1&&times[i]<2)
		{
			res += (words[i].size() - num);
			dfs(i);
			times[i]--;
			res -= (words[i].size() - num);
		}
	}

	ans = max(ans, res);                    //     �����д�ʱ��ÿ����ĩβ �Ҳ��������� ���ᾭ�����������ÿ����  ���ʱ��Ҫ������  ��ans  �����
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> words[i];
	cin >> head;
	for (int i = 1; i <= n; i++)
	{
		if (words[i][0] == head)
		{
			res += words[i].size();
			dfs(i);
			res = 0;
			for (int i = 1; i <= n; i++)times[i] = 0;
		}
	}

	cout << ans;

	return 0;
}