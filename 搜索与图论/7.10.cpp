


//�����������DFS�������������BFS������ͼ�Ĵ洢������ͼ��������ȱ���������ͼ�Ŀ�����ȱ�������������
//DFS����stackʵ�֣�BFS��queueʵ�֣�DFS�ռ临�Ӷ�O��n����BFS�ռ临�Ӷ�O(2��n�η�)
//DFS���������·�ص㣬BFS�������·�ص㣬BFS�ҵ�һ�����������·�ҵ��ģ��ӽ���Զ��
//DFS�����ݣ��ָ�֮ǰ�ֳ�����֦�������Լ�֦���жϵ�ǰ���һ���������Ž⣬����ǰ������ǰ�������һ�֡������Լ�֦���������һ��Υ�����⣬����ǰ������ǰ�������һ�֡�


//7.29
//��������
#include<bits/stdc++.h>
using namespace std;

const int N = 10;

int n,path[N];
bool st[N];

void dfs(int u)
{
	if (u == n + 1)
	{
		for (int i = 1; i <= n; i++)cout << path[i] << ' ';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!st[i])
		{
			path[u] = i;
			st[i] = true;
			dfs(u + 1);
			path[u] = 0;
			st[i] = false;
		}
	}

}

int main()
{
	cin >> n;
	dfs(1);

	return 0;
}
//n �ʺ�����    ������Ӷ� n*n��
#include<bits/stdc++.h>
using namespace std;

const int N = 20;
int n,col[N],dg[N],udg[N];
char path[N / 2][N / 2];

void dfs(int u)
{
	if (u == n + 1)       //      �ݹ�Ҫ�� ��������
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				cout << path[i][j];
			cout << endl;
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!col[i] && !dg[u + i - 1] && !udg[u - i + n])
		{
			path[u][i] = 'Q';
			col[i] = dg[u + i - 1] = udg[u - i + n] = true;
			dfs(u + 1);
			col[i] = dg[u + i - 1] = udg[u - i + n] = false;
			path[u][i] = '.';
		}
	}

}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			path[i][j] = '.';

	dfs(1);

	return 0;
}
//      ���б�Ȩ�ض���1��ʱ�򣬲�����BFS�����·
//      ���Թ�
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 110;
int n, m, g[N][N], d[N][N];   //g���Թ���d��ÿ���㵽������
PII q[N * N], Prev[N][N]; //��Ҫ��·�������ֻ��Ҫ ��¼һ���㣬��ǰ��ĵ���˭
int hh, tt = -1;

int bfs(int n, int m)
{
	q[++tt] = { 1,1 };                  //�ѵ�һ����Ž�ȥ
	d[1][1] = 0;                        //�ѵ�һ����Ž�ȥ
	int dx[4] = { 0,-1,0,1 };
	int dy[4] = { 1,0,-1,0 };         //  �����ߵ���Χ�ĸ������ϣ�����һ��һ��ö�٣���������д
	while (hh <= tt)
	{
		PII t = q[hh++]; //%%%%%%%%%%%%%%%%%%
		for (int i = 0; i < 4; i++)
		{
			int x = t.first + dx[i];
			int y = t.second + dy[i];
			if (x >= 1 && x <= n && y >= 1 && y <= m && g[x][y] != 1 && d[x][y] == -1)
			{//����µĵ����Թ��ڣ��Ҳ���ǽ�ڣ���û�е����
				d[x][y] = d[t.first][t.second] + 1;
				q[++tt] = { x,y };
				Prev[x][y] = t;
			}
		}
	}
	for (int x = n, y = m; x != 1 || y != 1; )
	{
		PII t = Prev[x][y];
		cout << t.first << ',' << t.second << '   ';
		x = t.first, y = t.second;
	}

	return d[n][m];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> g[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			d[i][j] = -1;

	cout << bfs(n, m);

	return 0;
}
// ����һ�������ͼ�������޻���ͨͼ.%%%%%%%%%%%%%%%%%%%% n���ڵ���������n-1���� %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// 
//  ͼ�ֳ�����ͼ������ͼ�� a -->b ����ͼ�����з���ģ�a--b����ͼ������ʱ��ͽ�a -->b��b -->a������ͼ�����������ͼ
//   ����ͼ  �洢  ��һ�֣��ڽӾ���g[a][b] ָa �� b�����ߣ���Ȩ�ؾ���Ȩ�أ���Ȩ�ؾ���boolֵ��ʾ  ֮����û�бߣ��ڽӾ����ܴ洢 �رߣ�ֻ�ܱ��� һ����
//   �ռ临�Ӷ� �� n�����ʺϴ洢����ͼ��ϡ��ͼ���ʺ�
//    �ڶ����ǣ��ڽӱ�n���㣬��n��������������idx���±�0��ʼ�洢���洢 ����� ���Ե��ĵ�

//����ͼ�ı�����������ȱ�����������ȱ�����ÿ���㶼����һ�飬��bool st�����ʾ��û�б�������

//�������ģ�������ȱ�������Ϊ������ȱ�������ĳ���ڵ㣬���ߵ��ף�����������п������������ڵ�Ϊ���ڵ�������Ĵ�С
#include<bits/stdc++.h>
using namespace std;

const int N = 100010, M = N * 2;     //  n���ڵ㣬���n-1����ߣ���2*N��С�洢��
int h[N], e[M], ne[M], idx;        // ��Ȼ��n������������e��ne��idxֻ������
bool st[N];                        //������ȱ��� ��bool��¼��û�б�������
int n, ans = N;                      //ע��ans���������ֵ����С��ans = min������ansһ��ʼ��ֵΪN

void add(int a, int b)         //  ����a��b�ı�
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx++;
}

