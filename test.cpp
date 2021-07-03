#include<bits/stdc++.h>
using namespace std;



int countSubSetSum(int arr[],int sum,int n){
    int t[n+1][sum+1];
    for (int i = 0; i < n+1; ++i)
    {
        for (int j = 0; j < sum+1; ++j)
        {
            if(i == 0){
                t[i][j] = false;
            }
            if(j == 0){
                t[i][j] = true;
            }
        }
    }

    for (int i = 1; i < n+1; ++i)
    {
        for (int j = 1; j < sum+1; ++j)
        {
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];

}


int countOfSubSetSumDiff(int arr[],int n,int diff){
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }

    int s1 = (diff + sum)/2;
    return countSubSetSum(arr,s1,n);

}


int main(){

    int arr[] = {1, 1, 2, 3};
    int n = 4;
    int diff = 1;
    cout<<countOfSubSetSumDiff(arr,n,diff);

}
