

//���ĸ��㵱���� 48 ʱ��������

#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>//����ͷ�ļ�
using namespace std;

typedef long long ll;//��int����ָ�������longlong������ָ���

int s;
vector<ll> A, B;

void mul(vector<ll>& A, int b)
{
	vector<ll> res;
	ll t = 0;
	for (int i = 0; i < A.size(); i++)
	{
		t += A[i] * b;
		res.push_back(t % 10);
		t /= 10;
	}
	if (t)res.push_back(t);
	while (res.size() > 1 && res.back() == 0)res.pop_back();
	A = res;
}
void add(vector<ll>& A, vector<ll>& B)
{
	vector<ll> res;
	ll t = 0;
	for (int i = 0; i < A.size() || i < B.size(); i++)
	{
		if (i < A.size())t += A[i];
		if (i < B.size())t += B[i];
		res.push_back(t % 10);
		t /= 10;
	}
	if (t)res.push_back(1);
	A = res;
}

int main()
{
	scanf("%d", &s);
	A.push_back(s % 10);
	if (s / 10)A.push_back(s / 10);
	for (int j = s; j > 1; j--)
		mul(A, j - 1);
	for (int i = s; i > 1; i--)
	{
		B.push_back((i - 1) % 10);
		if ((i - 1) / 10)B.push_back((i - 1) / 10);
		for (int j = i - 1; j > 1; j--)
			mul(B, j - 1);
		add(A, B);
		while (B.size())B.pop_back();
	}
	for (ll i = A.size()-1; i >= 0; i--)printf("%lld", A[i]);

	return 0;
}