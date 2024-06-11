


#include<bits/stdc++.h>
using namespace std;

//#define int  long long           //  换成ull后没负号了，但是结果错的很离谱，正确答案只有2行数，用ull进行高精度运算答案却有5，6行
 //     用int 和 long long 都是两行，和正确结果相似但都有负号
//     高精度乘低精度（10000以内）
//     但是这里是反复的进行高精度乘低精度，得到一个高精度再乘一个低精度，得到一个高精度。。。。。这时用这个模板出现负号就出错了，用高精度乘高精度的模板即可正确(下面mul函数)
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
		return false;                                 //  不是简单的想一下就对，要通过推理得出应该怎么排序才能使最大的最小（没用二分），通过举两个数，考虑两个大臣，它们站在国王的身后，则这两个大臣有两种排列方法
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
		return true;      //   要交换
	else if (coin.size() < ans.size())
		return false;    //  不交换
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
