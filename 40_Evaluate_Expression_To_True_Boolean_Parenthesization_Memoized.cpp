#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int evaluateExpressionTrueMemoized(string s,int i,int j,bool isTrue){

    if(i > j){        // Base condition if string is empty then return false
        return false;
    }
    /*
        if string has one character then i and j point same char
        so that if it is true then if its match with isTrue then return true
        othewise return false
    */
    if(i == j){   

        if(isTrue == true){
            return s[i] == 'T';
        }
        else{
            return s[i] == 'F';
        }
    }
    // creating a temp string 
    // Temp format is (i j isTrue)
    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));
    if(mp.find(temp) != mp.end()){ // if value is already present then return
        return mp[temp];
    }  

    int ans = 0;

    for (int k = i+1; k <= j-1; k = k+2)
    {
        /*
            creating an four variable
            why four 
            -------------
              |   |   |
        left(T,F)  k right(T,F)

            here we just need to find # of ways if true;
            here has a especial case the xor case
            xor true
            T  xor T = false
            F xor  F = false
            T xor F = true
            F xor T = true

            here T and F both we have to count how many # of true and false
            if no. of ways true is 2 then false iss 4
            the no. of ways true is (2*4) = 8 ways
            thats is left exp has T and F and right has T and F

        */
        int LT = evaluateExpressionTrueMemoized(s,i,k-1,1);
        int LF = evaluateExpressionTrueMemoized(s,i,k-1,0);
        int RT = evaluateExpressionTrueMemoized(s,k+1,j,1);
        int RF = evaluateExpressionTrueMemoized(s,k+1,j,0);



        if(s[k] == '&'){
            if(isTrue == true){
                ans = ans + (LT*RT);
            }
            else{
                ans = ans + (LT*RF) + (LF*RT) + (LF * RF);
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
                ans = ans + (LF*RT) + (LT*RF);
            }
            else{
                ans = ans + (LF*RF) + (LT*RT);
            }
        }
    }
    return mp[temp] = ans;
}


int main(){
    mp.clear();
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

    cout<<evaluateExpressionTrueMemoized(s,0,n-1,1);



}