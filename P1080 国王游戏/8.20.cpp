


#include<bits/stdc++.h>
using namespace std;

//#define int  long long           //  ����ull��û�����ˣ����ǽ����ĺ����ף���ȷ��ֻ��2��������ull���и߾��������ȴ��5��6��
 //     ��int �� long long �������У�����ȷ������Ƶ����и���
//     �߾��ȳ˵;��ȣ�10000���ڣ�
//     ���������Ƿ����Ľ��и߾��ȳ˵;��ȣ��õ�һ���߾����ٳ�һ���;��ȣ��õ�һ���߾��ȡ�����������ʱ�����ģ����ָ��žͳ����ˣ��ø߾��ȳ˸߾��ȵ�ģ�弴����ȷ(����mul����)
typedef pair<int,int> PII;
const int N = 1010;
int n;
PII hands[N];
vector<int> res, ans,coin;

bool cmp(PII a, PII b)
{
	/*if (a.second < b.second)
		return true;
	else if (a.second > b.second)
		return false;
	else
	{
		if (a.first < b.first)
			return true;
		else if(a.first>b.first)
			return false;
	}*/
	if (a.first * a.second < b.first * b.second)
		return true;
	else
		return false;                                 //  ���Ǽ򵥵���һ�¾Ͷԣ�Ҫͨ������ó�Ӧ����ô�������ʹ������С��û�ö��֣���ͨ���������������������󳼣�����վ�ڹ���������������������������з���
	//
}

/*vector<int> multiple(vector<int>& A, int b)
{
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size(); i++)
	{
		t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	if (t)C.push_back(t);
	while(C.size() > 1 && C.back() == 0)C.pop_back();

	return C;
}*/

vector<int> mul(vector<int> A, vector<int> B)
{
	vector<int> C(A.size() + B.size());

	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++)
			C[i + j] += A[i] * B[j];

	for (int i = 0, t = 0; i < C.size() || t; i++)
	{
		t += C[i];
		if (i >= C.size()) C.push_back(t % 10);
		else C[i] = t % 10;
		t /= 10;
	}

	while (C.size() > 1 && !C.back()) C.pop_back();

	return C;
}

vector<int> div(vector<int>& A, int b)
{
	vector<int> C;
	int r = 0;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;
	}
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0)C.pop_back();

	return C;
}

bool comp(vector<int>& coin, vector<int>& ans)
{
	if (coin.size() > ans.size())
		return true;      //   Ҫ����
	else if (coin.size() < ans.size())
		return false;    //  ������
	else
	{
		for (int i = coin.size() - 1; i >= 0; i--)
		{
			if (coin[i] > ans[i])
				return true;
			else if(coin[i]<ans[i])
				return false;
		}
	}

	return false;
}

signed main()
{
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		int left, right;
		cin >> left >> right;
		hands[i] = { left,right };
	}
	sort(hands + 1, hands + n + 1, cmp);
	res.push_back(1);
	ans.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		//res = multiple(res, hands[i - 1].first);
		vector<int> B;
		while (hands[i-1].first)
		{
			B.push_back(hands[i - 1].first % 10);
			hands[i - 1].first /= 10;
		}
		res = mul(res, B);
		coin = div(res, hands[i].second);
		if (comp(coin, ans))
		{
			ans.clear();
			for (int i = 0; i < coin.size(); i++)
				ans.push_back(coin[i]);
		}
	}

	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i];

	return 0;
}
