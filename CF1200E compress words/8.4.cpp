


//  �ù�ϣ������Լ򵥵��㷨����������⣬���������ĵ�һ��������TLE��������Ϊÿ�ζ������ϣֵ��������������ϣֵ������ͨ��ǰ��������Ĺ�ϣֵһ�����������������ͨ��Hash��������ѭ������
//  ��һ��P�����¼P�ĸ����η���ֵ������һ�ε�ֵ����һ�ε�ֵ������ˣ���ϣTLE�����⡣
//  �ڶ��������ǣ���Ŀ������Ȼ������Ĺ�ϣ�����ǿ��Ը�P����mod���ĳɵ�ģ����10��18�η������ģ����˫ģ���������Ϳ��Թ���
//     �ĳɵ�ģ���ĸķ����������䣬ULLʲô��Ҳ���ñ䣬ֱ�Ӷ���mod���ٽ�Hash�����ĳ�����(ans * P + str[i])%mod;��������û�꣬����������ϣֵ�йصĶ�Ҫ��%mod������P���ݴε����飬����һ�ι�ϣ�����
//     ��һ�ι�ϣ���ʱ����Ҫ����  %mod

//             ��������������͹���

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const ULL P = 291143, N = 1000010,mod = 998244353;  //  mod:212370440130137957  ll  ������long long ��д       P:291143,131,13331
int n;
string str,s;
ULL p[N];

ULL Hash(string str)
{
	ULL ans = 0;
	for (int i = 0; i < str.size(); i++)
		ans = (ans * P + str[i])%mod;

	return ans;
}

int main()
{
	cin.tie(0);
	p[0] = 1;
	for (int i = 1; i < N; i++)p[i] = (p[i - 1] * P)%mod;
	cin >> n;
	cin >> str;
	for (int i = 1; i < n; i++)
	{
		cin >> s;
		int j = 1,m = 0;
		//while (Hash(str.substr(str.size() - j, j)) == Hash(s.substr(0, j)))j++;          //��һ������׺�͵ڶ�����ǰ׺��ȣ�����  ast �� ast����һ����һ�������һ����һ���͵ڶ�����һ�����

		ULL has1 = Hash(str.substr(str.size() - j, j));
		ULL has2 = Hash(s.substr(0, j));

		while (1)                //  ע��str.size()����ֵunsigned������Ҫ�Ǹ��������˳�ѭ��������Ҫ����׼����int�����ܼ���������Ӷ��˳�ѭ��
		{
			if (has1!=has2)
				j++;
			else
				m = j++;
			if ((int(str.size())-j>=0)&&(j-1<s.size()))
			{
				has1 = (has1 + str[str.size() - j] * p[j - 1])%mod;
				has2 = (has2 * P + s[j - 1])%mod;
			}
			else
				break;
		}
		str += s.substr(m);
	}

	cout << str;

	return 0;
}
