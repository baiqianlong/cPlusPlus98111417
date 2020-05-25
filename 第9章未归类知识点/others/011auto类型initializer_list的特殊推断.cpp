#include<iostream>
#include<cstdlib>

#include <boost/type_index.hpp>

using namespace std;

//��ʾ�������ͣ����ﲻ�о�boost��
template<typename T>
void myFunction01(T&tem)//T������ģ�������T�������͵�,tem���βΣ�temҲ�������͵�
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//��ʾT����
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//��ʾT����

}



int main(void)
{
	//c++98֧�ֵĳ�ʼ����ʽ
	int number01 = 10;
	int number02(23);
	//c++11֧�ֵĳ�ʼ����ʽ
	int number03 = { 23 };
	int number04{ 234 };
	//�滻Ϊauto�����𣿣�

	auto number05 = 23;//ok
	auto number06(23);
	auto number07 = { 23 };//class std::initializer_list<int>  auto����{}�Ƶ�����һ��
	auto number08{ 23 };
	using boost::typeindex::type_id_with_cvr;
	cout << "number07 type=" << type_id_with_cvr<decltype(number07)>().pretty_name() << endl;//��ʾT����
	cout << "number08 type=" << type_id_with_cvr<decltype(number08)>().pretty_name() << endl;//��ʾT����
	/*
	 *  number07 type=class std::initializer_list<int>һ����ģ��
		number08 type=int
	 */

	auto number09 = { 23,345 };//���е�����Ҫһ�£���Ҫ���ж����Ƶ������Ƶ�auto=int,���Ƶ�����ģ������
	
	
	system("pause");
	return 0;
}
/*
* (1)auto����std::initializer_list�������ƶ�
*	class std::initializer_list<int> c++���������ģ�壬��ʾĳ���ض���ֵ������
* (2)auto�����Է��ں�������ֵ���ͣ��Ժ󽲡�
* (4)
* (5)
* (6)(7)
*/