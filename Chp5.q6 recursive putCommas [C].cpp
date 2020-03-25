#include<iostream>
using namespace std;
void putCommas(int a)
{
	if(a< 1000)
	{
		cout<<a;
	}
	else
	{
		int b = a % 1000;									// storing the remainders in b
		putCommas(a/1000);									// each recursive call reduces number by 1000
		cout<<","<<b;
	}
	
}
int main()
{	
	int n;
	cout<<"Enter a positive integer:  ";
	cin>>n;
	putCommas(n);
	
//	putCommas(1234567);
}
