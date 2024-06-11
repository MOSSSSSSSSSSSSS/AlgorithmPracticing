
//  因为到后面的时候，切一个横或竖需要在多块上切，所以到后面应该切代价小的，代价大的先切
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
const int N = 4010;
int length, width,sum_of_row = 1,sum_of_col = 1;
PII cut[N];
LL ans;

bool cmp(PII a, PII b)
{
	if (a.first > b.first)return true;
	else return false;
}

int main()
{
	cin >> length >> width;
	for (int i = 1; i <= length - 1; i++)
	{
		cin >> cut[i].first;
		cut[i].second = 0;
	}
	for (int i = length; i <= length+width - 2; i++)
	{
		cin >> cut[i].first;
		cut[i].second = 1;
	}
	sort(cut + 1, cut + length + width - 1,cmp);   //  从大到小排

	for (int i = 1; i <= length + width - 2; i++)
	{
		if (cut[i].second)
		{
			ans += cut[i].first * sum_of_row;
			sum_of_col++;
		}
		else
		{
			ans += cut[i].first * sum_of_col;
			sum_of_row++;
		}
	}

	cout << ans;

	return 0;
}