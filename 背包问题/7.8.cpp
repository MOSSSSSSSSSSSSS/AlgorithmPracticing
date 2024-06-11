

//c++最多一秒1e7到1e8次即一亿次运算，1e9是10亿
// 
//背包问题，线性dp，区间dp，计数类dp，数位统计dp，状态压缩dp，树形dp，记忆化搜索
// 
//背包问题，有一个容量为V的背包，有N件物品，每个物品有体积Vi和价值（权重）Wi        使背包能装得下的情况下 价值最大        一般思路想二维，一维优化
//01背包问题：每个物品 最多只能用一次， 所以叫 0 1背包问题
//完全背包问题：每件物品 有 无限 个，可以用无限次
//多重背包问题：每个物品 有 它的个数 ，可以用 它的个数次 ，有朴素版 和 优化版，优化版是 多重背包 经典的优化方式
//分组背包问题：有多组物品，每组只能选一个

//***************************************************************************************************
//01背包问题
//状态表示，f（i，j）表示拿前i个物品，j表示背包当前剩余容量，f（i，j）存储的是这种拿取方法的 价值最大值
//状态转移，根据拿不拿第i个物品，f（i，j） =max( f（i-1，j）, f（i-1，j-Vi） + Wi  )
//一开始是二维的，用一维优化空间大小
#include<iostream>
using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N];
int f[N][N];

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];//   这里从1开始，第一件物品到第n件物品
	//初始化状态，i = 0是存储值为0，j = 0是存储值为0
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (j >= v[i])f[i][j] = max(f[i - 1][j],f[i - 1][j - v[i]] + w[i]);//注意f（i-1，j-Vi）中的j-Vi，j是从1开始，有可能是负数，要避免，分情况。
			//f(i,j)有两种可能，拿或不拿，要选择 价值最大的
			else f[i][j] = f[i - 1][j];
		}
	}
	cout << f[n][V];

	return 0;
}
//***********************************************************************************************
//01背包优化，由于算每一层r的时候都只用到r - 1即上一层的值，   ￥￥￥去掉r这个维度￥￥￥。再处理
//处理完后并不是等价的，处理完后的状态转移方程，形象的说就是每一次i的循环，都对数组重新从左往右赋值。
// 因为f[j] = max(f[j], f[j - v[i]] + w[i])求的是i层的j等号右边f[j]是i-1层的，
//由于j从小到大循环，f[j - v[i]]已经是第i层的，但需要i-1层的，所以再改成j从大到小循环
#include<iostream>
using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N];
int f[N];

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++)
		for (int j = V; j >= v[i]; j--)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	cout << f[V];//最后结果都是第i = n的结果，只需输出容量是V的

	return 0;
}
/*#include<iostream>
using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N];
int f[N];

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++)
		for (int j = v[i]; j <= V; j++)
		{
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	cout << f[V];

	return 0;
}*/
//*************************************************************************************************
//完全背包问题
//朴素解法 :01背包问题是看第i个拿或不拿即拿0个拿1个，完全背包问题是看第i个是拿0个，还是拿1个，还是拿2个，一直到背包装不下。
#include<iostream>
using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N];
int f[N][N];

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= V; j++)
			for (int k = 0; k * v[i] <= j; k++)//j是当前容量，不是V
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + w[i] * k);//取这所有情况的最大值
	cout << f[n][V];

	return 0;
}
//时间优化
#include<iostream>
using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N];
int f[N][N];

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= V; j++)
		{
			if (j >= v[i])
			{
				f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i]);//为什么可以优化成这种形式？写出f[i][j] = max(拿0个，拿1个，。。。。一直到拿最多k个)表达式
				//再写出，f[i][j- v[i]] = max(拿0个，拿1个。。。。拿k-1个（因为减了v[i]）)可以发现，f[i][j]除了拿0个的，剩下的都和f[i][j-v]等号右边差一个w
				//所以f[i][j-v]的最大值+w就是  f[i][j]等号右边剩下的最大值.。
			}
			else
			{
				f[i][j] = f[i - 1][j];
			}
		}
	cout << f[n][V];

	return 0;
}
//时间优化的基础上空间优化（由于推导出的状态转移方程只和 01背包有一点差别，空间优化后只有第二层循环的顺序与优化后的01背包不同）
#include<iostream>
using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N];
int f[N];

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++)
		for (int j = v[i]; j <= V; j++)
		{
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	cout << f[V];

	return 0;
}
//*************************************************************************************************
//多重背包问题
//朴素
#include<iostream>
using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N],s[N];//s是第n件物品有多少个
int f[N][N];

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i]>>s[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= V; j++)
			for (int k = 0; k * v[i] <= j&&k<=s[i]; k++)//两个条件有一个不满足也不行，k即不能超出s[i]，也不能拿的超过背包容量
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + w[i] * k);//取这所有情况的最大值
	cout << f[n][V];

	return 0;
}
//朴素方法复杂度O(N*V*S)（最大是s）
//时间优化 
//首先，当k满足背包容量不管是j还是j-v都能存储下k个，全部存储的，再次尝试使用完全背包优化方法，会发现由于f[i][j-v] = max(括号中由于是k不是k-1)
//会比f[i][j] = max()括号中除拿0个外的部分，还多一项，而知道多一项的序列的最大值，不能推出去掉多的那一项后的序列的最大值，所以这种情况（当k满足背包容量不管是j还是j-v都能存储下k个，全部存储的）
//（即某一种特殊情况都不行，不必再看k的其他情况）不能按 完全背包的方法优化
//而要使用，二进制（倍增）的方法转化成01背包问题再优化。
//对于一个物品有s个，都可以分成若干组，第一组1个，第二组2个，第三组4个，第四组8个......直到不能用2的n次幂再分，则直接将剩余的再分一组
//对于这些组，每组选择拿或不拿，就可以把拿0到拿s个的情况全部包括，（证明再动态规划一上课录播1：28：16）
//所以这些组就是一个个物品，像01背包一样，要么只拿1个，要么不拿
//按这种方法优化后时间复杂度O(N*log2s*V)，01背包是N*V，这里有N个每个分成log2s组，一共N*log2s组，（1023恰好分成10组，1024就得11组而比1023小如900也得是10组2047也是11组）
#include<iostream>
using namespace std;

