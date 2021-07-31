#include <bits/stdc++.h>
using namespace std;
 
int static t[1001][1001];

bool isPalindrome(string s,int i,int j){
	while(j > i){
		if(s[i++] != s[j--]){
			return false;
		}
	}
	return true; 
}


int palindromePartitionMemoization(string s,int i,int j){
	if(i >= j){
		return 0;
	}
	if(isPalindrome(s,i,j)){
		return 0;
	}
	if(t[i][j] != -1){
		return t[i][j];
	}
	int mn = INT_MAX;
	for (int k = i; k <= j-1; ++k)
	{
		int tempAns = 1+palindromePartitionMemoization(s,i,k)+
						palindromePartitionMemoization(s,k+1,j);
		mn = min(mn,tempAns);
	}
	return t[i][j] = mn;
}


int optimizedPalindromePartitionMemoization(string s,int i,int j){
	if(i >= j){
		return 0;
	}
	if(isPalindrome(s,i,j)){
		return 0;
	}
	if(t[i][j] != -1){
		return t[i][j];
	}
	int mn = INT_MAX;
	int left,right;
	for (int k = i; k <= j-1; ++k)
	{
		if(t[i][k] != -1){
			left = t[i][k];
		}
		else{
			left = optimizedPalindromePartitionMemoization(s,i,k);
			t[i][k] = left;
		}
		if(t[k+1][j] != -1){
			right = t[k+1][j];
		}
		else{
			right = optimizedPalindromePartitionMemoization(s,k+1,j);
			t[k+1][j] = right;
		}
		int tempAns = 1+left+right;
		mn = min(mn,tempAns);
	}
	return t[i][j] = mn;
}




int main(){
 	memset(t,-1,sizeof(t));

	string s = "nitik";
	
	// cout<<palindromePartitionMemoization(s,0,s.size()-1);
	cout<<optimizedPalindromePartitionMemoization(s,0,s.size()-1);
	
}