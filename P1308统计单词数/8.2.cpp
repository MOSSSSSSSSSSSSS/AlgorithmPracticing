


//    cin>>string  ���ո�Ϊֹ���ո񲻶���
//    getline(cin,string) ���س�����������һ��,���ǣ������ǵڶ���������ַ���������һ���õ�cin��
//    ʣһ���س������Ե��Ȱѻس�����  ,  getchar,scanf(%c)���ܶ��س�


#include<bits/stdc++.h>
using namespace std;

const int N = 1000010,P = 131;
typedef unsigned long long ULL;
ULL ht, h0;
string str;
int sum,pos;

ULL Hash(string str)
{
	ULL ans = 0;
	int n = str.size();
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;              //     ��Ŀ˵�����ִ�Сд
		ans = ans * P + str[i];
	}

	return ans;
}

int main()
{
	cin >> str;
	h0 = Hash(str);
	getchar();
	getline(cin, str);
	int i = 0;
	while (str[i]==' ')
		i++;
	for (int j = i+1;j<str.size(); j++)
	{
		if (str[j] == ' ')
		{
			ht = Hash(str.substr(i, j - i));
			if (h0 == ht)
			{
				sum++;
				if (sum == 1)pos = i;
			}
			while (str[j] == ' ')
				j++;
			i = j;
		}
	}
	ht = Hash(str.substr(i, str.size() - i));
	if (h0 == ht)
	{
		sum++;
		if (sum == 1)pos = i;
	}
	
	if (sum) cout << sum << ' ' << pos;
	else cout << -1;

	return 0;
}