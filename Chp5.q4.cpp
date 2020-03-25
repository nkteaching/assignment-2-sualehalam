#include<iostream>
using namespace std;
void reverse()
{
	static char ch;
	cin.get(ch);
	if(ch!='\n')
		reverse();
	cout.put(ch);	
}
int main()
{
	reverse();													// displays input plus 3 additonal spaces
}
