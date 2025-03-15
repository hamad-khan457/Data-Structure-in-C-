#include <iostream>
#include <stack>
using namespace std;
struct  que
{
    stack<int>st1;
    stack<int>st2;
public:
    void Push(int value){
        st1.push(value);
    }
    int pop(){
        if(st1.empty() && st2.empty()){
            cout<<"queue is empty";
            return -1;
        }
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            int item = st2.top();
            st2.pop();
            return item;
        }
    }
    bool isempty(){
                if(st1.empty() && st2.empty()){
            cout<<"queue is empty";
            return true;
        }
        return false;
    }
};

// struct que
// {
//     stack<int> st1;

// public:
//     void Push(int x)
//     {
//         st1.push(x);
//     }

//     int Pop()
//     {
//         if (st1.empty())
//         {
//             cout << "No element in queue." << endl;
//             return -1;
//         }
//         int x = st1.top();
//         st1.pop();
//         if (st1.empty())
//         {
//             return x;
//         }
//         int item = Pop();
//         st1.push(x);
//         cout << "Main ab return pr phoncha." << endl;
//         return item;
//     }

//     bool empty()
//     {
//         if (st1.empty())
//         {
//             return true;
//         }
//         return false;
//     }
//     void display()
//     {
//         stack<int> temp = st1;
//         while (!temp.empty())
//         {
//             cout << temp.top() << endl;
//             temp.pop();
//         }
//     }
// };
int main()
{
    que q1;
    q1.Push(1);
    q1.Push(2);
    q1.Push(3);
    q1.Push(4);
    q1.Push(5);
    // q1.display();
    cout << q1.pop() << endl;
    // cout << q1.Pop() << endl;
}