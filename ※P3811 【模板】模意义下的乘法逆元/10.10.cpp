
/*
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
int n, p;
LL qmi(int a, int k, int p)
{
	LL res = 1 % p;
	while (k)
	{
		if (k & 1)res = res * a % p;
		k >>= 1;
		a = (LL)a * a % p;
	}
	return res;
}

int main()
{
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
		cout << qmi(i, p - 2, p) << endl;

	return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3e6 + 10;
ll Inv[N];
int n, p;
inline ll mod(ll a, ll p)
{
	return (a % p + p) % p;
}
ll inv(ll a, ll p)
{
	if (Inv[a])
		return Inv[a];
	Inv[a] = mod(-p / a * inv(p % a, p), p);
	return Inv[a];
}
int main()
{
	Inv[1] = 1;
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
		cout << inv(i, p) << '\n';
	return 0;
}