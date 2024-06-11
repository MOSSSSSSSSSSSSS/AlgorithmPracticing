

#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> A;
vector<int> B;

vector<int> mul(vector<int>& A, vector<int>& B)          //  原来的模板没有引用，也可以加上，提高速度
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

vector<int> factorial(int n)
{
	vector<int> C;
	vector<int> D;
	C.push_back(1);
	for (int i = 2; i <= n; i++)
	{
		int k = i;
		while (k)
		{
			D.push_back(k % 10);
			k /= 10;                 //   注意i是循环的计数器，i/=10，改变了i的值，这样回死循环，要用另一个数而不是用i
		}
		C = mul(C, D);
		D.clear();            //  并且D要清空
	}

	return C;
}


vector<int> add(vector<int>& A, vector<int>& B)
{
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size() || i < B.size(); i++)
	{
		if (i < A.size())t += A[i];
		if (i < B.size())t += B[i];
		C.push_back(t % 10);
		t /= 10;
	}
	if (t)C.push_back(1);

	return C;
}

int main()
{
	A.push_back(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		B = factorial(i);
		A = add(A, B);
	}
	for (int i = A.size() - 1; i >= 0; i--)cout << A[i];

	return 0;
}