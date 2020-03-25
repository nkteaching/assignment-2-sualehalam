#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node *next;
};
class Stack
{
	private:
		Node *top;
		
		Node *previous, *current,*t;									// For reversing a stack
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
		void transferStack(Stack &stack1, Stack &stack2)     	// Copies element of stack1 onto stack2
		{	
			
			while(stack1.isEmpty()!=true )						// while stack2 is not empty 
			{
				stack2.push(stack1.pop() );						// pushing all popped values of stack1 int stack2				
				
			 } 
		
		}
		void reverseStack(Stack &stk)     							// Reverse stack1 and then put it in stack 2
		{				
			current = top;
			previous = top;
			
			current=current->next;
			previous->next = NULL;
			
			while(current!=NULL)
			{
				t=current->next;
				current->next = previous;
				previous=current;
				current = t;
			}
			top = previous;
				
		}
		
			
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
	
	Stack stk2;
	
	
	cout<<"\n AFter transfering using without additional stack"<<endl;
	
	stk1.reverseStack(stk1);
	
	
	stk1.transferStack(stk1, stk2); 	
	cout<<"Stack2: ";
	stk2.Display();
	
	
}
