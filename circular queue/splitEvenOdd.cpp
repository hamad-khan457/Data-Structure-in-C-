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
    void splitQueue(CircularQueue &c1, CircularQueue &c2)
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int pos = 1;
        while (!(front == -1))
        {
            int val = dequeue();
            if (pos % 2 == 1)
            {
                c1.enqueue(val);
            }
            else
            {
                c2.enqueue(val);
            }
            pos++;
        }
    }
};
int main()
{
    CircularQueue q(10);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(2);
    q.enqueue(1);
    q.enqueue(9);
    q.enqueue(8);
    q.enqueue(12);
    q.enqueue(10);
    cout << "Original Queue: ";
    q.display();
    CircularQueue c1(5);
    CircularQueue c2(5);
    q.splitQueue(c1, c2);
    c1.display();
    c2.display();
}