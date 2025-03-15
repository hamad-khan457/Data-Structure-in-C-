#include <iostream>
using namespace std;
struct node{
    int data;
    node * next;
    node(int value){
        data = value;
        next = NULL;
    }
};
struct queue{
        node * front;
        node * back;
    queue(){
        front = back = NULL;
    }
    void push(int data){
        node * n = new node(data);
        if(front ==NULL &&  back ==  NULL){
            front= back = n;
            return;
        }
        else{
            back->next = n;
            back = n;
        }
    }
    void pop(){
        if(front == NULL){
            cout <<"Queue is empty"<<endl;
            return;
        }
        else{
            node * temp = front;
            front = front->next; 
            delete(temp);
            
        }
    }
    bool isempty(){
        if(front == NULL){
            cout <<"Queue is empty"<<endl;
            return true;
        }
        else{
            false;
        }
    }
    int peak(){
        if(front == NULL){
            cout <<"Queue is empty"<<endl;
            return -1;
        }
        else{
            return front->data;
        }

    }
    void display(){
        if(front == NULL){
            cout <<"Queue is empty"<<endl;
            return;
        }
        else{
            node * temp = front;
            while(temp != NULL){
                cout<<temp->data <<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};
// #define n 100
// struct queue{
//     int front;
//     int back;
//     int *arr;
//     queue(){
//         front = back = -1;
//         arr = new int[n];
//     }
// public : 
//         void push(int value){
//             if(back == n-1){
//                 cout<<"Queue is full"<<endl;
//                 return;
//             }
//             else{
//                 back++;
//                 arr[back] = value;
//                 if(front == -1){
//                     front++;
//                 }
//                 return;
//             }
//         }
//         void pop(){
//             if(front == -1 || front > back){
//                 cout<<"Queue is empty"<<endl;
//                 return;
//             }
//             else{
//                 front++;
//             }
//         }
//         int peak(){
//             if(front == -1 || front > back){
//                 cout<<"Queue is empty"<<endl;
//                 return -1;
//             }
//             else{
//                 return arr[front];
//             }
//         }
//         bool isempty(){
//             if(front == -1 || front > back){
//                 return true;
//             }
//             else{
//                 false;
//             }
//         }

// };
int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.display();
    cout << q.peak() << endl;
    q.pop();
    q.pop();
    cout << q.peak() << endl;
    q.pop();
    q.pop();
    q.pop();
    cout << q.isempty() << endl;
    q.pop();
    q.display();
    return 0;
}