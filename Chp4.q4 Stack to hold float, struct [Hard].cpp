#include <iostream>
using namespace std;
template<class T>												// Using class templates for stack
class Stack
{
	private:
		T *stk;
		int size;
		int top;
	public:
		Stack() 
		{
			size=5;												// Default size = 5
			top=-1;
			stk=new T[size];										// Allocating memory at run time
		}
		Stack(int size)
		{
			this->size=size;
			
			top=-1;
			
			stk=new T[this->size];
		}
		
		void push(T x);
		int isFull();
		void Display();
};

template<class T>
void Stack<T>::push(T x)											// Any thing can be pushed, int , float, char, struct
{
	if(isFull())
		cout<<"Stack FULL"<<endl;
	else
	{
		top++;
		stk[top]=x;
	}
}


template<class T>
int Stack<T>::isFull()
{
	return top==size-1;										// since top starts from 0 . so if top == size -1 FULL
}


template<class T>
void Stack<T>::Display()
{
	for(int i=top;i>=0;i--)
	{

		cout<<stk[i]<<" ";
	}
	cout<<endl;
}

struct name{
	
	string fn;
	string ln;
	
}s2;
int main()
{
	Stack<char> stk(3);
	stk.push('x');
	stk.push('z');
	stk.Display();
	
	Stack<float> stkf(2);
	stkf.push(3.142);
	stkf.push(99.999);
	stkf.Display();
	cout<<endl;
	
	cout<<"Enter first name: ";
	cin>>s2.fn;
	cout<<"Enter last name: ";
	cin>>s2.ln;
	
	

	Stack<string> data(2);									// Holding individual datamembers of struct in stack
	data.push(s2.fn);
	data.push(s2.ln);
	data.Display();

	Stack<name> stkstruct;									// Holding complete struct  in stack
	stkstruct.push(s2);										
	

}
