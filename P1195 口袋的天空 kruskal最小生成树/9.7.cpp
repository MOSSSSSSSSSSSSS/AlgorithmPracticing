


/*��һ�仰˵���� ���n���㱻n-1�������ӵĻ�����һ���ǿ�����

��ô��

���ı��� �õ������ĸ���

n-1 1

n-2 2

n-3 3

... ...

n-k k

�������������Ҫ����k����������Ҫ��n-k���ߡ�*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1010,M = 10010;
int n, m,k;
int p[N];
struct edge {
	int a, b, w;
}edges[M];

bool cmp(edge a, edge b)
{
	if (a.w < b.w)return true;
	else return false;
}

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> m>>k;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges[i] = { a,b,w };
	}
	sort(edges + 1, edges + 1 + m,cmp);
	int res = 0, cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		a = find(a), b = find(b);
		if (a != b)
		{
			p[a] = b;
			res += w;
			cnt++;
		}//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		if (cnt == n - k)break;    //  �Ѿ�����k������ֱ���˳���������������ˣ���ֻҪk��%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	}//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	if (cnt < n - k)cout << "No Answer" << endl;
	else cout << res << endl;   //���ڵ���n-k

	return 0;
}