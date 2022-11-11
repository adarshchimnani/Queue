#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

struct queue
{
	int maxQueueSize, queueFront, queueRear, count, *list;
	string state;

	queue (int queueSize)
	{
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

	void peek () // void front
	{
		if (!emptyQueue())
			cout<<"The from element in the queue is: "<<list[queueFront]<<endl;
	}

	void back ()
	{
		if (!emptyQueue())
			list[queueRear];
	}

	void enqueue (int item)
	{
		if (!fullQueue())
		{
			queueRear=(queueRear+1)%maxQueueSize;
			list[queueRear]=item;
			count++;
			cout<<endl<<"The queue has beeen enqueued with: "<<item<<endl;
		}

		else
			cout<<"Queue is full."<<endl;
	}

	void dequeue ()
	{
		if (!emptyQueue())
		{
			cout<<endl<<"The queue has been dequeued of: "<<list[queueFront]<<endl;
			count--;
			queueFront=(queueFront+1)%maxQueueSize;
		}

		else
			cout<<"Queue is empty."<<endl;
	}

	void size ()
	{
		cout<<endl<<"The size of the queue is: "<<count<<endl;
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

	
};


void main ()
{
	queue Array(5);
	
	Array.enqueue(1);
	Array.enqueue(2);
	Array.enqueue(3);

	Array.peek();

	Array.dequeue();
	Array.size();

	Array.peek();

	Array.dequeue();
	Array.dequeue();

	if (Array.emptyQueue())
		cout<<"Queue is empty."<<endl;

	else
		cout<<"Queue is not empty."<<endl;

_getch();
}