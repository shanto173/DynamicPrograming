#include<bits/stdc++.h>
using namespace std;


int static t[1001][1001];

int longestCommonSubsequence(string x,string y,int n,int m){
    if(n == 0 || m == 0){
        return 0;
    }   
    if(t[m][n] != -1){
        return t[m][n];
    }
    if(x[n-1] == y[m-1]){
        return t[m][n] = 1+longestCommonSubsequence(x,y,n-1,m-1);
    }
    else{
        return t[m][n] = max(longestCommonSubsequence(x,y,n,m-1),
                            longestCommonSubsequence(x,y,n-1,m));
    }

}


int main(){
    memset(t,-1,sizeof(t));
    string x = "abcdgh";
    string y = "abedfhr";
    int n = x.size();
    int m = y.size();

    cout<<longestCommonSubsequence(x,y,n,m);
   
   
}
