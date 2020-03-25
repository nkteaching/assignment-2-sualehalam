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
	cin>>s;
	
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
