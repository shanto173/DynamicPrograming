#include<bits/stdc++.h>
using namespace std;



vector<int> subSetSum(int Array[],int range,int n){

    int t[n+1][range+1];

    for(int i=0;i < n+1;i++){
        for(int j = 0;j<range+1;j++){
            if(i == 0){
                t[i][j] = false;
            }
            if(j == 0){
                t[i][j] = true;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<range+1;j++){

            if(Array[i-1] <= j){
                t[i][j] = t[i-1][j-Array[i-1]] or t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    vector<int> v;

    for(int i=0;i<range;i++){
        if(t[n][i] == true){
            v.push_back(i);
        }
    }
    return v;
}




int subSetSumDiff(int Array[],int n){
    int range = 0;
    for(int i = 0; i < n; i++){
        range += Array[i];
    }

    vector<int> v = subSetSum(Array,range,n);

    int mn = INT_MAX;

  

    for (int i = 0; i <= v.size(); ++i)
    {
        mn = min(mn,abs(range-2*v[i]));
    }
    return mn;
}


int main(){
    
    int arr[] = {1, 6, 11, 5};
    int n = 4;

    cout<<subSetSumDiff(arr,n);

}