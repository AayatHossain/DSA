https://www.naukri.com/code360/problems/duplicate-parenthesis_2663296?leftPanelTabValue=PROBLEM

My approach: Using a stack to store the indices of opening brackets, 
and a pair to store the indices of the previous pop of both opening 
and closing brackets. If the distance between the 
current pop and the previous pop of both 
opening and closing brackets is 1, then there 
are duplicate parentheses.

Time complexity: O(n) where n is the length of the string
Space complexity: O(n) for the stack

#include <bits/stdc++.h> 
bool duplicateParanthesis(string &s)
{
    int n = s.size();
    stack<int> st;
    pair<int,int> p = {-1,-1};
    for(int i = 0; i < n; i++){
        if(s[i]=='('){
            st.push(i);
        }else if(s[i] == ')' && !st.empty()){
            if(st.top()==p.first-1
                && i==p.second+1){
                return true;
            }else{
                p = {st.top(),i};
            }
            st.pop();
        }else if(s[i]==')'){
            return false;
        }
    }
    return false;
}




#include <bits/stdc++.h> 
bool duplicateParanthesis(string &s)
{
    int n = s.size();
    stack<int> st;
    pair<int,int> p = {-1,-1};
    for(int i = 0; i < n; i++){
        if(s[i]=='('){
            st.push(i);
        }else if(s[i] == ')' && !st.empty()){
            if(st.top()==p.first-1
                && i==p.second+1){
                return true;
            }else{
                p = {st.top(),i};
            }
            st.pop();
        }else if(s[i]==')'){
            return false;
        }
    }
    return false;
}


Approach 2: Using stack
Time complexity: O(n)
Space complexity: O(n) for the stack

#include <bits/stdc++.h> 
bool duplicateParanthesis(string &s)
{
    int n = s.size();
    stack<char> st;
    for(int i = 0; i < n; i++){
        if(s[i]==')'){
            int cnt = 0;
            while(!st.empty() && st.top()!= '('){
                cnt++;
                st.pop();
            }
            st.pop();

            if(cnt==0)return true;
        }else{
            st.push(s[i]);
        }
    }
}






