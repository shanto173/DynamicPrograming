#include<bits/stdc++.h>
using namespace std;





int coinChangeMinNumOfCoins(int coin[],int sum,int n){
    long long t[n+1][sum+1];

    for (int i = 0; i < n+1; ++i)
    {
        for (int j = 0; j < sum+1; ++j)
        {
            if(i == 0){
                t[i][j] = INT_MAX-1;
            }
            if(j == 0){
                t[i][j] = 0;
            }
           
        }
    }
    for (int i = 1; i < sum+1; ++i)
    {
        if(i % coin[0] == 0){
            t[1][i] = i/coin[0];
        }
        else{
            t[1][i] = INT_MAX-1;
        }
    }

    for (int i = 2; i < n+1; ++i)
    {
        for (int j = 1; j < sum+1; ++j)
        {
            if(coin[i-1] <= j){
                t[i][j] = min(t[i][j-coin[i-1]]+1, t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}



int main(){


    int coin[] = {1, 2, 3};
    int n = 3;
    int sum = 5;

    cout<<coinChangeMinNumOfCoins(coin,sum,n);
 
}
