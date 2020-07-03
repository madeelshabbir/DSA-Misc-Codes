#include<iostream>
#include<stack>
using namespace std;
class Node
{
public: 
	int data;
	Node *p1, *p2, *p3;
	Node(int d)
	{
		data = d;
		p1 = p2 = p3 = NULL;
	}
};
void display(Node* root)
{
	Node* tmp = NULL;
	stack<Node *> *s = new stack<Node *>;
	s->push(root);
	while (!s->empty())
	{
		tmp = s->top();
		s->pop();
		cout << tmp->data << endl;
		if (tmp->p1 != NULL)
			s->push(tmp->p1);
		if (tmp->p2 != NULL)
			s->push(tmp->p2);
		if (tmp->p3 != NULL)
			s->push(tmp->p3);
	}
}
int main()
{
	Node *start = new Node(10);
	start->p1 = new Node(66);
	start->p3 = new Node(32); 
	start->p1->p1 = new Node(9); 
	start->p1->p2 = new Node(45); 
	start->p1->p3 = new Node(11); 
	start->p3->p2 = new Node(21); 
	start->p3->p3 = new Node(39); 
	start->p1->p2->p1 = new Node(50); 
	start->p1->p2->p1->p1 = new Node(30); 
	start->p1->p2->p1->p2 = new Node(77); 
	start->p1->p3->p2 = new Node(26); 
	start->p1->p2->p1->p2->p1 = new Node(123); 
	start->p1->p2->p1->p2->p2 = new Node(231); 
	start->p1->p2->p1->p2->p3 = new Node(312); 
	display(start);
	system("pause");
	return 0; 
}