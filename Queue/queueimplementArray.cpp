#include <iostream>
using namespace std;

struct Queue
{
private:
    int capacity;
    int *que;
    int front;
    int rear;

public:
    Queue(int cap)
    {
        capacity = cap;
        que = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~Queue()
    {
        delete[] que;
    }

    bool is_full()
    {
        return (rear + 1) % capacity == front;
    }

    bool is_empty()
    {
        return front == -1 || rear == -1;
    }

    void enque(int n)
    {
        if (is_full())
        {
            cout << "Queue is full." << endl;
            return;
        }
        if (is_empty())
        {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        que[rear] = n;
    }

    int deque()
    {
        if (is_empty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        int n = que[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        return n;
    }

    int peek()
    {
        if (is_empty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return que[front];
    }

    void display()
    {
        if (is_empty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        int i = front;
        while (i != rear)
        {
            cout << que[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << que[rear] << endl;
    }
};

int main()
{
    Queue q(5);
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    q.enque(6);
    q.display();
    cout << "Dequeue: " << q.deque() << endl;
    cout << "Dequeue: " << q.deque() << endl;
    q.display();
    return 0;
}
