

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int N = 1010, M = 5010,P = 131;
ULL h[N][M];
int n,m,l[N];
string word;

ULL Hash(string word)
{
	ULL ans = 0;
	for (int i = 0; i < word.size(); i++)
		ans = ans * P + word[i];
	return ans;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i];
		for (int j = 1; j <= l[i]; j++)
		{
			cin >> word;
			h[i][j] = Hash(word);
		}
	}
	cin >> m;
	while (m--)
	{
		bool flag = true;
		cin >> word;
		ULL ha = Hash(word);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= l[i]; j++)
			{
				if (h[i][j] == ha)
				{
					if(flag)
					{
						cout << i;
						flag = false;
					}
					else cout << ' ' << i;
					break;
				}
			}
		}
		cout << endl;
	}

	return 0;
}