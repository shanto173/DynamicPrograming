#include <bits/stdc++.h>
using namespace std;
 


string printShortestCommonSuperSequence(string a,string b,int n,int m){

	int t[n+1][m+1];
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < m+1; ++j)
		{
			if(i == 0 || j == 0){
				t[i][j] = 0;
			}
		}
	}

	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < m+1; ++j)
		{
			if(a[i-1] == b[j-1]){
				t[i][j] = 1 + t[i-1][j-1];
			}
			else{
				t[i][j] = max(t[i-1][j],t[i][j-1]);
			}
		}
	}

	int i = n,j = m;
	string s = "";


	while(i > 0 and j > 0){

		if(a[i-1] == b[j-1]){
			s.push_back(a[i-1]);
			i--;
			j--;
		}	
		else{
			if(t[i][j-1] > t[i-1][j]){
				s.push_back(b[j-1]);
				j--;
			}
			else{
				s.push_back(a[i-1]);
				i--;
			}
		}
	}

	/*  Now if the before while loop breaks because of i == 0 or j == 0
	    so the rest of the string we have to add in the string so in that the case 
		the code will be 

		a = "ac"
		b = "" 
		so the scss = s.puhs_back("ac")

	*/

	while(i > 0){
		s.push_back(a[i-1]);
		i--;
	}
	while(j > 0){
		s.push_back(b[j-1]);
		j--;
	}

	reverse(s.begin(),s.end());
	return s;
}


int main(){
 	
	string a = "abac";
	string b = "cab";

	int n = a.size();
	int m = b.size();


	cout<<printShortestCommonSuperSequence(a,b,n,m);
}