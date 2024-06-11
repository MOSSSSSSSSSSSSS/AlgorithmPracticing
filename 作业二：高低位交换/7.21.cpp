


//  ^ 表示按位异或，相同是0不同是1
//  左移：例如7是00000111左移1是：00001110(右边多出个0)
//  右移：例如7是00000111右移1是：00000011(左边多出个0)
//  如果是负数那么右移左边多的都是1

#include<bits/stdc++.h>
using namespace std;

unsigned int n;   //范围是0到2的32次方-1，和题目范围吻合

int main()
{
	cin >> n;
	cout << ((n & 0xffff0000) >> 16 | (n & 0x0000ffff) << 16) << endl;

	return 0;
}