#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> num;

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		int x;
		scanf("%d", &x);
		num.push_back(x);
	}
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	printf("%d\n", num.size());
	for (auto item : num)printf("%d ", item);

	return 0;
}