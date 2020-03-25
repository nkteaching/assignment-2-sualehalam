#include<iostream>
using namespace std;
class Node
{
	public:
	char data;
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
		void push(int x);
		char pop();
		void Display();
		
		bool isEmpty()
		{
			return top == NULL;										// returns a boolean
		}
		
		bool ParenthesisChecker(string s)
		{
			char pair;
			
			for(int i =0 ;i< s.length() ;i++)
			{
				if(s[i] == '{' || s[i] == '[' || s[i] == '(' )
				{
					push(s[i]);
				}
				
				if(isEmpty())				// if only a single '{' or '[' or '(' so not BALANCED PARENTHESIS so if stacks empty false
				{
					return false;
				}
				
				if( s[i] == ')' )
				{
					pair = pop();											// Storing the older parenthesis ' ( '
					
					if(pair == '{' || pair =='[') 
					{
						return false;
					}
					
				}
				else if (s[i] == '}')
				{
					pair = pop();											// Retrieving previous bracket ' } '
					
					if(pair == '[' || pair =='(')							// if retrieved is different from ' } ' return false
					{
						return false;
					}
				}
				else if(s[i] == ']')
				{
					pair = pop();
					
					if(pair == '(' || pair == '{')
					{
						return false;
					}
				}
			}
			
			return isEmpty();								// If stack is empty so BALANCED else stacknotempty UNBALANCEDs
			
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
char Stack :: pop()
{
	char x = 'x';				// to denote stack is empty
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
	
	string s = "{25+(3–6)*8}";											// Even space is counted as character so no spaces given


	if(stk.ParenthesisChecker(s))										// if returns 1
	{
		cout<<"Balanced Parenthesis and MATCHING SYMBOLS";
	}
	else
	{
		cout<<"Unbalanced Parenthesis and UNMATCHED SYMBOLS";
	}
	
	
}
