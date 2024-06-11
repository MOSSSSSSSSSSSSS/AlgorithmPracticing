

//   哈希表就是查找一个数有没有，存入一个数
//   拉链法删除一个数就是让前面的直接指向后面的

//在从小到大的排序数组中，
//lower_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的地址,不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
//upper_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于num的数字，找到返回该数字的地址，不存在则返回end,通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。




//  题目中要求找到长度为x的，如果没有就找离x最近的长度的，而哈希表O（1）是无序的，用哈希表完成这个操作很麻烦，

//     平衡树，复杂度O（logn），是有序的，用平衡树做这种操作更好。



/*明明hash表查询更快，数据库为什么不用hash表？

我能想到的有两方面，一个是平衡树的有序特性，另一个就是hash表的扩容问题。

有序有什么用？

假设数据库中有1百万条数据，有100条的id>xxx。现在我们要从这一百万条数据中，取出这100条id>xxx的数据。由于平衡树是有序的，只要找到xxx这个主键，就可以顺藤摸瓜，得到所有的大于xxx的用户。而对于hash表，它只能把每个数据都拿出来比对一遍。

hash表的扩容问题是什么？

我们常见的hash表实现，是基于数组实现的，用拉链法解决hash冲突。基于数组的固定大小，我们才方便进行hash计算。但是当数据量上去的时候，每个hash桶内的元素会越来越多，必然影响到查询。所以一般都会在达到临界值的时候，进行扩容。找一片更大的空间，然后把旧数据移入新空间中，这个过程需要重hash。数据量一大的话，重hash的时间成本非常高。

可以尽量避免重hash吗？

可以是可以。前提是我们知晓将要存入的数据大概在什么范围，这样的话就可以在初始化hash表的时候指定大小。但是对于数据库这种应用，我们没办法确定到底会放多少数据进去。*/




#include<bits/stdc++.h>
using namespace std;

const int N = 100003;
int h[N], e[N], ne[N], idx,n,m,backup[N]; //   m动态维护木材数量
bool check[N];        //  e中的元素并不是现有的元素，有的被删了有的没被删（因为删除操作只是动了ne），用check记录某个数据有没有被删

void insert(int len)
{
	int k = (len % N + N) % N;
	e[idx] = len;
	ne[idx] = h[k];
	h[k] = idx++;
}

bool find(int len)
{
	int k = (len % N + N) % N;
	for (int i = h[k]; i != -1; i = ne[i])
		if (e[i] == len)
			return true;
	return false;
}

void del(int len)
{
	int k = (len % N + N) % N;
	int i = h[k];
	if (e[i] == len)
	{
		check[i] = 1;
		h[k] = ne[i];
		return;
	}
	for (int i = h[k];; i = ne[i])
	{
		int j = ne[i];
		if (e[j] == len)
		{
			check[j] = 1;
			ne[i] = ne[j];
			return;
		}
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < N; i++)h[i] = -1;
	cin >> n;
	while (n--)
	{
		char flag;
		int len;
		cin >> flag >> len;
		if (flag == '1')
		{
			if (find(len))cout << "Already Exist" << endl;
			else
			{
				insert(len);
				m++;
			}
		}
		else
		{
			if (m)
			{
				if (find(len))
				{
					del(len);
					m--;
					cout << len << endl;
				}
				else
				{
					int j = 0;
					for (int i = 0; i < idx; i++)
						if(check[i]==0)
							backup[j++] = e[i];
					if (m == 1)
					{
						del(backup[0]);
						m--;
						cout << backup[0] << endl;
					}
					else
					{
						sort(backup, backup + m);
						int t = upper_bound(backup, backup + m, len) - backup;
						if (t == m)
						{
							del(backup[m - 1]);
							cout << backup[m - 1] << endl;
							m--;
						}
						else
						{
							if (t == 0)
							{
								del(backup[0]);
								m--;
								cout << backup[0] << endl;
							}
							else
							{
								if (backup[t] - len < len - backup[t - 1])        //    至少有两个,所以有一个的时候要特判
								{
									del(backup[t]);
									m--;
									cout << backup[t] << endl;
								}
								else
								{
									del(backup[t - 1]);
									m--;
									cout << backup[t - 1] << endl;
								}
							}
						}
					}
				}
			}
			else
				cout << "Empty" << endl;
		}
	}

	return 0;
}