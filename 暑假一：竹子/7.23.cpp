

//%%%%%%%%%%%%%%%%%%%%%%%����ߵ����ӵ���С�߶ȡ��������Ķ�������Сֵ�����뵽���֣�ͬ��帴��һ��


#include<bits/stdc++.h>
using namespace std;

int n, m, k, p,x = 1e9;//n�����ӣ�m�죬k�Σ�p��
int l = 0, r;
vector<int> bamboos;// m���߶�

bool check(int height,vector<int> bamboos)
{
	int use = 0;
	for (int i = 0; i < n; i++)
	{
		while (bamboos[i] > height)
		{
			use++;
			bamboos[i] = max(0, bamboos[i]-p);
		}
	}

	if (use <= m * k)return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> k >> p;
	for (int i = 0; i < n; i++)
	{
		int h, a;
		cin >> h >> a;
		bamboos.push_back(h+m*a);
		r = max(r, h + m * a);
		x = min(x, a);
	}
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid,bamboos))r = mid;
		else l = mid + 1;
	}

	if (l==0)cout << x;
	else cout << l;

	return 0;
}