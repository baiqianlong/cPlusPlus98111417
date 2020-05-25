#include<iostream>
#include<cstdlib>
#include <boost/type_index.hpp>
using namespace std;

template<typename T>
void myFunction01(T &&tem)//T������ģ�������T�������͵�,tem���βΣ�temҲ�������͵�
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//��ʾT����
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//��ʾtem����

}

int main(void)
{
	int i = 18;//i��������int���ͣ�i�Ǹ���ֵ��
	myFunction01(i);//ʵ������,������Ϊ�������ƶϺ�ĽṹΪvoid myFunction(int& &&tem){}
	myFunction01(12);
	/*
	 *	T type=int &
		tem type=int &
		T type=int
		tem type=int &&
	 */
	//����������ʵ����������myFunction��ʲô���� void myFunction(int&tem){}--�����۵�


	//1.1���õ�����
	int number = 500;
	int &number_reference = number;//����
	//int & &rr = b;//������һ�����ֵ���ã��ֿ������õ����ã��ǷǷ��ġ����Ǳ������ڲ����Գ��֣����Լ��Ƶ���ʹ�������۵�����


	
	system("pause");
	return 0;
}
/*
 * (1)�����۵�����
 * �����۵���c++s11�±�׼����һ��������һ������reference-collapsing rules ����̮����&&&--->&
 * c++��׼������ȷ���������ֻ�����֣�һ����&��ֵ���ã�һ����&&��ֵ���á�
 *	void myFunction(int& &&tem)//���� int&����ֵ���ã��ڶ���&&tem����ֵ��������
 *	
 *	ʲô����³��������۵�����
 *	�ֳ����飬��һ������ֵ����/��ֵ����		�ڶ��� ��ֵ����/��ֵ����
 *			��ֵ����  ��ֵ����	&		&
 *			��ֵ����	��ֵ����	&		&&	��ǰ�����
 *			��ֵ����	��ֵ����	&&		&
 *			��ֵ����	��ֵ����	&		&
 *		�۵���������κ�һ��Ϊ��ֵ���ã���ô���������ֵ���ã����������ֵ���á�--��ֵ���д�Ⱦ�ԡ�
 *
 *		1.1���õ�����
 *		��������ʾд�����Ǳ������ڲ����к���ģ�������ƶϵ�ʱ����Գ��֣�������ʹ�������۵�������д���
 *		��������������򿪷���д�����õ����õĴ��롣
 *	��Ҫ�����۵��ĳ����У�
 *		1.����ģ��ʵ����
 *		2.auto�Զ������ƶϵ�ʱ��
 *		
 * (2)
 * (3)
 * (4)
 * (5)
 * (6)
 */