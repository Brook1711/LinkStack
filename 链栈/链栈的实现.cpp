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
	Node<T> * p = new Node<T>;
	p->data = x;
	p->next = top;
	top = p;
}

template<class T>
T LinkStack<T>::Pop() //ʵ�ֳ�ջ����
{
	if (Empty())
		throw"����";
	T x = top->data;
	Node<T> *p = top;
	top = top->next;
	delete p;
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