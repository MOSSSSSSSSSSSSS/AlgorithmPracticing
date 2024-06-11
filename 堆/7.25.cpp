

//  堆：一个集合，1.插入一个数 2.求当前集合的最小值 3.删除最小值 4.删除任意一个元素 5.修改任意一个元素
//  堆 是一个 完全二叉树,(除最后一层节点，上面所有节点都是满的，最后一层节点从左到右排布)  小根堆：每个节点的值小于等于两边子节点的值，所以根节点是最小值，模板里小于更改成大于就是大根堆
//  用一个一维数组存储   1号点是根节点，所有节点，左边子节点，是2*x号节点，右边子节点是2*x+1号节点。
//  堆的五个操作都可以用  down 和  up函数实现    这  两个的时间复杂度都是   log2n



//   循环的判断条件里  ，i>=1可以写成i，     i>=0可以写成~i


#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, m;
int heap[N], size6;//size记录堆中目前有多少元素%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void down(int u)   //参数下标
{
	int t = u;     //   t存储三个数中最小的数的下标
	if (2 * u <= size6 && heap[2 * u] < heap[t])t = 2 * u;
	if (2 * u + 1 <= size6 && heap[2 * u + 1] < heap[t])t = 2 * u + 1;
	if (u != t)       //  如果u!=t才交换，如果没这个判断就无限循环
	{
		swap(heap[t], heap[u]);
		down(t);
	}
}

void up(int u)
{
	while (u / 2 && heap[u / 2] > heap[u])         //如果有父节点，并且父节点那个数更大
	{
		swap(heap[u], heap[u / 2]);
		u /= 2;             //  u等于父节点的下标，再看
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)scanf("%d", &heap[i]);   //先把所有数依次放入heap,从1开始%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	size6 = n;  // size6记录目前多少个
	for (int i = n / 2; i ; i--)down(i);              //建堆，复杂度小于O(n) 从n/2开始down
	while (m--)
	{
		printf("%d", heap[1]);
		heap[1] = heap[size6];   //  把最后一个和第一个交换，这样第一个到了最后，可以方便地 删掉
		size6--;
		down(1);
	}


	return 0;
}
//*********************************************************************************************************************************
//模拟堆，由于题目需要删除和修改   第  k  个 插  入的 数，所以需要ph[]数组存储第k（下标）个插入的数的下标，hp[]数组存储下标是k（下标）的数是第几个插入的
// 这个ph，hp数组在Dijkstra算法优化中也用到，并且所有swap要改成heap_swap
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
			heap_swap(1, size6);        //是交换  第一个和最后一个  方便删掉
			size6--;
			down(1);
		}
		else if (str == "D")
		{
			cin >> k;
			heap_swap(ph[k], size6);    //  这个交换 由于是删掉任意的数  ，所以不能确定 交换后是down还是up，不一定  就一定是down，
			//所以两个都要写
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


