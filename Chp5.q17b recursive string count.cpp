#include<iostream>
using namespace std;
int count(char *s, char a)
{
	static int i = 0;
	
	if(*s == NULL)
		return i;
	else if(*s == a)
	{
		i++;
	}
	
	return count(s+1,a );					// progressing character forward
	
	return i;	
}
int main()
{
	int a = count("hello",'l');
	cout<<a;
}
