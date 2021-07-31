#include <bits/stdc++.h>
using namespace std;
 


bool isPalindrome(string s,int i,int j){
	while(j > i){
		if(s[i++] != s[j--]){
			return false;
		}
	}
	return true;
}


int palindromePartitionRecursive(string s, int i, int j){
	// Base condition
	/* s = " "               
	   partiton = 0;
	   and s = "a"
	   partition = 0
	*/
	if(i >= j){
		return 0;  
	}

	/*
		s = "abcba";
		partition = 0
		because the whole string is palindrome 
	*/


	if(isPalindrome(s,i,j)){
		return 0;
	}
	// k loop scheme
	int mn = INT_MAX;
	for (int k = i; k <= j-1; ++k)
	{
		int tempAns = 1 + palindromePartitionRecursive(s,i,k)+
						  palindromePartitionRecursive(s,k+1,j);
        
       	mn = min(mn,tempAns);
	}
	return mn;
} 




int main(){
 	
	string s = "geek";

	int n = s.size();

	cout<<palindromePartitionRecursive(s,0,n-1);
}