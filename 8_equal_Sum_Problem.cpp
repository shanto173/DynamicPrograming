#include<bits/stdc++.h>
using namespace std;



bool subSetSum(int Array[],int sum,int n){
    int t[n+1][sum+1];
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < sum+1; j++){
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
            if(Array[i-1] <= j){
                t[i][j] = t[i-1][j-Array[i-1]] or t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

bool equalSumPartition(int Array[],int n){
    int sm = 0;
    for (int i = 0; i < n; ++i)
    {
        sm += Array[i];
    }
    if(sm%2 != 0){
        return false;
    }

    if(sm%2 == 0){
        int sum = sm/2;
        return subSetSum(Array,sum,n);
    }
    return false;
}


int main(){

    int Array[] = {1, 5, 11, 5};

    int n = sizeof(Array)/sizeof(0);

    cout<<equalSumPartition(Array,n);

}