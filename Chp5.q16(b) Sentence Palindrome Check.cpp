#include<iostream>
#include<bits/stdc++.h> 						// to use transform function
using namespace std;

bool isPalindrome(string s, int start, int end)
{
	
	if( s[start] == s[end]   ) 									// If equal proceed to next character
	{
		isPalindrome(s,++start,--end);
	}
	else
	{
		return false;
	}
	
	return true;
}
int main()
{
	string s;
	cout<<"Enter string to check if Palindrome or not: ";			
	getline(cin,s);
	
	transform(s.begin(), s.end(), s.begin(), ::tolower); 		// converting whole sentence into lowercase
	
	int i = 0;
	int count = 0;
	
	while(s[i]!=NULL)											// removing whitespaces and punctuations from the sentence
	{
		if(s[i] != ' ' || s[i]!= ',' || s[i]!= '!' || s[i]!= '?' || s[i]!= ':' )
		{
			s[count] = s[i];									// storing all characters except punctuations or space
			count++;
		}
		
		i++;
	}
	s[count] = '\0';
	
	
	int length = s.length() - 1;					 			 // to find the last element of string
	
	if( isPalindrome(s,0,length) == 0 )
	{
		cout<<"Not Palindrome";
	}
	else
	{
		cout<<"Palindrome";
	}
}
