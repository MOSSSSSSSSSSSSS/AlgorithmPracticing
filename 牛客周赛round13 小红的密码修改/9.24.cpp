

#include<bits/stdc++.h>
using namespace std;

int t;

int main()
{
	cin >> t;
	while (t--)
	{
		string str;
		int daxie = 0, xiaoxie = 0, shu = 0, teshu = 0;
		int len = 0;
		cin >> str;
		len = str.size();
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
				shu++;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				daxie++;
			else if (str[i] >= 'a' && str[i] <= 'z')
				xiaoxie++;
			else
				teshu++;
		}

	}


	return 0;
}