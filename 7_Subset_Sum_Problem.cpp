#include<bits/stdc++.h>
using namespace std;




bool subSetSum(int Array[],int sum,int n){
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
        for(int j = 1; j < sum+1; j++){

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


int main(){

    int Array[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    int n = sizeof(Array)/sizeof(0);

    cout<<subSetSum(Array,sum,n);

}