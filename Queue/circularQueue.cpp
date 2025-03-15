#include<iostream>
using namespace std;
struct cicularque{
    int rear;
    int front;
    int *arr;
    int size;
    cicularque(int n){
        size = n;
        arr = new int[size];
        front= rear = -1;
    }
public:
    void enque(int value){
        if((front == 0 && rear == size-1)||(rear == (front -1)%(size-1))){
            cout <<"Queue is full"<<endl;
            return;
        }
        else if(front == -1){
            front = rear = 0;
            arr[rear] = value;
        }
        else if(rear == size-1  && front != 0){
            rear = 0;
            arr[rear] = value;
        }
        else{
            rear++;
            arr[rear] = value;
        }
    }
    int pop(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int ans= arr[front];
        arr[front] = -1;
        if(front == rear){
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            front++;
        }
        return ans;

    }

    void display(){
        int i = front;
        while(i!= rear){
            cout<<arr[i]<<" ";
            if(i == size-1){
                i = -1;
            }
            i++;
        }
        cout<<arr[i]<<" ";
    }
};

int main(){
    cicularque q1(6);
    q1.enque(1);
    q1.enque(2);
    q1.enque(3);
    q1.enque(4);
    q1.enque(5);

    q1.enque(6);
    q1.enque(7);
    q1.display();
}