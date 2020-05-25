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
	int number01 = 18;
	const int number02 = number01;
	const int&number03 = number01;
	myFunction01(number01);//T=int  tem=int&����
	myFunction01(number02);//T=int const tem=const int&
	myFunction01(number03);//T=int const tem=const int& ���ûᱻ���ԣ����ݲ���ȥ
	/*
	T type=int
	tem type=int &
	T type=int const
	tem type=int const &
	T type=int const
	tem type=int const &
	 */

	// (1)auto���ͳ����ƶ�
	auto number04 = 23;//number04��int���ͣ�auto��int����ռλ��
	
	//1.ָ������������ͣ���������������
	const auto&number07 = number01;  //auto =int,number07=const int&
	auto number08 = number07;//��ֵ��ʽ�����ú�const���Իᱻ�������ѶԷ������¸����� number08=int ,auto =int
	auto &number09 = number07;//auto =const int		number09=const int&  �������Ա�������const���Ա�����
	const auto*p1 = &number01;//auto =int		p1=const int*
	auto*p2 = &number01;//auto=int	p2=int*
	auto p3 = &number01;//auto=int*		p3=int*
	


	
	//2.������������  --����ģ������������T&&   auto����������auto&&
	auto&&number11 = number01;//number11����ֵ��auto =int&,number11=int&,������������۵�
	const auto number12 = 234;
	auto&&number13 = number12;//autu=int&��number13=const int&
	auto&&number14 = 234;//��ֵ����������ֵ  --auto=int,number14=int&&
	

	
	//3.��ֵ��ʽ����ָ�룬������--
	auto number05 = 234;
	const auto number06 = number05;//auto =int number06=const int


	//auto����ʹ��new������
	auto number10 = new auto(2343);//auto=int
	
	system("pause");
	return 0;
}
/*
* (1)auto���ͳ����ƶ�
* c++11�У�autoӢ��������Զ������ƶϣ�������������ʱ����ݱ����ĳ�ֵ�������Զ�Ϊ�˱���ѡ��ƥ������ͣ�
*	������Ҫ������ʾָ������
*�ص㣺
*1.�Զ������ƶϷ����ڱ����ڼ䣬����Ӱ�����ִ���ڼ�����ܡ�
*2.auto����ı�������������ʼ�������������������Զ��ƶ��������͡�ȷ��auto�����ͺ�����������������͡�
*	Ȼ���ڱ����ڼ�ʹ�������������滻��auto�������ռλ����
*3.autoʹ�������Ժ�ָ�룬���ã�const���޶������ʹ�á�
*4.auto�����ƶϺͺ���ģ���ƶϷǳ����ơ�autu�Ƶ������һ���������͡�
*	autoʵ������һ�����ͣ�ʵ�����൱�ں���ģ���Ƶ��е�����ģ�����T��autoҲ�����������е�һ���֡�
*	���԰�auto��������ռλ��
*
*
* (2)auto�����ƶϷ���
*		1.ָ������������ͣ���������������--��������const���ԣ����ǻ��������õ��޶���
*		2.������������
*		3.��ֵ��ʽ����ָ�룬������--��ֵ��ʽ���������ú�const���ԡ�
* (3)
* (4)
* (5)
* (6)(7)
*/