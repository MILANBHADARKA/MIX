// //postfix

// #include <bits/stdc++.h>
// using namespace std;

// int prec(char c)
// {
//     if (c == '^')
//     {
//         return 3;
//     }
//     else if (c == '*' || c == '/')
//     {
//         return 2;
//     }
//     else if (c == '+' || c == '-')
//     {
//         return 1;
//     }
//     else
//     {
//         return -1;
//     }
// }

// void postfix(string s1)
// {
//     stack<char> c;

//     int i;
//     for (i = 0; i < s1.length(); i++)
//     {

//         if (s1[i] == '(')
//         {
//             c.push(s1[i]);
//         }
//         else if (s1[i] == ')')
//         {
//             while (c.top() != '(' && !c.empty())
//             {
//                 cout << c.top();
//                 c.pop();
//             }
//             c.pop();
//         }
//         else if (isalnum(s1[i]))
//         {
//             cout << s1[i];
//         }
//         else
//         {
//             while (!c.empty() && prec(c.top()) >= prec(s1[i]))
//             {
//                 cout << c.top();
//                 c.pop();
//             }
//             c.push(s1[i]);
//         }
//     }

//     while (!c.empty())
//     {
//         cout << c.top();
//         c.pop();
//     }
// }

// int calc(int a,int b, char c){
//     if(c == '+') return a+b;
//     else if(c == '-') return a-b;
//     else if(c == '*') return a*b;
//     else if(c == '/') return a/b;
//     else if(c == '^') return pow(a,b);
//     else return -1;
// }

// void evelutionprefix(string s1){
//     stack<int> c;

//     int i;
//     int ans=0;
//     for(i = 0; i<s1.length(); i++){
//         if(isdigit(s1[i])){
//             c.push(s1[i]-48);
//         }
//         else{
//             int b = c.top();
//             c.pop();
//             int a = c.top();
//             c.pop();

//             ans = calc(a,b,s1[i]);
//             c.push(ans);
//         }
//     }

//     cout << c.top();

// }

// int main(int argc, char const *argv[])
// {
//     string s1;

//     cout << "Enter Expression : ";
//     getline(cin,s1);

//     evelutionprefix(s1);

//     // postfix(s1);

//     return 0;
// }



//now prefix

#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

// Function to convert infix to prefix
string infixToPrefix(string s1) {
    stack<char> c;
    string result;

    for (int i = s1.length() - 1; i >= 0; i--) {
        if (s1[i] == ')') {
            c.push(s1[i]);
        } else if (s1[i] == '(') {
            while (!c.empty() && c.top() != ')') {
                result += c.top();
                c.pop();
            }
            c.pop();
        } else if (isalnum(s1[i])) {
            result += s1[i];
        } else {
            while (!c.empty() && prec(c.top()) > prec(s1[i])) {
                result += c.top();
                c.pop();
            }
            c.push(s1[i]);
        }
    }

    while (!c.empty()) {
        result += c.top();
        c.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int calc(int a, int b, char c) {
    if (c == '+') return a + b;
    else if (c == '-') return a - b;
    else if (c == '*') return a * b;
    else if (c == '/') return a / b;
    else if (c == '^') return pow(a, b);
    else return -1;
}

void evaluationPrefix(string s1) {
    stack<int> c;

    for (int i = s1.length() - 1; i >= 0; i--) {
        if (isdigit(s1[i])) {
            c.push(s1[i] - '0'); // Convert char to int
        } else {
            int a = c.top(); c.pop();
            int b = c.top(); c.pop();
            int ans = calc(a, b, s1[i]);
            c.push(ans);
        }
    }

    cout << "Result: " << c.top() << endl;
}

int main() {
    string s1;

    cout << "Enter Expression: ";
    getline(cin, s1);

    // string prefixExpr = infixToPrefix(s1);
    // cout << "Prefix Expression: " << prefixExpr << endl;

    evaluationPrefix(s1);

    return 0;
}