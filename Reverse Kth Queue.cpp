#include<iostream>
#include<stack>
using namespace std;
template <typename Object>
class QueueADT
{
public:
	virtual bool isEmpty() const = 0;
	virtual long qSize() const = 0;
	virtual Object peek() const = 0;
	virtual void enqueue(const Object &) = 0;
	virtual Object dequeue() = 0;
};
template <typename Object>
class Queue : public QueueADT<Object>
{
private:
	class ListNode
	{
	public:
		Object data;
		ListNode* next;
		ListNode(Object d)
		{
			data = d;
			next = NULL;
		}
	};
	ListNode* head;
	ListNode* tail;
	long size;
public:
	Queue()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	~Queue()
	{
		while (head != NULL)
		{
			ListNode *junk = head;
			head = head->next;
			delete junk;
		}
		head = NULL;
		tail = NULL;
	}
	bool isEmpty() const
	{
		return (head == NULL);
	}
	long qSize() const
	{
		return size;
	}
	Object peek() const
	{
		if (isEmpty())
		{
			throw 0;
		}
		return head->data;
	}
	void enqueue(const Object &d)
	{
		size++;
		if (isEmpty())
		{
			head = new ListNode(d);
			tail = head;
			return;
		}
		tail->next = new ListNode(d);
		tail = tail->next;
	}
	Object dequeue()
	{
		if (isEmpty())
		{
			throw 0;
		}
		ListNode* tmp = head;
		head = head->next;
		Object o = tmp->data;
		delete tmp;
		size--;
		return o;
	}
};
int main()
{
	QueueADT<int> *q = new Queue<int>;
	QueueADT<int> *tmp = new Queue<int>;
	int k = 5;
	q->enqueue(10);
	q->enqueue(20);
	q->enqueue(30);
	q->enqueue(40);
	q->enqueue(50);
	q->enqueue(60);
	q->enqueue(70);
	q->enqueue(80);
	q->enqueue(90);
	q->enqueue(100);
	stack<int> s;
	for (int i = 0; i < k; i++)
		s.push(q->dequeue());
	while(!q->isEmpty())
		tmp->enqueue(q->dequeue());
	for (int i = 0; i < k; i++)
	{
		q->enqueue(s.top());
		s.pop();
	}
	while (!tmp->isEmpty())
		q->enqueue(tmp->dequeue());
	delete tmp;
	while (!q->isEmpty())
		cout << q->dequeue() << endl;
	system("pause");
}