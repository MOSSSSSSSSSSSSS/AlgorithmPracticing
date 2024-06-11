

//      注意   数组   作为  函数的  参数  时，在函数内部 改变数组的值，实参会改变
//      因为忽略这一点，这题浪费时间


//   直接对答案二分 
//      不是二分浮点数，而是所有的数都乘100，最后结果除100，二分整数  求mid除以二的时候，mid直接用int就行，没用double试   因为 浮点数 计算有 误差。
//      if (sum >= k)return false;
//	    else return true;
//一开始是这样写的，
//if (check(mid, k, sheng, n)) r = mid;
//		else l = mid + 1;
//就错了，但如果改成
//if (sum >= k)return true;
//	else return false;
//  下面改成
//int mid = (l + r + 1) / 2;
//if (check(mid, k, sheng, n)) l = mid;
//else r = mid - 1;
//  就对了
//
#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, k;
int sheng[N], m;

bool check(int mid, int k, int sheng[], int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int j = sheng[i];
		while (j - mid >= 0)
		{
			j -= mid;
			sum++;
		}
	}
	//l = mid
	if (sum >= k)return true;//  等于时，由于要最大值，所以区间向更大的方向移动
	else return false;
}

int main()
{
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		double a;
		cin >> a;
		sheng[i] = int(a * 100);
		m = max(m, sheng[i]);
	}
	int l = 0, r = m;
	while (r - l > 0.0001)           //   要求0.01，直接多2个0，0.0001
	{
		int mid = (l + r + 1) / 2;
		if (check(mid, k, sheng, n)) l = mid;
		else r = mid - 1;
	}
	printf("%.2f", r / 100.0);                //除100.0，再保留两位输出                 //  printf("%.2f"  是四舍五入的,这里要求直接舍去

	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, k;
double sheng[N],m;

bool check(double mid,int k,double sheng[],int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		double j = sheng[i];
		while (j-mid>=0)
		{
			j -= mid;
			sum++;
		}
	}
	//l = mid
	if (sum >= k)return false;//  等于时，由于要最大值，所以区间向更大的方向移动
	else return true;
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> sheng[i];
		m = max(m, sheng[i]);
	}
	double l = 0, r = m+3;
	while (r - l > 0.001)
	{
		double mid = (l + r) / 2.0;
		if(!mid)break;
		if (check(mid, k, sheng, n)) r = mid;
		else l = mid;
	}
	printf("%.2lf", ((l * 100)) / 100.0);                     //  printf("%.2f"  是四舍五入的,这里要求直接舍去
	return 0;
}
*/