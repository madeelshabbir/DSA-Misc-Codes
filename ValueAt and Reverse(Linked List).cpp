#include<iostream>
using namespace std;
template <typename Object>
class StackADT
{
public:
	virtual bool isEmpty() const = 0;
	virtual long sSize() const = 0;
	virtual Object peek() const = 0;
	virtual void push(const Object &) = 0;
	virtual Object pop() = 0;
};
template <typename Object>
class StackL : public StackADT<Object>
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
	long size;
public:
	StackL()
	{
		head = NULL;
		size = 0;
	}
	~StackL()
	{
		while (head != NULL)
		{
			ListNode *junk = head;
			head = head->next;
			delete junk;
		}
		head = NULL;
	}
	bool isEmpty() const
	{
		return (head == NULL);
	}
	long sSize() const
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
	void push(const Object &d)
	{
		size++;
		if (isEmpty())
		{
			head = new ListNode(d);
			return;
		}
		ListNode* tmp = new ListNode(d);
		tmp->next = head;
		head = tmp;
	}
	Object pop()
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
class LinkedList
{
private:
	class ListNode
	{
	public:
		double data;
		ListNode *next;
		ListNode(int d)
		{
			data = d;
			next = NULL;
		}
	};

	ListNode *head;

public:
	LinkedList()
	{
		head = NULL;
	}

	~LinkedList()
	{
		ListNode *tmp = head;
		while (tmp != NULL)
		{
			ListNode *junk = tmp;
			tmp = tmp->next;
			delete junk;
		}
	}

	void append(int d)
	{
		if (head == NULL)
		{
			head = new ListNode(d);
			return;
		}

		ListNode *tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new ListNode(d);
	}

	void erase(int d)
	{
		ListNode *tmp = head;
		while (tmp != NULL && tmp->next != NULL && tmp->next->data != d)
		{
			tmp = tmp->next;
		}
		if (tmp->next != NULL)
		{
			ListNode *junk = tmp->next;
			tmp->next = tmp->next->next;
			// OR tmp->next = junk->next;
			delete junk;
		}
	}

	void display()
	{
		ListNode *tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->data << endl;
			tmp = tmp->next;
		}

	}

	double ValueAt(const int n)
	{
		ListNode *tmp = head;
		int count = 0;
		while (count != n)
		{
			if (tmp == NULL)
				throw 0;
			tmp = tmp->next;
			count++;
		}
		return tmp->data;
	}
	void reverse()
	{
		StackADT<int> *s = new StackL<int>;
		ListNode *tmp = head;
		while (tmp != NULL)
		{
			s->push(tmp->data);
			tmp = tmp->next;
		}
		tmp = head;
		while (tmp != NULL)
		{
			tmp->data = s->pop();
			tmp = tmp->next;
		}
	}
};


int main()
{
	LinkedList *c = new LinkedList;
	c->append(30);
	c->append(90);
	c->append(20);
	c->append(70);
	c->append(50);
	cout << c->ValueAt(3) << endl;
	c->reverse();
	c->display();
	delete c;
	system("pause");
}
