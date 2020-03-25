#include<iostream>
using namespace std;
void reverse()
{
	int ch;										// ERROR wrong datatype ( cannot compile ). It should be char ch in order to reverse input
	cin.get(ch);
	if(ch!='\n')
		reverse();
	cout.put(ch);	
}
int main()
{
	reverse();																
}