int dfs(int x)
{
 	st[x] = true;           //���Ϊ�Ѿ����ҹ�
 	int sum = 1, res = 0;
	for (int i = h[x]; i != -1; i = ne[i])      //  �����������
	{
		if (!st[e[i]])
		{
			int s = dfs(e[i]);
			res = max(res, s);
			sum += s;
		}
	}

	res = max(res, n - sum);
	ans = min(ans, res);

	return sum;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)h[i] = -1;
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);    //  ���Σ���Ϊ��  �� ���
	}
	dfs(1);      //�����нڵ��У���ѡһ����ʼ�Ѿ���
	cout << ans;
}

//  ������ȱ��� �� �����������+�ڽӱ�
//ͼ�е�Ĳ��
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;    
int q[N], hh, tt = -1, d[N];  

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void bfs()
{
	q[++tt] = 1;
	d[1] = 0;
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1)
			{
				q[++tt] = j;
				d[j] = d[t] + 1;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		d[i] = h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}

	bfs();

	cout << d[n];

	return 0;
}

//   ͼ�Ŀ������������Ӧ�ã���������
//   ͼ�����������������ͼ��˵�ģ�����ͼû�У���������A���㣬����ͼ�е�x��y�ı���˵����A��x��yǰ��
// Ҳ����˵����������������ѱ߻����������еı߶�������ָ��
//   ���� �޻� ��ͼһ�����������У����������޻�ͼ����Ϊ����ͼ���л�һ��û�������У�
//    ����ͼ�У�ÿ���㶼�������ȣ������ʾ�ж��ٱ�ͨ���Լ������ȱ�ʾ�ж��ٱ��Լ�����ͨ�����
//
//   ������������У��Ȱ�ͼ���������Ϊ0�ķŶ����У�����ȡ��ͷ�����������г��ȣ�ÿ������ָ���Ӧ��
//�����Ķ�Ӧ����Ӧ���--��������ٰ����Ϊ0�ķŶ����һֱ��������ȥ

#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];//  ��ʾ ÿ��������

void add(int a,int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
	d[b]++;
}

bool topsort()
{
	int hh = 0, tt = -1;
	for (int i = 1; i <= n; i++)
		if (!d[i])
			q[++tt] = i;
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			d[j]--;
			if (!d[j])q[++tt] = j;
		}
	}

	return tt == n - 1;    //  ����û��ȫ�����������룬tt��һֱ�ڼӼӵģ����ȫ����tt == n-1�ʹ���������
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}

	if (topsort())
		for (int i = 0; i < n; i++)
			cout << q[i] << ' ';      //  ���ų���ͷԪ��ʱֻ��hh++�����Ǵ�0��ʼ���������ġ�
	else
		cout << -1;

	return 0;
}