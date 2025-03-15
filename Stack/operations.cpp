#include <iostream>
using namespace std;
#define n 100
struct stac{
    int top;
    int *arr;
    stac(){
        arr = new int[n];
        top = -1;
    }
public:
    void push(int value){
        if(top == n-1){
            cout<<"Stack is full"<<endl;
            return;
        }
        else{
            top++;
            arr[top] = value;
        }
    }
    void pop(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return;
        }
        else{
             top--;
             return;
        }
    }
    int peek(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }
};
// struct node{
//     int data;
//     node *next;
//     node(int value){
//         data = value;
//         next = NULL;
//     }
// };
// struct stac {
//     node *top;
//     stac(){
//         top =NULL;
//     }
// public: 
//     void push(int value){
//         node *n = new node(value);
//         if(top == NULL){
//             top = n;
//         }
//         else{
//             n->next = top;
//             top = n;
//         }

//     }
//     void pop(){
//         if(top == NULL){
//             cout<<"stack is empty"<<endl;
//             return;
//         }
//         else{
//             node * temp = top;
//             top = top->next;
//             delete(temp);
//         }
//     }
//     int peek(){
//         if(top == NULL){
//             cout<<"Stack is empty"<<endl;
//             return -1;
//         }
//         else{
//             return top->data;
//         }
//     }
//     bool isempty(){
//         return top==NULL;
//     }
// };
// int main(){
//     stac s1;
//     s1.push(5);
//     cout<<s1.peek();
// }
