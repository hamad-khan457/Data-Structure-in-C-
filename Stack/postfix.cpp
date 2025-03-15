#include <iostream>
using namespace std;
#include<stack>
#include <math.h>
double postfixtoinfix(string s){
    int total;
    stack<int>st1;
    for(int i = 0 ; i<  s.length() ; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            st1.push(s[i]-'0');
        }
        else{
            int operator2  = st1.top();
            st1.pop();
            int operator1 = st1.top();
            st1.pop();
            switch (s[i])
            {
            case '+': st1.push(operator1 + operator2);
                break;
            case '-': st1.push(operator1 - operator2);
                break;
            case '*': st1.push(operator1 * operator2);
                break;
            case '/': st1.push(operator1 / operator2);
                break;
            case '^': st1.push(pow(operator1 , operator2));
                break;
            }
        }
    }
    return st1.top();
    
}
int main(){
    cout<< " postfix to infix  : "<< postfixtoinfix("1234*5+")<<endl;
}