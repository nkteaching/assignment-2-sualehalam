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
			return top == NULL;									// returns true when stack is empty
			
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
	
		int peek()
		{
			if(!isEmpty())
				return top->data;
			else
			{
				cout<<"Stack underflow";
				return -1;
			}
		}
		void addingLargeNumbers(Stack &s1, Stack &s2, Stack &result)
		{
			long long int carry = 0;
			Stack s3,s4;
			while(s1.isEmpty()!=true)
			{
				s3.push(s1.pop() );
			}
			while(s2.isEmpty()!=true)										// To revert them to original form
			{
				s4.push(s2.pop());
			}
			
			while(s3.isEmpty()!=true || s4.isEmpty()!=true)
			{
				carry = carry + s3.pop() + s4.pop();
				
				if(s3.peek() == -1 || s4.peek() == -1)						// if one number > then other number
				{
					break;
				}
			}
			if(carry > 9)													// pushing unit part on result stack
			{
				int d = carry %10;
				result.push(d);
				d=d/10;
				
			}
			else
			{
				result.push(carry);
				carry = 0;
			}
			
			if(carry!=0)
				result.push(carry);
			
			
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
	Stack stk;
	Stack stk2;
	Stack result;
	
	long long int n1,n2;
	cout<<"Enter first number";
	cin>>n1;
	
	while(n1!=0)
	{
		stk.push(n1%10);
		n1=n1/10;
	}
	cout<<"Enter second number";
	cin>>n2;
	while(n2!=0)
	{
		stk2.push(n2%10);
		n2=n2/10;
	}
	
	stk.Display();
	stk2.Display();	
	
	stk.addingLargeNumbers(stk,stk2,result);
	
	cout<<"After adding large numbers"<<endl;
	result.Display();
	
}
