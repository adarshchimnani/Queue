#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
int push_count=0;

struct node
{
	int info; 
	node *link;
};

struct queue
{
	node *queueFront, *queueRear;

	queue ()
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

	int enqueue (int item)
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
		
	//	cout<<endl<<"The queue has been enqueued with: "<<item<<endl;
		return item;
	}


	int dequeue ()
	{
		node *temp;

		if (!emptyQueue())
		{
			int a = queueFront->info;

		//	cout<<endl<<"The queue has been dequeued of: "<<queueFront->info<<endl;

			temp=queueFront;
			queueFront=queueFront->link;

			delete temp;

			if (queueFront == NULL)
				queueRear=NULL;

			return a;
			
		}

		else
		{
			cout<<"Empty Queue."<<endl;
			return 0;
		}
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

		cout<<endl<<endl<<"The remaining items in the stack are: ";
		current=queueFront;
		while (current!=NULL)
		{
			cout<<current->info<<" ";
			current=current->link;
		}
	}

};

struct stack
{
	queue q1, q2;

	void push(int x)
	{
		while(!q1.emptyQueue())
		{	
			q2.enqueue(q1.dequeue());
		}
		
		q1.enqueue(x);

		while(!q2.emptyQueue())
		{
			q1.enqueue(q2.dequeue());
		}
		
		cout<<endl<<"The stack has been pushed with: "<<x<<endl;
	}

	void pop()
	{
		int p=q1.dequeue();
		cout<<endl<<"The stack has been popped of: "<<p;
	
	}

	void display()
	{
		q1.display();
	}

};

void main ()
{
	stack s;

	int keys [] = {1, 2, 3, 4, 5};

	for (int key : keys)
	{
		s.push(key);
		push_count++;		//globally delcared and initialized
	}

	s.pop();
	s.pop();
	s.display();


	

_getch();
}