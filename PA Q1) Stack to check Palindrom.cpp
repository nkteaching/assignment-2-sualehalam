
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
			size=10;												// Default size = 5
			top=-1;
			stk=new T[size];										// Allocating memory at run time
		}
		Stack(int size)
		{
			this->size=size;
			
			top=-1;
			
			stk=new T[this->size];
		}
		int Length()
		{
			int count=0;
			for(int i=top;i>=0;i--)
			{
				count++;
		
			}
			return count;
		}
		
		int isEmpty()
		{
			return top==-1;
		}
		
		bool checkPalindrome(Stack &s1, string s)
		{
			char a;
			int i=0;				
			int n = s.length();
			int mid = n/2;
			for(;i<mid;i++)					// pushing only half elements 
			{
				s1.push(s[i]);
			}
			
			if(n % 2!=0)
			{
				i = i + 1;					// neglecting middle character if even length
			}
			
			while(s[i]!=NULL)
			{
				a = s1.pop();
				
				if(a != s[i])
				{
					return false;
				}
				
				i++;
				
			}
			return true;
			
			
			
// 			LOGIC 2 ( pushing string in two stacks and comparing character by character )
//
//			int size1 = s1.Length();
//			
//			Stack<char>s2(size1);
//			
//			int i=0;
//			while(s[i]!=NULL)
//			{
//				s2.push(s[i]);
//				i++;
//				
//			}
//			int flag = 0;
//			while(size1!=0)
//			{
//				char a = s1.pop();
//				char b = s2.pop();
//				if( a != b )
//				{
//					flag =1;
//					
//				}
//				
//			}
//			if(flag == 1)
//				return false;
//			else
//				return true;	
			
		}
		
		
		T pop();
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
T Stack<T>::pop()
{
	T x=-1;
	if(isEmpty())
	cout<<"Stack underlfow"<<endl;
	else
	{
	x=stk[top];
	top--;
	}
	return x;
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

int main()
{
	int i=0;
	string s;
	cout<<"Enter string to check palindrome: ";
	cin>>s;
	
	int n = s.length();
	Stack<char>stk(n);

	
	int flag = stk.checkPalindrome(stk,s);
	
	if(flag==0)
	{
		cout<<"Not palindrome";
	}
	else
	{
		cout<<"Palindrome";
	}

}
