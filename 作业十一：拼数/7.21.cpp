//   ��̰��˼�� a+b>b+a return true
//   ��θı�sort�ǽ��������򣿼�  less<int>  ���������У�Ĭ�ϣ�,��  greater<int> �ǽ�������


#include<bits/stdc++.h>
using namespace std;

vector<string> str;
int n;

bool cmp(string a, string b)
{
	if (a + b > b + a)return true;     //string����� ��ʾ ƴ��          a��ʾ�����ǰһ������b��ʾ������һ���������a+b>b+a����true�ģ�

	//����ĳ� b+a>a+b ����true ������Ƿ������ģ�������Ǵ��%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

	else return false;
}

int main()
{
	cin >> n;
	while (n--)
	{
		string a;
		cin >> a;
		str.push_back(a);
	}

	sort(str.begin(), str.end(),cmp);

	for (auto item : str)cout << item;    //   ��������ÿ��Ԫ�أ�item�Ǹ���Ԫ��

	return 0;
}