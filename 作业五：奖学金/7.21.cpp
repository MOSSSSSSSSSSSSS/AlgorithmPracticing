

//sort��a[]���飬�����һ��ʼ�����һ��10����������������дa+0,a+9  �� �������������������д��

//  ע�������sort����ṹ�壬���д  cmp����  �� 

#include<bits/stdc++.h>
using namespace std;

struct student
{
	int xue_hao;
	int chinese;
	int math;
	int english;
	int total;
};

bool cmp(student a, student b)
{
	if (a.total > b.total)return true;
	else
	{
		if (a.total == b.total)
		{
			if (a.chinese > b.chinese)return true;
			else
			{
				if (a.chinese == b.chinese)
				{
					if (a.xue_hao < b.xue_hao)return true;
					else return false;
				}
				else return false;
			}
		}
		else return false;
	}
}

vector<student> students;
int n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b, c, d;
		scanf("%d%d%d", &a, &b, &c);
		d = a + b + c;
		students.push_back({ i,a,b,c,d });
	}

	sort(students.begin(), students.end(), cmp);

	for (int i = 0; i < 5; i++)cout << students[i].xue_hao << ' ' << students[i].total << endl;

	return 0;
}