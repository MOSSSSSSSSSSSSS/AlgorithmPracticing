

#include<bits/stdc++.h>
using namespace std;

string inord, aftord;

void beford(string inord, string aftord)
{
	if (inord.size() > 0)   //  inord和aftord长度一样，判断一个就行，因为有可能传入长为0的串，所以判断一下
	{
		char ch = aftord[aftord.size() - 1];
		cout << ch;
		int x = inord.find(ch);           //   在string字符串中查找字符的函数find，返回下标（左边第一个）
		beford(inord.substr(0, x), aftord.substr(0, x));
		beford(inord.substr(x + 1, inord.size() - x - 1), aftord.substr(x, aftord.size() - x - 1));  // 先左再右
	}
}

int main()
{
	cin >> inord >> aftord;
	beford(inord, aftord);

	return 0;
}