#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

struct node
{
	int xt;
	int bt1;
	int bt2;
	bool operator < (const node& w) const {
		if (xt != w.xt) return xt < w.xt;
		else if (bt1 != w.bt1) return bt1 < w.bt1;
		else return bt2 < w.bt2;
	}//�ýṹ����Ϊvector�����е�Ԫ�أ���Ҫ����ʱ����Ҫ���������ʾ���Ȱ�xt���򣬵�xt��ͬʱ������˵��С����
};

int n,k = -2e9,st = -2e9,ed = -2e9;
ll num;
vector<node> hengde, shude,resheng,resshu;

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1 == x2)shude.push_back({ x1,min(y1,y2),max(y1,y2)});
		else if (y1 == y2)hengde.push_back({ y1,min(x1,x2),max(x1,x2)});
	}

	sort(shude.begin(), shude.end());
	sort(hengde.begin(), hengde.end());

	for (auto item : hengde)
	{
		if (k == item.xt)
		{
			if (ed < item.bt1)
			{
				resheng.push_back({ k,st,ed });
				num += (ed - st + 1);
				st = item.bt1;
				ed = item.bt2;
			}
			else ed = max(ed, item.bt2);
		}
		else
		{
			if (st != -2e9) 
			{
				resheng.push_back({ k,st,ed });
				num += (ed - st + 1);
			}
			k = item.xt;
			st = item.bt1;
			ed = item.bt2;
		}
	}
	resheng.push_back({ k,st,ed });
	num += ed - st + 1;
	k = -2e9, st = -2e9, ed = -2e9;
	for (auto item : shude)
	{
		if (k == item.xt)
		{
			if (ed < item.bt1) 
			{
				resshu.push_back({ k,st,ed });
				num += (ed - st + 1);
				st = item.bt1;
				ed = item.bt2;
			}
			else ed = max(ed, item.bt2);
		}
		else
		{
			if (st != -2e9)
			{
				num += (ed - st + 1);
				resshu.push_back({ k,st,ed });
			}
			k = item.xt;
			st = item.bt1;
			ed = item.bt2;
		}
	}
	resshu.push_back({ k,st,ed });
	num += ed - st + 1;
	for (auto item1 : resshu)
		for (auto item2 : resheng)if (item1.xt >= item2.bt1 && item1.xt <= item2.bt2 && item2.xt >= item1.bt1 && item2.xt <= item1.bt2)num--;//ע�ⲻ����ԭ�������䣬Ҫ�úϲ���������󽻵�
	//���������ԭ���ģ���������������ཻ��һ�㣬һ����������������Ľ���ͬһ�㡣�ᵼ�¶��

	cout << num;

	return 0;
}
