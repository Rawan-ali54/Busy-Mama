#include<iostream>
#include<string>
#include"Windows.h"
#include"MMSystem.h"
#include"pqueue.h"
using namespace std;
template <class t>
pqueue<t>::pqueue()
{
	counter = 0;
	head = NULL;
};
template <class t>
void pqueue<t>::insert(string i, int p)
{
	n<t> *temp;
	temp = new n<t>;

	temp->info = i;
	temp->priority = p;

	if (head == NULL)
	{
		temp->next = NULL;
		head = temp;

	}
	else if (head->next == NULL)
	{
		if (head->priority <= p)
		{
			temp->next = head;
			head = temp;
		}
		else if (head->priority >= p)
		{
			temp->next = NULL;
			temp->next = head->next;
			head->next = temp;

		}
	}

	else
	{
		n<t>*current = head;
		if (head->priority <= p)
		{


			temp->next = NULL;
			temp->next = head;
			head = temp;

		}
		else
		{
			while (current->next != NULL)
			{
				if (current->next->priority <= p)
				{
					break;
				}
				current = current->next;
			}


			temp->next = current->next;
			current->next = temp;
		}
	}
	counter++;
};
template <class t>
void pqueue<t>::delet()
{
	n <t>*temp;
	if (head == NULL)
		cout << "You have no task \n";
	else
	{
		temp = head;
		cout << "Deleted Task is: " << temp->info << endl;
		head = head->next;
		delete(temp);
	}
	counter--;
};
template <class t>
void pqueue<t>::display()
{

	n<t> *ptr;
	ptr = head;
	if (head == NULL)
		cout << "You Have No Task\n";
	else
	{
		cout << "Your Task Is :\n";
		cout << "Task Name\t\t Task Priority \n";
		while (ptr != NULL)
		{
			cout << " " << ptr->info << "\t\t\t" << ptr->priority << endl;

			ptr = ptr->next;
		}
	}
};
template<class t>
void pqueue<t>::deleteat(int pos)
{

	n<t>* tmp = head;
	if (pos == 0)
	{
		head = head->next;

		delete tmp;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			tmp = tmp->next;
		n<t>* del = tmp->next;
		tmp->next = del->next;
		delete del;

	}

}
template <class t>
void pqueue<t>::deletspecific()
{
	n<t>*temp = head;
	string taskk;
	bool found = false;
	int count = 0;
	cout << "HERE ARE YOUR EXISTED TASK CHOOSE WHICH ONE TO BE DELETED\n";
	if (counter == 0)
	{
		cout << "You Have No Task\n";
		return;
	}
	else
	{
		display();
		cout << "Enter Task Name ";
		cin >> taskk;
		while (temp != NULL)
		{
			if (temp->info == taskk)
			{
				found = true;
				break;
			}
			else
			{
				temp = temp->next;
				count++;
			}
		}
		if (found == true)
		{
			deleteat(count);
		}
		else
		{
			cout << "Your Task Is Not Found \n";
		}
	}

}

template <class t>
void pqueue<t>::update_reminder()
{
	int num;
	if (counter == 0)
	{
		cout << "You Have No Task To be Done \n";
		return;
	}
	else
	{
		cout << " How Many Tasks Done \n";
		cin >> num;

		if (num > counter)
		{
			cout << "InValid Enter \n";
			cout << "More Than Number Of Task That Found\n";
			return;
		}
		else
		{
			for (int i = 0; i < num; i++)
			{
				delet();
			}

		}

		show();



	}



}template <class t>
int pqueue<t>::postpone(string taskname) {
	int choi;
	string day;
	int coun = 0;
	int taskpriority;
	n<t>*temp = head;

	/*cout << " which day to postpone to?\n";
	cout << "Choose Day From [1] to [7] \n";
	cout << "1-Friday   2-saturday\n";
	cout << "3-Sunday   4-Monday\n";
	cout << "5-Tuesday  6-Wednesday\n";
	cout << "7-Thursday\n";
	cin >> day;*/
	bool found = false;
	while (temp != NULL)
	{
		if (temp->info == taskname)
		{
			found = true;
			break;
		}
		else
		{
			temp = temp->next;
		}
	}
	if (found == true) {
		do {
			cout << "press [1] to postpone it with the same priority\npress [2] to change its priority\n";
			cin >> choi;
			if (choi == 1) {
				temp = head;
				while (temp->info != taskname) {
					temp = temp->next;
					coun++;
				}
				taskpriority = temp->priority;
				deleteat(coun);
				return taskpriority;

			}
			else if (choi == 2) {
				do {
					cout << "enter new priority\n";
					cin >> taskpriority;
				} while (taskpriority < 1 || taskpriority>10);
				temp = head;
				while (temp->info != taskname) {
					temp = temp->next;
					coun++;
				}
				deleteat(coun);
				return taskpriority;
			}
			else {
				cout << "invalid enter\n";

			}
		} while (choi != 1 || choi != 2);
	}
	else
	{
		cout << "Your Task Is Not Found \n";
	}

}
template<class t>
int pqueue<t>::lenght()
{
	if (head == NULL)
		return 1;
	else
		return 0;
}
template <class t>
void pqueue<t>::reminder() {
	if (head == NULL) {
		cout << "you have no task yet\n";
	}
	else {
		cout << "your first task according to priority is  " << head->info << endl;
	}
}
template <class t>
void pqueue<t>::edit() {
	n<t>*temp = head;
	string taskname;
	int taskpriority;
	int counterr = 0;
	int choi;
	bool found = false;

	cout << "enter task name\n";
	cin >> taskname;

	while (temp != NULL)
	{
		if (temp->info == taskname)
		{
			found = true;
			break;
		}
		else
		{
			temp = temp->next;
		}
	}
	if (found == true) {
		do {
			cout << "press [1] to edit its name\npress [2] to edit its priority\n";
			cin >> choi;
			if (choi == 1) {
				temp = head;
				while (temp->info != taskname) {
					temp = temp->next;
					counterr++;
				}
				cout << "enter new name\n";
				cin >> taskname;
				taskpriority = temp->priority;
				deleteat(counterr);
				insert(taskname, taskpriority);
				break;

			}
			else if (choi == 2) {
				do {
					cout << "enter new priority\n";
					cin >> taskpriority;
				} while (taskpriority < 1 || taskpriority>10);
				temp = head;
				while (temp->info != taskname) {
					temp = temp->next;
					counterr++;
				}
				deleteat(counterr);
				insert(taskname, taskpriority);
				break;
			}
			else {
				cout << "invalid enter\n";

			}
		} while (choi != 1 || choi != 2);
	}
	else
	{
		cout << "Your Task Is Not Found \n";
	}

}

template <class t>
void pqueue<t>::show()
{
	char mu;

	if (head == nullptr)
		cout << "Shatooraaa <3 " << endl;
	cout << " for music press 1 for not press any key\n";
	cin >> mu;
	if (mu == '1')
		PlaySound("project Rawan", NULL, SND_ASYNC);
	else
	{
		cout << "The Coming task \n";
		cout << head->info << endl;
	}
}