#include<bits/stdc++.h>
using namespace std;




int unboundedKnapSack(int val[],int wt[],int W,int n){
    int t[n+1][W+1];
    for (int i = 0; i < n+1; ++i)
    {
        for (int j = 0; j < W+1; ++j)
        {
            if(i == 0 or j == 0){
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n+1; ++i)
    {
        for (int j = 1; j < W+1; ++j)
        {
            if(wt[i-1] <= j){
                t[i][j] = max(val[i-1] + t[i][j-wt[i-1]], t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][W];
}



int main(){

  int val[] = {1,30};
  int wt[] = {1,50};
  int W = 100;
  int n = 2;
  cout<<unboundedKnapSack(val,wt,W,n);

}
