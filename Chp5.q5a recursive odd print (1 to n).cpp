#include<iostream>
using namespace std;

void odd_print(int a)
{
	static int i = 1;					 // starting from 1st odd number
	
	if(a%2 == 0)						// to check if an input number is even so subtract 1 to make it odd
	{
		a = a - 1;
	}
	
	if(i == a)							// if i become equals to the input a then exit from the function
	{
		cout<<" "<<i;
		return;
	}
	else
	{
		cout<<" "<<i;
		i=i+2;
		odd_print(a);
			
	}
	
}
int main()
{
	odd_print(25);
}
