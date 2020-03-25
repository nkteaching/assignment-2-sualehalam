#include<iostream>
using namespace std;
void tail(int i)
{
	if(i > 0)
	{
	
		cout<<i<<" ";
		tail(i-1);
	}	
}
void nontail(int i)						// HARD RECURSION
{
	if(i>0)
	{
		nontail(i-1);
		cout<<i<<" ";
		nontail(i-1);
	}
	
}
int main()
{
//	tail(0);
//	nontail(0);							// NO OUTPUT

//	tail(2);							// 2 1
	
//	nontail(2);							// VERY HARD  1 2 1

//	tail (4);							// 4 3 2 1

	nontail(4);
	
	
}
