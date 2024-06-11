

#include<bits/stdc++.h>
using namespace std;

int p;

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

int main()
{
	cin >> p;
	cout << (int)(log10(2) * p + 1) << endl;                //    �� 2��p�η���λ��
	vector<int> res,a;
	res.push_back(1);
	a.push_back(2);
	while (p)                             //  �߾������ݾ���  �߾���+�����ݣ�Ҳ���ǲ�ȡģ�Ŀ�����
	{
		if (p & 1)res = mul(res, a);
		p >>= 1;
		a = mul(a, a);
		while (a.size() > 500)           //    ֻҪ��500λ����9876*4561�������λ��876*561һ��������a��resһ������500λ��ֻҪ��500λ������tle
			a.pop_back();
		while (res.size() > 500)
			res.pop_back();
	}
	res[0] -= 1;
	while (res.size() < 500)
		res.push_back(0);
	int idx = 500;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 50; j++)
			cout << res[--idx];
		cout << endl;
	}

	return 0;
}