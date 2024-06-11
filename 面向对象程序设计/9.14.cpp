

//C++是一门强类型语言，所以无法做到像动态语言（python javascript）那样子，编写一段通用的逻辑，可以把任意类型的变量传进去处理。
//泛型编程弥补了这个缺点，通过把通用逻辑设计为模板，摆脱了类型的限制，提供了继承机制以外的另一种抽象机制，极大地提升了代码的可重用性。

//普通函数模板：
/*#include<bits/stdc++.h>
using namespace std;
template <typename T>    // 没分号
int Compare(const T a, const T b)
{
	if (a > b)
		return -1;
	else
		return 1;
}

int main()
{
	cout<<Compare<int>(1, 2);
	return 0;
}*/
//不仅普通函数可以定义为模板，类的成员函数也可以定义为模板:
/*#include<bits/stdc++.h>
using namespace std;

class liu {
public:
	template<typename T>
	void print(T t)
	{
		cout << t << endl;
	}
};

int main()
{
	liu l;
	l.print<int>(5);
	l.print<string>("abc");
	l.print<const char*>("abc");    //  char *  不行
	//实参推断:让编译器自己推断是什么类型:
	l.print("abc");
	l.print(2.0);

	return 0;
}*/

//  当有多个  typename T1, typename T2, typename T3时，在函数后面写sum<long>，long指定的是第一个，是从左往右指定的
//sum_alternative<long,int,long> 代表 T1是long，T2是int，T3是long
/*template<typename T1, typename T2, typename T3>
T1 sum(T2 v2, T3 v3) {
  return static_cast<T1>(v2 + v3);
}

auto ret = sum<long>(1L, 23); //指定T1, T2和T3交由编译器来推断

template<typename T1, typename T2, typename T3>
T3 sum_alternative(T1 v1, T2 v2) {
  return static_cast<T1>(v1 + v2);
}
auto ret = sum_alternative<long>(1L, 23); //error，只能从左向右逐一指定
auto ret = sum_alternative<long,int,long>(1L,23); //ok, 谁叫你把最后一个T3作为返回类型的呢？
*/

//声明模板为inline，提高效率：inline 放在template后，返回类型前
//template<typename T> inline int Compare(const T a,const T b)

//  类模板：
#include<bits/stdc++.h>
using namespace std;
template<class Type> class liu {
public:
	bool empty()const//已定义成const的成员函数，一旦企图修改数据成员的值，则编译器按错误处理
	{
		;
	}
	bool lalala()const;
};

int main()
{
	liu<int> l;

}


template<typename T> T sum()
{

}