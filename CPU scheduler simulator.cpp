#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Process
{
private:
	string process_name;
	int execution_time;
	int waiting_time;
	int turnaround_time;
	int arrival_time;
	int reamining_time;
	int execution_StartTime;
	int execution_EndingTime;
public:
	string proNM() const
	{
		return process_name;
	}
	int exeTM() const
	{
		return execution_time;
	}
	int wtTM() const
	{
		return waiting_time;
	}
	int taTM() const
	{
		return turnaround_time;
	}
	int aTM() const
	{
		return arrival_time;
	}
	int rTM() const
	{
		return reamining_time;
	}
	int exeSTM() const
	{
		return execution_StartTime;
	}
	int exeETM() const
	{
		return execution_EndingTime;
	}
	void setNM(string s)
	{
		process_name = s;
	}
	void setTM(int t)
	{
		execution_time = t;
	}
	void setwtTM(int t)
	{
		waiting_time = t;
	}
	void settaTM(int t)
	{
		turnaround_time = t;
	}
	void setaTM(int t)
	{
		arrival_time = t;
	}
	void setrTM(int t)
	{
		reamining_time = t;
	}
	void setexeSTM(int t)
	{
		execution_StartTime = t;
	}
	void setexeETM(int t)
	{
		execution_EndingTime = t;
	}
	Process(string n = "", const int t = 0, const int at = 0) : process_name(n), execution_time(t), waiting_time(0), turnaround_time(0), arrival_time(at), reamining_time(0), execution_StartTime(0), execution_EndingTime(){}
	Process(const Process &p)
	{
		 process_name = p.process_name;
		 execution_time = p.execution_time;
		 waiting_time = p.waiting_time;
		 turnaround_time = p.turnaround_time;
		 arrival_time = p.arrival_time;
		 reamining_time = p.reamining_time;
		 execution_StartTime = p.execution_StartTime;
		 execution_EndingTime = p.execution_EndingTime;
	}
	friend ostream& operator<<(ostream &s, const Process &p)
	{
		s << "\t\tProcess Completed\t\t" << endl;
		s << "\t*********************************\t" << endl;
		s << "\t" << p.process_name << ", " << p.execution_time << ", " << p.waiting_time << ", " << p.turnaround_time << endl;
		return s;
	}
};
class Queue
{
private:
	class ListNode
	{
	public:
		Process proc;
		ListNode* next;
		ListNode* pre;
		ListNode()
		{
			next = NULL;
			pre = NULL;
		}
		ListNode(const Process &p)
		{
			proc = p;
			next = NULL;
			pre = NULL;
		}
	};
	ListNode* head;
	ListNode* tail;
	long lsize;
public:
	Queue()
	{
		lsize = 0;
		head = new ListNode();
		tail = new ListNode();
		head->next = tail;
		tail->pre = head;
	}
	~Queue()
	{
		ListNode* tmp = head;
		while (tmp != NULL)
		{
			ListNode *junk = tmp;
			tmp = tmp->next;
			delete junk;
		}
		head = NULL;
		tail = NULL;
	}
	bool isEmpty() const
	{
		return head->next == tail;
	}
	void enqueue(const Process &p)
	{
		ListNode* node = new ListNode(p);
		ListNode* tmp = tail->pre;
		tail->pre = node;
		tmp->next = node;
		node->pre = tmp;
		node->next = tail;
		lsize++;
	}
	void dequeue()
	{
		ListNode* jnk = head->next;
		head->next = jnk->next;
		jnk->next->pre = head;
		delete jnk;
		lsize--;
	}
	Process peek()
	{
		return head->next->proc;
	}
	long size() const
	{
		return lsize;
	}
	void display() const
	{
		if (isEmpty())
		{
			return;
		}
		ListNode* tmp = head->next;
		while (tmp != tail)
		{
			cout << tmp->proc.proNM() << ", " << tmp->proc.exeTM() << endl;
			tmp = tmp->next;
		}
		cout << endl;
	}
	void sortByTime()
	{
		for (int i = 0; i < size(); i++)
		{
			ListNode* tmp = head->next;
			for (int j = 0; j < size() - i - 1; j++)
			{
				if (tmp->proc.exeTM() < tmp->next->proc.exeTM())
				{
					ListNode* jnk = tmp;
					tmp = tmp->next;
					jnk->pre->next = tmp;
					tmp->pre = jnk->pre;
					jnk->next = tmp->next;
					jnk->pre = tmp;
					tmp->next->pre = jnk;
					tmp->next = jnk;
				}
				tmp = tmp->next;
			}
		}
	}
};
class Simulation
{
private:
	Queue *procs;
	int tic;
	int noP;
	double totalTurnTime;
	double totalWaitTime;
	void deleteFile()
	{
		ofstream dataFile;
		dataFile.open("readyList.txt", ios::trunc);
		dataFile.close();
	}
	void readFile()
	{
		ifstream inp("readylist.txt");
		int tmp;
		string pn;
		while (inp.peek() != EOF)
		{
			getline(inp, pn, ' ');
			inp >> tmp;
			inp.ignore(1);
			Process p(pn, tmp, tic);
			procs->enqueue(p);
		}
		inp.close();
		procs->sortByTime();
		deleteFile();
	}
	void pause()
	{
		cout << "*****************************" << endl;
		cout << "Press enter to continue: ";
		while (cin.get() != '\n')
			cout << "Press Enter to continue: ";
		cout << "*****************************" << endl;
	}
	void pauseHandling()
	{
		tic++;
		if (tic % 15 == 0)
		{
			pause();
			readFile();
		}
	}
public:
	Simulation() : tic(0), noP(0), totalTurnTime(0), totalWaitTime(0)
	{
		procs = new Queue;
	}
	bool mainSimulation()
	{
		bool b = 0;
		readFile();
		while (!procs->isEmpty())
		{
			cout << "___________________________________________" << endl;
			cout << "\tProcess in Ready Queue" << endl;
			procs->display();
			cout << "___________________________________________" << endl;
			Process p = procs->peek();
			procs->dequeue();
			int e = p.exeTM();
			p.setexeSTM(tic);
			for (int i = e; i > 0; i--)
			{
				p.setrTM(p.rTM() - 1);
				pauseHandling();
			}
			p.setexeETM(tic);
			p.setwtTM(p.exeSTM() - p.aTM());
			p.settaTM(p.exeETM() - p.aTM());
			cout << p << endl;
			totalWaitTime += p.wtTM();
			totalTurnTime += p.taTM();
			noP++;
			b = 1;
		}
		delete procs;
		return b;
	}
	void dispAvg()
	{
		cout << "\tEnd Result\t" << endl;
		cout << "Average Turn Around Time: " << totalTurnTime / noP << endl;
		cout << "Average Waiting Time: " << totalWaitTime / noP << endl;
	}
};
int main()
{
	Simulation sim;
	if (sim.mainSimulation())
		sim.dispAvg();
	else
		cout << "Warning! There is no Process in readylist.txt" << endl;
	system("pause");
	return 0;
}