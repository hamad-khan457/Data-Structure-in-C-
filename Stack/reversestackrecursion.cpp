#include <iostream>
using namespace std;
#include <stack>
void insert_Atbottom(stack<int>&st1, int ele){
    if(st1.empty()){
        st1.push(ele);
        return;
    }
    int topele = st1.top();
    st1.pop();
    insert_Atbottom(st1,ele);
    st1.push(topele);
}
void reverseStack(stack<int>&st1){
    if(st1.empty()){
        return;
    }
    int ele = st1.top();
    st1.pop();
    reverseStack(st1);
    insert_Atbottom(st1,ele);
}
