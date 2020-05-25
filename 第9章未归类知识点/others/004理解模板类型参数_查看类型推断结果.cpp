#include<iostream>
#include<cstdlib>
#include <boost/type_index.hpp>

using namespace std;

//��ʾ�������ͣ����ﲻ�о�boost��
template<typename T>
//void myFunction01(T&tem)//T������ģ�������T�������͵�,tem���βΣ�temҲ�������͵�
void myFunction01(const T &tem)
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//��ʾT����
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//��ʾT����

}

//2.1ָ�������������
template<typename T>
void myFunction02( T &tem)//tem������
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//��ʾT����
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//��ʾT����

}

template<typename T>
void myFunction03( const T &tem)//�β��ǳ�������
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//��ʾT����
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//��ʾT����

}

template<typename T>
void myFunction04( T *tem)//�β���ָ������
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//��ʾT����
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//��ʾT����

}

template<typename T>
void myFunction05(T &&tem)//�β���������������
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//��ʾT����
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//��ʾT����

}


template<typename T>
void myFunction06(T tem)//�β���������������
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//��ʾT����
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//��ʾT����

}

void tesFunction()
{
	;
}
int main(void)
{
	//(2)void myFunction01(const T&tem)
	myFunction01(100);
	/*
	 * T type=int
	 * tem type=int const &
	 */
	
	//2.1
	int i = 18;	//int
	const int j = i;	//const int
	const int&k = i;	//const int&����
	cout << "-----" << endl;
	myFunction02(i);
	myFunction02(j);
	myFunction02(k);
	/*
	 *	T type=int
		tem type=int &
		T type=int const
		tem type=int const &
		T type=int const
		tem type=int const &
	1.���ʵ�����������ͣ����������ͻᱻ���Ե���T���ᱻ�Ƶ�Ϊ�������͡�
	2.���������������͵��β�tem����const����ʵ��ʱ���βξͻ��Ϊconst&
		ʵ�ε�const���Ի��Ϊ����ģ��������Ƶ������͵���ɲ��֣�
		Ҳ����˵��ʵ�ε�const���Իᴫ�ݡ��ں������޸Ĳ���ԭ����const���Ե�ʵ�Ρ�
	
	 */

	//�β��ǳ�������
	cout << "*******" << endl;
	myFunction03(i);
	myFunction03(j);
	myFunction03(k);
	/*
	 *  T type=int
		tem type=int const &
		T type=int
		tem type=int const &
		T type=int
		tem type=int const &

	1.���ʵ�����������ͣ����������ͻᱻ���Ե���T���ᱻ�Ƶ�Ϊ�������͡�
	2.������const���Ե�ʵ�Σ��Ƶ���T�е�const����û���ˣ���Ϊģ�庯��myFunction03���β�tem������const��ʵ��const�滻���β�const
	
	 */

	//ָ������
	const int*pi = &i;
	cout << "&&&&&&&&&" << endl;
	myFunction04(&i);
	myFunction04(pi);
	/*
	 *  T type=int
		tem type=int *
		T type=int const
		tem type=int const *
	���ۣ����tem�β���û��const����ʵ���е�const�ͻᴫ�ݵ�T������ȥ������β�����const����T�����в����const��
	
	 */

	//*	2.2��������--��ʽ����tem��һ��������������T&&
	cout << "2.2------------------------" << endl;
	myFunction05(i);//��ֵ
	myFunction05(j);//��ֵ
	myFunction05(k);
	myFunction05(100);//���ݹ�ȥ��ֵ
	/*
	T type=int &
	tem type=int &	//�����������۵�
	T type=int const &
	tem type=int const &
	T type=int const &
	tem type=int const &
	T type=int
	tem type=int &&
	 */


	//2.3��ֵ��ʽ �����ʽ����tem�ǳ���Ĵ�ֵ��ʽ����
	cout << "2.3------------------------" << endl;
	myFunction06(i);
	myFunction06(j);
	myFunction06(k);
	/*
	 *  T type=int
		tem type=int
		T type=int
		tem type=int
		T type=int
		tem type=int
	const����û�д��ݽ�ȥ����Ϊ��ʽ������һ���¸�������ô���ݽ�ȥconst���ԣ�����-->����ָ���ȥ
	 */
	char myStr[] = "jisuanjizuchengyhuanli";
	const char*const point = myStr;//��һ��const�����ڴ�ռ䣬�ڶ�����ʾָ���ָ���ܸı�
	cout << "jjjjjjjjjjjjjjjj" << endl;
	myFunction06(point);
	/*
	 T type=char const *
	 tem type=char const *
	����const char*����const char[]��һ��constû���ˣ��ڶ���const������
	 */

	//2.4������ʵ��
	const char mystr02[] = "jisuanjizuchegnaun";
	cout << "22222222222222222222222" << endl;

	myFunction06(mystr02);
	myFunction02(mystr02);//������--�Ƶ�������
	/*
	T type=char const *
	tem type=char const *
	T type=char const [19]
	tem type=char const (&)[19]//�������������
	*/

	//	2.5��������ʵ�Σ��������൱�ں����׵�ַ�����Ը�ֵ��һ������ָ��
	cout << "6666666666666" << endl;
	myFunction06(tesFunction);

	myFunction02(tesFunction);//����
	/*
	T type=void (__cdecl*)(void)//����ָ������
	tem type=void (__cdecl*)(void)
	T type=void __cdecl(void)//����ָ������
	tem type=void (__cdecl&)(void)
	 */

	
	cout << "helloWorld" << endl;
	system("pause");
	return 0;
}

