#include<iostream>
#include<cstdlib>
#include <vector>

using namespace std;

//2.1Ӧ���ɱ�����--һ��Ӧ����ģ�����ͱ����
template<typename T>
class CT
{
public:
	//typename T::iterator iter;//����������
	decltype(T().begin())  iter;//���T������const std::vector<int>�����س�������������
	//const std::vector<int>()��ʾ���ɸ����͵���ʱ����(������)��������ʱ�����begin()���õ�һ������������
	void getBegin(T&tem)
	{
		iter = tem.begin();
	}
public:
	CT(){}
};

//��ģ��ƫ�ػ�
//template<typename T>
//class CT<const T>
//{
//public:
//	typename T::const_iterator iter;//����������
//	void getBegin(T&tem)
//	{
//		iter = tem.begin();
//	}
//};

int main(void)
{
	//2.1Ӧ���ɱ�����--һ��Ӧ����ģ�����ͱ����
	//using conttype =std::vector<int>;
	using conttype =const std::vector<int>;
	
	conttype myVector = { 12,23,34 };//����ñ������ͣ�myVector�Ǹ�����
	CT<conttype>ct;
	ct.getBegin(myVector);

	//������������ʹ�ó���������
	const std::vector<int> myvector02 = { 23,345,45 };
	vector<int>::const_iterator iter = myvector02.begin();
	
	system("pause");
	return 0;
}
/*
* (1)decltype����Ҫ��;
*		2.1Ӧ���ɱ�����--һ��Ӧ����ģ�����ͱ����
*			������ʱ����ʹ��decltype��ȡ����
* (2)
* (3)
* (4)
* (5)
* (6)(7)
* ����vs2015û�ܱ���ͨ������֪��vs2017�ܷ����ͨ��
*	�����ơ�=��: û���ҵ����ܡ�std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<int>>>�����͵��Ҳ������������(��û�пɽ��ܵ�ת��)	others	e:\projectcode\��9��δ����֪ʶ��\others\Դ15.cpp	17	

*/