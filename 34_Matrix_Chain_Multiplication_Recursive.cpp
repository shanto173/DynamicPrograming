#include <bits/stdc++.h>
using namespace std;
 

/*
	arr[i-1]*arr[k]*arr[j];

	40 20 30 10 30
	|      |     |
	i      k     j

	in this case the matrix would be this 
	
	(i to K)        (k+1 to j)
		|				|
	(40*20)(20*30)   (30*10)(10*30)
	 
	 so the requred matrix is 

	 	(40*30)        (30*30)
	 			| 

	 			40 * 30 * 30

	so the array postion 40 is (i-1) and 30 is (k) and 30 is (j)
	so the formula is: arr[i-1]*arr[k]*arr[j] 


*/



int matrixChainMultiplicationRecursive(int arr[],int i,int j){

	int mn = INT_MAX;
	// Base condition
	if(i >= j){
		return 0;
	}

	// write K loop scheme

	for (int k = i; k <= j-1; k++)
	{
		int tempAns = matrixChainMultiplicationRecursive(arr,i,k)+
					  matrixChainMultiplicationRecursive(arr,k+1,j)+
					  arr[i-1]*arr[k]*arr[j];
		mn = min(mn,tempAns);
	}
	return  mn;
}






int main(){
 	

	int arr[] = {10, 20, 30, 40, 30};
	int n = sizeof(arr)/sizeof(0);
	cout<<matrixChainMultiplicationRecursive(arr,1,n-1);
	
}