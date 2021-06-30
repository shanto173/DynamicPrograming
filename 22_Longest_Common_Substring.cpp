#include<bits/stdc++.h>
using namespace std;


int longestCommonSubstring(string a,string b,int n,int m){
    int t[n+1][m+1];
    int res = 0;
    for (int i = 0; i < n+1; ++i)
    {
        for (int j = 0; j < m+1; ++j)
        {
            if(i==0 || j == 0){
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n+1; ++i)
    {
        for (int j = 1; j < m+1; ++j)
        {
            if(a[i-1] == b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
                res = max(res,t[i][j]);
            }
            else{
                t[i][j] = 0;
            }
        }
    }
    return res;
}


int main(){

    string a = "abxcde";
    string b = "cdeaos";

    int n = 6;
    int m = 6;

    cout<<longestCommonSubstring(a,b,n,m);


}
