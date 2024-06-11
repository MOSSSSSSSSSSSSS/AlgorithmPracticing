
//A，B，C
/*
并查集能维护连通性、传递性，通俗地说，亲戚的亲戚是亲戚。

然而当我们需要维护一些对立关系，比如 敌人的敌人是朋友 时，正常的并查集就很难满足我们的需求。

这时，种类并查集就诞生了。

常见的做法是将原并查集扩大一倍规模，并划分为两个种类。

在同个种类的并查集中合并，和原始的并查集没什么区别，仍然表达他们是朋友这个含义。

考虑在不同种类的并查集中合并的意义，其实就表达 他们是敌人 这个含义了。

按照并查集美妙的 传递性，我们就能具体知道某两个元素到底是 敌人 还是 朋友 了。

至于某个元素到底属于两个种类中的哪一个，由于我们不清楚，因此两个种类我们都试试。

具体实现，详见 P1525 关押罪犯。

概念解释
再来看本题，每个动物之间的关系就没上面那么简单了。

对于动物x 和y，我们可能有x 吃y，x 与y 同类，x 被y 吃。
但由于关系还是明显的，
1 倍大小、2 倍大小的并查集都不能满足需求，3 倍大小不就行了！
类似上面，我们将并查集分 3 个部分，每个部分代表着一种动物种类。
设我们有n 个动物，开了3n 大小的种类并查集，其中
1∼n 的部分为A 群系，n+1∼2n 的部分为
B 群系，2n+1∼3n 的部分为C 群系。
我们可以认为A 表示中立者，B 表示生产者，C 表示消费者。此时关系明显：A 吃B，A 被C 吃。
当然，我们也可以认为B 是中立者，这样C 就成为了生产者，A 就表示消费者。（还有
1 种情况不提及了）
联想一下2 倍大小并查集的做法，不难列举出：当A 中的x 与B 中的y 合并，有关系x 吃y；当C 中的x 和
C 中的y 合并，有关系x 和y 同类等等……
但仍然注意了！我们不知道某个动物属于A，B，还是C，我们3 个种类都要试试！
也就是说，每当有1 句真话时，我们需要合并3 组元素。容易忽略的是，题目中指出若x 吃y，y 吃z，应有x 被z 吃。
这个关系还能用种类并查集维护吗？答案是可以的。若将x 看作属于A，则y 属于B,z 属于C。最后，根据关系
A 被C 吃可得x 被z 吃。既然关系满足上述传递性，我们就能放心地使用种类并查集来维护啦。*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1.5e5 + 10;
int p[N];
int n, k;
int ans;

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= 3 * n; i++)
		p[i] = i;
	while (k--)
	{
		int op, x, y;
		cin >> op >> x >> y;
		if (x > n || y > n)
		{
			ans++;
			continue;
		}
		if (op == 2 && x == y)
		{
			ans++;
			continue;
		}
		if (op == 1)
		{
			int fx = find(x);
			int fy = find(n + y);
			int fx0 = find(n + x);
			int fy0 = find(y);
			if (fx == fy||fx0==fy0)
			{
				ans++;
				continue;
			}
			int fx1 = find(x), fy1 = find(y);
			if (fx1 != fy1)p[fx1] = p[fy1];
			int fx2 = find(n+x), fy2 = find(n+y);
			if (fx2 != fy2)p[fx2] = p[fy2];
			int fx3 = find(2*n+x), fy3 = find(2*n+y);
			if (fx3 != fy3)p[fx3] = p[fy3];
		}
		else
		{
			int fx = find(x), fy = find(y);
			int f = find(n + x);
			if (fx == fy || f == fy)
			{
				ans++;
				continue;
			}
			int fx1 = find(x), fy1 = find(n + y);
			if (fx1 != fy1)p[fx1] = p[fy1];
			int fx2 = find(n + x), fy2 = find(2*n + y);
			if (fx2 != fy2)p[fx2] = p[fy2];
			int fx3 = find(2 * n + x), fy3 = find(y);
			if (fx3 != fy3)p[fx3] = p[fy3];
		}
	}
	cout << ans;

	return 0;
}