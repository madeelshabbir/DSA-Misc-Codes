#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#define Infinity 1000
using namespace std;
int ti;
int num;
class Graph
{
private:
	class GraphNode
	{
	public:
		string data;
		vector<GraphNode*> next;
		char color;
		int dist;
		int ft;
		string pred;
		GraphNode(string d)
		{
			data = d;
			color = 'w';
			dist = Infinity;
			pred = "";
			ft = Infinity;
		}
	};
	vector<GraphNode> gr;
	GraphNode* searchPre(string s)
	{
		for (int i = 0; i < gr.size(); i++)
			if (gr[i].data == s)
				return &gr[i];
		throw 0;
	}
	void visitDFS(GraphNode &g, int &num)
	{
		ti++;
		g.dist = ti;
		g.color = 'g';
		vector<GraphNode *> &n = g.next;
		for (int k = 0; k != n.size(); k++)
			if (n[k]->color == 'w')
			{
				n[k]->pred = g.data;
				visitDFS(*n[k], ++num);
			}
		g.color = 'b';
		ti++;
		g.ft = ti;
	}
public:
	void insert(string d)
	{
		GraphNode tmp(d);
		gr.push_back(tmp);
	}
	void link(string a, string b)
	{
		for (vector<GraphNode>::iterator it = gr.begin(); it != gr.end(); it++)
			if (it->data == a)
			{
				it->next.push_back(searchPre(b));
				return;
			}
		throw 0;
	}
	int size() const
	{
		return gr.size();
	}
	bool isStrongDFS()
	{
		ti = 0;
		int num;
		for (vector<GraphNode>::iterator it = gr.begin(); it != gr.end(); it++)
		{
			for (vector<GraphNode>::iterator it1 = gr.begin(); it1 != gr.end(); it1++)
			{
				it1->color = 'w';
				it1->dist = Infinity;
				it1->pred = "";
			}
			num = 0;
			visitDFS(*it, num);
			if (num != gr.size() - 1)
				return false;
		}
		return true;
	}
};
int main()
{
	Graph g;
	g.insert("0");
	g.insert("1");
	g.insert("2");
	g.insert("3");
	g.insert("4");
	g.link("0", "4");
	g.link("1", "0");
	g.link("1", "2");
	g.link("2", "1");
	g.link("2", "4");
	g.link("3", "1");
	g.link("3", "2");
	g.link("4", "3");
	if(g.isStrongDFS())
		cout << "Graph is Strongly Connected" << endl;
	else
		cout << "Graph is not Strongly Connected" << endl;
	system("pause");
}