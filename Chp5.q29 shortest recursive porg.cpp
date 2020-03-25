#include<iostream>
using namespace std;

int shortest(int i)
{
	if(i == i)
		return i;
		
	shortest(10);
}
int main()
{
	int a = shortest(2);
}
