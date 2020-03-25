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
		void reverseStack(Stack &stack1, Stack &stack2, Stack &stack3)     // Copies element of stack1 onto stack2
		{
			
			while(stack1.isEmpty()!=true)						// while stack2 is not empty keep on removing values
			{
				stack2.push( stack1.pop() );
			}			
			
			while(stack2.isEmpty()!=true )						// while stack2 is not empty OR ( stack2.isEmpty() )
			{
				stack3.push(stack2.pop() );						// pushing all popped values of stack2 into stack3					
				
			 } 
			 while(stack3.isEmpty()!=true)						// while stack3 is not empty
			 {
			 	stack1.push(stack3.pop());						// pushing all popped values of stack3 into stack1 [ REVERSED ]
			 }
		
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
	
	stk1.push(10);
	stk1.push(20);
	stk1.push(30);
	
	cout<<"Stack1: ";
	stk1.Display();
	
	Stack stk2;
	
	Stack stk3;

	
	stk1.reverseStack(stk1, stk2, stk3); 	
	
	
	cout<<"\n AFter reversing using two stacks"<<endl;
	cout<<"Stack1: ";
	stk1.Display();
	
}
