

//由于区间是起点和终点，用pair，先将所有区间按左端点大小排好序，再用一个当前数组，和每一个区间比较（merge函数）

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> PII;

int n;
vector<PII> segs;

void merge(vector<PII>& segs)
{
	if (segs.size() == 0)return;

	vector<PII> res;
	int st = segs[0].first, ed = segs[0].second;//并没有把长度记录进去，只是记录起点终点
	for (auto seg : segs)
	{
		if (ed < seg.first)
		{
			res.push_back({ st,ed });//这是记录长度
			st = seg.first;
			ed = seg.second;
		}
		else ed = max(seg.second, ed);//这是只更新起点终点，不记录长度
	}
	res.push_back({ st,ed });//注意最后还有一个

	segs = res;
}

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		segs.push_back({ l,r });
	}

	sort(segs.begin(), segs.end());//优先按第一个排

	merge(segs);

	cout << segs.size();

	return 0;
}