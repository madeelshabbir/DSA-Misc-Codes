//#include <iostream>
//using namespace std;
//class LinkedList
//{
//private:
//	class ListNode
//	{
//	public:
//		int data;
//		ListNode *next;
//		ListNode(int d)
//		{
//			data = d;
//			next = NULL;
//		}
//	};
//
//	ListNode *head;
//	ListNode *tail;
//
//public:
//	LinkedList()
//	{
//		head = NULL;
//	}
//
//	~LinkedList()
//	{
//		ListNode *tmp = head;
//		while (tmp != NULL)
//		{
//			ListNode *junk = tmp;
//			tmp = tmp->next;
//			delete junk;
//		}
//	}
//
//	void append(int d)
//	{
//		if (head == NULL && tail == NULL)
//		{
//			head = new ListNode(d);
//			tail = head;
//			return;
//		}
//		tail->next = new ListNode(d);
//		tail = tail->next;
//	}
//
//	void display()
//	{
//		ListNode *tmp = head;
//		while (tmp != NULL)
//		{
//			cout << tmp->data << endl;
//			tmp = tmp->next;
//		}
//
//	}
//	void appendL(const LinkedList &lst)
//	{
//		if (head != NULL && tail != NULL && lst.head != NULL && lst.tail != NULL)
//		{
//			tail->next = lst.head;
//			tail = lst.tail;
//		}
//	}
//};
//
//int main()
//{
//	LinkedList *c = new LinkedList;
//	LinkedList *c1 = new LinkedList;
//	c->append(30);
//	c->append(90);
//	c->append(20);
//	c->append(70);
//	c->append(50);
//	c1->append(3);
//	c1->append(9);
//	c1->append(2);
//	c1->append(7);
//	c1->append(5);
//	c->appendL(*c1);
//	c->display();
//	delete c;
//	system("pause");
//}
