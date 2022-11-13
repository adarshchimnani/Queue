#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

struct node
{
	int info; 
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

	void enqueue (int item)
	{
		node *newNode = new node;
		newNode->info=item;
		newNode->link=NULL;

		if (queueFront==NULL)
		{
			queueFront=newNode;
			queueRear=newNode;
		}

		else
		{
			queueRear->link=newNode;
			queueRear=queueRear->link;
		}		

		cout<<endl<<"The queue has been enqueued with: "<<item<<endl;
	}


	void dequeue ()
	{
		node *temp;

		if (!emptyQueue())
		{
			cout<<endl<<"The queue has been dequeued of: "<<queueFront->info<<endl;

			temp=queueFront;
			queueFront=queueFront->link;

			delete temp;

			if (queueFront == NULL)
				queueRear=NULL;
			
		}

		else
			cout<<"Empty Queue."<<endl;
	}


	void peek ()   // void front
	{
		if (queueFront!=NULL)
			cout<<endl<<"The top element in the queue is: "<<queueFront->info<<endl;
	}

	void back ()
	{
		if (queueRear!=NULL)
			cout<<endl<<"The last item in the queue is: "<<queueRear->info<<endl;
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

};

void main ()
{
	list obj;

	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(4);

	obj.peek();

	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();

	if(obj.emptyQueue())
		cout<<"Queue is empty."<<endl;

	else
		cout<<"Queue is not empty."<<endl;


	

_getch();
}