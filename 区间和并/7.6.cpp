

//���������������յ㣬��pair���Ƚ��������䰴��˵��С�ź�������һ����ǰ���飬��ÿһ������Ƚϣ�merge������

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
	int st = segs[0].first, ed = segs[0].second;//��û�аѳ��ȼ�¼��ȥ��ֻ�Ǽ�¼����յ�
	for (auto seg : segs)
	{
		if (ed < seg.first)
		{
			res.push_back({ st,ed });//���Ǽ�¼����
			st = seg.first;
			ed = seg.second;
		}
		else ed = max(seg.second, ed);//����ֻ��������յ㣬����¼����
	}
	res.push_back({ st,ed });//ע�������һ��

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

	sort(segs.begin(), segs.end());//���Ȱ���һ����

	merge(segs);

	cout << segs.size();

	return 0;
}