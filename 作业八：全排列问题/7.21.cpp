

//   ȫ���к�����next_permutation����������iterator start,iterator end
//     int num[3]={1,2,3};  
//   (next_permutation(num,num+n))���Ƕ�num��ǰn����������һ���ֵ����ȫ���У��ٷŵ�ԭ������,����������ֵ�����һ�������򷵻�false�����򷵻�true
//   �����������һ���������е�ȫ���У���do while�������ȶ�������������
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