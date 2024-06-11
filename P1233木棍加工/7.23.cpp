

//  有两个性质，一个是宽度一个是长度，都需要不上升，所以先把长度按降序排列，如果长度相同，把宽度按降序排列，再看宽度这一维度，求已经排好的宽度这一序列中，
//  不上升子序列的个数，即最大上升子序列的个数。
//  如果没有长度相同，把宽度按降序排列，那么这个宽度的序列，求它的不上升子序列的个数就会大，而我们要求的是个数最小的
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const int N = 5010;

typedef pair<int, int> PII;

int n,f[N],res;
vector<PII> sticks;
vector<int> c;

bool cmp(PII a, PII b)
{
	if (a.first > b.first)return true;     // pair类型的a变量  a.first  不用加括号写成a.first()
	else
	{
		if (a.first == b.first)
		{
			if (a.second >= b.second)return true;
			else return false;
		}
		else return false;
	}
}

int main()
{
	sticks.push_back({ 0,0 });
	cin >> n;
	//while (n--)                               //while(n--)有个不好的地方，当循环结束时，n就没了变0了，n代表一共输入的数据，就不知道输入了多少了
	//{
	//	int l, w;
	//	scanf("%d%d", &l, &w);
	//	sticks.push_back({ l,w });
	//}

	for (int i = 1; i <= n; i++)
	{
		int l, w;
		scanf("%d%d", &l, &w);
		sticks.push_back({ l,w });
	}

	sort(sticks.begin()+1, sticks.end(), cmp);

	c.push_back(0);
	c.push_back(sticks[1].second);
	f[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		int l = 1, r = c.size();
		while (l < r)
		{
			int mid = l + r >> 1;
			if (c[mid] >= sticks[i].second)r = mid;
			else l = mid + 1;
		}
		if (l == c.size())c.push_back(sticks[i].second);
		else c[l] = sticks[i].second;
		f[i] = l;
	}

	for (int i = 1; i <= n; i++)res = max(res, f[i]);
	cout << res;

	return 0;
}
