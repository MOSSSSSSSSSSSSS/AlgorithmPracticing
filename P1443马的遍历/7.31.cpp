

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 410;
int n,m,x,y;
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
PII q[N * N];                            //   BFS���У���N*N��
int hh, tt = -1;
int dist[N][N];                         //   BFS�������ظ��ģ����������·����һ��bool�������ﻹҪ��¼������ֱ����dist��¼�������bool

int bfs(int xt, int yt)
{
	dist[x][y] = 0;
	q[++tt] = { x,y };              //     BFS��һ�����Ƚ���һϵ�г�ʼ��
	while (hh <= tt)                    //    ����������ѭ������������
	{
		PII t = q[hh++];                 //  ѭ����һ������ȡ��ͷԪ�أ���ɾ����ͷ
		for (int i = 0; i < 8; i++)
		{
			if (t.first + dx[i] >= 1 && t.first + dx[i] <= n && t.second+ dy[i] >= 1 && t.second + dy[i] <= m && dist[t.first + dx[i]][t.second + dy[i]] == -1)
			{
				q[++tt] = { t.first + dx[i] ,t.second + dy[i] };
				dist[t.first + dx[i]][t.second + dy[i]] = dist[t.first][t.second] + 1;      //  ����������ˣ��Ѳ���Ҳ���ˣ�������һ��λ�õļ�1
			}
		}
	}

	return dist[xt][yt];
}

int main()
{
	cin >> n >> m >> x >> y;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dist[i][j] = -1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << bfs(i, j) << "    ";
		cout << endl;
	}

	return 0;
}