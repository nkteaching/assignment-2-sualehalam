// http://www.chanduthedev.com/2013/11/cube-of-a-number-using-recursion-in-c.html
#include<iostream>
using namespace std;

int i=2;
int cube(int a)
{
	if(i==0)									
	{
		return a;
	}
	else
	{
		i--;
		return cube(a) * a;						// if returns cube(a*a)		it returns the 4th power of a a number
	}
}
int main()
{
	int a = cube(2);
	cout<<a;
}
