
//有四种，高精度加法（两个大数相加），高精度减法（两个大数相减），（一个大数乘一个数），和（一个大数除一个小数）

#include<iostream>
#include<vector>
using namespace std;

/*模板部分*/
vector<int> add(vector<int>& A, vector<int>& B)//返回一个数组，用引用可以提高效率，不用再把原数组复制一遍
{
	vector<int> C;
	int t = 0;//进位，每次算每一位之间相加时都是A的加B的加前一位进位，从个位开始算，所以t一开始是零
	for (int i = 0; i < A.size() || i < B.size(); i++)//一直到所有位数都算完，循环结束
	{
		if (i < A.size())t += A[i];
		if (i < B.size())t += B[i];
		C.push_back(t % 10);
		t /= 10;//一开始是t等于0进来，之后循环中是t = t/10后开始下一个循环
	}
	if (t)C.push_back(1);//最后看需不需要进位，因为t算完后如果不满足循环条件就退出了，最后t还没加上

	return C;
}
/*模板部分*/
int main()
{
	string a, b;//输入时先用字符串存放
	vector<int> A, B;
	cin >> a >> b; // 例如a = “123456”
	for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');//    用数组存放时，个位放最前面即[0]处，这样如果最高位需要进一位只需要在后面加一个，如果最高位放前面，最高位需要进一位就需要全部向后移一个
	for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');//    注意是字符，要减零  最终A数组 ：654321

	vector<int> C = add(A, B);
	for (int i = C.size() - 1; i >= 0; i--)printf("%d", C[i]);//从最高位开始输出


	return 0;
}
