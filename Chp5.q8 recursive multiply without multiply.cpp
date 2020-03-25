#include<iostream>
using namespace std;
int recursive_multiply(int a,int b)			// 2, 5 
{											// 2 + ( 2 + 2 + 2 + 2 + 2)

	if(a == 0 || b == 0 )					// if any of the number is 0 so return 0 
	{
		return 0;
	}
	else
	{
	
		return a + recursive_multiply(a, b-1);				// keep adding a until b not equals 0 ( 3 + 3 + 3 + 3 +3 +3 +3 +3 )
	}
	
}
int main()
{
	int result = recursive_multiply(3,8);
	cout<<result;
}