/*
*(1)��β鿴�����ƶϽ��
*	�ƶ���ʱ������Ƶ������ִ�c++�У������漰���ƶϣ���auto�ȡ�������Ҫ����ģ�������ƶϵ�֪ʶ��
*	ģ����������ƶ�һ��ģ���������ͨ���������͡�
*	����Ҫ��֤�����ƶϳ������ͺͱ������ƶϳ����������Ƿ�һ�¡�--ѧϰ�����ƶϵ�ԭ��
*	����Ϊ��ѧϰ�����ƶ����֪ʶ���б�Ҫ֪���������ƶϳ����ġ�ģ��������͡��Լ�����ͨ�������͡���protype
*
*	ͨ�����鿴�����������ƶϵĽ��������ֶ���ѧϰ������c++�����ƶϵĹ���Ҫ������C++�����ƶϽ����
*	����������ʲô�ֶ�ȥ�鿴�������������ƶϳ����Ľ����
*
*	ʹ��boost�⣬�ѱ������������ƶϳ�����������Ϣ��ӡ������
*		1.���ʹ���https://www.boost.org/ ����boost��
*		2.����Ҳ�Version History�������ص�1.68.0�汾
*		3.���ļ���ѹ��һ���ļ����У�������boost_1_68_0��
*		4.�Ҽ���Ŀ--�����ԡ�--��vc++Ŀ¼��--������Ŀ¼���н���ѹ��·�������
*	����ʹ��nuget��װ���Ҽ���Ŀ --������NuGet��װ����������boost��װ��
*	
*(2)���ģ�������ƶ�
*	2.1ָ�������������
*			���tem�����Ǹ�ָ��������ã����ǲ�����������
*	2.2��������--��ʽ����tem��һ��������������T&&
*
*	2.3��ֵ��ʽ
*
*	2.4������ʵ��
*		����������������׵�ַ
*	2.5��������ʵ�Σ��������൱�ں����׵�ַ�����Ը�ֵ��һ������ָ��
*(3)�ܽ᣺
*	1.�ƶ��У���������ʵ�ε��������͵��ڲ�����
*	2.���������У�ʵ��Ϊ��ֵ����ֵ���ƶϳ����Ľ����ͬ
*	3.��ֵ���ݵ�ʵ�Σ����ݸ��β�ʱconst���Բ������ã��򴫵ݹ�ȥָ����������á�
*	4.������ߺ����������ƶ��б�����ָ�룬���Ǻ���ģ����β��Ǹ����á�
*(4)
*2019��12��9��
*20��48��
*
*/