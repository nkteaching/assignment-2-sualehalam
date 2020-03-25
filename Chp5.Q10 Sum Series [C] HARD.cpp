// 1 + 1/2 - 1/3 + 1/4 - 1/5 ...

#include<iostream>
using namespace std;

float sumseries(int n, float sum)
{
	static int size = 1;
	static double i = 2;												// because 1/2 , 1/3 .. and so on
	
	if (size!= n)
	{
		if(size%2 != 0)													// starting from 1st element so  odd -
		{
			size++;
			return sumseries(n, sum+ (1/i++) );
		}
		else															// If even +
		{
			size++;
			return sumseries(n, sum- (1/i++) );
		}
		
	}
	else
	{
		return sum;
	}
	
}
int main()
{
	int n;
	cout<<"Enter n: ";
	cin>>n;
	float sum =	sumseries(n,1.0);
	cout<<sum;
}
