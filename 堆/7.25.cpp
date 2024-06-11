

//  �ѣ�һ�����ϣ�1.����һ���� 2.��ǰ���ϵ���Сֵ 3.ɾ����Сֵ 4.ɾ������һ��Ԫ�� 5.�޸�����һ��Ԫ��
//  �� ��һ�� ��ȫ������,(�����һ��ڵ㣬�������нڵ㶼�����ģ����һ��ڵ�������Ų�)  С���ѣ�ÿ���ڵ��ֵС�ڵ��������ӽڵ��ֵ�����Ը��ڵ�����Сֵ��ģ����С�ڸ��ĳɴ��ھ��Ǵ����
//  ��һ��һά����洢   1�ŵ��Ǹ��ڵ㣬���нڵ㣬����ӽڵ㣬��2*x�Žڵ㣬�ұ��ӽڵ���2*x+1�Žڵ㡣
//  �ѵ����������������  down ��  up����ʵ��    ��  ������ʱ�临�Ӷȶ���   log2n



//   ѭ�����ж�������  ��i>=1����д��i��     i>=0����д��~i


#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, m;
int heap[N], size6;//size��¼����Ŀǰ�ж���Ԫ��%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void down(int u)   //�����±�
{
	int t = u;     //   t�洢����������С�������±�
	if (2 * u <= size6 && heap[2 * u] < heap[t])t = 2 * u;
	if (2 * u + 1 <= size6 && heap[2 * u + 1] < heap[t])t = 2 * u + 1;
	if (u != t)       //  ���u!=t�Ž��������û����жϾ�����ѭ��
	{
		swap(heap[t], heap[u]);
		down(t);
	}
}

void up(int u)
{
	while (u / 2 && heap[u / 2] > heap[u])         //����и��ڵ㣬���Ҹ��ڵ��Ǹ�������
	{
		swap(heap[u], heap[u / 2]);
		u /= 2;             //  u���ڸ��ڵ���±꣬�ٿ�
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)scanf("%d", &heap[i]);   //�Ȱ����������η���heap,��1��ʼ%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	size6 = n;  // size6��¼Ŀǰ���ٸ�
	for (int i = n / 2; i ; i--)down(i);              //���ѣ����Ӷ�С��O(n) ��n/2��ʼdown
	while (m--)
	{
		printf("%d", heap[1]);
		heap[1] = heap[size6];   //  �����һ���͵�һ��������������һ��������󣬿��Է���� ɾ��
		size6--;
		down(1);
	}


	return 0;
}
//*********************************************************************************************************************************
//ģ��ѣ�������Ŀ��Ҫɾ�����޸�   ��  k  �� ��  ��� ����������Ҫph[]����洢��k���±꣩������������±꣬hp[]����洢�±���k���±꣩�����ǵڼ��������
// ���ph��hp������Dijkstra�㷨�Ż���Ҳ�õ�����������swapҪ�ĳ�heap_swap
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int heap[N],n,ph[N],hp[N],size6,No;

void heap_swap(int a, int b)
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(heap[a], heap[b]);
}

void down(int u)
{
	int t = u;
	if (2 * u && heap[2 * u] < heap[t])t = 2 * u;
	if (2 * u+1 && heap[2 * u+1] < heap[t])t = 2 * u+1;
	if (t != u)
	{
		heap_swap(t, u);
		down(t);
	}
}

void up(int u)
{
	while (u / 2 && heap[u / 2] > heap[u])
	{
		heap_swap(u / 2, u);
		u /= 2;
	}
}

int main()
{
	cin.tie(0);
	cin >> n;
	while (n--)
	{
		string str;
		int k, x;
		cin >> str;
		if (str == "I")
		{
			No++;
			cin >> x;
			heap[++size6] = x;
			ph[No] = size6;
			hp[size6] = No;
			up(size6);
		}
		else if (str == "PM")
			cout << heap[1] << endl;
		else if (str == "DM")
		{
			heap_swap(1, size6);        //�ǽ���  ��һ�������һ��  ����ɾ��
			size6--;
			down(1);
		}
		else if (str == "D")
		{
			cin >> k;
			heap_swap(ph[k], size6);    //  ������� ������ɾ���������  �����Բ���ȷ�� ��������down����up����һ��  ��һ����down��
			//����������Ҫд
			size6--;
			down(ph[k]); up(ph[k]);
		}
		else
		{
			cin >> k >> x;
			heap[ph[k]] = x;
			down(ph[k]); up(ph[k]);
		}
	}

	return 0;
}


