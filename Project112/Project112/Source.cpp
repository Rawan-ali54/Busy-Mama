#include <iostream>
#include<string>
#include<vector>
#include"Windows.h"
#include"MMSystem.h"
#include"pqueue.cpp"
using namespace std;
int counterid = 0;
struct task
{
	int priority;
	string info;

};
vector< mothers<task>>mama;
void regist(int&existedid)
{
	mothers<task>temp;
	cout << "Enter your name ";
	cin >> temp.name;
	cout << "Enter Your Password ";
	cin >> temp.passwrod;

	cout << "Your Fixed Id You Should keep it\n" << counterid + 1 << endl;
	temp.id = counterid;
	existedid = temp.id;
	counterid++;
	mama.push_back(temp);
}
bool login(int&existedid)
{
	bool correct = 0;
	int idd;
	string pass;
	cout << "Enter id  \n";
	cin >> idd;
	idd--;
	cout << "Enter Password   \n";
	cin >> pass;
	for (int i = 0; i != mama.size(); i++)
	{
		if (mama[i].id == idd) {
			if (mama[i].passwrod == pass)
			{
				existedid = mama[i].id;
				return 1;
			}
		}
	}
	return 0;
}



int main()
{
	char mu;
	
	string taskname;
	int prireturn;
	int existedid;
	bool loginn = 0;
	int check = 0;

	bool invalid;
	char lett = 'u';
	//char cond = 'j';

	int c, p, day, num = 0;
	string i, sta;

	while (lett != 'e')
	{
		//cond = 'o';

		system("cls");
		system("COLOR F0 ");
		cout << "\t\t\t\t\t\tBUSY MAMA\t\t\t\t\t\t\t\t\t\t\n";
		cout << " for music press 1 for not press any key\n";
		cin >> mu;
		if (mu == '1')
			PlaySound("project Rawan", NULL, SND_ASYNC);
		cout << "\t\t\t\tWelcome Mama \n";
		cout << "We know you have several responsibilities so we decide to help you organize your tasks\t\t\t\t\t\n";
		cout << "press [1] to registeration\npress [2] to login\n";

		do
		{
			cin >> num;
			if (num == 1) {
				regist(existedid);
				break;
			}
			else if (num == 2) {
				while (login(existedid) == false) {
					cout << "wrong\n";
				}
				break;
			}
			else {
				cout << "invalid enter\n";
				cout << "Please Try Again \n";
			}

		} while (num != 1 || num != 2);
		do
		{

			cout << "Choose Day From [1] to [7] \n";
			cout << "1-Friday   2-saturday\n";
			cout << "3-Sunday   4-Monday\n";
			cout << "5-Tuesday  6-Wednesday\n";
			cout << "7-Thursday\n";

			do
			{
				cin >> day;
				if ((1 <= day) && (day <= 7))
				{
					break;
				}
				else
				{
					cout << "InValid Enter \n";
					cout << "Choose Day From 1 to 7 \n";
				}


			} while (day > 7 || day < 1);

			check = mama[existedid].task[day - 1].lenght();
			if (check == 0)
				mama[existedid].task[day - 1].reminder();
			cout << "--------------------------------------------------------\n";
			cout << "1.Insert\n";
			cout << "2.Delete high priority\n";
			cout << "3.Delete specific task\n";
			cout << "4.Update\n";
			cout << "5.Edit\n";
			cout << "6.Postpone\n";
			cout << "7.Display\n";
			cout << "8.Exit\n";
			cout << "---------------------------------------------------------\n";
			cout << "Enter your choice : ";
			cin >> c;
			cout << "----------------------------------------------------------\n";
			switch (c)
			{
			case 1:
				cout << "Enter Your Task Name : ";
				cin >> i;
				invalid = 1;
				while (invalid) {
					cout << "Enter its priority : ";
					cin >> p;
					if (p <= 10 && p >= 0) {
						mama[existedid].task[day - 1].insert(i, p);
						invalid = 0;
					}
				}
				break;
			case 2:
				mama[existedid].task[day - 1].delet();

				break;
			case 3:
				mama[existedid].task[day - 1].deletspecific();


				break;
			case 4:
				mama[existedid].task[day - 1].update_reminder();
				break;
			case 5:
				mama[existedid].task[day - 1].edit();
				break;
			case 6:
				check = mama[existedid].task[day - 1].lenght();
				if (check == 0)
				{
					cout << "enter task name\n";
					cin >> taskname;
					prireturn = mama[existedid].task[day - 1].postpone(taskname);

					cout << " which day to postpone to?\n";
					cout << "Choose Day From [1] to [7] \n";
					cout << "1-Friday   2-saturday\n";
					cout << "3-Sunday   4-Monday\n";
					cout << "5-Tuesday  6-Wednesday\n";
					cout << "7-Thursday\n";
					cin >> day;

					mama[existedid].task[day - 1].insert(taskname, prireturn);
				}
				else
					cout << "No Task To Postpone \n";

				//	cout << "----------------------------------------------------\n";
				break;
			case 7:
				mama[existedid].task[day - 1].display();

				break;
			case 8:

				break;
			default:
				cout << "Wrong choice\n";
			}


		} while (c != 8);




		cout << "IF YOU WANT TO EXIT PRESS e ELSE PRESS ANY LETTER \n";
		cin >> lett;
	}

	system("pause");
	return 0;
}