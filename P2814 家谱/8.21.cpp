

//   ��ѧ���鼯��ʱ��ѧ�������ֵ�Ҳ���Ǳ�ţ�p[i] = i������ 3�ĸ��ڵ���5��p[3] = 5�����������Ҳ���ò��鼯��������һ������������p[����] = ���������������±꣬����
 

//     Ҫ�� map��ӳ��  һ��string����һ�� string����map�е�һЩ������ע��map�������þ��У���һ��first���±꣬�ڶ���second��ֵ


#include<bits/stdc++.h>
using namespace std;

const int N = 50010;
map <string, string> p;
string now;

string find(string name)            //  ���鼯·��ѹ��
{
	auto it = p.find(name);
	if (it!=p.end()&&p[name]!=name)p[name] = find(p[name]);
	else
	{
		p[name] = name;//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		return p[name];
	}    //   ���и��������п���ǰ�����һ�ε����Ƕ��ӣ������ֳ���һ���Ǹ��ף�������ҵ���ͷ�ϣ���p[name] = name,���������еĸ��׶�p[name] = name��ֻ�����Ȳ�p[name] = name
	return p[name];
}

int main()
{
	while (1)
	{
		char flag;
		string name;
		cin >> flag;
		if (flag == '$')
			return 0;
		cin >> name;
		if (flag == '#')
		{
			now = name;
			//p[name] = name;
		}
		else if (flag == '+')
			p[name] = now;
		else if (flag == '?')
			cout << name << ' ' << find(name)<< endl;
	}

	return 0;
}//it->second it�ǵ�����p.find(name)���ص�����