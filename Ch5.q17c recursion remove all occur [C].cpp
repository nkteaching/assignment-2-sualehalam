
#include <string.h>
#include<iostream>
using namespace std;
 
void deletechar(char *s,char c)
{
	static int i=0,k=0;
 
     if(s[i] == NULL)													// if ( !s[i] )
     {
	    return;															// exit from function
	 }
	 else
	 {
	 	s[i]=s[i+k];
 
     	
     	if(s[i]==c)
     	{
		  k++;
		  i--;
	    }
	    i++;
	    deletechar(s,c);
	 	
	 } 
	   
  	 
}
 
int main()
{
    char s[100];
    char c;
  
    cout<<"Enter string: ";
    cin>>s;
    cout<<"Enter character: ";
    cin>>c;
    
    deletechar(s,c);
    
    cout<<s;
}
