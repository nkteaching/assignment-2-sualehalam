// Reverse order of element S using one additional stack and non array variables
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
		void reverseStack(Stack &stack1, Stack &stack2)     // Copies element of stack1 onto stack2
		{
			
			while(stack1.isEmpty()!=true)	
			{
				stack2.push(stack1.pop());									// reversing the stack1
			}
			
			int a =stack2.pop();
			
			while(stack2.isEmpty()!=true)
			{
				stack1.push(stack2.pop());
			}
			stack1.push(a);	
			
			
			
			
//			
//			int a = stack1.pop();								// storing top value of stack in a 			[ FIRST ] 
//			
//			
//			while(stack1.isEmpty()!=true)						// while stack1 is not empty push values in stack2
//			{
//				stack2.push( stack1.pop() );
//			}			
//			
//			stack2.push(a);										// pushing a in stack1
//			
//			while(stack2.isEmpty()!=true)
//			{
//				stack1.push( stack2.pop() );
//			}
//			
//			a = stack1.pop();									// [ SECOND ]
//			
//			while(stack1.isEmpty()!=true)
//			{
//				stack2.push(stack1.pop());
//			}
//			
//			stack2.push(a);
//			
//			while(stack2.isEmpty()!=true)
//			{
//				stack1.push(stack2.pop());
//			}
//			a = stack1.pop();									// [ THIRD ]
//			
//			while(stack1.isEmpty()!=true)
//			{
//				stack2.push(stack1.pop());
//			}
//			stack2.push(a);
//			
//			
//			while(stack2.isEmpty()!=true)
//			{
//			
//				stack1.push(stack2.pop());
//			}
//			// END
//					
		
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
	
	
	stk1.reverseStack(stk1, stk2); 	
	
	
	cout<<"\n AFter reversing using one stack & non array variable"<<endl;
	cout<<"Stack1: ";
	stk1.Display();
	
}
