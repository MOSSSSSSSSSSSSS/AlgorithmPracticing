
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> A, B;

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
	cin >> n;

	A.push_back(1);
	B.push_back(2);

	for (int i = 0; i < n-2; i++)
	{
		if (i % 2 == 0)A = add(A, B);
		else B = add(A, B);
	}

	if (n % 2 == 0)
		for (int i = B.size() - 1; i >= 0; i--)printf("%d", B[i]);
	else
		for (int i = A.size() - 1; i >= 0; i--)printf("%d", A[i]);

	return 0;
}