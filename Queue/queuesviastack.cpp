#include<iostream>
using namespace std;
#include<stack>
struct que{
    stack<int>st1;
public:
    void Push(int value){
        st1.push(value);
    }
    int pop(){
        if(st1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int x = st1.top();
        st1.pop();
        if(st1.empty()){
            return x;
        }
        int item = pop();
        st1.push(x);
        return item;
    }
    bool isempty(){
        return st1.empty();
    }
    void display(){
        stack<int>temp = st1;
        while(!temp.empty()){
            cout<<temp.top()<<" ";
            temp.pop();
        }
        cout<<endl;
    }
};
int main()
{
    que q1;
    q1.Push(1);
    q1.Push(2);
    q1.Push(3);
    q1.Push(4);
    q1.Push(5);
    q1.display();
    cout << q1.pop() << endl;
    // cout << q1.Pop() << endl;
}