#include<iostream>

using namespace std;

class Node
{
	public:
	int data;
	Node *next;
}*front=NULL,*rear=NULL;

template<class T>
class Queue{
	
	public:
		Queue()
		{
			front = NULL;
			rear = NULL;
		}

			void enqueue(T x);		
			T dequeue();
			
			void Display()
			{
				Node *p=front;
				while(p!=NULL)
				{
					cout<<p->data<<" ";
					p=p->next;
				}
				cout<<endl;
			}
			bool isEmpty()
			{
				if(front == NULL)
				{
					return true;
				}
				else
					return false;
				
			}
			int peek()											// CANNOT DEFINE TEMPLATE FUNCTION IN CLASS
			{
				if(isEmpty()==true)
				{
					cout<<"Queue is empty";
					return -1;
				}
				else
				{
					return front->data;
				}
				
			}
						
};

template<class T>
T Queue <T>::dequeue()
{
				T x = -1;
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
template<class T>
void Queue<T> :: enqueue(T x)
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



//
template <class T>												// Template class
class StackQ{
	
	Queue <T> pool;
	int size;
	
	public:
		StackQ()
		{
			size = 10;
		}
		bool isStackEmpty()
		{
			return pool.isEmpty();								// both are similar
		}
		void push(T x)											// can push anydata type
		{
			
			pool.enqueue(x);
			
			size++;
		}
		T pop()														// can pop float char anything
		{
			if(isStackEmpty()==true)	
			{
				cout<<"Stack Empty";
				return -1;
			}
			else
			{
				size--;
				return	pool.dequeue();								// can return anything
			}
		}
		void Display()
		{
			while(isStackEmpty()!=true)
			{		
				cout<< pool.dequeue()<<" ";
			}
			
		}
		
	
};

int main()
{
	StackQ <int> s1;
	s1.push(1000);
	s1.push(5000);
	s1.push(4000);
	s1.Display();
	
	cout<<endl;
	
	StackQ <float> f;
	f.push(5.0);
	f.Display();
}
