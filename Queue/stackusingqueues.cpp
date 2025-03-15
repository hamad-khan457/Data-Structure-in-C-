#include <iostream>
#include <queue>
using namespace std;
struct sta{
    queue <int> qu1;
    queue <int> qu2;
    int N;
    sta(){
        N = 0;
    }
public : 
    void push(int value){
        qu2.push(value);
        N++;
        while(!qu1.empty()){
            qu2.push(qu1.front());
            qu1.pop();
        }
        queue <int> temp = qu1;
        qu1 = qu2;
        qu2 = temp;
    }
    void pop(){
        if(N==0){
            cout<<"Stack is empty"<<endl;
            return ;
        }
        qu1.pop();
        N--;
        return;
    }
    int top(){
        return qu1.front();
    }
    int size(){
        return N;
    }
    void Display(){
        queue <int> temp = qu1;
        while(!temp.empty()){
            cout<<temp.front()<<" ";
            temp.pop();
        }
        cout<<endl;
    }
};
int main()
{
    sta s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.pop();
    s1.Display();
}