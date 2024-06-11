



//  c字符串转数字 ： int x = atoi(str+1);
// 
// 
//  注意 1 不是质数

//  DFS要注意顺序从哪到哪DFS，从左到右还是从右到左？ 影响效率
//  由于模拟较多，没写完，直接交的别人的

// 单独判断质数也慢，可以筛出 根号99999999 以内的质数，通过取模判断某个数是不是质数的代码如下
/*
* // 筛10005以内的质数
inline void init() {
	flag[1]= 1;
	for(int i= 2; i < 10005; i++) {
		if(!flag[i]) prim[++tot]= i;
		for(int j= 1; j <= tot; j++) {
			if(i * prim[j] >= 10005) break;
			flag[i * prim[j]]= 1;
			if(i % prim[j] == 0) break;
		}
	}
	return;
}
// 判断质数
inline int pdzs(int x) {
	if(x < 2) return 0;
	for(int i= 1; i <= tot; i++)
		if(x % prim[i] == 0) 
			return x == prim[i];
	return 1;
}
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int T,len,ans;
char str[N];

bool is_prime(int x)
{
	if (x < 2)return false;    //  1不是质数
	for (int i = 2; i <= x / i; i++)
		if (x % i == 0)
			return false;
	return true;
}
bool check()
{
	int x = atoi(str + 1);
	int y = atoi(str + 5);
	int z = atoi(str + 7);
	if (is_prime(x) && is_prime(y) && is_prime(z))return true;
	return false;
}
void dfs(int u)
{
	if (u > len)
	{
		if (check())
		{
			ans++;
			cout <<"$$$" << str + 1 << endl;
		}
		return;
	}
	if (str[u] == '-')
	{
		if (u >= 1 && u <= 3)
		{
			for (int i = '0'; i <= '9'; i++)
			{
				str[u] = i;
				dfs(u + 1);
				str[u] = '-';
			}
		}
		else if (u == 4)  // 年的个位
		{
			char strr[N];
			for (int i = 1; i <= 3; i++)
				strr[i] = str[i];
			int x = atoi(strr + 1);
			if (x == 0)
			{
				for (int i = '1'; i <= '9'; i++)
				{
					str[u] = i;
					dfs(u + 1);
					str[u] = '-';
				}
			}
			else
			{
				for (int i = '0'; i <= '9'; i++)
				{
					str[u] = i;
					dfs(u + 1);
					str[u] = '-';
				}
			}
		}
		else if (u == 5)  // 月的十位
		{
			for (int i = '0'; i <= '1'; i++)
			{
				str[u] = i;
				dfs(u + 1);
				str[u] = '-';
			}
		}
		else if (u == 6)  // 月的个位
		{
			if (str[5] == '0')
			{
				for (int i = '1'; i <= '9'; i++)
				{
					str[u] = i;
					dfs(u + 1);
					str[u] = '-';
				}
			}
			else
			{
				for (int i = '0'; i <= '2'; i++)
				{
					str[u] = i;
					dfs(u + 1);
					str[u] = '-';
				}
			}
		}
		else if (u == 7)  // 日的十位
		{
			if (str[5] == '0' && str[6] == '2')
			{
				for (int i = '0'; i <= '2'; i++)
				{
					str[u] = i;
					dfs(u + 1);
					str[u] = '-';
				}
			}
			else
			{
				for (int i = '0'; i <= '3'; i++)
				{
					str[u] = i;
					dfs(u + 1);
					str[u] = '-';
				}
			}
		}
		else  // 日的个位
		{
			if (str[5] == '0' && str[6] == '1')
			{
				if (str[7] == '0')
				{
					for (int i = '2'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else if (str[7] == '1' || str[7] == '2')
				{
					for (int i = '0'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else
				{
					for (int i = '0'; i <= '1'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
			}
			else if (str[5] == '0' && str[6] == '2')
			{
				if (str[7] == '0')
				{
					for (int i = '2'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else if (str[7] == '1')
				{
					for (int i = '0'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else
				{
					char strr[N];
					for (int i = 1; i <= 4; i++)
						strr[i] = str[i];
					int x = atoi(strr + 1);
					if (x % 4 == 0)
					{
						for (int i = '0'; i <= '9'; i++)
						{
							str[u] = i;
							dfs(u + 1);
							str[u] = '-';
						}
					}
					else
					{
						for (int i = '0'; i <= '8'; i++)
						{
							str[u] = i;
							dfs(u + 1);
							str[u] = '-';
						}
					}
				}
			}
			else if (str[5] == '0' && str[6] == '3')
			{
				if (str[7] == '0')
				{
					for (int i = '2'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else if (str[7] == '1' || str[7] == '2')
				{
					for (int i = '0'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else
				{
					for (int i = '0'; i <= '1'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
			}
			else if (str[5] == '0' && str[6] == '4')
			{
				if (str[7] == '0')
				{
					for (int i = '2'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else if (str[7] == '1' || str[7] == '2')
				{
					for (int i = '0'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else
				{
					for (int i = '0'; i <= '0'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
			}
			else if (str[5] == '0' && str[6] == '5')
			{
				if (str[7] == '0')
				{
					for (int i = '2'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else if (str[7] == '1' || str[7] == '2')
				{
					for (int i = '0'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else
				{
					for (int i = '0'; i <= '1'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
			}
			else if (str[5] == '0' && str[6] == '6')
			{
				if (str[7] == '0')
				{
					for (int i = '2'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else if (str[7] == '1' || str[7] == '2')
				{
					for (int i = '0'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else
				{
					for (int i = '0'; i <= '0'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
			}
			else if (str[5] == '0' && str[6] == '7')
			{
				if (str[7] == '0')
				{
					for (int i = '2'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else if (str[7] == '1' || str[7] == '2')
				{
					for (int i = '0'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else
				{
					for (int i = '0'; i <= '1'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
			}
			else if (str[5] == '0' && str[6] == '8')
			{
				if (str[7] == '0')
				{
					for (int i = '2'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else if (str[7] == '1' || str[7] == '2')
				{
					for (int i = '0'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else
				{
					for (int i = '0'; i <= '1'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
			}
			else if (str[5] == '0' && str[6] == '9')
			{
				if (str[7] == '0')
				{
					for (int i = '2'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else if (str[7] == '1' || str[7] == '2')
				{
					for (int i = '0'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else
				{
					for (int i = '0'; i <= '0'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
			}
			else if (str[5] == '1' && str[6] == '0')
			{
				if (str[7] == '0')
				{
					for (int i = '2'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else if (str[7] == '1' || str[7] == '2')
				{
					for (int i = '0'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else
				{
					for (int i = '0'; i <= '1'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
			}
			else if (str[5] == '1' && str[6] == '1')
			{
				if (str[7] == '0')
				{
					for (int i = '2'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else if (str[7] == '1' || str[7] == '2')
				{
					for (int i = '0'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else
				{
					for (int i = '0'; i <= '0'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
			}
			else if (str[5] == '1' && str[6] == '2')
			{
				if (str[7] == '0')
				{
					for (int i = '2'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else if (str[7] == '1' || str[7] == '2')
				{
					for (int i = '0'; i <= '9'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
				else
				{
					for (int i = '0'; i <= '1'; i++)
					{
						str[u] = i;
						dfs(u + 1);
						str[u] = '-';
					}
				}
			}
		}
	}
	else dfs(u + 1);
}

int main()
{
	cin >> T;
	while (T--)
	{
		ans = 0;
		cin >> str + 1;
		len = strlen(str + 1);
		dfs(1);
		cout << ans << '\n';
	}

	/*char sr[3] = "01";
	cout << atoi(sr);*/

	return 0;
}