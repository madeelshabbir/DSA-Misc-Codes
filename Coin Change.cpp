#include<iostream>
using namespace std;
class LinkedSet
{
private:
	class SetNode
	{
	public:
		double data;
		SetNode *next;
		SetNode(double d)
		{
			data = d;
			next = NULL;
		}
	};

	SetNode *head;

public:
	LinkedSet()
	{
		head = NULL;
	}

	~LinkedSet()
	{
		SetNode *tmp = head;
		while (tmp != NULL)
		{
			SetNode *junk = tmp;
			tmp = tmp->next;
			delete junk;
		}
	}

	void append(double d)
	{
		if (head == NULL)
		{
			head = new SetNode(d);
			return;
		}

		SetNode *tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new SetNode(d);
	}

	void display()
	{
		SetNode *tmp = head;
		cout << "{ ";
		while (tmp != NULL)
		{
			if (tmp->next == NULL)
				cout << tmp->data << " ";
			else
				cout << tmp->data << ", ";
			tmp = tmp->next;
		}
		cout << "}" << endl;
	}
};
void swap(int &a, int &b)
{
	int k = a;
	a = b;
	b = k;
}
void Sort(int *&a, int n)
{
	for (int i = 0; i <= n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j])
				swap(a[i], a[j]);
}
LinkedSet currencySystem(int *c, int n,  int v)
{
	Sort(c, n);
	LinkedSet *l = new LinkedSet;
	int i = 0, sum = 0;
	while (v != 0)
	{
		if (v >= c[i])
		{
			int num = v / c[i];
			v %= c[i];
			for (int j = 0; j < num; j++)
				l->append(c[i]);
		}
		i++;
	}
	return *l;
}
int main()
{
	int arr[]{ 1, 2, 5, 10, 20, 50, 100, 500, 1000, 5000 };
	cout << "Currency Set = ";
	currencySystem(arr, 9, 67).display();
	system("pause");
}