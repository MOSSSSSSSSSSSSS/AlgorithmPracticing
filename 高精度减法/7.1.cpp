
//高精度减法   A>=B 若A<B 就用B - A   A\B为正   若不是需要也可以用这个模板 需其他输入输出处理

#include<iostream>
#include<vector>
using namespace std;

bool cmp(vector<int>& A, vector<int>& B)
{
	if (A.size() != B.size())return A.size() > B.size();

	for (int i = A.size() - 1; i >= 0; i--)
		if (A[i] != B[i])return A[i] > B[i];
	return true;
}

vector<int> sub(vector<int> A, vector<int> B)
{
	vector<int> C;
	for (int i = 0, t = 0; i < A.size(); i++)
	{
		t = A[i] - t;
		if (i < B.size())t -= B[i];//注意判断B是否有东西，否则越界
		C.push_back((t + 10) % 10);// 如果t>=0则是t，如果t<0，则是t+10，讲两句话合二为一
		if (t >= 0)t = 0;
		else t = 1;//一开始是t等于0进来，之后循环中是t = 0\1后开始下一个循环
	}
	while (C.size() > 1&&C.back() == 0)C.pop_back();//如果123 - 121 则会是002，所以要把前面的0去掉，，，注意现在会用  .back  .push_back   .pop_back

	return C;
}

int main()
{
	string a, b;
	vector<int> A, B;
	cin >> a>>b;
	for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');

	if (cmp(A, B))
	{
		vector<int> C = sub(A, B);
		for (int i = C.size() - 1; i >= 0; i--)printf("%d", C[i]);
	}
	else
	{
		vector<int> C = sub(B, A);
		printf("-");
		for (int i = C.size() - 1; i >= 0; i--)printf("%d", C[i]);
	}
	

	return 0;
}