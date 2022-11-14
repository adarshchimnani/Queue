#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

struct node
{
	string info; 
	node *link;
};

struct list
{
	node *queueFront, *queueRear;

	list ()
	{
		queueFront=NULL;
		queueRear=NULL;
	}

	bool emptyQueue ()
	{
		return (queueFront==NULL);
	}

	bool fullQueue ()
	{
		return false;
	}

	void initialize ()
	{
		node *temp;

		while ( queueFront!=NULL )
		{
			temp=queueFront;
			queueFront=queueFront->link;
			delete temp;
		}
	}

	void addQueue ()
	{
		node *newNode;
		string item;
		int priority;
		char ask='y';

		while (ask=='y' || ask=='Y')
		{
			cout<<"Please enter the the Name of the patient."<<endl;
			cin.ignore();
			getline(cin, item);
			cout<<endl<<"Now enter the priority among:"<<endl;
			cout<<"Normal Patients              - 0"<<endl;
			cout<<"Patients who pay double fee  - 1."<<endl;
			cout<<"Patients with severe disease - 2."<<endl;
			cout<<"Patients with emergency      - 3."<<endl;
			cin>>priority;
		
			newNode= new node;
			newNode->info=item;
			newNode->link=NULL;

			if (queueFront==NULL)
			{
				queueFront=newNode;
				queueRear=newNode;
			}

			else
			{
				if (priority==0)
				{
					queueRear->link=newNode;
					queueRear=queueRear->link;
				}

				else if ( priority==1)
				{
					
				}
			}

			cout<<endl<<"If you want to enter another value, enter 'y'."<<endl;
			cin>>ask;
		}
	}

	void front ()
	{
		if (queueFront!=NULL)
			cout<<endl<<queueFront->info;
	}

	void back ()
	{
		if (queueRear!=NULL)
			cout<<endl<<queueRear->info;
	}

	void deleteQueue ()
	{
		node *temp;

		if (!emptyQueue())
		{
			temp=queueFront;
			queueFront=queueFront->link;

			delete temp;

			if (queueFront == NULL)
				queueRear=NULL;
		}

		else
			cout<<"Empty Queue."<<endl;
	}

	void display()
	{
		node *current;

		current=queueFront;
		cout<<endl;
		while (current!=NULL)
		{
			cout<<current->info<<" "<<endl;
			current=current->link;
		}
	}

	void menu ()
	{
		int entry;
		char returnToMenu='y';


		while (returnToMenu=='y' || returnToMenu=='Y')
		{
			cout<<"Welcome"<<endl;
			cout<<"Please enter 1 to Add Queue."<<endl;
			cout<<"Please enter 2 to get the Front Queue."<<endl;
			cout<<"Please enter 3 to get the Rear Queue."<<endl;
			cout<<"Please enter 4 to Delete Queue."<<endl;
			cout<<"Please enter 5 to Display Queue."<<endl;
			cin>> entry;

			if (entry==1)
				addQueue();

			else if (entry==2)
				front();

			else if (entry==3)
				back();

			else if (entry==4)
				deleteQueue();

			else if (entry==5)
				display();

			cout<<endl<<"If you want to return to the menu, enter 'y'."<<endl;
			cin>>returnToMenu;
		}
		cout<<endl;
	}
};

void main ()
{
	list obj;

	obj.menu();

getch();
}