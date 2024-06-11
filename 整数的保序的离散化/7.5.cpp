//for(auto item :add)�Ǳ�������add�е�����Ԫ�أ�ÿһ��ѭ�����Ὣadd�е�һ��Ԫ�ظ�ֵ������item��ʹ��autoϵͳ�Զ��ж������͡�
//�����pair<int,int>��һ���������ʹ��item.first,item.second


//ģ�壬��������ȥ�أ���ӳ��
//����Χ�ܴ󣬵����õ������ٵģ���ϡ��ģ����������Խ��Ҳû��Ӱ�죬�Ϳ��Խ��⼸��ϡ����� ��ɢ������ ��������˵ԭ����С����ӳ���Ҳ��С����
//#include<iostream>
//#include<vector>
//#include<algorithm>                                               reverse, sort��unique����<algorithm>���
//
//using namespace std;

//vector<int> alls;
//int find(int x)
//{
//	int l = 0, r = alls.size() - 1;
//	while (l < r)
//	{
//		int mid = l + r >> 1;
//		if (alls[mid] >= x) r = mid;
//		else l = mid + 1;
//	}
//
//	return r;//r���±��0��ʼ��r+1���±��1��ʼ��ȡ������Ŀ��Ҫ
//}

//int main()
//{
//	sort(alls.begin(),alls.end());
//	alls.erase(unique(alls.begin(), alls.end()), alls.end());//unique��ȥ���õģ��ظ���Ԫ�ض��ŵ�������棬Ȼ�󷵻�ǰ�治���ظ�Ԫ�ص����ĺ�һ��λ�õ��±꣨���������end����erase�������������µ��ظ�Ԫ��
//	//���ö�����һ������ӳ�䣬ӳ��Ϊ���������е��±꣬���ֺ���������

//}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;
int n, m;
vector<int> alls;//��Ҫһ���������Ҫ��ɢ������������,��������е���������Ҫȥ�أ�ͨ����������find������ӳ��ķ���
vector<PII> add,query;
int a[N], s[N];//����ɢ����Ĵ�1��ʼ��ǰ׺�ʹ�1��ʼ������Ȼ������Ϊa������±�

int find(int x)
{
	int i = 0, j = alls.size() - 1;
	while (i < j)
	{
		int mid = i + j >> 1;
		if (alls[mid] >= x)j = mid;
		else i = mid + 1;
	}

	return i + 1;
}

int main()
{
	scanf("%d%d", &n,&m);
	while (n--)
	{
		int x, c;
		scanf("%d%d", &x, &c);
		add.push_back({ x,c });
		alls.push_back(x);
	}
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		query.push_back({ l,r });
		alls.push_back(l);
		alls.push_back(r);
	}
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	
	for (auto item : add)a[find(item.first)] += item.second;
	for (int i = 1; i < N; i++)s[i] = s[i - 1] + a[i];
	for (auto item : query)
	{
		int i = find(item.first), j = find(item.second);
		cout << s[j] - s[i - 1] << endl;
	}
}
//7.6�ڶ���
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 300010;
typedef pair<int, int> PII;
vector <int> alls;
vector <PII> add, query;
int n, m;
int a[N], s[N];

int find(int x)
{
	int l = 0, r = alls.size() - 1;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (alls[mid] >= x)r = mid;
		else l = mid + 1;
	}

	return r + 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	while (n--)
	{
		int x, c;
		scanf("%d%d", &x, &c);
		alls.push_back(x);
		add.push_back({ x,c });
	}
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		alls.push_back(l);
		alls.push_back(r);
		query.push_back({ l,r });
	}
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	for (auto item : add)a[find(item.first)] += item.second;
	for (int i = 1; i < N; i++)s[i] = s[i - 1] + a[i];
	for (auto item : query)
	{
		int l = find(item.first), r = find(item.second);
		cout << s[r] - s[l - 1] << endl;
	}

	return 0;
}