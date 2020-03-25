#include<iostream>
#include<string.h>
using namespace std;
bool checkString(char *s, char a)
{
	
	if(*s == NULL)
		return false;
	else if (*s == a)
	{
		return true;
	}
	else
		return checkString(s+1,a);						// progressing character forward in string through recursive call
			
}
int main()
{
	int a = checkString("help",'l');
	
	if(a==0)
		cout<<"Not found";
	else
		cout<<"Found";
}
