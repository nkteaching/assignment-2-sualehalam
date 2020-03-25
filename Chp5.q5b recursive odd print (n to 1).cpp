#include<iostream>
using namespace std;
int odd_print(int n)
{
	if(n==1)
	{
	
		cout<<"1 ";
		return 0 ;
	}
	
	if(n%2!=0)
	{
		cout<<n<<" ";
		odd_print(n-2);
	}
	else
		odd_print(n-1);
}
int main()
{
	odd_print(13);
}
