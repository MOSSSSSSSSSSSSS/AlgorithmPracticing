

//高精度除法，从最高位开始算，也就是数组中最后一个数开始算
//一般情况下，题目加减乘除混合，所以除法也用倒着存储的方式
//如果要把123和4变成1234,就可以123*10+4
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> div(vector<int>& A, int b, int& r)
{
	vector<int> C;
	r = 0;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;//最后退出循环时，r就是最终的余数
	}
	reverse(C.begin(), C.end());//由于输出，所以要将C再逆转过来，reverse需要头文件algorithm，C.begin(),C.end()
	while (C.size() > 1 && C.back() == 0)C.pop_back();//因为例如120除11，首先看1除11，商0，所以最前面有个没用的0，逆转后去了最后，再把最后的0都扔掉

	return C;
}

int main()
{
	string a;
	int b,r;//r是余数，除法的函数要返回商和余数
	vector<int> A, C;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');

	C = div(A,b,r);
	for (int i = C.size() - 1; i >= 0; i--)printf("%d", C[i]);
	cout << endl << r;

	return 0;
}