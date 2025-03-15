#include <iostream>
#include <stack>
using namespace std;
struct CircularQueue
{
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int s)
    {
        arr = new int[s];
        size = s;
        front = rear = -1;
    }

    void enqueue(int x)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is full";
            return;
        }
        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = x;
    }

    int dequeue()
    {
        if (front == -1)
        {
            cout << "queue is empty." << endl;
            return -1;
        }
        int temp = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return temp;
    }

    void display()
    {
        if (front == -1)
        {
            cout << "queue is empty." << endl;
            return;
        }
        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << endl;
    }

    void reverse()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        stack<int> st;
        while (!(front == -1))
        {
            st.push(dequeue());
        }
        while (!st.empty())
        {
            enqueue(st.top());
            st.pop();
        }
    }
};
int main()
{
    CircularQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.reverse();
    q.display();
}