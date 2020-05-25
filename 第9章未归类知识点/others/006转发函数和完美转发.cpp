#include<iostream>
#include<cstdlib>
#include <boost/type_index.hpp>
using namespace std;
//��ͨ����
void myFunction(int value01,int value02)
{
	++value02;
	cout <<"Sum="<< value02 + value01 << endl;
	return;
}

//��ֵ����
void myFunction02(int value01, int &value02)
{
	++value02;
	cout << "Sum=" << value02 + value01 << endl;
	return;
}

//��Ϊ��ֵ����
void myFunction03(int &&value01, int &value02)
{
	++value02;
	cout << "Sum=" << value02 + value01 << endl;
	return;
}


//ģ�庯����Ҫ���յ��Ĳ����Լ���Щ�������Ӧ�Ĳ������ֲ���ת��Ϊ��������myFunction  --�����ת��
template<typename F,typename T1,typename T2>
void myFunctionTramsmit(F f,T1 t1,T2 t2)//F����Ҫ���õĵ���������,Ҫת����Ŀ�꺯��
{
	f(t1, t2);
	

}

//������ģ���Ϊ������������
template<typename F, typename T1, typename T2>
void myFunctionTramsmit02(F f, T1&& t1, T2 &&t2)//F����Ҫ���õĵ���������,Ҫת����Ŀ�꺯��
{
	/*����������еĵ���myFunctionTramsmit02(myFunction02, 34, i);
	 *T1=int, t1=int&&  t1����ֵ�������ͣ�t1��������ֵ
	 *T2=int&,t2=int&
	 * 
	 */
	//f(t1, t2);
	//��void(int &&, int &)��: �޷������� 1 �ӡ�int��ת��Ϊ��int &&��
	//���ô�����һ����ֵ������ͨ����������ת��Ϊһ����ֵ�ˣ�t1������һ����ֵ�����Ǻ���myFunction03��Ҫ����һ����ֵ
	f(std::forward<T1>(t1), std::forward<T2>(t2));
	//t1��ԭ������ֵ������ֵ��Ϣ������T1ģ������У�����Ὣt1ת��Ϊԭʼʵ�ε���ֵ����
}

int main(void)
{	int i = 50;
	myFunction(34, i);

	//ͨ��ת����������
	myFunctionTramsmit(myFunction, 34, i);
	myFunctionTramsmit(myFunction02, 34, i);//���ﷵ�غ�i=50,����������������51.Ҳ����˵��T2��û��ʵ����Ϊint&����
	//void myFunctionTramsmit(void(*f)(int,int&),int t1,, int t2){}//ʵ����������ӣ�t2��������������������ݹ�ȥ��������
	//��ô�޸Ĵ��ݺ�������ģ�庯���Ĳ����ܹ����ָ���ʵ�ε���ֵ�ԣ�i��const����Ҳ���ݵ�ģ�庯���У���������
	/*
	 *��������  T&& ����ʵ��i���������ԣ��Ӷ��ñ������Ƶ���������ģ�����յ��β�����
	 *���ʹ��T&��ͨ���ã���ʵ����ֻ��const���Կ��Դ��ݵ�����ģ�壬��ʵ���е���ֵ����ֵ�ԾͲ��ܴ��ݵ�����ģ��
	 * 
	 */

	//�������ú����
	myFunctionTramsmit02(myFunction02, 34, i);//i��ֵ��51

	//��ֵ����
	int &&number01 = 80;//��ֵ���ð���ֵ
	/*
	 * ��Ȼ&&number01�ǰ󶨵���ֵ�ģ�����number01�����Ǹ���ֵ����Ϊnumber01�����ڵȺ���ߡ�
	 * &&number01����ֵ���ã�number01�Ǹ���ֵ�����ڴ����е�ַ��
	 * number01�����Ǹ���ֵ������������������ֵ���á�Ҳ����˵��ֵ���ã���ֵ���ø���˵�����������͡�
	 *void myFunctionTramsmit02(F f, T1&& t1, T2 &&t2)�����β��еı���������ֵ��������������ֵ����
	 */
	//myFunction03(number01, i);//error��ʵ����Ҫ����ֵ��number01��������һ����ֵ���β�����һ����ֵ���ã������һ����ֵ
	int j = 50;
	myFunctionTramsmit02(myFunction03, 20, j);
	
	system("pause");
	return 0;
}
/*
* (1)ת��������ת��
*	ͨ������ָ����ú��������Ѻ���������Ϊ�������ݣ�����ת����
*
*	����ת���������ǿ���д������������ʵ�εĺ���ģ�壬������ת����Ŀ�꺯����
*		Ŀ�꺯������յ���ת�����������յ��Ĳ���������ȫ��ͬ����ֵ�ԣ���ֵ�ԣ�
*		ͨ��std::forword()��ʵ��
*	
* (2)std::forward()
*	c++11�е��º�����ר��Ϊת�������ڡ�
*	��Ҫô����һ����ֵ��Ҫô����һ����ֵ��
*	ʹ��������
*		����ģ�庯����ģ�庯�������������������ͣ�ģ���������ת��
*		void myFunctionTramsmit02(F f, T1&& t1, T2 &&t2)
*		f(std::forward<T1>(t1), std::forward<T2>(t2));
*		void myFunction03(int &&value01, int &value02)//value01Ҫ��һ����ֵ
*		//����
*		myFunctionTramsmit02(myFunction03, 20, j);
*	std::forword()���������ǰ���ʵ�α��������ת����
*		1.ʵ��ԭ������ֵ�����β��л�����ֵ,forward�ǰ����β�ԭ�������ʹ�������std::forward���������ֵ
*		2.ʵ��ԭ������ֵ�����β��б����ֵ,forward�ǰ����β�ԭ�������ʹ�������std::forward������Ǹ���ֵ
*		�������￴��std::forward()��ǿ�ư���ֵת��Ϊ��ֵ������������forward()��ʵֻ��ԭ������ֵ��������á�
*
*		std::forward()���������Ǳ���ԭʼʵ�ε����ͣ���ֵ������ֵ��
* (3)����ת������α���ԭʼʵ�ε���ֵ����ֵ��Ϣ��
*	�Ǳ�����ת������������ģ���У���ģ�����T�У�����ת�������Ĳ������ͱ����������������͡�
* (4)�ܽ�
*forward��ǿ�ư�һ����ֵת��Ϊ��ֵ��������ԭʼ�βξ���һ����ֵ�����ҵ�forwardɶҲ���ɣ�
*move()������ǿ������ת����ת����ԭʼ�������ֲ���ʹ�á�
* 
* (5)��̸��������
*	�������ò���һ���µ��������͡���һ�ֳ����д���������������ø���Ĵ�����������ġ�
* 
* 1.ת������
* 2.��ֵ����ֵ
* 3.����ת��std::forward()
 
* (6)
*/