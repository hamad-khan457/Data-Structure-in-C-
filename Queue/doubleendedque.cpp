#include <iostream>
using namespace std;
struct doublendedque{
    int size;
    int rear;
    int front;
    int *arr;
    doublendedque(int n){
        rear = front = -1;
        size = n;
        arr = new int[size];
    }
public : 
    void push_front(int value){
        if((front == 0 && rear == size -1) ||((front != 0) &&(rear == (front-1)%(size -1)))){
            cout<<"Queue is full"<<endl;
            return;
        }
        if(front == -1){
            front = rear = 0;
            arr[front] = value;
        }
        else if(front == 0 && rear != size-1){
            front = size -1;
            arr[front] = value;
        }
        else{
            front--;
            arr[front] = value;
        }
    }

    int  pop_rear(){                //apply on rear
        if(front == -1){
            cout <<"Queue is empty"<<endl;
            return -1;
        }
        int item = arr[rear];
        if(front == rear){
            front = rear = -1; 
        }
        else if(rear == 0 && front != size-1){
            rear = 0;
        }
        else{
            rear--
        }
        return item;

    }


    void push_rear(int value){
        if(((front == 0 && rear == size-1)) || (rear == (front-1)%(size -1))){
            cout<<"Queue is full"<<endl;
            return;
        }
        if(front == -1){
            front = rear = 0;
            arr[rear] = value;
        }
        else if((rear == size-1) &&(front != 0)){
            rear = 0;
            arr[rear] = value;
        }
        else{
            rear++;
            arr[rear] = value;
        }
    }
    int pop_front(){
        if(front == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        int item = arr[front];
        if(front == rear){
            front = rear = -1;
        }
        else if(front == size -1){
            front = 0;
        }
        else{
            front++;
        }
        return item;
    }
    void display(){
        int i = front;
        while(i != rear){
            cout<<arr[i]<<" ";
            if(i == size-1){
                i =-1;
            }
            i++;
        }
        cout<<arr[i]<<" ";
    }
};
int main(){
    doublendedque q1(3);
    q1.push_front(1);
    q1.push_rear(2);
    q1.push_front(3);
    q1.display();
}