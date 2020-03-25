// Queue implementation using linked list
#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node *next;
}*front=NULL,*rear=NULL;


//Queue functions

void enqueue(int x)
{
	Node *t;
	t = new Node;
	if (t==NULL)
		cout<<"Queue is FULL";
	else
	{
		t->data = x;
		t->next = NULL;
		if(front == NULL)
			front = rear = t;
		else
		{
			rear->next = t;
			rear = t;
		}
	}
}

int dequeue()
{
	int x = -1;
	Node *t = new Node;
	
	if(front == NULL)
		cout<<"Queue is Empty";
	else
	{
		x = front->data;
		t=front;
		front=front->next;
		delete(t);
	}
	return x;
}


class Stack
{
	private:
		Node *top;
	public:
		Stack()
		{
			top = NULL;
		}
		bool isEmpty()
		{
			return top == NULL;									// returns a boolean value
			
		}
		
		void push(int x);
		int pop();
		void Display();
		
		int Length()
		{
			int count =0;
			Node *p= top;
			
			while(p!=NULL)
			{
				count++;
				p=p->next;
			}
			
			return count;
		}
		void reverseStack(Stack &stk1)     // Copies element of stack1 onto stack2
		{
			int count = 0;
			while(stk1.isEmpty()!=true)
			{
				enqueue(stk1.pop());
				count++;									// to find count of stack1		
				
			}
			while(count!=0)
			{
				stk1.push(dequeue());
				count--;
			}
					
		}
		
		//	Logic 2 using ADT 
//		void reverseStack(Stack &stk1, Queue &q1)
//		{
//			while(stk1.isEmpty()!=true)
//			{
//				q1.enqueue(stk1.pop());
//			}
//			while(q1.isEmpty()!=true)
//			{
//				stk1.push(q1.dequeue());
//			}
//			stk1.Display();
//			
//		}
		
		
			
};
void Stack :: push(int x)
{
	Node *t = new Node;
	if(t== NULL)				// If node not created
	{
		cout<<"Stack is FULL";
	}
	else
	{
		t->data = x;
		t->next = top;			// new node points to top
		top = t;				// top becomes t now
	}
}
int Stack :: pop()
{
	int x = -1;
	if(top == NULL)
	{
		cout <<"Stack is Empty"<<endl;
	}
	else
	{
		x = top->data;
		Node *t = top;
		top = top->next;
		delete t;
	}
	return x;
	
}
void Stack :: Display()
{
	Node *p = top;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}


int main()
{
	Stack stk1;
	
	int size,n;
	cout<<"Enter size of stack: ";
	cin>>size;
	
	for(int i=0;i<size;i++)
	{
		cin>>n;
		stk1.push(n);
	}

	cout<<"Stack1: ";
	stk1.Display();

	stk1.reverseStack(stk1); 	
	
	
	cout<<"\n AFter reversing stack using one queue "<<endl;
	cout<<"Stack1: ";
	stk1.Display();
	
}
