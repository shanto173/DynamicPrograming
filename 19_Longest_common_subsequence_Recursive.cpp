#include<bits/stdc++.h>
using namespace std;




int longestCommonSubsequence(string x,string y,int n,int m){
    if(n == 0 || m == 0){
        return 0;
    }
    if(x[n-1] == y[m-1]){
        return 1+longestCommonSubsequence(x,y,n-1,m-1);
    }
    else{
        return max(longestCommonSubsequence(x,y,n,m-1),
                    longestCommonSubsequence(x,y,n-1,m));
    }
}


int main(){

    string x = "abcdgh";
    string y = "abedfhr";
    int n = x.size();
    int m = y.size();

    cout<<longestCommonSubsequence(x,y,n,m);
   
   
}
