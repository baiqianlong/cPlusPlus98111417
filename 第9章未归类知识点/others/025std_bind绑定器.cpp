#include<iostream>
#include<cstdlib>
#include <functional>

using namespace std;

void myFunction(int x,int y,int z)
{
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	cout << "z=" << z << endl;
}

void myFunction02(int x, int y, int z)
{
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	cout << "z=" << z << endl;
}

void myFunction03(int&x,int&y)
{
	x++;
	y++;
}

int main(void)
{
	auto bf1 = std::bind(myFunction, 1, 2, 3);//auto��ʾ�����ķ��ص����ͣ���ʵbind���ص���һ���º������Ͷ���
	bf1();//1  2  3
	//placeholders::_2��ռλ��
	auto bf2 = std::bind(myFunction02, placeholders::_1, placeholders::_2, 34);
	//��ʾ��һ���ڶ��������ֱ��ɵ������ṩ������ֻ�ƶ��˵���������
	bf2(1, 2);// 1  2  34
	//ֱ�ӵ���
	std::bind(myFunction02, placeholders::_1, placeholders::_2, 34)(12, 23);


	auto bf3 = std::bind(myFunction02, placeholders::_2, placeholders::_1, 300);
	bf3(1, 2);//2	1	300 ���ձ��λ�ô���

	int a = 1;
	int b = 2;
	auto bf4 = std::bind(myFunction03, a, placeholders::_1);
	bf4(b);
	cout << "a=" <<a<< endl;//1����2
	cout << "b=" <<b<< endl;//3
	/*
	 * ��˵����bind����Ԥ�Ȱ󶨵ĺ���������ͨ��ֵ���ݵģ����������aʵ������ֵ����
	 * ���ڲ�Ԥ�Ȱ󶨵Ĳ�����ͨ��std::placeholde���ݵĲ�������ͨ�����ô��ݵģ�bʵ���������ô��ݵġ�
	 */



	
	system("pause");
	return 0;
}
/*
* (1)std::bind����
* Ҳ�Ǹ���ģ�壬��c++11��������
* std::bind�ܹ�����������صĲ����󶨵�һ�𣬰���Ϻ����ֱ�ӵ��ã�Ҳ����ʹ��std::function���棬����Ҫ��ʱ�����
* ��ʽ��
* std::bind(���󶨵ĺ�������/����ָ��/��Ա����ָ�룬�󶨲���ֵ1��������ֵ2��������....)
* �ܽ᣺
*	1.���ɵ��ö���ɲ�������һ�𣬹���һ���º���������ֱ�ӵ���
*	2.��������ж������������ֻ��һ���֣����������ڵ���ʱ��ָ��
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/