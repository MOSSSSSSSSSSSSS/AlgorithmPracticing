

/*函数内申请的变量，数组，是在栈（stack）中申请的一段连续的空间。栈的默认大小为2M或1M，开的比较小。
全局变量，全局数组，静态数组（static）则是开在全局区（静态区）（static）。大小为2G，所以能够开的很大。
而malloc、new出的空间，则是开在堆（heap）的一段不连续的空间。理论上则是是内存大小。*/

//  所以main函数里的数组不要开太大



/*其中，next[i]，next[next[i]]，next[next[next[i]]]......都是这个前缀串i的公共前后缀，而且只有它们是公共前后缀
那么，我们其实只要在求next的过程中，顺便把这个公共前后缀的数量递推一下，就得到了一个弱化版的num数组：可以重叠的公共前后缀数量，我们称之为ans
如何去除有重叠的？
还是看上面那张图
首先next数组有一个性质：next[i]<i
也就是说，一旦有一个递归了n层的next，比原前缀i的长度的一半要小，那么这个next的递推出的答案ans就是i的num了
一个问题
假如我们拿到的串是1e6个'a'，那么上面那个算法就会被卡成O(n2)，道理的话大家可以想一想（每一次递归都只会把next[i]变小1）
那么我们需要做一个优化，来解决这个问题，而解决问题的核心就是：减少重复递归
减少重复递归......有没有想到什么？
没错，就是如同求next时一样的方法！
我们将递归用的变量j的值不更新，这样，求完了i的答案以后，j的位置一定在i/2​的左边，也就是它已经满足要求了
这时再递归求解，总时间效率是O(n)的*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1000010, mod = 1000000007;
int n;
char str[N];
int ne[N];
int num[N];
int all[N];     //  是有重叠,且不包含本身有多少个

int main()
{
	cin >> n;
	while (n--)
	{
		unsigned long long ans = 1;        //  虽然 %mod，但是观察式子，会发现有一项是ans * (num[i]+1)%mod，在算出这个乘积的过程中使用int型的ans会溢出，所以改成unsigned long long 型的ans，这个
		//乘积就不会溢出。
		cin >> str + 1;
		int len = strlen(str + 1);
		for (int i = 2, j = 0; i <= len; i++)
		{
			while (j && str[i] != str[j + 1])j = ne[j];         //   注意判断条件还有个  j&&
			if (str[i] == str[j + 1])j++;
			ne[i] = j;
			if (j == 0)all[i] = 0;
			else all[i] = all[j] + 1;
		}
		for (int i = 2,j = 0; i <= len; i++)
		{
			while (j && str[i] != str[j + 1])j = ne[j];            //   就是因为这一个操作用了一天时间做这道题，首先我们要找到第一个j，（i/2后的第一个j），根据all[j]+1得出num[i]
			//  但是如果求每个i的时候都令j = ne[i],在循环去找i/2后的第一个j，时间复杂度太高，不是线性，由于数据范围，必须要 n 的时间复杂度
			//  在求num[i]时我们找到了一个j，再求下一个num[i+1]时不需要 j 重新赋值ne[i]，再去找，而是利用上一个j的值，利用和求  ne数组时一样的方式（53，57行和求ne一样），调整上一个j
			//   使它变成我们需要的 新的j，再进行58行及以下操作去求
			if (str[i] == str[j + 1])j++;
			for (; j != 0; j = ne[j])
			{
				if (j <= i / 2)
				{
					num[i] = all[j] + 1;
					ans = (ans * (num[i] + 1) % mod) % mod;        //  注意取模运算规律
					break;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}