#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <array>

using namespace std;

class A
{
public:
	/*A()
	{
		;
	}*/

	virtual void myFunction()
	{
		
	}
public:
	int m_i;
	
};

int main(void)
{

	A *pa1 = new A;
	A *pa2 = new A();

	//2.4�������ͼӲ���()������
	int *p3 = new int;//��ֵ���
	int*p4 = new int();//��ֵ0
	int*p5 = new int(100);//��ֵ100

	//2.5 new �����ʱ�򵽵�����ʲô
	A *p6 = new A();
	delete p6;
	/*
	 *  012054A9  push        8  
		012054AB  call        operator new (012012B2h)  
		012054B0  add         esp,4  
		012054B3  mov         dword ptr [ebp-158h],eax  
		012054B9  cmp         dword ptr [ebp-158h],0  
		012054C0  je          main+1A2h (012054E2h)  
		012054C2  xor         eax,eax  
		012054C4  mov         ecx,dword ptr [ebp-158h]  
		012054CA  mov         dword ptr [ecx],eax  
		012054CC  mov         dword ptr [ecx+4],eax  
		012054CF  mov         ecx,dword ptr [ebp-158h]  
		012054D5  call        A::A (0120129Eh)  
		012054DA  mov         dword ptr [ebp-160h],eax  
		012054E0  jmp         main+1ACh (012054ECh)  
		012054E2  mov         dword ptr [ebp-160h],0  
		012054EC  mov         edx,dword ptr [ebp-160h]  
		012054F2  mov         dword ptr [p6],edx


	delete p6;
	
	008C54F5  mov         eax,dword ptr [p6]  
	008C54F8  mov         dword ptr [ebp-164h],eax  
	008C54FE  push        8  
	008C5500  mov         ecx,dword ptr [ebp-164h]  
	008C5506  push        ecx  
	008C5507  call        operator delete (08C1050h)  
	008C550C  add         esp,8  
	008C550F  cmp         dword ptr [ebp-164h],0  
	008C5516  jne         main+1E4h (08C5524h)  
	008C5518  mov         dword ptr [ebp-16Ch],0  
	008C5522  jmp         main+1F4h (08C5534h)  
	008C5524  mov         dword ptr [p6],8123h  
	008C552B  mov         edx,dword ptr [p6]  
	008C552E  mov         dword ptr [ebp-16Ch],edx 

	�ܽ᣺������ operator new�������� operator new�����������malloc��Ȼ����ù��캯���������
		delete��ʱ������ȵ�������������Ȼ�� operator delete�ͷ��ڴ����free()����
	 */
	system("pause");
	return 0;
}

/*
*(1)�����ͻع�
*	�����ģ�����е��ڴ��������Ҫ���á�
*
*(2)��new˵��
*		A *pa1 = new A;
		A *pa2 = new A();
*	2.1new�����ʱ��Ӳ���()�Ĳ��
*		����Ǹ����࣬����д��û������
*		�����A���г�Ա����,��()��ʼ�����һЩ�ͳ�Ա�����йص��ڴ���0�����ǲ��������ڴ�ȫ����0��
*	2.2	�����й��캯��������д��һ����
*		��û�й��캯����������һ���麯����ʱ�򣬻��ǻ�ѳ�Ա����m_i��0.
*		�ܽ᣺���û�й��캯����������������Ǹ�
*
*	2.3 ����()����һ�ֺ������õĸо�������()ʵ���ϻ��ǻ����Ĭ�Ϲ��캯����
*	2.4�������ͼӲ���()������
*	2.5 new �����ʱ�򵽵�����ʲô
*		
	�ܽ᣺������ operator new()�������� operator new�����������malloc��Ȼ����ù��캯���������
		delete��ʱ������ȵ�������������Ȼ�� operator delete()�����ͷ��ڴ����free()����
*(3)malloc����ʲô���飿malloc����ô�����ڴ�ģ�
*	���ǲ���ϵͳ�ڲ����ڴ����ǣ�浽�ڴ���䣬�����ϲ����ͷŵ����⡣
*	malloc����ò���ϵͳ���ײ�Ľ����ʵ���������ڴ���䡣
*(4)�ܽ᣺
*
*/