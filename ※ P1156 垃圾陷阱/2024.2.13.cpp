

#include<bits/stdc++.h>
using namespace std;

const int N = 3020, M = 110;
struct laji 
{
	int T, F, H;
};
int D, G;
vector<laji> lajis;
int f[N][M];

bool cmp(laji a, laji b)
{
	return a.T < b.T;
}

int main()
{
	cin >> D >> G;
	for (int i = 1; i <= G; i++)
	{
		int T, F, H;
		cin >> T >> F >> H;
		lajis.push_back({ T < F < H });
	}
	sort(lajis.begin(), lajis.end());


	return 0;
}