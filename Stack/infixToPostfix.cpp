#include <iostream>
#include <stack>
using namespace std;
int precedence(char c){
    if(c   == '^'){
        return 3;
    }
    if( c == '*' || c == '/'){
        return 2;
    }
    if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}
string infixtopostfix(string s){
    stack<char>s1;
    string newone;
    for(int i = 0 ;i<s.length();i++){
        if((s[i] >= 'a'  && s[i] <= 'z') || (s[i] >= 'A' && s[i]<= 'z')){
            newone +=s[i];
        }
        else if(s[i] == '('){
            s1.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!s1.empty()&&s1.top() == '('){
                newone += s1.top();
                s1.pop();
            }
            if(!s1.empty()){
                s1.pop();
            }
        }
        else {  
            while(!s1.empty()&& precedence(s1.top()) > precedence(s[i])){
                    newone += s1.top();
                    s1.pop();
                }
                s1.push(s[i]);
            
        }
    }
    while(!s1.empty()){
        newone += s1.top();
        s1.pop();
    }
    return newone;
}
int main()
{
    cout <<infixtopostfix("A/(B+C*D-E)") << endl;
    return 0;
}
// int preced(char c)
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
// string infixToPostfix(string s)
// {
//     stack<char> st;
//     string res;
//     for (int i = 0; i < s.length(); i++)
//     {
//         if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
//         {
//             res += s[i];
//         }
//         else if (s[i] == '(')
//         {
//             st.push(s[i]);
//         }
//         else if (s[i] == ')')
//         {
//             while (!st.empty() && st.top() != '(')
//             {
//                 res += st.top();
//                 st.pop();
//             }
//             if (!st.empty())
//             {
//                 st.pop();
//             }
//         }
//         else
//         {
//             while (!st.empty() && preced(st.top()) > preced(s[i]))
//             {
//                 res += st.top();
//                 st.pop();
//             }
//             st.push(s[i]);
//         }
//     }
//     while (!st.empty())
//     {
//         res += st.top();
//         st.pop();
//     }
//     return res;
// }
// int main()
// {
//     cout << infixToPostfix("A/(B+C*D-E)") << endl;
//     return 0;
// }