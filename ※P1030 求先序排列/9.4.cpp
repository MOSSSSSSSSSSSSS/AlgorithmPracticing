

#include<bits/stdc++.h>
using namespace std;

string inord, aftord;

void beford(string inord, string aftord)
{
	if (inord.size() > 0)   //  inord��aftord����һ�����ж�һ�����У���Ϊ�п��ܴ��볤Ϊ0�Ĵ��������ж�һ��
	{
		char ch = aftord[aftord.size() - 1];
		cout << ch;
		int x = inord.find(ch);           //   ��string�ַ����в����ַ��ĺ���find�������±꣨��ߵ�һ����
		beford(inord.substr(0, x), aftord.substr(0, x));
		beford(inord.substr(x + 1, inord.size() - x - 1), aftord.substr(x, aftord.size() - x - 1));  // ��������
	}
}

int main()
{
	cin >> inord >> aftord;
	beford(inord, aftord);

	return 0;
}