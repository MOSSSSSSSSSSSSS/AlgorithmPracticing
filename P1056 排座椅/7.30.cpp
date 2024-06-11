
#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
typedef pair<int, int> PII;
PII heng[N], shu[N];

bool cmp(PII a, PII b)
{
	if (a.first > b.first)return true;
	else return false;
}
bool cmp2(PII a, PII b)
{
	if (a.second < b.second)return true;
	else return false;
}

int main()
{
	int m, n, k, l, d;
	cin >> m >> n >> k >> l >> d;
	while (d--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2)
		{
			heng[min(y1, y2)].first += 1;
			heng[min(y1, y2)].second = min(y1, y2);
		}
		else if (y1 == y2)
		{
			shu[min(x1, x2)].first += 1;
			shu[min(x1, x2)].second = min(x1, x2);
		}
	}

	sort(heng, heng + n, cmp);
	sort(heng, heng + l, cmp2);
	sort(shu, shu + m, cmp);
	sort(shu, shu + k, cmp2);

	for (int i = 0; i < k; i++)
	{
		cout << shu[i].second;
		if (i != k - 1)cout << ' ';
		else cout << endl;
	}
	for (int i = 0; i < l; i++)
	{
		cout << heng[i].second;
		if (i != l - 1)cout << ' ';
	}


	return 0;
}
/*

*/