

//第一个   l + r >> 1   等价于   （l+r）/2
//第二个   按位与 & 当左右两个数的 内存中补码形式 对应位置 的数 均为 1时 结果是 1，其他结果是0
//第三个   求 一个数 二进制形式 中 第k个数是1还是0   用 n >> k & 1  例如10的二进制是1010，从右到左依次是第0个，第1个，第2个，第3个，要求第 1 个是几，就10 >> 1 & 1,10>>1结果是101(二进制)，1是001，&完后就是1
//第四个   lowbit（x）返回二进制中最后一个1，如1000111000，返回1000(2进制)。如何实现：x&-x，-x的补码是x取反加一，最后结果是1000,   可以实现统计x中1的个数。
//第五个   c++如果右移负数，系统会自动在 最高位 补 1
#include<iostream>
using namespace std;

int lowbit(int x)
{
	return x & -x;
}

int main()
{
	cout << (15 >> 1) << endl;

	cout << lowbit(10);

	return 0;
}

//二进制数中1的个数题
#include<iostream>
using namespace std;

int n;
int lowbit(int x)
{
	return x & -x;
}

int main()
{
	scanf("%d", &n);

	while (n--)
	{
		int x;
		scanf("%d", &x);

		int res = 0;
		while (x)
		{
			x -= lowbit(x);
			res++;
		}
		printf("%d ", res);
	}

	return 0;
}
#include<iostream>
using namespace std;

int lowbit(int x)
{
	return x & -x;
}

int main()
{

	int x;
	scanf("%d", &x);

	int res = 0;
	while (x)
	{
		x -= lowbit(x);
		res++;
	}
	printf("%d ", res);

	return 0;
}
