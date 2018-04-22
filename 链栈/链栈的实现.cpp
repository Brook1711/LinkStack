#include<iostream>

using namespace std;

template<class T>
struct Node
{
	T data;
	struct Node<T>* next;
};//����ڵ�

template<class T>
class LinkStack
{
private:
	struct Node<T> * top; //ջ��ָ��
public:
	LinkStack() { top = NULL; } //���캯������ʼ����ջ
	~LinkStack(); //������������
	void Push(T x);
	T Pop(); //��ջ����
	T GetTop()
	{
		return top->data;
	}//��ȡջ��Ԫ��
	bool Empty()
	{
		return (NULL == top) ? true : false;
	} //�ж�ջ�Ƿ�Ϊ��ջ

};

template<class T>
LinkStack<T>::~LinkStack() //ʵ����������
{
	while (top)
	{
		Node<T> * p = top;
		top = top->next;
		delete p;
	}
}

template<class T>
void LinkStack<T>::Push(T x) //ʵ����ջ����
{
	Node<T> * p = new Node<T>; //��	�½�ָ��pָ�������Node�Ͷѿռ䡣
	p->data = x; //��	���µĽڵ��е�data��ֵΪx��
	p->next = top;//��	���½ڵ��е�nextָ��ջ��Ԫ�ء�
	top = p;//��	����ջ��ָ�롣
}

template<class T>
T LinkStack<T>::Pop() //ʵ�ֳ�ջ����
{
	if (Empty()) //�ж������Ƿ�Ϊ�գ���Ϊ�գ��׳�������Ϣ�����硰��
		throw"����";
	T x = top->data;//��	��ջ��Ԫ�ص�data��������ʱ�½���T�ͱ���x�С�
	Node<T> *p = top;//��	�½�Node��ָ��ָ��ջ��Ԫ�ء�
	top = top->next;//��	ջ��ָ����ݡ�
	delete p;//��	�ͷ�ԭջ��ָ�룬��p��
	return x;
}


int main()
{
	LinkStack<int> Mine;
	for (int i = 0; i < 10; i++)
	{
		Mine.Push(i + 1);
		cout << Mine.GetTop() << " ";
	}//������ջ����
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << Mine.Pop() << " ";
	}//�����ջ����
	cout << endl;
	if (Mine.Empty())
		cout << "ջ��" << endl;//�����жϺ���
	try
	{
		Mine.Pop();
	}
	catch (const char * msg)
	{
		cerr << msg << endl;
	} //�����쳣�������

	system("pause");
	return 0;
}