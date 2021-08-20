#include<bits/stdc++.h>
using namespace std;


int static t[1001][1001][2];

int solve(string s,int i,int j,bool isTrue){

    // Base condititon 
    if(i > j){
        return false;
    }

    if(i == j){
        if(isTrue == true){
            return s[i] == 'T';
        }
        else{
            return s[i] == 'F';
        }
    }
    if(t[i][j][isTrue] != -1){
        return t[i][j][isTrue];
    }
    int ans = 0;
    for (int k = i+1; k <= j-1; k+=2)
    {
        int LT; 
        int LF;
        int RT; 
        int RF;

        if(t[i][k-1][1] != -1){
            LT = t[i][k-1][1];
        }
        else{
            LT = solve(s,i,k-1,1);
        }

        if(t[i][k-1][0] != -1){
            LF = t[i][k-1][0];
        }
        else{
            LF = solve(s,i,k-1,0);
        }

        if(t[k+1][j][1] != -1){
            RT = t[k+1][j][1];
        }
        else{
            RT = solve(s,k+1,j,1);
        }

        if(t[k+1][j][0] != -1){
            RF = t[k+1][j][0];
        }
        else{
            RF = solve(s,k+1,j,0);
        }

        


        if(s[k] == '&'){
            if(isTrue == true){
                ans += (LT*RT);
            }
            else{
                ans += (LF*RT) + (LT*RF) + (LF*RF);
            }
        }
        else if(s[k] == '|'){
            if(isTrue == true){
                ans += (LT*RT) + (LF*RT) + (LT*RF);
            }
            else{
                ans += (LF*RF);
            }
        }
        else if(s[k] == '^'){
            if(isTrue == true){
                ans += (LF*RT) + (LT*RF);
            }
            else{
                ans += (LF*RF) + (LT*RT);
            }
        }

    }
    return t[i][j][isTrue] = ans;
} 




int main(){
    memset(t,-1,sizeof(t));
    string symbols = "TTF";
    string operators = "&^";

    string s;
    int j = 0;

    for (int i = 0; i < symbols.size(); ++i)
    {

        s.push_back(symbols[i]);
        if(j < operators.size()){
            s.push_back(operators[j++]);
        }
    }

    int n = s.size();

    cout<<solve(s,0,n-1,1);


}