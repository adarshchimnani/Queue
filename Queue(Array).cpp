#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

struct queue
{
	int queueSize, maxQueueSize, queueFront, queueRear, count, *list;
	string state;

	queue ()
	{
		cout<<"Please enter the size of queue."<<endl;
		cin>>queueSize;

		if (queueSize<=0)
		{
			cout<<endl<<"Size must be positive."<<endl;
			cout<<"Creating an array of size 100."<<endl;
			maxQueueSize=100;
		}

		else 
			maxQueueSize=queueSize;

		queueFront=0;
		queueRear=maxQueueSize-1;
		count=0;
		list = new int [maxQueueSize];
	}

	bool emptyQueue ()
	{
		return (count==0);
	}

	bool fullQueue ()
	{
		return (count==maxQueueSize);
	}

	void front ()
	{
		if (!emptyQueue())
			list[queueFront];
	}

	void back ()
	{
		if (!emptyQueue())
			list[queueRear];
	}

	void addQueue ()
	{
		if (!fullQueue())
		{
			queueRear=(queueRear+1)%maxQueueSize;
			count++;
			cout<<"Please enter the value."<<endl;
			cin>>list[queueRear];	
		}

		else
		cout<<"Queue is full."<<endl;
	}

	void deleteQueue ()
	{
		if (!emptyQueue())
		{
			count--;
			queueFront=(queueFront+1)%maxQueueSize;
		}

		else
			cout<<"Queue is empty."<<endl;
	}

	void display ()
	{
		if(!emptyQueue())
		{
			for ( int i=queueFront; i<=queueRear; i++)
			{
				cout<<list[i]<<" ";
			}
			cout<<endl;
		}

		else 
			cout<<"Quene is empty."<<endl;
	}

	void menu ()
	{
		char ask;
		int enter;

		do
		{
			cout<<"Welcome"<<endl;
			cout<<"Please enter 1 to add Queue."<<endl;
			cout<<"Please enter 2 to delete Queue."<<endl;
			cout<<"Please enter 3 to display Queue."<<endl;
			cin>>enter;

			switch (enter)
			{
				case 1:
					addQueue();
					break;

				case 2:
					deleteQueue();
					break;

				case 3:
					display();
					break;

				default:
					cout<<"Enter valid number."<<endl;
			}

			cout<<"For going to the menu, enter 'y'."<<endl;
			cin>>ask;
		}

		while (ask=='y' || ask=='Y');
	}
};


void main ()
{
	queue intArray;
	intArray.menu();

getch();
}