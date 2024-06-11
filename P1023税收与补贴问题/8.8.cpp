


#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int expect, cheng, liang[N],jian;

bool cmp(int ans)
{
	for (int i = cheng; liang[i] > 0; i++)
		if ((expect - cheng + ans) * liang[expect] < (i - cheng + ans) * liang[i])
			return false;
	
	return true;
} 

int main()
{
	int x ,y = -1e9;
	double k, b0;
	cin >> expect >> cheng >> x;
	liang[cheng] = x;
	x = -1e9;
	int a, b;
	while (cin >> a >> b, a != -1)
	{
		liang[a] = b;
		y = max(y, a);
		x = max(x, b);
	}
	k = (double)(x - liang[cheng]) / (double)(y - cheng);
	b0 = x - k * y;
	cin >> jian;
	for (int i = cheng; i<y; i++)
		if (liang[i] == 0)
				liang[i] = i * k + b0;
	for (int i = y+1; liang[i] == 0; i++)
	{
		if (liang[i - 1] >= jian)
			liang[i] = liang[i - 1] - jian;
		else
			break;
	}
	for (int i = 0 ;i<expect; i++)
	{
		if (cmp(i))
		{
			cout << i;
			return 0;
		}
		if (cmp(-i))
		{
			cout << -i;
			return 0;
		}
	}

	cout << "NO SOLUTION";

	return 0;
}