#include<bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void convert(string s){
    int i = 0;
    stack<char> st;

    while(i < s.length()){
        if(s[i] == '('){
            st.push(s[i]);
            i++;
        }
        else if(s[i] == ')'){
            while(st.top() != '(' && !st.empty()){
                cout << st.top();
                st.pop();
            }
            st.pop();
            i++;
        }
        else if(isalnum(s[i])){
            cout << s[i];
            i++;
        }
        else{
            while(!st.empty() && prec(st.top()) >= prec(s[i])){
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
            i++;
        }
    }

    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}

int main(){
    string s;

    cout << "Enter infix : ";
    getline(cin,s);

    convert(s);

}