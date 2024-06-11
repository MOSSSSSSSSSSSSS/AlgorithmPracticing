//   有贪心思想 a+b>b+a return true
//   如何改变sort是降序还是升序？加  less<int>  是升序排列（默认）,加  greater<int> 是降序排列


#include<bits/stdc++.h>
using namespace std;

vector<string> str;
int n;

bool cmp(string a, string b)
{
	if (a + b > b + a)return true;     //string的相加 表示 拼接          a表示排序后前一个数，b表示排序后后一个数，如果a+b>b+a就是true的，

	//如果改成 b+a>a+b 返回true 排序就是反着来的，结果就是错的%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

	else return false;
}

int main()
{
	cin >> n;
	while (n--)
	{
		string a;
		cin >> a;
		str.push_back(a);
	}

	sort(str.begin(), str.end(),cmp);

	for (auto item : str)cout << item;    //   遍历容器每个元素，item是各个元素

	return 0;
}