const int N = 23000, M = 2010;//存的是组有多少个，最多是*2000*   log2 2000大概是11组就是11000    但11000会错  11010可以对 

int n, m;
int v[N], w[N];
int f[M];//直接用一维，看V最大多少

int main()
{
	cin >> n >> m;
	int cnt = 1;//不要定义在for循环里面，cnt的值要一直往下走
	for (int i = 1; i <= n; i++)
	{
		int a, b, s, k = 1;//count计数,k一组多少个,不要用v w s命名否则与上面数组重名
		cin >> a >> b >> s;
		while (k <= s)
		{
			s -= k;
			v[cnt] = a * k;
			w[cnt] = b * k;
			cnt++;
			k *= 2;
		}
		if (s)
		{
			v[cnt] = a * s;
			w[cnt] = b * s;
			cnt++;             //为下一个数做准备
		}
	}

	n = cnt - 1;                //01背包 n是总共多少物品，注意n要变

	for (int i = 1; i <= n; i++)
		for (int j = m; j >= v[i]; j--)
			f[j] = max(f[j], f[j - v[i]] + w[i]);

	cout << f[m];

	return 0;
}
//7.24又写一遍   注意v是体积w是价值
//多重背包二进制优化，复杂度：n*v*log2s
#include<bits/stdc++.h>
using namespace std;

const int N = 11000, M = 2010;

int n, m;
int a[N], b[N];
int f[N][M];

int main()
{
	cin >> n >> m;
	int cnt = 1;
	for (int i = 1; i <= n; i++)
	{
		int v, w, s,k = 1;
		cin >> v >> w >> s;
		while (s >= k)
		{
			s -= k;
			a[cnt] = k * v;
			b[cnt] = k * w;
			cnt++;
			k *= 2;
		}
		if (s)
		{
			a[cnt] = s * v;
			b[cnt] = s * w;
			cnt++;
		}
	}
	n = cnt - 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j >= a[i])
			{
				f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + b[i]);
			}
			else
			{
				f[i][j] = f[i - 1][j];
			}
		}
	}

	cout << f[n][m];

	return 0;
}
//7.24  多重背包  第二种优化方式   用单调队列优化     时间复杂度比二进制优化更小  看bilibili视频，  不完全理解

#include<bits/stdc++.h>
using namespace std;

const int M = 20010;

int n, m;
int f[M], g[M], q[M];//         直接用一维做，g记录f的上一层，因为要用到f的上一层，但这种单调队列优化要从小到大枚举

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int v, w, s;
		cin >> v >> w >> s;
		memcpy(g, f, sizeof(f));
		for (int j = 0; j < v; j++)
		{
			int hh = 0, tt = -1;
			for (int k = j; k <= m; k += v)
			{
				if (hh <= tt && q[hh] < k - s * v)hh++;
				if (hh <= tt)f[k] = max(g[k], g[q[hh] + (k - q[hh]) / v * w);
				while (hh <= tt && g[k] >= g[q[tt]] + (k - q[tt]) / v * w)tt--;
				q[++tt] = k;
			}
		}
	}

	cout << f[m];

	return 0;
}





//**********************************************************************************************************
//分组背包问题
//状态表示：从前i组中选，背包剩余容量是j，状态转移方程：f[i][j] = 第i组一个也不选，第i组选第1个.....第i组选最后一个
//f[i][j] = max(f[i-1][j],f[i-1][j-v[i][1]]+w[i][1],f[i-1][j-v[i][2]]+w[i][2],f[i-1][j-v[i][s[i]]]+w[i][s[i]])
#include<bits/stdc++.h>
using namespace std;

const int N = 110;

int n, V;
int s[N], v[N][N], w[N][N];
int f[N][N];

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		for (int j = 1; j <= s[i]; j++)
			cin >> v[i][j] >> w[i][j];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			for (int k = 0; k <= s[i]; k++)
			{
				if (j >= v[i][k])
					f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
				else
					f[i][j] = f[i - 1][j];
			}
		}
	}

	cout << f[n][V];

	return 0;
}
//空间优化
#include<bits/stdc++.h>
using namespace std;

const int N = 110;

int n, V;
int S[N], v[N][N], w[N][N];
int f[N];        //依旧是只和r-1行有关，删掉第一维。

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++)
	{
		cin >> S[i];
		for (int j = 1; j <= S[i]; j++)
			cin >> v[i][j] >> w[i][j];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = V; j >= 1; j--)       //注意改的时候把加加改成减减
		{
			for (int k = 0; k <= S[i]; k++)
				if (j >= v[i][k])          //j并不能改成从v[i][k]开始，这个判断要保留
					f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
		}
	}

	cout << f[V];

	return 0;
}