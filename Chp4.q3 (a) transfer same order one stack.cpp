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
		void transferStack(Stack &stack1, Stack &stack2, Stack &temp)     // Copies element of stack1 onto stack2
		{
			
			while(stack1.isEmpty()!=true)						// while stack2 is not empty keep on removing values
			{
				temp.push( stack1.pop() );
			}			
			
			while(temp.isEmpty()!=true )						// while stack2 is not empty OR ( stack2.isEmpty() )
			{
				stack2.push(temp.pop() );						// pushing all popped values of stack2 into stack3					
				
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
	
	Stack temp;

	
	stk1.transferStack(stk1, stk2, temp); 	
	
	
	cout<<"\n AFter transfering using one additional stack"<<endl;
	cout<<"Stack2: ";
	stk2.Display();
	
}
