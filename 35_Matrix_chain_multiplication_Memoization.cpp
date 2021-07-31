#include <bits/stdc++.h>
using namespace std;
 
// Matrix chain multiplcation memoization
int static t[1001][1001];

int matrixChainMultiplicationMemoization(int arr[],int i,int j){
	
	// Base condition
	if(i >= j){
		return 0;
	}
	if(t[i][j] != -1){
		return t[i][j];
	}
	int mn = INT_MAX;
	for (int k = i; k <= j-1; ++k)
	{
		int tempAns = matrixChainMultiplicationMemoization(arr,i,k)+
					  matrixChainMultiplicationMemoization(arr,k+1,j)+
					  arr[i-1] * arr[k] * arr[j];

		mn = min(mn,tempAns);
	}
	return t[i][j] = mn;
}



int main(){
 	
	int arr[] = {10, 20, 30, 40, 30};
	
	memset(t,-1,sizeof(t));
	
	int n = sizeof(arr)/sizeof(0);

	cout<<matrixChainMultiplicationMemoization(arr,1,n-1);
}