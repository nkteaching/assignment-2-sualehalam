#include<iostream>
using namespace std;
struct node{
	
	int data;
	node *next;
}*first=NULL;

void create(int A[],int n)
{
	int i;
	node *t,*last;
	first = new node;
	first->data = A[0];
	first->next = NULL;			// Initializing address to NULL after inserting
	last = first;
	
	for(i=1;i<n;i++)
	{
		t = new node;
		t->data=A[i];
		t->next = NULL;			// Re initializing
		last->next = t;
		last = t;
	}
}
void Display(node *p)
{
	while(p!=NULL)
	{
		cout<<p->data<<" ->";
		p=p->next;
	}
}



int recursive_length(node *p)
{
	if(p == NULL)
		return 0;
	else
	{
		return recursive_length(p->next) + 1;
	}
	
}
int main()
{
	node *tmp;
	int A[]={3,5,7,10,25,8,32,2};
	create(A,8);
	
	Display(first);

	
	cout<<"\n Recursive Length of Linked list is "<<recursive_length(first);
	
	
}
