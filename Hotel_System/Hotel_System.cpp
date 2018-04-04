#include <iostream>
#include "list.h"
#include <fstream>
using namespace std;

class hotel
{
public:
	void main_menu(){
		int choice = 0;

		while (choice != 3)
		{
			system("CLS");
			cout << "\n\t\t\t\t*************";
			cout << "\n\t\t\t\t* MAIN MENU *";
			cout << "\n\t\t\t\t*************";
			cout << "\n\n\n\t\t\t1.Book A Room";
			cout << "\n\t\t\t2.Customer Record";
			cout << "\n\t\t\t3.Exit";
			cout << "\n\n\t\t\tEnter Your Choice: ";
			cin >> choice;

			switch (choice)
			{
			case 1: add();
			break;
			case 2: display();
			break;
	case 3: break;
			default:
			{
			cout << "\n\n\t\t\tWrong choice!!!";
			cout << "\n\t\t\tPress any key to continue!!";
			}
			}
			}
};   //to dispay the main menu
void add() {
	system("CLS");
	list *a;
	a = new list();
	ofstream fout("file.txt",ios::app);
	ifstream fin("file.txt",ios::in); 
	string name; int x[4]; x[1] = x[2] = 0; long count = 0;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			if (count > 0){ a->addEndall(x[0], name, x[2], x[3]); }
			for (int i = 0; i < 4; i++)
			{
				if (i != 1)
				{
					fin >> x[i];

				}

				else
				{
					fin >> name;

				}
			}
			count++;
		}
		fin.close();
	}
	else cout << "Unable to open file"; count = 0;

	cout << "\n Enter Customer Detalis";
	cout << "\n **********************";
	int RoomID, StartDate, /*EndDate,*/ Period; string Name;
	cout << "\nRoom No is " ;
	cin >> RoomID;
	node *temp = a->getChain(); int flag = 0;
	if (a->isEmpty())
	{
		flag = 1;
	}
	for (int i = 0; i < a->getSize_horizontally(); i++)
	{
		if (temp->getData() == RoomID)
		{
			flag = 0;
			break;
		}
		else{
			flag = 1; 
		}
		temp = temp->getNext();
	}
	if (flag)
	{
		cout << "\nEnter The Full Name With no space : ";
		cin >> Name;
		cout << "\nStart Date is " ;
		cin >> StartDate;
		//cout << "End Date is:" << '\n';
		//cin >> EndDate;
		cout << "\nPeriod (in days) is " ;
		cin >> Period;
		a->addEndall(RoomID, Name, Period, StartDate);
		if (fout.is_open())
		{
			fout << RoomID<<"\n";
			fout << Name<<"\n";
			fout << Period << "\n";
			fout << StartDate << "\n";
			fout.close();
		}
		else cout << "Unable to open file"; 
	}
	else{
		cout << "Sorry ...Room is already booked.\n\n"; system("PAUSE");
	}
};     //to book a room
void display(){
	system("CLS");
	list *a;
	a = new list();
	ifstream fin("file.txt", ios::in);
	string name; int x[4]; x[1] = x[2] = 0; long count = 0;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			if (count > 0){ a->addEndall(x[0], name, x[2], x[3]); }
			for (int i = 0; i < 4; i++)
			{
				if (i != 1)
				{
					fin >> x[i];

				}

				else
				{
					fin >> name;

				}
			}
			count++;
		}
		fin.close();
	}
	else cout << "Unable to open file"; count = 0;
	int room;
	cout << "\n Cusromer Details";
	cout << "\n ****************";
	cout << "\n\n Enter Room no for Check : " ;
	cin >> room;
	node *temp = a->getChain(); 
	if (a->isEmpty())
	{
		cout << "\n Sorry Room no. not found or vacant!!\n\n";
		system("PAUSE");
	}int flag = 0;
	for (int i = 0; i < a->getSize_horizontally(); i++)
	{
		if (temp->getData() == room)
		{
			flag = 0;
			cout << "\n\n Name: " << temp->getname();
			cout << "\n\n Period: " << temp->getperiod();
			cout << "\n\n Startdate: " << temp->getstartdate();
			cout << "\n\n";
			system("PAUSE");
			break;
		}
		else{
			temp = temp->getNext();
			flag = 1;
		}
	}
	if (flag){
		cout << "\n Sorry Room no. not found or vacant!!\n\n";
		system("PAUSE");
	}
	
};    //to display the customer record
	
};

	
int main(){
	hotel h;
	h.main_menu();
	
	
	return 0;
}
