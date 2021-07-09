#include <bits/stdc++.h>
using namespace std;
 


void minimumNumberOfInsertionDeletionToConvert_a_to_b(string a, string b, int n, int m){
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
				t[i][j] = max(t[i][j-1],t[i-1][j]);
			}
		}
	}

	cout<<"Insertion: "<< m - t[n][m]<<endl;
	cout<<"Deletion: "<< n - t[n][m]<<endl;
}



int main(){
 	
 	string a = "heap";
 	string b = "pea";

 	int n = a.size();
 	int m = b.size();

 	minimumNumberOfInsertionDeletionToConvert_a_to_b(a,b,n,m);
 	
}