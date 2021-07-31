#include<bits/stdc++.h>
using namespace std;


int evaluateExpressionTrueRecursive(string s,int i,int j, bool isTrue){

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

    int ans = 0;
    for (int k = i+1; k <= j-1; k = k+2)
    {
        
        int LT = evaluateExpressionTrueRecursive(s,i,k-1,1);
        int LF = evaluateExpressionTrueRecursive(s,i,k-1,0);
        int RT = evaluateExpressionTrueRecursive(s,k+1,j,1);
        int RF = evaluateExpressionTrueRecursive(s,k+1,j,0);

        if(s[k] == '&'){
            if(isTrue == true){
                ans = ans + (LT*RT); 
            }
            else{
                ans = ans + (LF*RT) + (LT * RF) + (LF*RF);
            }
        }

        else if(s[k] == '|'){
            if(isTrue == true){
                ans = ans + (LT*RF) + (LF*RT) + (LT*RT);
            }
            else{
                ans = ans + (LF*RF);
            }
        }
        else if(s[k] == '^'){
            if(isTrue == true){
                ans = ans + (LT*RF) + (LF*RT);
            }
            else{
                ans = ans + (LT*RT) + (LF*RF);
            }
        }
    }
    return ans;
}


int main(){
    
    string symbols = "TTFT";
    string operators = "|&^";

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

    cout<<evaluateExpressionTrueRecursive(s,0,n-1,1);



}