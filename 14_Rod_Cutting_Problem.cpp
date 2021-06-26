#include<bits/stdc++.h>
using namespace std;





int rodCutting(int length[],int price[],int N){
    int t[N+1][N+1];
    for (int i = 0; i < N+1; ++i)
    {
        for (int j = 0; j < N+1; ++j)
        {
            if(i == 0 or j == 0){
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < N+1; ++i)
    {
        for (int j = 1; j < N+1; ++j)
        {
            if(length[i-1] <= j){
                t[i][j] = max(price[i-1] + t[i][j-length[i-1]],t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[N][N];
}


int main(){

    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int N = sizeof(price)/sizeof(0);

    int length[N];
    for (int i = 0; i < N; ++i)
    {
        length[i] = i+1;
    }

    cout<<rodCutting(length,price,N);


}
