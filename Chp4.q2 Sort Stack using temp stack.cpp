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
		
		int peek()
		{
			if(!isEmpty())
				return top->data;
			else
				exit(1);
			
		}
		
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
		void SortAscendingStack(Stack &stk1, Stack &stk2)     // Copies element of stack1 onto stack2
		{
			int temp = 0;
			
			while(stk1.isEmpty() != true)						// while stack2 is not empty keep on removing values
			{
				temp = stk1.pop();
				
				while(stk2.isEmpty() != true && temp > stk2.peek() ) 		// while stack2 is not empty and stack2 elements greater than temp
				{
					stk1.push(stk2.pop());
				}
				stk2.push(temp);
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
	Stack stk2;
	
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
	
	stk1.SortAscendingStack(stk1,stk2); 	
	
	cout<<"\n AFter arranging in ascending order using one stack"<<endl;
	cout<<"Stack1: ";
	stk2.Display();

	
}
