

//����һ�㶼�ǵ�һ�������ݸ������ڶ������������ݣ����û�и�������һ�����ٸ���ֱ�Ӹ��������ݣ���û�����ݽ����ı�ʶ��������һ��0��ʾ���������
//��ʱӦ����while(cin>>)����

//������ҵ���  �������������

//Dilworth Dilworth �������е�������������еĸ���������������������еĴ�С

#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

vector<int> b,c;
int a[N],f[N],res,n = 1;

int main()
{
	ios::sync_with_stdio(false);   //���cin�ٶ�
	while (cin >> a[n])n++;
	n--;   //��ʱn��һ���ж��ٸ����������

	b.push_back(0);
	b.push_back(a[1]);
	f[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		int l = 0, r = b.size() - 1;
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			if (b[mid] >= a[i])l = mid;
			else r = mid - 1;
		}
		if (l == b.size() - 1)b.push_back(a[i]);        //    ��Ϊ���==д����=���˷Ѻü�Сʱ
		else b[l + 1] = a[i];
		f[i] = l + 1;
	}

	for (int i = 1; i <= n; i++)res = max(res, f[i]);
	//for (int i = 1; i <= n; i++)cout << f[i] << ' ';           //  �ǵý���ȥ��ʱ��Ҫɾ
	cout << endl << res << endl;

	c.push_back(0);
	c.push_back(a[1]);

	for (int i = 2; i <= n; i++)
	{
		int l =1, r = c.size();
		while (l < r)
		{
			int mid = l + r >> 1;
			if (c[mid] >= a[i])r = mid;
			else l = mid + 1;
		}
		if (l == c.size())c.push_back(a[i]);
		else c[l] = a[i];
		f[i] = l;
	}

	res = 0;
	for (int i = 1; i <= n; i++)res = max(res, f[i]);
	cout << res;


	return 0;
}
