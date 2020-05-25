#include<iostream>
#include<cstdlib>

#include <boost/type_index.hpp>
#include <map>
#include <string>

using namespace std;

//��ʾ�������ͣ����ﲻ�о�boost��
template<typename T>
void myFunction01(T&tem)//T������ģ�������T�������͵�,tem���βΣ�temҲ�������͵�
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//��ʾT����
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//��ʾT����

}

class TescClassA
{
public:
	static int test()
	{
		return 0;
	}
};

class TescClassB
{
public:
	static double test()
	{
		return 0.12;
	}
};

//ͨ����ģ����������������еĺ���,����ֵ��ȷ��
template<typename T>
auto testFunction()
{
	auto value = T::test();//�����ĸ�������ȷ��������ֵҲ��ȷ��
	return value;
}

int main(void)
{
	std::map<string, int>myMap;
	myMap.insert(make_pair("aaa", 3454));
	myMap.insert({ "bbb",222 });
	myMap.insert({ "ccc",3434 });
	for (map<string,int>::iterator iter=myMap.begin();iter!=myMap.end();iter++)
	{
		cout << iter->first << "=" << iter->second << endl;
	}
	//����ʹ��auto��������
	for (auto iter=myMap.begin();iter!=myMap.end();iter++)
	{
		cout << iter->first << "=" << iter->second << endl;
	}

	//2.��û�а취ȷ�����͵�ʱ��ʹ��auto
	cout << testFunction<TescClassA>() << endl;//0
	cout << testFunction<TescClassB>() << endl;//0.12
	

	system("pause");
	return 0;
}
/*
* (1)auto���ó��Ͼ���
*	1.����ܳ����������֣��������
*	2.��û�а취ȷ�����͵�ʱ��ʹ��auto
* (2)�ܽ᣺
*	auto��������һ���ؼ��֣�Ҳ���Կ���һ��ǿ��Ĺ��ߣ��������á�
*	2019��12��10��
*	20��47��
* (5)
* (6)(7)
*/