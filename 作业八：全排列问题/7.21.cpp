

//   全排列函数：next_permutation函数参数：iterator start,iterator end
//     int num[3]={1,2,3};  
//   (next_permutation(num,num+n))就是对num的前n个求它的下一个字典序的全排列，再放到原数组中,如果不存在字典序下一个排列则返回false，否则返回true
//   所以如果想求一个数组所有的全排列，用do while，并事先对数组升序排序
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> num;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)num.push_back(i);
	do {
		for (auto item : num)cout <<setw(5)<< item;
		cout << endl;
	} while (next_permutation(num.begin(), num.end()));

	return 0;
}