

//  ���������ʣ�һ���ǿ��һ���ǳ��ȣ�����Ҫ�������������Ȱѳ��Ȱ��������У����������ͬ���ѿ�Ȱ��������У��ٿ������һά�ȣ����Ѿ��źõĿ����һ�����У�
//  �����������еĸ�������������������еĸ�����
//  ���û�г�����ͬ���ѿ�Ȱ��������У���ô�����ȵ����У������Ĳ����������еĸ����ͻ�󣬶�����Ҫ����Ǹ�����С��
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
	if (a.first > b.first)return true;     // pair���͵�a����  a.first  ���ü�����д��a.first()
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
	//while (n--)                               //while(n--)�и����õĵط�����ѭ������ʱ��n��û�˱�0�ˣ�n����һ����������ݣ��Ͳ�֪�������˶�����
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
