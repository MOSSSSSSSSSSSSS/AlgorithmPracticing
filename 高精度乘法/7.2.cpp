//两个非负整数A和b，计算乘积
#include<iostream>
#include<vector>
using namespace std;

vector<int> mul(vector<int> &A, int b)
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
	while (C.size() > 1 && C.back() == 0)C.pop_back();//防止0*12345 = 00000

	return C;
}

int main()
{
	string a;
	int b;
	vector<int> A,C;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
	
	C = mul(A, b);
	
	for (int i = C.size() - 1; i >= 0; i--)printf("%d", C[i]);

	return 0;
}