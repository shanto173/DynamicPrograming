#include<bits/stdc++.h>
using namespace std;



int countSubSetSum(int Array[],int sum,int n){
    int t[n+1][sum+1];

    for (int i = 0; i < n+1; ++i)
    {
        for (int j = 0; j < sum+1; ++j)
        {
            if(i == 0){
                t[i][j] = 0;
            }
            if(j == 0){
                t[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n+1; ++i)
    {
        for (int j = 1; j < sum+1; ++j)
        {
            
            if(Array[i-1] <= j){
                t[i][j] = t[i-1][j-Array[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}



int main(){

    int Array[] = {0,0,0,0,0,1};
    // int Array[] = {2, 3, 5, 6, 8, 10}; 
    int n = sizeof(Array)/sizeof(0);
    int sum = 1;
    cout<<countSubSetSum(Array,sum,n);

}