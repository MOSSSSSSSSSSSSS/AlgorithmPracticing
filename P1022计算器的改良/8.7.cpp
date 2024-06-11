


#include<bits/stdc++.h>
using namespace std;

string str;
int a, c,now;
bool flag = 1,r = 1; // ³£
int p = 1;
char x;

int main()
{
	cin >> str;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			now = now + p * (str[i] - '0');
			p *= 10;
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '=')
		{
			if (str[i] == '-') 
				now = -now;
			if (!flag)
			{
				if (!r)now = -now;
				a += now;
				flag = 1;
			}
			else
			{
				if (!r)now = -now;
				c += now;
			}
			if (str[i] == '=')
				r = 0;
			now = 0;
			p = 1;
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			x = str[i];
			flag = 0;
		}
	}
	if (now)
	{
		now = -now;
		if (flag)
			c += now;
		else
			a += now;
	}
	else
		if (str[0] == 'a')
			a += -1;
	double ans = double(c) / double(-a);
	printf("%c=%.3lf",x, ans);
}